
/* Joystick.cpp 
	This is a Modified joystick.h file made to support 2db9 joysticks
	By Gary Metheringham
*/

/*
* joystick.cpp
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
  Joystick2.cpp

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

#include "Joystick.h"

#if defined(_USING_HID)

#define JOYSTICK_REPORT_ID  0x02
#define JOYSTICK2_REPORT_ID 0x03
#define JOYSTICK_STATE_SIZE 4

static const uint8_t _hidReportDescriptor[] PROGMEM = {

	// Joystick #1
	0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
	0x09, 0x04,               // USAGE (Joystick)
	0xa1, 0x01,               // COLLECTION (Application)
		0xa1, 0x02,                 // COLLECTION (Application)
			0x85, JOYSTICK_REPORT_ID, // Report ID

			0x75, 0x08,               // REPORT_SIZE (8)
			0x95, 0x02,               // REPORT_COUNT (5)
			0x26, 0xff, 0x00,         // LOGICAL_MAXIMUM (255)
			0x35, 0x00,               // Physical min (0)
			0x46, 0xff, 0x00,         // Physical max (255)      
			0x09, 0x30,               // USAGE (x)
			0x09, 0x31,               // USAGE (y)
			0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
			0x65, 0x00,               // Unit (none)

			0x75, 0x01,               // REPORT_SIZE (4)
			0x95, 0x10,               // REPORT_COUNT (1)
			0x25, 0x01,               // LOGICAL_MAXIMUM (1)
			0x45, 0x01,               // Physical_MAXIMUM (1)
			0x05, 0x09,               // USAGE_PAGE (Button)
			0x19, 0x01,               // USAGE_MINIMUM (Button 1)
			0x29, 0x08,               // USAGE_MAXIMUM (Button 8)
			0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)

			0x06, 0x00, 0xff,         // Usage page (Vendor-Defined 1)
			0x75, 0x01,               // REPORT_SIZE (1)
			0x95, 0x08,               // REPORT_COUNT (8)
			0x25, 0x01,               // Logical max (255)
			0x45, 0x01,               // Physical max (255)
			0x09, 0x01,               // Usage (Vendor-Defined 1)
			0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
		0xc0,                       // END_COLLECTION
		0xc0,                 // COLLECTION (Application)
	// Joystick #2
	0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
	0x09, 0x04,               // USAGE (Joystick)
	0xa1, 0x01,               // COLLECTION (Application)
		0xa1, 0x02,                 // COLLECTION (Application)
			0x85, JOYSTICK2_REPORT_ID, // Report ID
			0x75, 0x08,               // REPORT_SIZE (8)
			0x95, 0x02,               // REPORT_COUNT (5)
			0x26, 0xff, 0x00,         // LOGICAL_MAXIMUM (255)
			0x35, 0x00,               // Physical min (0)
			0x46, 0xff, 0x00,         // Physical max (255)      
			0x09, 0x30,               // USAGE (x)
			0x09, 0x31,               // USAGE (y)
			0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)

			0x65, 0x00,               // Unit (none)
			0x75, 0x01,               // REPORT_SIZE (4)
			0x95, 0x10,               // REPORT_COUNT (1)
			0x25, 0x01,               // LOGICAL_MAXIMUM (1)
			0x45, 0x01,               // Physical_MAXIMUM (1)
			0x05, 0x09,               // USAGE_PAGE (Button)
			0x19, 0x01,               // USAGE_MINIMUM (Button 1)
			0x29, 0x01,               // USAGE_MAXIMUM (Button 8)
			0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)

			0x06, 0x00, 0xff,         // Usage page (Vendor-Defined 1)
			0x75, 0x01,               // REPORT_SIZE (1)
			0x95, 0x08,               // REPORT_COUNT (8)
			0x25, 0x01,               // Logical max (255)
			0x45, 0x01,               // Physical max (255)
			0x09, 0x01,               // Usage (Vendor-Defined 1)
			0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
		0xc0,                       // END_COLLECTION
	0xc0                       // END_COLLECTION
};

Joystick_::Joystick_(uint8_t initJoystickId)
{
    // Setup HID report structure
	static bool usbSetup = false;
	
	if (!usbSetup)
	{
	    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	    HID().AppendDescriptor(&node);
        usbSetup = true;
	}
    
    // Initalize State
    joystickId = initJoystickId;
	_xAxis = 0;
    _yAxis = 0;
    _buttons = 0;
}

void Joystick_::begin(bool initAutoSendState)
{
    autoSendState = initAutoSendState;
    sendState();
}

void Joystick_::end()
{
}

void Joystick_::setButton(uint8_t button, uint8_t value)
{
    if (value == 0)
    {
        releaseButton(button);
    }
    else
    {
        pressButton(button);
    }
}
void Joystick_::pressButton(uint8_t button)
{
    bitSet(_buttons, button);
    if (autoSendState) sendState();
}
void Joystick_::releaseButton(uint8_t button)
{
    bitClear(_buttons, button);
    if (autoSendState) sendState();
}

void Joystick_::setXAxis(int8_t value)
{
    _xAxis = value;
    if (autoSendState) sendState();
}
void Joystick_::setYAxis(int8_t value)
{
    _yAxis = value;
    if (autoSendState) sendState();
}

void Joystick_::sendState()
{
    int8_t data[JOYSTICK_STATE_SIZE];
    uint16_t buttonTmp = _buttons;

    // Split 16 bit button-state into 2 bytes
    data[0] = buttonTmp & 0xFF;        
    buttonTmp >>= 8;
    data[1] = buttonTmp & 0xFF;

    data[2] = _yAxis;
    data[3] = _yAxis;

    // HID().SendReport(Report number, array of values in same order as HID descriptor, length)
    HID().SendReport(JOYSTICK_REPORT_ID + joystickId, data, JOYSTICK_STATE_SIZE);
}

void Joystick_::reset()
{
	//reset button state..
	_buttons = 0x0;

	//reset x & y axis
	_xAxis = 0x7f;
	_yAxis = 0x7f;
}

void Joystick_::up()
{
	_yAxis = 0x0;
}

void Joystick_::right()
{
	_xAxis = 0xff;
}

void Joystick_::down()
{
	_yAxis = 0xff;
}

void Joystick_::left()
{
	_xAxis = 0x00;
}

void Joystick_::button_press(uint16_t b)
{
	_buttons = _buttons | b;
}

void Joystick_::usb_update()
{
	// only send usb data if needed..
	uint8_t m[5];
	m[0] = _xAxis;
	m[1] = _yAxis;
	m[2] = _buttons & 0xff;
	m[3] = _buttons >> 8;
	m[4] = 0x0;

	HID().SendReport(JOYSTICK_REPORT_ID + joystickId, m, sizeof(m));
}

Joystick_ Joystick[2] =
{
	Joystick_(0),
	Joystick_(1)
};
extern Joystick_ Joystick[2];
#endif
