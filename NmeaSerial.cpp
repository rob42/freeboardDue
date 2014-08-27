/*
 * Copyright 2010,2011,2012,2013 Robert Huitema robert@42.co.nz
 *
 * This file is part of FreeBoard. (http://www.42.co.nz/freeboard)
 *
 *  FreeBoard is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  FreeBoard is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with FreeBoard.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 * NmeaSerial.cpp
 *
 *  Created on: 23/12/2010
 *      Author: robert
 */

#include "NmeaSerial.h"

NmeaSerial::~NmeaSerial() {

}
void NmeaSerial::begin(long speed) {
	//initialise the nmea output, always pin 46/48 for AltSoftSerial
	HardwareSerial::begin(speed);
}

void NmeaSerial::printNmea(char* sentence) {
	//sentence can be up to 80 chars
	//make it as perfect as possible, as the Raymarine C70 is very touchy
	// noInterrupts();
	println(sentence);
	// interrupts();
	//if(DEBUG)Serial.println(sentence);
}


/*
 * Heading, True.
 *
 *Actual vessel heading in degrees Ture produced by any device or system producing true heading.
 *
 *$--HDT,x.x,T
 *x.x = Heading, degrees True
 */
void NmeaSerial::printTrueHeading() {
	//Assemble a sentence of the various parts so that we can calculate the proper checksum
	// declination is positive when true N is west of MagN, eg subtract the declination
	if(model->getSignalkValueFloat(NAVIGATION_MAGNETICVARIATION)==0.0)return;

	PString str(trueHeadingSentence, sizeof(trueHeadingSentence));
	str.print("$HCHDT,");
	float trueHeading = model->getSignalkValueFloat(NAVIGATION_HEADINGMAGNETIC)-model->getSignalkValueFloat(NAVIGATION_MAGNETICVARIATION);
	str.print(trueHeading);
	str.print(",T*");
	//calculate the checksum

	cs = 0; //clear any old checksum
	for (unsigned int n = 1; n < strlen(trueHeadingSentence) - 1; n++) {
		cs ^= trueHeadingSentence[n]; //calculates the checksum
	}
	//bug - arduino prints 0x007 as 7, 0x02B as 2B, so we add it now
	if (cs < 0x10) str.print('0');
	str.print(cs, HEX); // Assemble the final message and send it out the serial port
	Serial.println(trueHeadingSentence);
	printNmea(trueHeadingSentence);

}
