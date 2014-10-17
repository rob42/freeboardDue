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
 * SignalkHelper.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: robert
 */

#include "SignalkHelper.h"

const char * SignalkHelper::j_vessels = "vessels";
const char * SignalkHelper::j_self = "self";
const char * SignalkHelper::j_arduino = "_arduino";
const char * SignalkHelper::j_airPressure = "airPressure";
const char * SignalkHelper::j_airPressureChangeRateAlarm = "airPressureChangeRateAlarm";
const char * SignalkHelper::j_airTemp = "airTemp";
const char * SignalkHelper::j_alarm = "alarm";
const char * SignalkHelper::j_alarmHeadingXte = "alarmHeadingXte";
const char * SignalkHelper::j_alarmRadius = "alarmRadius";
const char * SignalkHelper::j_alarms = "alarms";
const char * SignalkHelper::j_altitude = "altitude";
const char * SignalkHelper::j_anchor = "anchor";
const char * SignalkHelper::j_anchorAlarmMethod = "anchorAlarmMethod";
const char * SignalkHelper::j_anchorAlarmState = "anchorAlarmState";
const char * SignalkHelper::j_autopilot = "autopilot";
const char * SignalkHelper::j_autopilotAlarmMethod = "autopilotAlarmMethod";
const char * SignalkHelper::j_autopilotAlarmState = "autopilotAlarmState";
const char * SignalkHelper::j_average = "average";
const char * SignalkHelper::j_backlash = "backlash";
const char * SignalkHelper::j_baud0 = "baud0";
const char * SignalkHelper::j_baud1 = "baud1";
const char * SignalkHelper::j_baud2 = "baud2";
const char * SignalkHelper::j_baud3 = "baud3";
const char * SignalkHelper::j_baud4 = "baud4";
const char * SignalkHelper::j_baud5 = "baud5";
const char * SignalkHelper::j_baudRate = "baudRate";
const char * SignalkHelper::j_bearingActual = "bearingActual";
const char * SignalkHelper::j_bearingDirect = "bearingDirect";
const char * SignalkHelper::j_belowKeel = "belowKeel";
const char * SignalkHelper::j_belowSurface = "belowSurface";
const char * SignalkHelper::j_belowTransducer = "belowTransducer";
const char * SignalkHelper::j_status = "status";
const char * SignalkHelper::j_courseOverGroundMagnetic = "courseOverGroundMagnetic";
const char * SignalkHelper::j_courseOverGroundTrue = "courseOverGroundTrue";
const char * SignalkHelper::j_courseRequired = "courseRequired";
const char * SignalkHelper::j_currentDirection = "currentDirection";
const char * SignalkHelper::j_currentRadius = "currentRadius";
const char * SignalkHelper::j_currentRoute = "currentRoute";
const char * SignalkHelper::j_currentSpeed = "currentSpeed";
const char * SignalkHelper::j_deadZone = "deadZone";
const char * SignalkHelper::j_decode = "decode";
const char * SignalkHelper::j_depth = "depth";
const char * SignalkHelper::j_destination = "destination";
const char * SignalkHelper::j_directionApparent = "directionApparent";
const char * SignalkHelper::j_directionChangeAlarm = "directionChangeAlarm";
const char * SignalkHelper::j_directionTrue = "directionTrue";
const char * SignalkHelper::j_drift = "drift";
const char * SignalkHelper::j_east = "east";
const char * SignalkHelper::j_engineAlarmMethod = "engineAlarmMethod";
const char * SignalkHelper::j_engineAlarmState = "engineAlarmState";
const char * SignalkHelper::j_environment = "environment";
const char * SignalkHelper::j_eta = "eta";
const char * SignalkHelper::j_factor = "factor";
const char * SignalkHelper::j_fireAlarmMethod = "fireAlarmMethod";
const char * SignalkHelper::j_fireAlarmState = "fireAlarmState";
const char * SignalkHelper::j_gain = "gain";
const char * SignalkHelper::j_gasAlarmMethod = "gasAlarmMethod";
const char * SignalkHelper::j_gasAlarmState = "gasAlarmState";
const char * SignalkHelper::j_genericAlarmMethod = "genericAlarmMethod";
const char * SignalkHelper::j_genericAlarmState = "genericAlarmState";
const char * SignalkHelper::j_gps = "gps";
const char * SignalkHelper::j_gpsAlarmMethod = "gpsAlarmMethod";
const char * SignalkHelper::j_gpsAlarmState = "gpsAlarmState";
const char * SignalkHelper::j_headingMagnetic = "headingMagnetic";
const char * SignalkHelper::j_headingSource = "headingSource";
const char * SignalkHelper::j_headingTrue = "headingTrue";
const char * SignalkHelper::j_heightHigh = "heightHigh";
const char * SignalkHelper::j_heightLow = "heightLow";
const char * SignalkHelper::j_heightNow = "heightNow";
const char * SignalkHelper::j_humidity = "humidity";
const char * SignalkHelper::j_last = "last";
const char * SignalkHelper::j_lastFix = "lastFix";
const char * SignalkHelper::j_lastTime = "lastTime";
const char * SignalkHelper::j_lastUpdate = "lastUpdate";
const char * SignalkHelper::j_latitude = "latitude";
const char * SignalkHelper::j_level1 = "level1";
const char * SignalkHelper::j_level2 = "level2";
const char * SignalkHelper::j_level3 = "level3";
const char * SignalkHelper::j_upper = "upper";
const char * SignalkHelper::j_lower = "lower";
const char * SignalkHelper::j_longitude = "longitude";
const char * SignalkHelper::j_magneticVariation = "magneticVariation";
const char * SignalkHelper::j_max = "max";
const char * SignalkHelper::j_maxDriveAmps = "maxDriveAmps";
const char * SignalkHelper::j_maxDriveRate = "maxDriveRate";
const char * SignalkHelper::j_maxRadius = "maxRadius";
const char * SignalkHelper::j_maydayAlarmMethod = "maydayAlarmMethod";
const char * SignalkHelper::j_maydayAlarmState = "maydayAlarmState";
const char * SignalkHelper::j_mobAlarmMethod = "mobAlarmMethod";
const char * SignalkHelper::j_mobAlarmState = "mobAlarmState";
const char * SignalkHelper::j_mode = "mode";
const char * SignalkHelper::j_model = "model";
const char * SignalkHelper::j_navigation = "navigation";
const char * SignalkHelper::j_next = "next";
const char * SignalkHelper::j_nextEta = "nextEta";
const char * SignalkHelper::j_north = "north";
const char * SignalkHelper::j_offcourse = "offcourse";
const char * SignalkHelper::j_panpanAlarmMethod = "panpanAlarmMethod";
const char * SignalkHelper::j_panpanAlarmState = "panpanAlarmState";
const char * SignalkHelper::j_pitch = "pitch";
const char * SignalkHelper::j_portLock = "portLock";
const char * SignalkHelper::j_position = "position";
const char * SignalkHelper::j_powerAlarmMethod = "powerAlarmMethod";
const char * SignalkHelper::j_powerAlarmState = "powerAlarmState";
const char * SignalkHelper::j_radarAlarmMethod = "radarAlarmMethod";
const char * SignalkHelper::j_radarAlarmState = "radarAlarmState";
const char * SignalkHelper::j_radiusDeg = "radiusDeg";
const char * SignalkHelper::j_rateOfTurn = "rateOfTurn";
const char * SignalkHelper::j_roll = "roll";
const char * SignalkHelper::j_route = "route";
const char * SignalkHelper::j_rudderAngle = "rudderAngle";
const char * SignalkHelper::j_rudderAngleTarget = "rudderAngleTarget";
const char * SignalkHelper::j_rudderCommand = "rudderCommand";
const char * SignalkHelper::j_salinity = "salinity";
const char * SignalkHelper::j_seatalk = "seatalk";
const char * SignalkHelper::j_serial = "serial";
const char * SignalkHelper::j_set = "set";
const char * SignalkHelper::j_silentInterval = "silentInterval";
const char * SignalkHelper::j_snooze = "snooze";
const char * SignalkHelper::j_south = "south";
const char * SignalkHelper::j_speedAlarm = "speedAlarm";
const char * SignalkHelper::j_speedApparent = "speedApparent";
const char * SignalkHelper::j_speedOverGround = "speedOverGround";
const char * SignalkHelper::j_speedThroughWater = "speedThroughWater";
const char * SignalkHelper::j_speedTrue = "speedTrue";
const char * SignalkHelper::j_starboardLock = "starboardLock";
const char * SignalkHelper::j_startTime = "startTime";
const char * SignalkHelper::j_state = "state";
const char * SignalkHelper::j_steering = "steering";
const char * SignalkHelper::j_surfaceToTransducer = "surfaceToTransducer";
const char * SignalkHelper::j_targetHeadingMagnetic = "targetHeadingMagnetic";
const char * SignalkHelper::j_targetHeadingNorth = "targetHeadingNorth";
const char * SignalkHelper::j_tide = "tide";
const char * SignalkHelper::j_timeHigh = "timeHigh";
const char * SignalkHelper::j_timeLow = "timeLow";
const char * SignalkHelper::j_transducerToKeel = "transducerToKeel";
const char * SignalkHelper::j_utc = "utc";
const char * SignalkHelper::j_waterTemp = "waterTemp";
const char * SignalkHelper::j_waypoint = "waypoint";
const char * SignalkHelper::j_west = "west";
const char * SignalkHelper::j_wind = "wind";
const char * SignalkHelper::j_windAlarmMethod = "windAlarmMethod";
const char * SignalkHelper::j_windAlarmState = "windAlarmState";
const char * SignalkHelper::j_xte = "xte";
const char * SignalkHelper::j_zeroOffset = "zeroOffset";


SignalkHelper::SignalkHelper() {

}

int SignalkHelper::findInArray(const char *array[], const char* value) {

	for (unsigned int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
		if ((strcmp(array[i], value) == 0)) {
			return i;
		}
	}
	return -1;
}
unsigned long SignalkHelper::hash(const char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

void SignalkHelper::openMessage(HardwareSerial* serial){
	serial->print("{");
}
void SignalkHelper::closeMessage(HardwareSerial* serial){
	serial->println("}");
}
void SignalkHelper::openBranch(HardwareSerial* serial, const char* key){
	serial->print("\"");
	serial->print(key);
	serial->print("\":{");
}
void SignalkHelper::closeBranch(HardwareSerial* serial, bool last){
	serial->print("}");
	if(!last)serial->print(",");
}

void SignalkHelper::printValue(HardwareSerial* serial, const char* key, const float value, bool last){
	serial->print("\"");
	serial->print(key);
	serial->print("\": {\"value\":");
	if( value!=value){
		serial->print("null");
	}else{
		serial->print(value,DEC);
	}
	serial->print("}");
	if(!last)serial->print(",");
}
void SignalkHelper::printValue(HardwareSerial* serial, const char* key, const unsigned long value, bool last){
	serial->print("\"");
	serial->print(key);serial->print("\": {\"value\":");
	if(value==SIZE_MAX){
			serial->print("null");
		}else{
			serial->print(value,DEC);
		}
	serial->print("}");
	if(!last)serial->print(",");
}

void SignalkHelper::printValue(HardwareSerial* serial, const char* key, const int value, bool last){
	serial->print("\"");
	serial->print(key);
	serial->print("\": {\"value\":");
	if(value==SIZE_MAX){
			serial->print("null");
		}else{
			serial->print(value,DEC);
		}
	serial->print("}");
	if(!last)serial->print(",");
}
void SignalkHelper::printValue(HardwareSerial* serial, const char* key, const long value, bool last){
	serial->print("\"");
	serial->print(key);
	serial->print("\": {\"value\":");
	if(value==SIZE_MAX){
			serial->print("null");
		}else{
			serial->print(value,DEC);
		}
	serial->print("}");
	if(!last)serial->print(",");
}
void SignalkHelper::printValue(HardwareSerial* serial, const char* key, const bool value, bool last){
	serial->print("\"");
	serial->print(key);
	serial->print("\": {");
		serial->print("\"value\":");
	if(value){
			serial->print("true");
	}else{
		serial->print("false");
	}
	serial->print("}");
	if(!last)serial->print(",");
}
void SignalkHelper::printValue(HardwareSerial* serial, const char* key,  const char* value, bool last){
	serial->print("\"");
	serial->print(key);
	serial->print("\": {\"value\":\"");
	serial->print(value);
	serial->print("\"}");
	if(!last)serial->print(",");
}
void SignalkHelper::printValue(HardwareSerial* serial, const char* key,  const char value, bool last){
	serial->print("\"");
	serial->print(key);
	serial->print("\": {\"value\":\"");
	serial->print(value);
	serial->print("\"}");
	if(!last)serial->print(",");
}



byte SignalkHelper::getChecksum(char* str) {
		byte cs = 0; //clear any old checksum
		for (unsigned int n = 1; n < strlen(str) - 1; n++) {
			cs ^= str[n]; //calculates the checksum
		}
		return cs;
	}

int SignalkHelper::getNumericType(unsigned long key){
	switch (key) {
		case NAVIGATION_DESTINATION_ETA: return TYPE_UNSIGNED_LONG;break;
		case STEERING_AUTOPILOT_GAIN: return TYPE_INT;break;
		case _ARDUINO_GPS_MODEL: return TYPE_INT;break;
		case _ARDUINO_GPS_LASTFIX: return TYPE_UNSIGNED_LONG;break;
		case _ARDUINO_GPS_UTC: return TYPE_UNSIGNED_LONG;break;
		case _ARDUINO_GPS_DECODE: return TYPE_BOOL;break;
		case _ARDUINO_AUTOPILOT_BAUDRATE: return TYPE_UNSIGNED_LONG;break;
		case _ARDUINO_AUTOPILOT_OFFCOURSE: return TYPE_DOUBLE;break;
		case _ARDUINO_AUTOPILOT_RUDDERCOMMAND: return TYPE_DOUBLE;break;
		case _ARDUINO_ALARM_LAST: return TYPE_UNSIGNED_LONG;break;
		case _ARDUINO_ALARM_SNOOZE: return TYPE_UNSIGNED_LONG;break;
		case ALARMS_SILENTINTERVAL: return TYPE_INT;break;
		case _ARDUINO_GPS_STATUS: return TYPE_CHAR;break;
		//all char array, which we know anyway, or float
		default: return TYPE_FLOAT;

	/* - all char array, which we know, or float
	 * case ALARMS_ANCHORALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_ANCHORALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_AUTOPILOTALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_AUTOPILOTALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_ENGINEALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_ENGINEALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_FIREALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_FIREALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_GASALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_GASALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_GPSALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_GPSALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_MAYDAYALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_MAYDAYALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_PANPANALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_PANPANALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_POWERALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_POWERALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_WINDALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_WINDALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_GENERICALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_GENERICALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_RADARALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_RADARALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case ALARMS_MOBALARMMETHOD: return TYPE_CHAR_ARRAY;break;
		case ALARMS_MOBALARMSTATE: return TYPE_CHAR_ARRAY;break;
		case NAVIGATION_STATE: return TYPE_CHAR_ARRAY;break;
		case STEERING_AUTOPILOT_STATE: return TYPE_CHAR_ARRAY;break;
		case STEERING_AUTOPILOT_MODE: return TYPE_CHAR_ARRAY;break;
		case STEERING_AUTOPILOT_HEADINGSOURCE: return TYPE_CHAR_ARRAY;break;

	 * these are now all float so = 0
		case NAVIGATION_COURSEOVERGROUNDMAGNETIC:return TYPE_FLOAT;break;
		case NAVIGATION_COURSEOVERGROUNDTRUE: return TYPE_FLOAT;break;
		case NAVIGATION_MAGNETICVARIATION: return TYPE_FLOAT;break;
		case NAVIGATION_DESTINATION_LONGITUDE: return TYPE_FLOAT;break;
		case NAVIGATION_DESTINATION_LATITUDE: return TYPE_FLOAT;break;

		case NAVIGATION_HEADINGMAGNETIC: return TYPE_FLOAT;break;
		case NAVIGATION_HEADINGTRUE: return TYPE_FLOAT;break;
		case NAVIGATION_POSITION_LONGITUDE: return TYPE_FLOAT;break;
		case NAVIGATION_POSITION_LATITUDE: return TYPE_FLOAT;break;
		case NAVIGATION_POSITION_ALTITUDE: return TYPE_FLOAT;break;
		case NAVIGATION_PITCH: return TYPE_FLOAT;break;
		case NAVIGATION_RATEOFTURN: return TYPE_FLOAT;break;
		case NAVIGATION_ROLL: return TYPE_FLOAT;break;
		case NAVIGATION_SPEEDOVERGROUND: return TYPE_FLOAT;break;
		case NAVIGATION_SPEEDTHROUGHWATER: return TYPE_FLOAT;break;

		case NAVIGATION_ANCHOR_ALARMRADIUS: return TYPE_FLOAT;break;
		case NAVIGATION_ANCHOR_MAXRADIUS: return TYPE_FLOAT;break;
		case NAVIGATION_ANCHOR_CURRENTRADIUS: return TYPE_FLOAT;break;
		case NAVIGATION_ANCHOR_POSITION_ALTITUDE: return TYPE_FLOAT;break;
		case NAVIGATION_ANCHOR_POSITION_LATITUDE: return TYPE_FLOAT;break;
		case NAVIGATION_ANCHOR_POSITION_LONGITUDE: return TYPE_FLOAT;break;


		case STEERING_AUTOPILOT_TARGETHEADINGNORTH: return TYPE_FLOAT;break;
		case STEERING_AUTOPILOT_TARGETHEADINGMAGNETIC: return TYPE_FLOAT;break;
		case STEERING_AUTOPILOT_ALARMHEADINGXTE: return TYPE_FLOAT;break;

		case STEERING_AUTOPILOT_DEADZONE: return TYPE_FLOAT;break;
		case STEERING_AUTOPILOT_BACKLASH: return TYPE_FLOAT;break;

		case STEERING_AUTOPILOT_MAXDRIVEAMPS: return TYPE_FLOAT;break;
		case STEERING_AUTOPILOT_MAXDRIVERATE: return TYPE_FLOAT;break;
		case STEERING_AUTOPILOT_PORTLOCK: return TYPE_FLOAT;break;
		case STEERING_AUTOPILOT_STARBOARDLOCK: return TYPE_FLOAT;break;
		case STEERING_RUDDERANGLE: return TYPE_FLOAT;break;
		case STEERING_RUDDERANGLETARGET: return TYPE_FLOAT;break;



		case ENVIRONMENT_WIND_DIRECTIONAPPARENT: return TYPE_FLOAT;break;
		case ENVIRONMENT_WIND_DIRECTIONCHANGEALARM: return TYPE_FLOAT;break;
		case ENVIRONMENT_WIND_DIRECTIONTRUE: return TYPE_FLOAT;break;
		case ENVIRONMENT_WIND_SPEEDALARM: return TYPE_FLOAT;break;
		case ENVIRONMENT_WIND_SPEEDTRUE: return TYPE_FLOAT;break;
		case ENVIRONMENT_WIND_SPEEDAPPARENT: return TYPE_FLOAT;break;
		case ENVIRONMENT_AIRPRESSURECHANGERATEALARM: return TYPE_FLOAT;break;
		case ENVIRONMENT_AIRPRESSURE: return TYPE_FLOAT;break;
		case ENVIRONMENT_WATERTEMP: return TYPE_FLOAT;break;


		case _ARDUINO_SERIAL_BAUD0: return TYPE_FLOAT;break;
		case _ARDUINO_SERIAL_BAUD1: return TYPE_FLOAT;break;
		case _ARDUINO_SERIAL_BAUD2: return TYPE_FLOAT;break;
		case _ARDUINO_SERIAL_BAUD3: return TYPE_FLOAT;break;
		case _ARDUINO_SERIAL_BAUD4: return TYPE_FLOAT;break;
		case _ARDUINO_SERIAL_BAUD5: return TYPE_FLOAT;break;
		case _ARDUINO_ALARM_LEVEL1_UPPER: return TYPE_FLOAT;break;
		case _ARDUINO_ALARM_LEVEL1_LOWER: return TYPE_FLOAT;break;
		case _ARDUINO_ALARM_LEVEL2_UPPER: return TYPE_FLOAT;break;
		case _ARDUINO_ALARM_LEVEL2_LOWER: return TYPE_FLOAT;break;
		case _ARDUINO_ALARM_LEVEL3_UPPER: return TYPE_FLOAT;break;
		case _ARDUINO_ALARM_LEVEL3_LOWER: return TYPE_FLOAT;break;
		case _ARDUINO_SEATALK: return TYPE_FLOAT;break;
		case _ARDUINO_WIND_ZEROOFFSET: return TYPE_FLOAT;break;
		case _ARDUINO_WIND_LASTUPDATE: return TYPE_FLOAT;break;

		case _ARDUINO_WIND_AVERAGE: return TYPE_FLOAT;break;
		case _ARDUINO_WIND_FACTOR: return TYPE_FLOAT;break;
		case _ARDUINO_WIND_MAX: return TYPE_FLOAT;break;

		case _ARDUINO_ANCHOR_RADIUSDEG: return TYPE_FLOAT;break;
		case _ARDUINO_ANCHOR_NORTH: return TYPE_FLOAT;break;
		case _ARDUINO_ANCHOR_SOUTH: return TYPE_FLOAT;break;
		case _ARDUINO_ANCHOR_EAST: return TYPE_FLOAT;break;
		case _ARDUINO_ANCHOR_WEST: return TYPE_FLOAT;break;
		*/
	}
return TYPE_FLOAT;
}
