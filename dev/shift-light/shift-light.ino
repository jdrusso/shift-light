//Miata shift light!
// Based on code from https://www.reddit.com/r/arduino/comments/515vsd/my_progressive_shift_light_because_racecar/?ref=share&ref_source=link
// Ignition frequency is equal to RPM/30
//initialize libraries
#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>


#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            5  //LED Data Pin
#define BUTTON_PIN     6
#define NUMPIXELS      12  //number of leds connected
#define YLWPIXELS       2  //
Bounce debouncer = Bounce();
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int i;
int rpm;
float ighigh,iglow;
unsigned long igfreq, igcal1, igcal2;
int cnt;
int niday=HIGH;

int _red[] = {100,0,0};
int _green[] = {0,100,0};
int _blue[] = {0,0,100};
int _yellow[] = {100,100,0};

int _dimred[] = {20,0,0};
int _dimgreen[] = {0,20,0};
int _dimblue[] = {0,0,20};
int _dimyellow[] = {20,20,0};

int _off[] = {0,0,0};

int MIN_RPM = 3000;
int SHIFT_RPM = 6200;
int MAX_RPM = 6900;

int manual_igfreq;
int brightness_state = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5);
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);        // connect to the serial port

  Serial.println("Frequency Counter"); //this is jsut for debugging so we can see what freq the controller is reading

  manual_igfreq = 100;

  if (YLWPIXELS > NUMPIXELS){
    Serial.println("Error. Number of yellow pixels set incorrectly");
    exit(-1);
  }
}

void loop() {

  //DEBUGGING CODE - Manually set RPM using a digit between 0-7
//  char manual_RPM = Serial.read();
//  Serial.println("Read");
//  int manual_igfreq = 100 + 7 * manual_RPM; 
  if (manual_igfreq <= 250){

    manual_igfreq++;
    delay(10);
  } else {
    manual_igfreq = 100;
  }
  
  //loop code, runs every cycle

  // Update the Bounce instance to see if button was pressed:
   debouncer.update();

   // Call code if Bounce fell (transition from HIGH to LOW) :
   if ( debouncer.fell() ) {

     Serial.println("Button pressed");
     // Toggle LED state if button was pressed :
     niday = !niday;
     brightness_state++;
     brightness_state = brightness_state % 3;


   }

  //measure period of tach signal
//  ighigh = pulseIn(5,HIGH);
//  iglow = pulseIn(5,LOW);
//
//  igcal1=1000/((ighigh/1000)+(iglow/1000));
//
//  //do it again
//  ighigh = pulseIn(5,HIGH);
//  iglow = pulseIn(5,LOW);
//
//  igcal2=1000/((ighigh/1000)+(iglow/1000));
//  //to filter out some noise, we only consider our measurement valid if they are similar in value, we accept the average
//  if((igcal1-igcal2)<8)igfreq = (igcal1+igcal2)/2;
//
//  //displaying measured freq through serial for debugging 
//  Serial.print(cnt++);
//  Serial.print("  Freq: ");
//  Serial.println(igfreq);
//  delay(1);


  //day mode LED setup
  //Progressive lights from 3000-6500, 6 green lights, then yellow, then blue.
  // @6500 all flashing blue
  // @7000 all flashing red 
  igfreq = manual_igfreq;

  int rpm = igfreq/30;

  int red[3];
  int green[3];
  int blue[3];
  int yellow[3];
  
  if (brightness_state == 1){
    memcpy(red, _red, 3*sizeof(int));
    memcpy(green, _green, 3*sizeof(int));
    memcpy(blue, _blue, 3*sizeof(int));
    memcpy(yellow, _yellow, 3*sizeof(int));
  } 
  else if (brightness_state == 2){
    memcpy(red, _dimred, 3*sizeof(int));
    memcpy(green, _dimgreen, 3*sizeof(int));
    memcpy(blue, _dimblue, 3*sizeof(int));
    memcpy(yellow, _dimyellow, 3*sizeof(int));
  }

  // If the current RPM is below the trigger RPM,
  //  or brightness is set to OFF, turn the strip off
  //  and proceed.
  if (rpm < MIN_RPM || brightness_state == 0){

    lightPixels(pixels, 0, NUMPIXELS, _off);
  }

  // Light green pixels
  else if (rpm > MIN_RPM && rpm < SHIFT_RPM){

    // Light the LEDs using the number of green pixels * ratio of current rpm to shift rpm
    int litPixels = (NUMPIXELS) * (rpm - MIN_RPM)/(SHIFT_RPM-MIN_RPM);

    //If it's only green pixels..
    if (litPixels <= NUMPIXELS - YLWPIXELS){

      lightPixels(pixels, 0, litPixels, green);
    }

    //If both green and yellow should be lit
    else if (litPixels > (NUMPIXELS-YLWPIXELS)){

      //    Pixels / RPM = NUMPIXELS / (shift - min)
      //    Number of pixels to be lit is NUMPIXELS / (shift-min) * (rpm-min)
      //    If this number is > total pixels - yellow pixels, light the green
      //    otherwise also light the yellow

      //Light the green pixels
      lightPixels(pixels, 0, (NUMPIXELS-YLWPIXELS), green);

      //Light the yellow pixels
      lightPixels(pixels, (NUMPIXELS-YLWPIXELS)+1, litPixels, yellow);
    }
  }

  //Flash blue to shift
  else if (rpm >= SHIFT_RPM && rpm < MAX_RPM){

    lightPixels(pixels, 0, NUMPIXELS, _blue);
    delay(20);
    pixels.show();
    lightPixels(pixels, 0, NUMPIXELS, _off);
    delay(20);
  }

  //Flash red when you're past max
  else if (rpm >= MAX_RPM){

    lightPixels(pixels, 0, NUMPIXELS, _red);
    delay(20);
    pixels.show();
    lightPixels(pixels, 0, NUMPIXELS, _off);
    delay(20);
  }

   pixels.show();
}

// Light a range of pixels with a given color
void lightPixels(Adafruit_NeoPixel pixels, int pixelStart, int pixelEnd, int rgb[]){

  for(i=0;(i<(pixelEnd-pixelStart));i++){

    lightPixel(pixels,pixelStart+i,rgb);
  }
}

// Light a single pixel
void lightPixel(Adafruit_NeoPixel pixels, int pixelNum, int rgb[]){

  int red = rgb[0];
  int green = rgb[1];
  int blue = rgb[2];  

  pixels.setPixelColor(pixelNum, pixels.Color(red, green, blue));
}

