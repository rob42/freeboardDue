
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
// Do not remove the include below
#include "freeboardDue.h"


volatile boolean execute = false;
volatile int interval = 0;
int inByteSerial1;
int inByteSerial2;
int inByteSerial3;
int inByteSerial4;
char input;


//freeboard model
SignalkModel signalkModel;


//NMEA output - The arduino puts out TTL, NMEA is RS232. They are different V and amps. The +-5V levels may need inverting or you get
// garbage.
// See http://forums.parallax.com/forums/default.aspx?f=19&m=50925
// See http://www.avrfreaks.net/index.php?name=PNphpBB2&file=printview&t=63469&start=0
//NmeaSerial nmea(&signalkModel);

//NMEA ports
NMEA gpsSource(ALL);
NMEARelay talker0(ALL);
NMEARelay talker2(ALL);
NMEARelay talker3(ALL);
NMEARelay talker4(ALL);

//alarm
Alarm alarm(&signalkModel);

//wind
Wind wind(&signalkModel);

//Gps
Gps gps(&gpsSource, &signalkModel);


MultiSerial mSerial1 = MultiSerial(CS_PIN,1); //NMEA4
//Autopilot

Autopilot autopilot( &signalkModel);

//Anchor
Anchor anchor(&signalkModel);

Seatalk seatalk(&Serial2, &signalkModel);

Levels levels(&signalkModel);

char inputSerialArray[200];
int inputSerialPos=0;

boolean inputSerial1Complete = false; // whether the GPS string is complete
boolean inputSerial2Complete = false; // whether the string is complete
boolean inputSerial3Complete = false; // whether the string is complete
boolean inputSerial4Complete = false; // whether the string is complete

//json support
//{"navigation":{ "position":{"longitude":173.5, "latitude":-43.5}}}
//static const char* queries[] = {
//					"_arduino.wind.zeroOffset",
//					};

StreamJsonReader jsonreader(&Serial, &signalkModel);

/*
 * Timer interrupt driven method to do time sensitive calculations
 * The calc flag causes the main loop to execute other less sensitive calls.
 */
void calculate() {
	//we create 100ms pings here
	execute = true;
	//we record the ping count out to 2 secs
	interval++;
	interval = interval % 20;
}


void readWDS() {
	wind.readWindDataSpeed();
}

void readWDD() {
	wind.readWindDataDir();
}
void setup()
{
// Add your initialization code here
	// initialize  serial ports:
		Serial.begin(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD0));
		if (DEBUG) Serial.println("Initializing..");

		//start gps on serial1, autobaud
		//if (DEBUG) Serial.println(F("Start gps.."));
		//gps.setupGps();
		if (DEBUG) {
			Serial.print("Start GPS Rx - serial1 at ");
			Serial.println(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD1));
		}

		Serial1.begin(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD1));

		if (signalkModel.getValueBool(_ARDUINO_SEATALK)) {
			if (DEBUG) Serial.println("Start seatalk - serial2 at 4800");
			//Serial2.begin(4800, SERIAL_9N1); //Seatalk interface
		} else {
			if (DEBUG) {
				Serial.print("Start nmea Rx - serial2 at ");
				Serial.println(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD2));
			}
			Serial2.begin(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD2), SERIAL_8N1);
		}

		if (DEBUG) {
			Serial.print("Start nmea Rx - serial3 at ");
			Serial.println(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD3));
		}
		Serial3.begin(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD3), SERIAL_8N1); //talker2

		if (DEBUG) Serial.println("Start SPI uarts..");
			delay(1000);
			pinMode(CS_PIN, OUTPUT);
			Serial.println("CS_PIN set to OUTPUT");
			delay(100);
			//Clear Chip Select
			digitalWrite(CS_PIN,HIGH);
			Serial.println("CS_PIN OUTPUT = HIGH");

		if (DEBUG) {
				Serial.print("Start nmea Rx - serial4 at ");
				Serial.println(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD4));
			}
		//mSerial1.begin(model.getSerialBaud4()); //talker3
		delay(100);
		if (DEBUG) Serial.println("Start nmea Tx..");
			pinMode(nmeaRxPin, INPUT);
			pinMode(nmeaTxPin, OUTPUT);
			if (DEBUG) {
				Serial.print("Start nmea Tx - on pins 46 Tx, 48 Rx at ");
				Serial.println(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD5));
			}
		//nmea.begin(signalkModel.getValueLong(_ARDUINO_SERIAL_BAUD5));

		autopilot.init();

		//setup interrupts to windPins
		if (DEBUG) Serial.println("Start wind..");
		pinMode(windSpeedPin, INPUT);
		//digitalWrite (windSpeedPin, HIGH) ;
		attachInterrupt(windSpeedInterrupt, readWDS, RISING);
		pinMode(windDirPin, INPUT);
		//digitalWrite (windDirPin, HIGH) ;
		attachInterrupt(windDirInterrupt, readWDD, RISING);

	//	//setup timers
		if (DEBUG) Serial.println("Start timer..");
		Timer.getAvailable().attachInterrupt(calculate).start(100000);


		if (DEBUG) Serial.println("Setup complete..");

		//execute hashing
		/*for(int x=0; x<1; x++){
			Serial.print(queries[x]);
			Serial.print("=");
			Serial.println(signalkModel.hash(queries[x]),DEC);
		}*/

		//test json print

		signalkModel.printVesselWrapper(&Serial);



		//TODO: setup lvl3 pin - actually its analogue
		pinMode(lvl3Pin, INPUT);
}



/*
 SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.

 See http://joost.damad.be/2012/01/arduino-mega-and-multiple-hardware.html
 */
void serialEvent() {
	while (Serial.available()) {
		// get the new byte:
		char inChar = (char) Serial.read();
		//try out the json reader here
		jsonreader.process_char(inChar);

	}

}

void serialEvent1() {
	while (Serial1.available()) {
		inputSerial1Complete = gps.decode(Serial1.read());
		// read from port 1 (GPS), send to port 0:
		if (inputSerial1Complete) {
			//if (MUX) nmea.printNmea(gpsSource.sentence());
			Serial.println(gpsSource.sentence());
			//loop every sentence
			break;
		}
	}
}

void serialEvent2() {
	while (Serial2.available()) {
		if (signalkModel.getValueBool(_ARDUINO_SEATALK)) {
			seatalk.processSeaTalkByte(Serial2.read());
		} else {
			inputSerial2Complete = talker2.decode(Serial2.read());
			if (inputSerial2Complete) {
				//if (MUX) nmea.printNmea(talker2.sentence());
				Serial.println(talker2.sentence());
				//loop every sentence
				break;
			}
		}
	}
}

void serialEvent3() {
	while (Serial3.available()) {
		byte b = Serial3.read();
		Serial.println(b);
		inputSerial3Complete = talker3.decode(b);
		if (inputSerial3Complete) {
			//if (MUX) nmea.printNmea(talker3.sentence());
			Serial.println(talker3.sentence());
			//loop every sentence
			break;
		}
	}
}

//must call manually every loop - 3+ not in core arduino code
void serialEvent4() {
	while (mSerial1.available()) {
		byte b = mSerial1.read();
		Serial.println(b);
		inputSerial4Complete = talker4.decode(b);
		if (inputSerial4Complete) {
			//if (MUX) nmea.printNmea(talker4.sentence());
			Serial.println(talker4.sentence());
			//loop every sentence
			break;
		}
	}
}
// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	if (execute) {
			//timer ping
			//do these every 100ms
			autopilot.calcAutoPilot();

			if (interval % 2 == 0) {
				//do every 200ms
				wind.calcWindSpeedAndDir();
			}
			if (interval % 50 == 0) {
				//do every 500ms
				wind.calcWindData();

				//signalkModel.writeSimple(Serial);
			}
			if (interval % 100 == 0) {
				//Serial.println(freeMemory());
				//do every 1000ms
				//Serial.println(wind.getWindNmea());
				//nmea.printNmea(wind.getWindNmea());
				//nmea.printTrueHeading();

				//do alarm stuff here
				anchor.checkAnchor();
				wind.checkWindAlarm();
				levels.checkLvlAlarms();
				alarm.checkAlarms();
				signalkModel.printVesselWrapper(&Serial);
			}

			execute = false;
		}
}


