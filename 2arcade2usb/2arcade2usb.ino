/*
	2x DB9 to USB converter 
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
 * Version 1.1 (See CHANGELOG)
 * Release date: 2019-04-19
 * 
 * Written & released by M.F. Wieland (TSB)
 * 
 * This is free and unencumbered software released into the public domain.
 * See the file LICENSE for more details, or visit <http://unlicense.org>.
 */

#include "Joystick.h" 

// define buttons joystick port 2
const int pin_joystick_up = 4;      //6
const int pin_joystick_down = 5;    //5
const int pin_joystick_left = 6;    //4
const int pin_joystick_right = 7;   //3
const int pin_joystick_button1 = 8; //2

// define buttons joystick port 1
const int pin_joystick2_up = 21;      //
const int pin_joystick2_down = 20;    //
const int pin_joystick2_left = 19;    //
const int pin_joystick2_right = 18;   //
const int pin_joystick2_button1 = 15; //

// define Menu buttons
const int pin_joystick_button_menu = 14; //A0
const int pin_joystick_button_a = 9; //A3
const int pin_joystick_button_b = 10; //A2
const int pin_joystick_button_c = 16; //15
const int pin_joystick_button_lt = 2;
const int pin_joystick_button_rt = 3;

int debounceDelay = 1; // debounce delay

void setup() {
  // turn off green led's
	pinMode(1, OUTPUT);
	pinMode(0, OUTPUT);
	
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
	
	delay(debounceDelay);
}
