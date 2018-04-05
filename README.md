MAX7219

Copyright(c) 2018 BitBank Software, Inc.<br>
<br>

![MAX7219 Array](/max7219.gif?raw=true "ATtiny85 Demo")

MAX7219 is a simple C library for working with the Maxim LED matrix
controllers when connected to the SPI bus or bit-banged on GPIO pins.
The idea is to provide a simple interface for C programmers to make use of 
those low-cost, cascadable LED controllers without having to read the data sheet or figure
out SPI programming. When using SPI, the display controller needs an additional control
line (GPIO pin) for latching the data; this requires extra work on Linux platforms.
In this case, I use my ArmbianIO library (https://github.com/bitbank2/ArmbianIO)
<br>
To build the library, simply type 'make' in the terminal. To build the sample
app, type 'make -f make_demo'. This will build the demo executable to show
that the library is working.
<br>
For Arduino, choose the SPI option by defining "USE_SPI" before you include max7219.h.
Otherwise, the bit-banged option will be used. This is useful for devices like the
ATtiny85 which don't have SPI hardware.<br>
Linux Troubleshooting tips:<br>
<br>
1) Make sure to enable the SPI interface and check the bus number (e.g. /dev/spidev0.0)<br>
2) Connect the "CS" pin of the first MAX7219 to the correct GPIO pin.<br>
3) You can use any GPIO pin to control the data latch; initialize the
   library with the pin number used (not GPIO number)<br>

Written by Larry Bank<br>
Project started 3/10/2018<br>
bitbank@pobox.com<br>

