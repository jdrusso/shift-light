EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:crumpschemes
LIBS:shiftlight-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR01
U 1 1 589CEC8D
P 3650 4150
F 0 "#PWR01" H 3650 3900 50  0001 C CNN
F 1 "GND" H 3650 4000 50  0000 C CNN
F 2 "" H 3650 4150 50  0000 C CNN
F 3 "" H 3650 4150 50  0000 C CNN
	1    3650 4150
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 589CECD3
P 4150 3550
F 0 "R1" V 4230 3550 50  0000 C CNN
F 1 "3.3k" V 4150 3550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4080 3550 50  0001 C CNN
F 3 "" H 4150 3550 50  0000 C CNN
	1    4150 3550
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 589CED08
P 4950 3100
F 0 "R2" V 5030 3100 50  0000 C CNN
F 1 "10k" V 4950 3100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4880 3100 50  0001 C CNN
F 3 "" H 4950 3100 50  0000 C CNN
	1    4950 3100
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q1
U 1 1 589CED65
P 4850 3800
F 0 "Q1" H 5050 3850 50  0000 L CNN
F 1 "Q_NPN_BCE" H 5050 3750 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 5050 3900 50  0001 C CNN
F 3 "" H 4850 3800 50  0000 C CNN
	1    4850 3800
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 589CEDBF
P 4150 4000
F 0 "D1" H 4150 4100 50  0000 C CNN
F 1 "D" H 4150 3900 50  0000 C CNN
F 2 "Diodes_THT:D_DO-15_P12.70mm_Horizontal" H 4150 4000 50  0001 C CNN
F 3 "" H 4150 4000 50  0000 C CNN
	1    4150 4000
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 589CEEF5
P 4400 4150
F 0 "#PWR02" H 4400 3900 50  0001 C CNN
F 1 "GND" H 4400 4000 50  0000 C CNN
F 2 "" H 4400 4150 50  0000 C CNN
F 3 "" H 4400 4150 50  0000 C CNN
	1    4400 4150
	1    0    0    -1  
$EndComp
Text Label 3900 3000 0    60   ~ 0
Tach_Signal
$Comp
L ATTINY85-P IC1
U 1 1 589CF11E
P 6450 2900
F 0 "IC1" H 5300 3300 50  0000 C CNN
F 1 "ATTINY85-P" H 7450 2500 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_Socket" H 7450 2900 50  0000 C CIN
F 3 "" H 6450 2900 50  0000 C CNN
	1    6450 2900
	0    1    1    0   
$EndComp
$Comp
L LM317K U1
U 1 1 589CFC51
P 3800 2050
F 0 "U1" H 3600 2250 50  0000 C CNN
F 1 "LM317K" H 3800 2250 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Horizontal" H 3800 2150 50  0000 C CIN
F 3 "" H 3800 2050 50  0000 C CNN
	1    3800 2050
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 589CFD56
P 3450 2400
F 0 "R3" V 3530 2400 50  0000 C CNN
F 1 "5" V 3450 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 3380 2400 50  0001 C CNN
F 3 "" H 3450 2400 50  0000 C CNN
	1    3450 2400
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 589CFD93
P 4200 2400
F 0 "R4" V 4280 2400 50  0000 C CNN
F 1 "7" V 4200 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4130 2400 50  0001 C CNN
F 3 "" H 4200 2400 50  0000 C CNN
	1    4200 2400
	0    1    1    0   
$EndComp
$Comp
L CONN_01X03 LED1
U 1 1 589D2BEF
P 4100 1500
F 0 "LED1" H 4100 1700 50  0000 C CNN
F 1 "CONN_01X03" V 4200 1500 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4100 1500 50  0001 C CNN
F 3 "" H 4100 1500 50  0000 C CNN
	1    4100 1500
	-1   0    0    1   
$EndComp
$Comp
L +12V #Power_From_Car03
U 1 1 589D2E39
P 2650 2000
F 0 "#Power_From_Car03" H 2650 1850 50  0001 C CNN
F 1 "+12V" H 2650 2140 50  0000 C CNN
F 2 "" H 2650 2000 50  0000 C CNN
F 3 "" H 2650 2000 50  0000 C CNN
	1    2650 2000
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P1
U 1 1 589D1326
P 4150 3100
F 0 "P1" H 4150 3200 50  0000 C CNN
F 1 "CONN_01X01" V 4250 3100 50  0001 C CNN
F 2 "Connectors:PINTST" H 4150 3100 50  0001 C CNN
F 3 "" H 4150 3100 50  0000 C CNN
	1    4150 3100
	0    -1   -1   0   
$EndComp
Text Label 3450 4450 0    60   ~ 0
Car_GND
$Comp
L DG9421 U2
U 1 1 589D1348
P 7950 1350
F 0 "U2" H 8030 1220 50  0000 L CNN
F 1 "DG9421" H 8020 1470 50  0000 L CNN
F 2 "Buttons_Switches_THT:SW_PUSH-12mm" H 7950 1350 60  0001 C CNN
F 3 "" H 7950 1350 60  0001 C CNN
	1    7950 1350
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 589D1EA3
P 6600 4800
F 0 "R5" V 6680 4800 50  0000 C CNN
F 1 "10k" V 6600 4800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6530 4800 50  0001 C CNN
F 3 "" H 6600 4800 50  0000 C CNN
	1    6600 4800
	0    1    1    0   
$EndComp
Text Label 7750 1150 0    60   ~ 0
Dimmer_Button
$Comp
L CONN_01X01 P2
U 1 1 58A388F4
P 3300 4150
F 0 "P2" H 3300 4250 50  0000 C CNN
F 1 "CONN_01X01" V 3400 4150 50  0000 C CNN
F 2 "Connectors:PINTST" H 3300 4150 50  0000 C CNN
F 3 "" H 3300 4150 50  0000 C CNN
	1    3300 4150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4950 4150 4950 4000
Connection ~ 4950 4150
Wire Wire Line
	4950 3250 4950 3600
Wire Wire Line
	4150 3700 4150 3850
Wire Wire Line
	4650 3800 4150 3800
Connection ~ 4150 3800
Wire Wire Line
	6400 1400 6400 1550
Wire Wire Line
	6700 4250 6700 4600
Wire Wire Line
	2450 2000 3400 2000
Wire Wire Line
	3150 2000 3150 2400
Wire Wire Line
	3150 2400 3300 2400
Connection ~ 3150 2000
Wire Wire Line
	3600 2400 4050 2400
Wire Wire Line
	3800 2300 3800 2400
Connection ~ 3800 2400
Wire Wire Line
	3500 4150 5500 4150
Wire Wire Line
	4350 2400 4350 2850
Wire Wire Line
	4350 2850 3650 2850
Wire Wire Line
	3650 2850 3650 4150
Wire Wire Line
	4200 2000 4950 2000
Wire Wire Line
	4950 1600 4950 2950
Wire Wire Line
	4950 2800 5800 2800
Wire Wire Line
	5800 2800 5800 4600
Wire Wire Line
	5800 4600 7650 4600
Connection ~ 4950 2800
Wire Wire Line
	6400 1400 4300 1400
Wire Wire Line
	4300 1500 5500 1500
Wire Wire Line
	5500 1500 5500 4250
Wire Wire Line
	4300 1600 4950 1600
Connection ~ 4950 2000
Wire Wire Line
	6700 1350 7650 1350
Wire Wire Line
	6700 1350 6700 1550
Wire Wire Line
	4950 3500 5950 3500
Wire Wire Line
	5950 3500 5950 1500
Connection ~ 4950 3500
Wire Wire Line
	6300 1550 6300 1500
Wire Wire Line
	4150 3300 4150 3400
Wire Wire Line
	5500 4250 6200 4250
Connection ~ 5500 4150
Wire Wire Line
	6300 1500 5950 1500
Wire Wire Line
	6200 4250 6200 4800
Wire Wire Line
	6200 4800 6450 4800
Wire Wire Line
	6750 4800 8250 4800
Wire Wire Line
	8250 4800 8250 1350
Wire Wire Line
	7650 4600 7650 1500
Connection ~ 6700 4600
Connection ~ 3650 4150
$Comp
L CONN_01X01 P3
U 1 1 58A38F00
P 2800 2400
F 0 "P3" H 2800 2500 50  0000 C CNN
F 1 "CONN_01X01" V 2900 2400 50  0000 C CNN
F 2 "Connectors:PINTST" H 2800 2400 50  0000 C CNN
F 3 "" H 2800 2400 50  0000 C CNN
	1    2800 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 2000 2450 2400
Connection ~ 2450 2000
Wire Wire Line
	2450 2400 2600 2400
$EndSCHEMATC
