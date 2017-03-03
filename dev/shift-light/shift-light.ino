//Miata shift light!
// Based on code from https://www.reddit.com/r/arduino/comments/515vsd/my_progressive_shift_light_because_racecar/?ref=share&ref_source=link
// Ignition frequency is equal to RPM/30
//initialize libraries
#include <Bounce2.h>
#include <FastLED.h>



#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            4  //LED Data Pin
#define BUTTON_PIN     3  //Pin for pushbutton
#define NUMPIXELS      8  //number of leds connected
Bounce debouncer = Bounce();

CRGB pixels[NUMPIXELS];


int i;
int rpm;
float ighigh, iglow;
unsigned long igfreq, igcal1, igcal2;
int cnt;
int niday = HIGH;

int manual_igfreq;
int brightness_state = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5);
//  Serial.begin(115200);        // connect to the serial port

//  Serial.println("Frequency Counter"); //this is jsut for debugging so we can see what freq the controller is reading

  manual_igfreq = 100;

  FastLED.addLeds<NEOPIXEL, PIN>(pixels, NUMPIXELS);
  FastLED.setBrightness(100);
}

void loop() {

  //DEBUGGING CODE - Manually set RPM using a digit between 0-7
  //  char manual_RPM = Serial.read();
  //  Serial.println("Read");
  //  int manual_igfreq = 100 + 7 * manual_RPM;
  if (manual_igfreq <= 250) {

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

//    Serial.println("Button pressed");
    // Toggle LED state if button was pressed
    brightness_state++;
    brightness_state = brightness_state % 3;
    if (brightness_state == 2){
      FastLED.setBrightness(10);
    }
    else if (brightness_state == 0){
      FastLED.setBrightness(0);
    }
    else if (brightness_state == 1){
      FastLED.setBrightness(100);
    }
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

  //  if(niday == HIGH){
  if (brightness_state == 0) {
    for (i = 0; (i < NUMPIXELS); i++) {

      pixels[i] = CRGB::Black;

    }
  }

  //As you approach the shift point, light up
  if (igfreq >= 100 && igfreq < 216) {
    for ( i = 0; (i < NUMPIXELS) && (i <= ((igfreq - 100) / 16)); i++) {

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      if (i < 6) {
        pixels[i] = CRGB::Green;
      }
      if (igfreq > 196) {
        pixels[i] = CRGB::Yellow;
      }
      if (igfreq > 212) {
        pixels[i] = CRGB::Blue;
      }
    }

   //Useless code was here
  }

  // If you're at the shift point, strobe blue
  else if (igfreq >= 216 && igfreq < 230) {
    for ( i = 0; i < NUMPIXELS; i++) {
      
      pixels[i] = CRGB::Blue;
      FastLED.show();
    }
    
    delay(10);
    for (i = 0; i < NUMPIXELS; i++) {

      pixels[i] = CRGB::Black;
      FastLED.show();
    }
    delay(10);
  }

  // If above target RPM, strobe red
  else if (igfreq >= 230) {
    for ( i = 0; (i < NUMPIXELS); i++) {

      pixels[i] = CRGB::Red;
      FastLED.show();
    }
    delay(10);
    for ( i = 0; (i < NUMPIXELS); i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255

      pixels[i] = CRGB::Black;
      FastLED.show();
    }
    
    delay(10);
  }

  // Else, turn the strip off
  else for (i = 0; (i < NUMPIXELS); i++) {

      pixels[i] = CRGB::Black;
    }
    
    FastLED.show();
}
