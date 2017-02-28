# shift-light
This repository contains code for a Miata shift light,
using a generic WS2812 individually addressible LED strip and ATTiny85 microcontroller.

## CAD Files
The ```cad/``` directory contains files generated in KiCAD for the PCB layout.
The included Gerber files should be useful in manufacturing this (as-yet-untested) board.

## Circuit Design
Most of the circuitry here is just stepping the 12V tach signal down to 5V for
the microcontroller to read it.


<!-- The voltage regulator sees (12 volts - 5 volts) * 1A max, so is dissipating
around 7 watts. This will definitely require a heatsink. Assuming a max ambient
temp of around 50 degrees Celsius, we need a heatsink with a thermal resistance
of at least 1.4 degrees/Watt, or one that can dissipate about 7W -->
