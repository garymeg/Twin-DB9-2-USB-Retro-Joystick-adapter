# Twin-DB9-2-USB
a Dual db9 to usb adapter for use with TheC64 mini/maxi windows

if you use the above GERBER file there is an error on the ISP connecter with some pins 
Do not use it unless you build an adapter to correct the pins

Use avrdudess to upload the .HEX file to the pro-micro

set MCU to ATMEGA32u4
set programmer to your programmer
click read fuses to ensure you have communication

select one of the hex-files in the flash section (use the bootloader one if you plan on using arduino ide to program)
click write under the hex file  (Still in flash section)

to add to the gamecontrollerdb.txt

please download from my x-windows repo.
and follow instructions there.

