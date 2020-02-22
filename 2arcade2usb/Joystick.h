/*
	Joystick.h
	This is a Modified joystick.h file made to support 2db9 joysticks
	By Gary Metheringham*/
/*
	* joystick.h
	*
	* Joystick routines to handle arcade to usb conversion
	*
	* Version 1.1
	* Release date: 2019-04-19
	*
	* Written & released by M.F. Wieland (TSB)
	*
	* This is free and unencumbered software released into the public domain.
	* See the file LICENSE for more details, or visit <http://unlicense.org>.
	*/

/*
  Joystick2.h

  Copyright (c) 2015, Matthew Heironimus

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef JOYSTICK_h
#define JOYSTICK_h

#include "HID.h"

#if ARDUINO < 10606
#error The Joystick2 library requires Arduino IDE 1.6.6 or greater. Please update your IDE.
#endif

#if ARDUINO > 10606
#if !defined(USBCON)
#error The Joystick2 library can only be used with a USB MCU (e.g. Arduino Leonardo, Arduino Micro, etc.).
#endif
#endif

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Joystick (Gamepad)

class Joystick_
{
private:
	uint8_t  joystickId;
	bool     autoSendState;
	int8_t	 _xAxis = 0x7f;
	int8_t	 _yAxis = 0x7f;
	uint16_t _buttons =0x0;

public:
	Joystick_(uint8_t initJoystickId);

	void reset(void);
	void begin(bool initAutoSendState = true);
	void end();

	void setXAxis(int8_t value);
	void setYAxis(int8_t value);

	void setButton(uint8_t button, uint8_t value);
	void pressButton(uint8_t button);
	void releaseButton(uint8_t button);

	void up();
	void down();
	void left();
	void right();
	void button_press(uint16_t button);
	void usb_update();
	void sendState();
};
extern Joystick_ Joystick[2];

#endif
#endif
