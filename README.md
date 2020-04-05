# Twin-DB9-2-USB
a Dual db9 to usb adapter for use with TheC64 mini/maxi windows

if you use the above GERBER file there is an error on the ISP connecter with some pins 
Do not use the isp header unless you build an adapter to correct the pins
The Pro-micro can be programmed over usb with the usb cable though.

Use avrdudess to upload the .HEX file to the pro-micro

set MCU to ATMEGA32u4
set programmer to your programmer
click read fuses to ensure you have communication

select one of the hex-files in the flash section (use the bootloader one if you plan on using arduino ide to program)
click write under the hex file  (Still in flash section)

to add to the gamecontrollerdb.txt insert the following line at the beginning of gamecontrollerdb.txt

03000000828200000132000001010000,DB9-2-USB,a:b4,b:b5,back:b6,lefttrigger:b0,leftx:a0,lefty:a1,righttrigger:b1,start:b7,x:b3,y:b2,platform:Linux,

the above line(s) are 1 line of text in gamecontrollerdb.txt



