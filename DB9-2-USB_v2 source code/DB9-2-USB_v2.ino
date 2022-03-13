  /*
	DB9-2-USB converter V2
	By Gary Metheringham

	Code Modified from M.F. Wieland (TSB) Code to support 2 Classic Atari Type DB9 Joysticks

	This is free and unencumbered software released into the public domain.
	See the file LICENSE for more details, or visit <http://unlicense.org>.
*/
/*
 * c64mini-arcade2usb-converter.ino
 * 
 * C64 Mini Arcade Joystick to USB Converter.
 * 
 * Version 2 (See CHANGELOG)

 * Release date: 20-05-01

 
 * 
 * Written & released by M.F. Wieland (TSB)
 * 
 * This is free and unencumbered software released into the public domain.
 * See the file LICENSE for more details, or visit <http://unlicense.org>.

 * Before uploading goto C:\Program Files (x86)\arduino-PR-beta1.9-BUILD-119\hardware\arduino\avr
 * and edit boards.txt
 * scroll down to leoanardo and change hid and vid to 
 * vid = 8282
 * HID = 3201
 */


#include "Joystick.h" 


// define buttons joystick port 2
const int pin_joystick_up = 2;      //6
const int pin_joystick_down = 6;    //5
const int pin_joystick_left = 5;    //4
const int pin_joystick_right = 4;   //3
const int pin_joystick_button1 = 7; //2

// define buttons joystick port 1
const int pin_joystick2_up = 16;      //
const int pin_joystick2_down = 15;    //
const int pin_joystick2_left = 18;    // A0
const int pin_joystick2_right = 19;   // A1
const int pin_joystick2_button1 = 14; //

// define Analog (paddle) inputs port 1
const int pot1x = 20;    // A2
const int pot1y = 21;    // A3

// define Analog (paddle) inputs port 2
const int pot2x = 9;    // A9
const int pot2y = 8;    // A8

// define Menu buttons
const int pin_joystick_button_menu = 10; //A10
const int pin_joystick_button_a = 9; //A9
const int pin_joystick_button_b = 8; //A8
const int pin_joystick_button_c = 3; 
const int pin_joystick_button_lt = 21; //A3
const int pin_joystick_button_rt = 20; //A2

int debounceDelay = 1; // debounce delay

void setup() {
	Serial.begin(115200);
  // turn off green led's
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
digitalWrite(0, LOW);
digitalWrite(1, LOW);

// setup input pins Joystick 1
pinMode(pin_joystick_up, INPUT_PULLUP);
pinMode(pin_joystick_down, INPUT_PULLUP);
pinMode(pin_joystick_left, INPUT_PULLUP);
pinMode(pin_joystick_right, INPUT_PULLUP);
pinMode(pin_joystick_button1, INPUT_PULLUP);

// setup input pins Joystick 2
pinMode(pin_joystick2_up, INPUT_PULLUP);
pinMode(pin_joystick2_down, INPUT_PULLUP);
pinMode(pin_joystick2_left, INPUT_PULLUP);
pinMode(pin_joystick2_right, INPUT_PULLUP);
pinMode(pin_joystick2_button1, INPUT_PULLUP);

// setup input pins Menu buttons
pinMode(pin_joystick_button_menu, INPUT_PULLUP);
pinMode(pin_joystick_button_a, INPUT_PULLUP);
pinMode(pin_joystick_button_b, INPUT_PULLUP);
pinMode(pin_joystick_button_c, INPUT_PULLUP);
pinMode(pin_joystick_button_lt, INPUT_PULLUP);
pinMode(pin_joystick_button_rt, INPUT_PULLUP);
}


void loop() {
	digitalWrite(0, LOW);
	digitalWrite(1, LOW);
	TXLED0;
	RXLED0;
	// Reset values for next loop..  
	Joystick[0].reset();
	Joystick[1].reset();

	// Button - Fire (1) (7 0x40)
	if (digitalRead(pin_joystick_button1) == LOW) {

		Joystick[0].button_press(0x01);
		// see documentation to use other device
	}

	// Button - Menu (10 0x0200)
	if (digitalRead(pin_joystick_button_menu) == LOW) {

		Joystick[0].button_press(0x80);
		// see documentation to use other device
	}

	// Button - A (9 0x0100)
	if (digitalRead(pin_joystick_button_a) == LOW) {

		Joystick[0].button_press(0x010);
		// see documentation to use other device
	}

	// Button - B (2 0x02)
	if (digitalRead(pin_joystick_button_b) == LOW) {

		Joystick[0].button_press(0x20);
		// see documentation to use other device
	}

	// Button - C (3 0x04)
	if (digitalRead(pin_joystick_button_c) == LOW) {

		Joystick[0].button_press(0x40); 
		// see documentation to use other device
	}


// Button - lt (4 0x08)
if (digitalRead(pin_joystick_button_lt) == LOW) {

	Joystick[0].button_press(0x04);
	// see documentation to use other device
}

// Button - rt (5 0x10)
if (digitalRead(pin_joystick_button_rt) == LOW) {

	Joystick[0].button_press(0x08);
	Joystick[1].button_press(0x02);
	// see documentation to use other device
}


	// Button - Up j1
	if (digitalRead(pin_joystick_up) == LOW) {

		Joystick[0].up();
	}

	// Button - Right j1
	if (digitalRead(pin_joystick_right) == LOW) {
		Joystick[0].right();
	}

	// Button - Down j1
	if (digitalRead(pin_joystick_down) == LOW) {

		Joystick[0].down();
	}

	// Button - Left j1
	if (digitalRead(pin_joystick_left) == LOW) {

		Joystick[0].left();
	}



	// Button - fire (2)
	if (digitalRead(pin_joystick2_button1) == LOW) {

		Joystick[1].button_press(0x01);
		// see documentation to use other device
	}

	// Button - Up j2
	if (digitalRead(pin_joystick2_up) == LOW) {

		Joystick[1].up();
	}

	// Button - Down j2
	if (digitalRead(pin_joystick2_down) == LOW) {

		Joystick[1].down();
	}

	// Button - Left j2
	if (digitalRead(pin_joystick2_left) == LOW) {

		Joystick[1].left();
	}

	// Button - Right j2
	if (digitalRead(pin_joystick2_right) == LOW) {
		Joystick[1].right();
	}
	// update joystick actions
	
	Joystick[0].usb_update();
	Joystick[1].usb_update();
	
}
