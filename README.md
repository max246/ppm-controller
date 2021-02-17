# PPM Controller
The repo contains schematic to build a simple board with level shift to 3.3V and firmware to control some channels with a FrSky radio (Spektrum has not been tested yet).

![alt text](https://github.com/max246/ppm-controller/blob/main/images/board.png?raw=true)

## Board
The board has two jacks, one for Frsky( TESTED ) and one for Spektrum ( NOT TESTED ), the idea behind this is to allow a wide range of radio to be connect to the board, Spektrum has the possiblity to read as well but it has not been implemented.

There is a solder jumper to select which LEFT or RIGHT channel to use with Spektrum or potentially other radios otherwise the FrSky jack is fully working and tested.
The level shift IC is a BSS138 with two resistor of 10K ohm.

## Firmware
The firmware can be uploded on any Arduino but it has been tested only on a UNO version, it uses PIN 10 to output the signal and reading from Serial for new values to be set.
The idea is to send a 5 bytes buffer which can be expanded for more channels, but the last slot it just a termial value which is 0X0C.
In the example the system just accepts 0 or 1 as value and it switches between MAX, IDLE and MIN values.

## Issues

If you try to set a PPM value that is out of range, the radio will act as trainer mode is disconnected, make sure you use the correct values for your radio!
