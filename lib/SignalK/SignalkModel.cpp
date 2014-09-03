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
 * SignalkModel.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: robert
 */

#include "SignalkModel.h"



SignalkModel::SignalkModel() {

	navigation.courseOverGroundMagnetic = 93.0;
	navigation.courseOverGroundTrue = 0.0;
	navigation.currentRoute.bearingActual = 0.0;
	navigation.currentRoute.bearingDirect = 0.0;
	navigation.currentRoute.courseRequired = 0.0;
	navigation.currentRoute.eta = 0;
	navigation.currentRoute.route = "The current route";
	navigation.currentRoute.startTime = 0;
	navigation.currentRoute.waypoint.lastTime = 0;
	//navigation.currentRoute.waypoint.last = "";
	navigation.currentRoute.waypoint.nextEta = 0;
	//navigation.currentRoute.waypoint.next = "";
	navigation.currentRoute.waypoint.xte = 0.0;
	navigation.magneticVariation = 0.0;
	navigation.destination.eta = 0;
	navigation.destination.longitude = 0.0;
	navigation.destination.latitude = 0.0;
	navigation.destination.altitude = 0.0;
	navigation.drift = 0.0;
	//abc = {NAVIGATION_COURSEOVERGROUNDMAGNETIC,J_FLOAT,j_courseOverGroundMagnetic, navigation.currentRoute.route};
	//navigation.gnss
	navigation.headingMagnetic = 0.0;
	navigation.headingTrue = 0.0;
	navigation.position.longitude = 0.0;
	navigation.position.latitude = 0.0;
	navigation.position.altitude = 0.0;
	navigation.pitch = 0.0;
	navigation.rateOfTurn = 0.0;
	navigation.roll = 0.0;
	navigation.set = 0.0;
	navigation.speedOverGround = 0.0;
	navigation.speedThroughWater = 0.0;
	navigation.state = NAV_NOT_DEFINED;
	navigation.anchor.alarmRadius = 0.0;
	navigation.anchor.maxRadius = 0.0;
	navigation.anchor.currentRadius = 0.0;
	navigation.anchor.position.altitude = 0.0;
	navigation.anchor.position.latitude = 0.0;
	navigation.anchor.position.longitude = 0.0;
	steering.rudderAngle = 0.0;
	steering.rudderAngleTarget = 0.0;
	steering.autopilot.state = AP_OFF;
	steering.autopilot.mode = AP_NORMAL;
	steering.autopilot.targetHeadingNorth = 0.0;
	steering.autopilot.targetHeadingMagnetic = 0.0;
	steering.autopilot.alarmHeadingXte = 0.0;
	steering.autopilot.headingSource = AP_COMPASS;
	steering.autopilot.deadZone = 0.0;
	steering.autopilot.backlash = 0.0;
	steering.autopilot.gain = 0.0;
	steering.autopilot.maxDriveAmps = 0.0;
	steering.autopilot.maxDriveRate = 0.0;
	steering.autopilot.portLock = 0.0;
	steering.autopilot.starboardLock = 0.0;
	alarms.anchorAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.anchorAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.autopilotAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.autopilotAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.engineAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.engineAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.fireAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.fireAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.gasAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.gasAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.gpsAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.gpsAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.maydayAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.maydayAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.panpanAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.panpanAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.powerAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.powerAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.silentInterval = 300; //seconds?
	alarms.windAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.windAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.genericAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.genericAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.radarAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.radarAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	alarms.mobAlarmMethod = static_cast<AlarmMethodType>(ALRM_SOUND);
	alarms.mobAlarmState = static_cast<AlarmStateType>(ALRM_DISABLED);
	environment.airPressureChangeRateAlarm = 0.0;
	environment.airPressure = 1024.0;
	environment.airTemp = 0.0;
	environment.currentDirection = 0.0;
	environment.currentSpeed = 0.0;
	environment.depth.belowKeel = 0.0;
	environment.depth.belowTransducer = 0.0;
	environment.depth.belowSurface = 0.0;
	environment.depth.transducerToKeel = 0.0;
	environment.depth.surfaceToTransducer = 0.0;
	environment.humidity = 0.0;
	environment.salinity = 0.0;
	environment.tide.heightHigh = 0.0;
	environment.tide.heightNow = 0.0;
	environment.tide.heightLow = 0.0;
	environment.tide.timeLow = 0;
	environment.tide.timeHigh = 0;
	environment.waterTemp = 0;
	environment.wind.directionApparent = 0.0;
	environment.wind.directionChangeAlarm = 0.0;
	environment.wind.directionTrue = 0.0;
	environment.wind.speedAlarm = 0.0;
	environment.wind.speedTrue = 0.0;
	environment.wind.speedApparent = 0.0;
	environment.airPressureChangeRateAlarm = 0.0;
	environment.airPressure = 0.0;
	environment.waterTemp = 0.0;
	steering.rudderAngle = 0.0;
	steering.rudderAngleTarget = 0.0;
	steering.autopilot.state = static_cast<AutopilotStateType>(AP_OFF);
	steering.autopilot.mode = AutopilotModeType();
	steering.autopilot.targetHeadingNorth = 0.0;
	steering.autopilot.targetHeadingMagnetic = 0.0;
	steering.autopilot.alarmHeadingXte = 0.0;
	steering.autopilot.headingSource = static_cast<AutopilotHeadingSourceType>(AP_COMPASS);
	steering.autopilot.deadZone = 0.0;
	steering.autopilot.backlash = 0.0;
	steering.autopilot.gain = 0;
	steering.autopilot.maxDriveAmps = 0.0;
	steering.autopilot.maxDriveRate = 0.0;
	steering.autopilot.portLock = 0.0;
	steering.autopilot.starboardLock = 0.0;
	_arduino.gps.decode = false;
	_arduino.gps.model = 0;
	_arduino.gps.lastFix = 0UL;
	_arduino.gps.utc = 0UL;
	_arduino.gps.status = GPS_WARN;
	_arduino.serial.baud0 = 38400UL;
	_arduino.serial.baud1 = 38400UL;
	_arduino.serial.baud2 = 9600UL;
	_arduino.serial.baud3 = 9600UL;
	_arduino.serial.baud4 = 3840UL;
	_arduino.serial.baud5 = 4800UL;
	_arduino.alarm.level1.upper = 0;
	_arduino.alarm.level2.upper = 0;
	_arduino.alarm.level3.upper = 0;
	_arduino.alarm.level1.lower = 0;
	_arduino.alarm.level2.lower = 0;
	_arduino.alarm.level3.lower = 0;
	_arduino.alarm.snooze = 0UL;
	_arduino.alarm.last = 0UL;
	_arduino.anchor.radiusDeg = 0.0;
	_arduino.anchor.north = 0.0;
	_arduino.anchor.south = 0.0;
	_arduino.anchor.east = 0.0;
	_arduino.anchor.west = 0.0;
	_arduino.seatalk = false;
	_arduino.wind.lastUpdate = 0UL;
	_arduino.wind.average = 0.0;
	_arduino.wind.factor = 0.0;
	_arduino.wind.max = 0.0;
	_arduino.wind.zeroOffset = 0.0;
	_arduino.autopilot.baudRate = 0UL;
	_arduino.autopilot.offcourse = 0.0;
	_arduino.autopilot.rudderCommand = 0.0;
}

/* Add to setSignalk
navigation.destination.eta;
steering.rudderAngle;
steering.rudderAngleTarget;
steering.autopilot.portLock;
steering.autopilot.starboardLock;
environment.airPressureChangeRateAlarm;
environment.airPressure;
environment.waterTemp;
_arduino.wind.lastUpdate;
_arduino.autopilot.rudderCommand;
 */

void SignalkModel::setValue(char* attribute, bool value) {
	unsigned long key = hash(attribute);
	setValue(key, value);

}
void SignalkModel::setValue(unsigned long key, bool value) {
	switch (key) {

	case _ARDUINO_SEATALK:
		_arduino.seatalk = value;
		break;
	case _ARDUINO_GPS_DECODE:
		_arduino.gps.decode = value;
		break;
	default:
		break;

	}
}
void SignalkModel::setValue(char* attribute, char value) {
	unsigned long key = hash(attribute);
	setValue(key, value);
}

void SignalkModel::setValue(unsigned long key, char value) {

	switch (key) {

	case _ARDUINO_GPS_STATUS:
		_arduino.gps.status = value;
		break;
	}
}

void SignalkModel::setValue(unsigned long key, double value) {

	switch (key) {

	case _ARDUINO_AUTOPILOT_OFFCOURSE:
		_arduino.autopilot.offcourse = value;
		break;
	}
}

void SignalkModel::setValue(char* attribute, char* value) {
	unsigned long key = hash(attribute);
	setValue(key, value);
}

void SignalkModel::setValue(unsigned long key, char* value) {

	int c;
	switch (key) {

	case NAVIGATION_STATE:
		if ((c = findInArray(NavigationStateString, value)) > -1) {
			navigation.state = static_cast<NavigationStateType>(c);
		}
		break;
	case STEERING_AUTOPILOT_STATE:
		if ((c = findInArray(AutopilotStateString, value)) > -1) {
			steering.autopilot.state = static_cast<AutopilotStateType>(c);
		}
		break;
	case STEERING_AUTOPILOT_MODE:
		if ((c = findInArray(AutopilotModeString, value)) > -1) {
			steering.autopilot.mode = static_cast<AutopilotModeType>(c);
		}
		break;
	case STEERING_AUTOPILOT_HEADINGSOURCE:
		if ((c = findInArray(AutopilotHeadingSourceString, value)) > -1) {
			steering.autopilot.headingSource =
					static_cast<AutopilotHeadingSourceType>(c);
		}
		break;
	case ALARMS_ANCHORALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.anchorAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_ANCHORALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.anchorAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_AUTOPILOTALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.autopilotAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_AUTOPILOTALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.autopilotAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_ENGINEALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.engineAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_ENGINEALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.engineAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_FIREALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.fireAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_FIREALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.fireAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_GASALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.gasAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_GASALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.gasAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_GPSALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.gpsAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_GPSALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.gpsAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_MAYDAYALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.maydayAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_MAYDAYALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.maydayAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_PANPANALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.panpanAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_PANPANALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.panpanAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_POWERALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.powerAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_POWERALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.powerAlarmState = static_cast<AlarmStateType>(c);
		}
		break;

	case ALARMS_WINDALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.windAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_WINDALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.windAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_GENERICALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.genericAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_GENERICALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.genericAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_RADARALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.radarAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_RADARALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.radarAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	case ALARMS_MOBALARMMETHOD:
		if ((c = findInArray(AlarmMethodString, value)) > -1) {
			alarms.mobAlarmMethod = static_cast<AlarmMethodType>(c);
		}
		break;
	case ALARMS_MOBALARMSTATE:
		if ((c = findInArray(AlarmStateString, value)) > -1) {
			alarms.mobAlarmState = static_cast<AlarmStateType>(c);
		}
		break;
	default:
		break;

	}
}
void SignalkModel::setValue(char* attribute, int value) {
	setValue(hash(attribute), (int) value);
	//Serial.print(" setValue:");
	//Serial.println(key);
}
void SignalkModel::setValue(unsigned long key, int value) {

	switch (key) {
	case _ARDUINO_GPS_MODEL:
		_arduino.gps.model = (int) value;
		break;
	case STEERING_AUTOPILOT_GAIN:
		steering.autopilot.gain = (int) value;
		break;
	case ALARMS_SILENTINTERVAL:
		alarms.silentInterval = (int) value;
		break;
	case _ARDUINO_ALARM_LEVEL1_UPPER:
		_arduino.alarm.level1.upper = (int) value;
		break;
	case _ARDUINO_ALARM_LEVEL1_LOWER:
		_arduino.alarm.level1.lower = (int) value;
		break;
	case _ARDUINO_ALARM_LEVEL2_UPPER:
		_arduino.alarm.level2.upper = (int) value;
		break;
	case _ARDUINO_ALARM_LEVEL2_LOWER:
		_arduino.alarm.level2.lower = (int) value;
		break;
	case _ARDUINO_ALARM_LEVEL3_UPPER:
		_arduino.alarm.level3.upper = (int) value;
		break;
	case _ARDUINO_ALARM_LEVEL3_LOWER:
		_arduino.alarm.level3.lower = (int) value;
		break;
	}
}

void SignalkModel::setValue(char* attribute, unsigned long value) {
	setValue(hash(attribute), (unsigned long) value);
	//Serial.print(" setValue:");
	//Serial.println(key);
}
void SignalkModel::setValue(unsigned long key, unsigned long value) {

	switch (key) {
	case _ARDUINO_SERIAL_BAUD0:
		_arduino.serial.baud0 = value;
		break;
	case _ARDUINO_SERIAL_BAUD1:
		_arduino.serial.baud1 = value;
		break;
	case _ARDUINO_SERIAL_BAUD2:
		_arduino.serial.baud2 = value;
		break;
	case _ARDUINO_SERIAL_BAUD3:
		_arduino.serial.baud3 = value;
		break;
	case _ARDUINO_SERIAL_BAUD4:
		_arduino.serial.baud4 = value;
		break;
	case _ARDUINO_SERIAL_BAUD5:
		_arduino.serial.baud5 = value;
		break;

	case _ARDUINO_AUTOPILOT_BAUDRATE:
		_arduino.autopilot.baudRate = value;
		break;
	case _ARDUINO_ALARM_SNOOZE:
		_arduino.alarm.snooze = value;
		break;
	case _ARDUINO_ALARM_LAST:
		_arduino.alarm.last = value;
		break;
	case _ARDUINO_GPS_LASTFIX:
		_arduino.gps.lastFix = value;
		break;
	case _ARDUINO_GPS_UTC:
		_arduino.gps.utc = value;
		break;
	default:
		setValue(key,(int)value);
		break;
	}
}

void SignalkModel::setValue(char* attribute, float value) {
	setValue(hash(attribute), value);
	//Serial.print(" setValue:");
	//Serial.println(key);
}
void SignalkModel::setValue(unsigned long key, float value) {

	switch (key) {
	case NAVIGATION_COURSEOVERGROUNDMAGNETIC:
		navigation.courseOverGroundMagnetic = value;
		break;
	case NAVIGATION_COURSEOVERGROUNDTRUE:
		navigation.courseOverGroundTrue = value;
		break;
	case NAVIGATION_MAGNETICVARIATION:
		navigation.magneticVariation = value;
		break;
	case NAVIGATION_DESTINATION_LONGITUDE:
		navigation.destination.longitude = value;
		break;
	case NAVIGATION_DESTINATION_LATITUDE:
		navigation.destination.latitude = value;
		break;
	case NAVIGATION_HEADINGMAGNETIC:
		navigation.headingMagnetic = value;
		break;
	case NAVIGATION_HEADINGTRUE:
		navigation.headingTrue = value;
		break;
	case NAVIGATION_POSITION_LONGITUDE:
		navigation.position.longitude = value;
		break;
	case NAVIGATION_POSITION_LATITUDE:
		navigation.position.latitude = value;
		break;
	case NAVIGATION_POSITION_ALTITUDE:
		navigation.position.altitude = value;
		break;
	case NAVIGATION_PITCH:
		navigation.pitch = value;
		break;
	case NAVIGATION_RATEOFTURN:
		navigation.rateOfTurn = value;
		break;
	case NAVIGATION_ROLL:
		navigation.roll = value;
		break;
	case NAVIGATION_SPEEDOVERGROUND:
		navigation.speedOverGround = value;
		break;
	case NAVIGATION_SPEEDTHROUGHWATER:
		navigation.speedThroughWater = value;
		break;
	case NAVIGATION_ANCHOR_ALARMRADIUS:
		navigation.anchor.alarmRadius = value;
		break;
	case NAVIGATION_ANCHOR_MAXRADIUS:
		navigation.anchor.maxRadius = value;
		break;
	case NAVIGATION_ANCHOR_CURRENTRADIUS:
		navigation.anchor.currentRadius = value;
		break;
	case NAVIGATION_ANCHOR_POSITION_ALTITUDE:
		navigation.anchor.position.altitude = value;
		break;
	case NAVIGATION_ANCHOR_POSITION_LATITUDE:
		navigation.anchor.position.latitude = value;
		break;
	case NAVIGATION_ANCHOR_POSITION_LONGITUDE:
		navigation.anchor.position.longitude = value;
		break;
	case STEERING_AUTOPILOT_TARGETHEADINGNORTH:
		steering.autopilot.targetHeadingNorth = value;
		break;
	case STEERING_AUTOPILOT_TARGETHEADINGMAGNETIC:
		steering.autopilot.targetHeadingMagnetic = value;
		break;
	case STEERING_AUTOPILOT_ALARMHEADINGXTE:
		steering.autopilot.alarmHeadingXte = value;
		break;

	case STEERING_AUTOPILOT_DEADZONE:
		steering.autopilot.deadZone = value;
		break;
	case STEERING_AUTOPILOT_BACKLASH:
		steering.autopilot.backlash = value;
		break;

	case STEERING_AUTOPILOT_MAXDRIVEAMPS:
		steering.autopilot.maxDriveAmps = value;
		break;
	case STEERING_AUTOPILOT_MAXDRIVERATE:
		steering.autopilot.maxDriveRate = value;
		break;

	case ENVIRONMENT_WIND_DIRECTIONAPPARENT:
		environment.wind.directionApparent = value;
		break;
	case ENVIRONMENT_WIND_DIRECTIONCHANGEALARM:
		environment.wind.directionChangeAlarm = value;
		break;
	case ENVIRONMENT_WIND_DIRECTIONTRUE:
		environment.wind.directionTrue = value;
		break;
	case ENVIRONMENT_WIND_SPEEDALARM:
		environment.wind.speedAlarm = value;
		break;
	case ENVIRONMENT_WIND_SPEEDTRUE:
		environment.wind.speedTrue = value;
		break;
	case ENVIRONMENT_WIND_SPEEDAPPARENT:
		environment.wind.speedApparent = value;
		break;
	case _ARDUINO_WIND_AVERAGE:
		_arduino.wind.average = value;
		break;
	case _ARDUINO_WIND_FACTOR:
		_arduino.wind.factor = value;
		break;
	case _ARDUINO_WIND_MAX:
		_arduino.wind.max = value;
		break;
	case _ARDUINO_ANCHOR_RADIUSDEG:
		_arduino.anchor.radiusDeg = value;
		break;

	case _ARDUINO_ANCHOR_NORTH:
		_arduino.anchor.north = value;
		break;
	case _ARDUINO_ANCHOR_SOUTH:
		_arduino.anchor.south = value;
		break;
	case _ARDUINO_ANCHOR_EAST:
		_arduino.anchor.east = value;
		break;
	case _ARDUINO_ANCHOR_WEST:
		_arduino.anchor.west = value;
		break;

	default:
		//try long
		setValue(key,(unsigned long)value);
		break;

	}

}

bool SignalkModel::getValueBool(unsigned long key) {
	switch (key) {
	case _ARDUINO_SEATALK:
			return true;
			break;
	}
	return false;
}
int SignalkModel::getValueInt(unsigned long key) {
	switch (key) {
	case _ARDUINO_GPS_MODEL:
		return _arduino.gps.model;
		break;
	case STEERING_AUTOPILOT_GAIN:
		return steering.autopilot.gain;
		break;
	case ALARMS_SILENTINTERVAL:
		return alarms.silentInterval;
		break;
	case _ARDUINO_ALARM_LEVEL1_UPPER:
		return _arduino.alarm.level1.upper;
		break;
	case _ARDUINO_ALARM_LEVEL1_LOWER:
		return _arduino.alarm.level1.lower;
		break;
	case _ARDUINO_ALARM_LEVEL2_UPPER:
		return _arduino.alarm.level2.upper;
		break;
	case _ARDUINO_ALARM_LEVEL2_LOWER:
		return _arduino.alarm.level2.lower;
		break;
	case _ARDUINO_ALARM_LEVEL3_UPPER:
		return _arduino.alarm.level3.upper;
		break;
	case _ARDUINO_ALARM_LEVEL3_LOWER:
		return _arduino.alarm.level3.lower;
		break;
	}
	return INT16_MAX;
}

unsigned long SignalkModel::getValueLong(unsigned long key) {
	switch (key) {
	case _ARDUINO_SERIAL_BAUD0:
		return _arduino.serial.baud0;
		break;
	case _ARDUINO_SERIAL_BAUD1:
		return _arduino.serial.baud1;
		break;
	case _ARDUINO_SERIAL_BAUD2:
		return _arduino.serial.baud2;
		break;
	case _ARDUINO_SERIAL_BAUD3:
		return _arduino.serial.baud3;
		break;
	case _ARDUINO_SERIAL_BAUD4:
		return _arduino.serial.baud4;
		break;
	case _ARDUINO_SERIAL_BAUD5:
		return _arduino.serial.baud5;
		break;
	case _ARDUINO_ALARM_SNOOZE:
		return _arduino.alarm.snooze;
		break;
	case _ARDUINO_ALARM_LAST:
		return _arduino.alarm.last;
		break;
	case _ARDUINO_GPS_LASTFIX:
		return _arduino.gps.lastFix;
		break;
	case _ARDUINO_GPS_UTC:
		return _arduino.gps.utc;
		break;
	}
	return SIZE_MAX;
}


double SignalkModel::getValueDouble(unsigned long key) {
	switch (key) {
	case _ARDUINO_AUTOPILOT_OFFCOURSE:
		return _arduino.autopilot.offcourse;
		break;
	case _ARDUINO_AUTOPILOT_RUDDERCOMMAND:
		return _arduino.autopilot.rudderCommand;
		break;
	}
	return SIZE_MAX;
}

float SignalkModel::getValueFloat(unsigned long key) {
	switch (key) {

	case NAVIGATION_COURSEOVERGROUNDMAGNETIC:
		return navigation.courseOverGroundMagnetic;
		break;
	case NAVIGATION_COURSEOVERGROUNDTRUE:
		return navigation.courseOverGroundTrue;
		break;
	case NAVIGATION_MAGNETICVARIATION:
		return navigation.magneticVariation;
		break;
	case NAVIGATION_DESTINATION_LONGITUDE:
		return navigation.destination.longitude;
		break;
	case NAVIGATION_DESTINATION_LATITUDE:
		return navigation.destination.latitude;
		break;
	case NAVIGATION_HEADINGMAGNETIC:
		return navigation.headingMagnetic;
		break;
	case NAVIGATION_HEADINGTRUE:
		return navigation.headingTrue;
		break;
	case NAVIGATION_POSITION_LONGITUDE:
		return navigation.position.longitude;
		break;
	case NAVIGATION_POSITION_LATITUDE:
		return navigation.position.latitude;
		break;
	case NAVIGATION_POSITION_ALTITUDE:
		return navigation.position.altitude;
		break;
	case NAVIGATION_PITCH:
		return navigation.pitch;
		break;
	case NAVIGATION_RATEOFTURN:
		return navigation.rateOfTurn;
		break;
	case NAVIGATION_ROLL:
		return navigation.roll;
		break;
	case NAVIGATION_SPEEDOVERGROUND:
		return navigation.speedOverGround;
		break;
	case NAVIGATION_SPEEDTHROUGHWATER:
		return navigation.speedThroughWater;
		break;
	case NAVIGATION_ANCHOR_ALARMRADIUS:
		return navigation.anchor.alarmRadius;
		break;
	case NAVIGATION_ANCHOR_MAXRADIUS:
		return navigation.anchor.maxRadius;
		break;
	case NAVIGATION_ANCHOR_CURRENTRADIUS:
		return navigation.anchor.currentRadius;
		break;
	case NAVIGATION_ANCHOR_POSITION_ALTITUDE:
		return navigation.anchor.position.altitude;
		break;
	case NAVIGATION_ANCHOR_POSITION_LATITUDE:
		return navigation.anchor.position.latitude;
		break;
	case NAVIGATION_ANCHOR_POSITION_LONGITUDE:
		return navigation.anchor.position.longitude;
		break;
	case STEERING_AUTOPILOT_TARGETHEADINGNORTH:
		return steering.autopilot.targetHeadingNorth;
		break;
	case STEERING_AUTOPILOT_TARGETHEADINGMAGNETIC:
		return steering.autopilot.targetHeadingMagnetic;
		break;
	case STEERING_AUTOPILOT_ALARMHEADINGXTE:
		return steering.autopilot.alarmHeadingXte;
		break;

	case STEERING_AUTOPILOT_DEADZONE:
		return steering.autopilot.deadZone;
		break;
	case STEERING_AUTOPILOT_BACKLASH:
		return steering.autopilot.backlash;
		break;

	case STEERING_AUTOPILOT_MAXDRIVEAMPS:
		return steering.autopilot.maxDriveAmps;
		break;
	case STEERING_AUTOPILOT_MAXDRIVERATE:
		return steering.autopilot.maxDriveRate;
		break;

	case ENVIRONMENT_WIND_DIRECTIONAPPARENT:
		return environment.wind.directionApparent;
		break;
	case ENVIRONMENT_WIND_DIRECTIONCHANGEALARM:
		return environment.wind.directionChangeAlarm;
		break;
	case ENVIRONMENT_WIND_DIRECTIONTRUE:
		return environment.wind.directionTrue;
		break;
	case ENVIRONMENT_WIND_SPEEDALARM:
		return environment.wind.speedAlarm;
		break;
	case ENVIRONMENT_WIND_SPEEDTRUE:
		return environment.wind.speedTrue;
		break;
	case ENVIRONMENT_WIND_SPEEDAPPARENT:
		return environment.wind.speedApparent;
		break;
	case _ARDUINO_WIND_AVERAGE:
		return _arduino.wind.average;
		break;
	case _ARDUINO_WIND_FACTOR:
		return _arduino.wind.factor;
		break;
	case _ARDUINO_WIND_MAX:
		return _arduino.wind.max;
		break;
	case _ARDUINO_ANCHOR_RADIUSDEG:
		return _arduino.anchor.radiusDeg;
		break;

	case _ARDUINO_ANCHOR_NORTH:
		return _arduino.anchor.north;
		break;
	case _ARDUINO_ANCHOR_SOUTH:
		return _arduino.anchor.south;
		break;
	case _ARDUINO_ANCHOR_EAST:
		return _arduino.anchor.east;
		break;
	case _ARDUINO_ANCHOR_WEST:
		return _arduino.anchor.west;
		break;

	default:
		break;
	}
	return NAN;
}

char SignalkModel::getValueChar(unsigned long key) {

	switch (key) {
	case _ARDUINO_GPS_STATUS:
		return _arduino.gps.status;
		break;
	}
	return '0';
}

const char* SignalkModel::getValueCharArray(unsigned long key) {


		switch (key) {

		case NAVIGATION_STATE:
				return NavigationStateString[navigation.state];
			break;
		case STEERING_AUTOPILOT_STATE:
			return AutopilotStateString[steering.autopilot.state];
			break;
		case STEERING_AUTOPILOT_MODE:
			return AutopilotModeString[steering.autopilot.mode];
			break;
		case STEERING_AUTOPILOT_HEADINGSOURCE:
			return AutopilotHeadingSourceString[steering.autopilot.headingSource];
			break;
		case ALARMS_ANCHORALARMMETHOD:
			return AlarmMethodString[alarms.anchorAlarmMethod];
			break;
		case ALARMS_ANCHORALARMSTATE:
			return AlarmStateString[alarms.anchorAlarmState];
			break;
		case ALARMS_AUTOPILOTALARMMETHOD:
			return AlarmMethodString[alarms.autopilotAlarmMethod];
			break;
		case ALARMS_AUTOPILOTALARMSTATE:
			return AlarmStateString[alarms.autopilotAlarmState];
			break;
		case ALARMS_ENGINEALARMMETHOD:
			return AlarmMethodString[alarms.engineAlarmMethod];
			break;
		case ALARMS_ENGINEALARMSTATE:
			return AlarmStateString[alarms.engineAlarmState];
			break;
		case ALARMS_FIREALARMMETHOD:
			return AlarmMethodString[alarms.fireAlarmMethod];
			break;
		case ALARMS_FIREALARMSTATE:
			return AlarmStateString[alarms.fireAlarmState];
			break;
		case ALARMS_GASALARMMETHOD:
			return AlarmMethodString[alarms.gasAlarmMethod];
			break;
		case ALARMS_GASALARMSTATE:
			return AlarmStateString[alarms.gasAlarmState];
			break;
		case ALARMS_GPSALARMMETHOD:
			return AlarmMethodString[alarms.gpsAlarmMethod];
			break;
		case ALARMS_GPSALARMSTATE:
			return AlarmStateString[alarms.gpsAlarmState];
			break;
		case ALARMS_MAYDAYALARMMETHOD:
			return AlarmMethodString[alarms.maydayAlarmMethod];
			break;
		case ALARMS_MAYDAYALARMSTATE:
			return AlarmStateString[alarms.maydayAlarmState];
			break;
		case ALARMS_PANPANALARMMETHOD:
			return AlarmMethodString[alarms.panpanAlarmMethod];
			break;
		case ALARMS_PANPANALARMSTATE:
			return AlarmStateString[alarms.panpanAlarmState];
			break;
		case ALARMS_POWERALARMMETHOD:
			return AlarmMethodString[alarms.powerAlarmMethod];
			break;
		case ALARMS_POWERALARMSTATE:
			return AlarmStateString[alarms.powerAlarmState];
			break;

		case ALARMS_WINDALARMMETHOD:
			return AlarmMethodString[alarms.windAlarmMethod];
			break;
		case ALARMS_WINDALARMSTATE:
			return AlarmStateString[alarms.windAlarmState];
			break;
		case ALARMS_GENERICALARMMETHOD:
			return AlarmMethodString[alarms.genericAlarmMethod];
			break;
		case ALARMS_GENERICALARMSTATE:
			return AlarmStateString[alarms.genericAlarmState];
			break;
		case ALARMS_RADARALARMMETHOD:
			return AlarmMethodString[alarms.radarAlarmMethod];
			break;
		case ALARMS_RADARALARMSTATE:
			return AlarmStateString[alarms.radarAlarmState];
			break;
		case ALARMS_MOBALARMMETHOD:
			return AlarmMethodString[alarms.mobAlarmMethod];
			break;
		case ALARMS_MOBALARMSTATE:
			return AlarmStateString[alarms.mobAlarmState];
			break;
		default:
			break;

		}
		return "ERROR";
}

volatile bool SignalkModel::isAutopilotOn() {
	if (steering.autopilot.state == AP_OFF)
		return false;
	return true;
}
volatile bool SignalkModel::isAlarmTriggered() {
	if (alarms.windAlarmState > ALRM_ENABLED
			|| alarms.gpsAlarmState > ALRM_ENABLED
			|| alarms.gasAlarmState > ALRM_ENABLED
			|| alarms.anchorAlarmState > ALRM_ENABLED
			|| alarms.autopilotAlarmState > ALRM_ENABLED
			|| alarms.engineAlarmState > ALRM_ENABLED
			|| alarms.maydayAlarmState > ALRM_ENABLED
			|| alarms.panpanAlarmState > ALRM_ENABLED
			|| alarms.powerAlarmState > ALRM_ENABLED
			|| alarms.fireAlarmState > ALRM_ENABLED
			|| alarms.genericAlarmState > ALRM_ENABLED
			|| alarms.radarAlarmState > ALRM_ENABLED
			|| alarms.mobAlarmState > ALRM_ENABLED)
		return true;
	return false;

}

volatile bool SignalkModel::isAlarmTriggered(unsigned long key) {
	switch (key) {

	case ALARMS_ANCHORALARMSTATE:
		return (alarms.anchorAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_ENGINEALARMSTATE:
		return (alarms.engineAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_FIREALARMSTATE:
		return (alarms.fireAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_GASALARMSTATE:
		return (alarms.gasAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_GPSALARMSTATE:
		return (alarms.gpsAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_MAYDAYALARMSTATE:
		return (alarms.maydayAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_PANPANALARMSTATE:
		return (alarms.panpanAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_POWERALARMSTATE:
		return (alarms.powerAlarmState > ALRM_ENABLED);
		break;

	case ALARMS_WINDALARMSTATE:
		return (alarms.windAlarmState > ALRM_ENABLED);
		break;
	case ALARMS_GENERICALARMSTATE:
		return (alarms.genericAlarmState > ALRM_ENABLED);
		break;
	case ALARMS_RADARALARMSTATE:
		return (alarms.radarAlarmState > ALRM_ENABLED);
		break;
	case ALARMS_MOBALARMSTATE:
		return (alarms.mobAlarmState > ALRM_ENABLED);
		break;
	default:
		break;

	}
	return false;
}

volatile bool SignalkModel::isAlarmOn(unsigned long key) {
	switch (key) {

	case ALARMS_ANCHORALARMSTATE:
		return (alarms.anchorAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_ENGINEALARMSTATE:
		return (alarms.engineAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_FIREALARMSTATE:
		return (alarms.fireAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_GASALARMSTATE:
		return (alarms.gasAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_GPSALARMSTATE:
		return (alarms.gpsAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_MAYDAYALARMSTATE:
		return (alarms.maydayAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_PANPANALARMSTATE:
		return (alarms.panpanAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_POWERALARMSTATE:
		return (alarms.powerAlarmState > ALRM_DISABLED);
		break;

	case ALARMS_WINDALARMSTATE:
		return (alarms.windAlarmState > ALRM_DISABLED);
		break;
	case ALARMS_GENERICALARMSTATE:
		return (alarms.genericAlarmState > ALRM_DISABLED);
		break;
	case ALARMS_RADARALARMSTATE:
		return (alarms.radarAlarmState > ALRM_DISABLED);
		break;
	case ALARMS_MOBALARMSTATE:
		return (alarms.mobAlarmState > ALRM_DISABLED);
		break;
	default:
		break;

	}
	return false;
}

/* Add to get
navigation.state;
steering.rudderAngle;
steering.rudderAngleTarget;
steering.autopilot.state;
steering.autopilot.mode;
steering.autopilot.headingSource;
steering.autopilot.portLock;
steering.autopilot.starboardLock;
alarms.autopilotAlarmState;
alarms.autopilotAlarmMethod;
environment.airPressureChangeRateAlarm;
environment.airPressure;
environment.waterTemp;
_arduino.gps.decode;
_arduino.seatalk;
_arduino.wind.lastUpdate;
_arduino.wind.zeroOffset;
_arduino.autopilot.baudRate;
 *
 */

/*
	Output, with the trailing comma if last = false

	*/
void SignalkModel::printAlarmBranch(HardwareSerial* serial, bool last){
	openBranch(serial,SignalkHelper::j_alarm);
		printValue(serial, SignalkHelper::j_anchorAlarmMethod, getValueCharArray(ALARMS_ANCHORALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_anchorAlarmState, getValueCharArray(ALARMS_ANCHORALARMSTATE), false);
		printValue(serial, SignalkHelper::j_autopilotAlarmMethod, getValueCharArray(ALARMS_AUTOPILOTALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_autopilotAlarmState, getValueCharArray(ALARMS_AUTOPILOTALARMSTATE), false);
		printValue(serial, SignalkHelper::j_engineAlarmMethod, getValueCharArray(ALARMS_ENGINEALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_engineAlarmState, getValueCharArray(ALARMS_ENGINEALARMSTATE), false);
		printValue(serial, SignalkHelper::j_fireAlarmMethod, getValueCharArray(ALARMS_FIREALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_fireAlarmState, getValueCharArray(ALARMS_FIREALARMSTATE), false);
		printValue(serial, SignalkHelper::j_gasAlarmMethod, getValueCharArray(ALARMS_GASALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_gasAlarmState, getValueCharArray(ALARMS_GASALARMSTATE), false);
		printValue(serial, SignalkHelper::j_gpsAlarmMethod, getValueCharArray(ALARMS_GPSALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_gpsAlarmState, getValueCharArray(ALARMS_GPSALARMSTATE), false);
		printValue(serial, SignalkHelper::j_maydayAlarmMethod, getValueCharArray(ALARMS_MAYDAYALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_maydayAlarmState, getValueCharArray(ALARMS_MAYDAYALARMSTATE), false);
		printValue(serial, SignalkHelper::j_panpanAlarmMethod, getValueCharArray(ALARMS_PANPANALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_panpanAlarmState, getValueCharArray(ALARMS_PANPANALARMSTATE), false);
		printValue(serial, SignalkHelper::j_powerAlarmMethod, getValueCharArray(ALARMS_POWERALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_powerAlarmState, getValueCharArray(ALARMS_POWERALARMSTATE), false);
		printValue(serial, SignalkHelper::j_silentInterval, (long)getValueInt(ALARMS_SILENTINTERVAL), false);
		printValue(serial, SignalkHelper::j_windAlarmMethod, getValueCharArray(ALARMS_WINDALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_windAlarmState, getValueCharArray(ALARMS_WINDALARMSTATE), false);
		printValue(serial, SignalkHelper::j_genericAlarmMethod, getValueCharArray(ALARMS_GENERICALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_genericAlarmState, getValueCharArray(ALARMS_GENERICALARMSTATE), false);
		printValue(serial, SignalkHelper::j_radarAlarmMethod, getValueCharArray(ALARMS_RADARALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_radarAlarmState, getValueCharArray(ALARMS_RADARALARMSTATE), false);
		printValue(serial, SignalkHelper::j_mobAlarmMethod, getValueCharArray(ALARMS_MOBALARMMETHOD), false);
		printValue(serial, SignalkHelper::j_mobAlarmState, getValueCharArray(ALARMS_MOBALARMSTATE), true);
	closeBranch(&Serial, last);

}

/*
 Output, with the trailing comma if last = false
				float alarmRadius;
				float maxRadius;
				float currentRadius;

 */

void SignalkModel::printAnchorBranch(HardwareSerial* serial, bool last){
	openBranch(serial,SignalkHelper::j_anchor);
	printValue(serial, SignalkHelper::j_alarmRadius, getValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS), false);
	printValue(serial, SignalkHelper::j_maxRadius, getValueFloat(NAVIGATION_ANCHOR_MAXRADIUS), false);
		openBranch(serial,SignalkHelper::j_position);
			printValue(serial, SignalkHelper::j_latitude, getValueFloat(NAVIGATION_POSITION_LATITUDE), false);
			printValue(serial, SignalkHelper::j_longitude, getValueFloat(NAVIGATION_POSITION_LONGITUDE), false);
			printValue(serial, SignalkHelper::j_altitude, getValueFloat(NAVIGATION_POSITION_ALTITUDE), true);
		closeBranch(&Serial, true);
	closeBranch(&Serial, last);

}

/*
 Output, with the trailing comma if last = false:
"position": {
		"latitude": 0,
		"longitude": 0,
		"altitude": 0
	},
*/
void SignalkModel::printPositionBranch(HardwareSerial* serial, bool last){
	openBranch(serial,SignalkHelper::j_position);
		printValue(serial, SignalkHelper::j_latitude, getValueFloat(NAVIGATION_POSITION_LATITUDE), false);
		printValue(serial, SignalkHelper::j_longitude, getValueFloat(NAVIGATION_POSITION_LONGITUDE), false);
		printValue(serial, SignalkHelper::j_altitude, getValueFloat(NAVIGATION_POSITION_ALTITUDE), true);
	closeBranch(&Serial, last);

}

/*
	Output, with the trailing comma if last = false
	"wind": {
		   "speedAlarm": 0,
		   "directionChangeAlarm": 0,
		   "directionApparent": 0,
		   "directionTrue": 0,
		   "speedApparent": 0,
		   "speedTrue": 0
	   },
	*/
void SignalkModel::printAutopilotBranch(HardwareSerial* serial, bool last){
	openBranch(serial,SignalkHelper::j_autopilot);
		printValue(serial, SignalkHelper::j_state, getValueCharArray(STEERING_AUTOPILOT_STATE), false);
		printValue(serial, SignalkHelper::j_mode, getValueCharArray(STEERING_AUTOPILOT_MODE), false);
		printValue(serial, SignalkHelper::j_targetHeadingNorth, getValueFloat(STEERING_AUTOPILOT_TARGETHEADINGNORTH), false);
		printValue(serial, SignalkHelper::j_targetHeadingMagnetic, getValueFloat(STEERING_AUTOPILOT_TARGETHEADINGMAGNETIC), false);
		printValue(serial, SignalkHelper::j_alarmHeadingXte, getValueFloat(STEERING_AUTOPILOT_ALARMHEADINGXTE), false);
		printValue(serial, SignalkHelper::j_headingSource, getValueCharArray(STEERING_AUTOPILOT_HEADINGSOURCE), false);
		printValue(serial, SignalkHelper::j_deadZone, getValueFloat(STEERING_AUTOPILOT_DEADZONE), false);
		printValue(serial, SignalkHelper::j_backlash, getValueFloat(STEERING_AUTOPILOT_BACKLASH), false);
		printValue(serial, SignalkHelper::j_gain,(long) getValueInt(STEERING_AUTOPILOT_GAIN), false);
		printValue(serial, SignalkHelper::j_maxDriveAmps, getValueFloat(STEERING_AUTOPILOT_MAXDRIVEAMPS), false);
		printValue(serial, SignalkHelper::j_maxDriveRate, getValueFloat(STEERING_AUTOPILOT_MAXDRIVERATE), false);
		printValue(serial, SignalkHelper::j_portLock, getValueFloat(STEERING_AUTOPILOT_PORTLOCK), false);
		printValue(serial, SignalkHelper::j_starboardLock, getValueFloat(STEERING_AUTOPILOT_STARBOARDLOCK), true);
	closeBranch(&Serial, last);

}
/*
	Output, with the trailing comma if last = false
	"wind": {
		   "speedAlarm": 0,
		   "directionChangeAlarm": 0,
		   "directionApparent": 0,
		   "directionTrue": 0,
		   "speedApparent": 0,
		   "speedTrue": 0
	   },
	*/
void SignalkModel::printWindBranch(HardwareSerial* serial, bool last){
	openBranch(serial,SignalkHelper::j_wind);
		printValue(serial, SignalkHelper::j_speedAlarm, getValueFloat(ENVIRONMENT_WIND_SPEEDALARM), false);
		printValue(serial, SignalkHelper::j_directionChangeAlarm, getValueFloat(ENVIRONMENT_WIND_DIRECTIONCHANGEALARM), false);
		printValue(serial, SignalkHelper::j_directionApparent, getValueFloat(ENVIRONMENT_WIND_DIRECTIONAPPARENT), false);
		printValue(serial, SignalkHelper::j_directionTrue, getValueFloat(ENVIRONMENT_WIND_DIRECTIONAPPARENT), false);
		printValue(serial, SignalkHelper::j_speedApparent, getValueFloat(ENVIRONMENT_WIND_DIRECTIONAPPARENT), false);
		printValue(serial, SignalkHelper::j_speedTrue, getValueFloat(ENVIRONMENT_WIND_DIRECTIONAPPARENT), true);
	closeBranch(&Serial, last);

}
void SignalkModel::printConfigBranch(HardwareSerial* serial, bool last){

	openBranch(serial,SignalkHelper::j_arduino);
	openBranch(serial,SignalkHelper::j_gps);
	printValue(serial, SignalkHelper::j_decode, getValueBool(_ARDUINO_GPS_DECODE), false);
	printValue(serial, SignalkHelper::j_model, (long)getValueInt(_ARDUINO_GPS_MODEL), false);
				printValue(serial, SignalkHelper::j_lastFix, getValueLong(_ARDUINO_GPS_LASTFIX), false);
				printValue(serial, SignalkHelper::j_utc, getValueLong(_ARDUINO_GPS_UTC), false);
				printValue(serial, SignalkHelper::j_status, getValueChar(_ARDUINO_GPS_STATUS), true);
			closeBranch(&Serial, false);
			openBranch(serial,SignalkHelper::j_serial);
				printValue(serial, SignalkHelper::j_baud0, getValueLong(_ARDUINO_SERIAL_BAUD0), false);//console
				printValue(serial, SignalkHelper::j_baud1, getValueLong(_ARDUINO_SERIAL_BAUD1), false);//GPS
				printValue(serial, SignalkHelper::j_baud2, getValueLong(_ARDUINO_SERIAL_BAUD2), false);//NMEA1 or Seatalk
				printValue(serial, SignalkHelper::j_baud3, getValueLong(_ARDUINO_SERIAL_BAUD3), false);//NMEA2
				printValue(serial, SignalkHelper::j_baud4, getValueLong(_ARDUINO_SERIAL_BAUD4), false);//NMEA3 - SPI-2
				printValue(serial, SignalkHelper::j_baud5, getValueLong(_ARDUINO_SERIAL_BAUD5), true);//NMEA talker - AltSoftSerial
			closeBranch(&Serial, false);
			openBranch(serial,SignalkHelper::j_alarm);
				openBranch(serial, SignalkHelper::j_level1);
					printValue(serial, SignalkHelper::j_upper, getValueCharArray(_ARDUINO_ALARM_LEVEL1_UPPER), false);
					printValue(serial, SignalkHelper::j_lower, getValueCharArray(_ARDUINO_ALARM_LEVEL1_LOWER), true);
				closeBranch(&Serial, false);
				openBranch(serial, SignalkHelper::j_level2);
					printValue(serial, SignalkHelper::j_upper, getValueCharArray(_ARDUINO_ALARM_LEVEL2_UPPER), false);
					printValue(serial, SignalkHelper::j_lower, getValueCharArray(_ARDUINO_ALARM_LEVEL2_LOWER), true);
				closeBranch(&Serial, false);
				openBranch(serial, SignalkHelper::j_level3);
					printValue(serial, SignalkHelper::j_upper, getValueCharArray(_ARDUINO_ALARM_LEVEL3_UPPER), false);
					printValue(serial, SignalkHelper::j_lower, getValueCharArray(_ARDUINO_ALARM_LEVEL3_LOWER), true);
				closeBranch(&Serial, false);
				printValue(serial, SignalkHelper::j_snooze, getValueLong(_ARDUINO_ALARM_SNOOZE), false);
				printValue(serial, SignalkHelper::j_last, getValueLong(_ARDUINO_ALARM_LAST), true);
			closeBranch(&Serial, false);
			openBranch(serial,SignalkHelper::j_anchor);
				printValue(serial, SignalkHelper::j_radiusDeg, getValueFloat(_ARDUINO_ANCHOR_RADIUSDEG), false);
				printValue(serial, SignalkHelper::j_north, getValueFloat(_ARDUINO_ANCHOR_NORTH), false);
				printValue(serial, SignalkHelper::j_south, getValueFloat(_ARDUINO_ANCHOR_SOUTH), false);
				printValue(serial, SignalkHelper::j_east, getValueFloat(_ARDUINO_ANCHOR_EAST), false);
				printValue(serial, SignalkHelper::j_west, getValueFloat(_ARDUINO_ANCHOR_WEST), true);
			closeBranch(&Serial, false);
			printValue(serial, SignalkHelper::j_seatalk, getValueBool(_ARDUINO_SEATALK), false);
			openBranch(serial,SignalkHelper::j_wind);
				printValue(serial, SignalkHelper::j_lastUpdate, getValueFloat(_ARDUINO_WIND_LASTUPDATE), false);
				printValue(serial, SignalkHelper::j_average, getValueFloat(_ARDUINO_WIND_AVERAGE), false);
				printValue(serial, SignalkHelper::j_factor, getValueFloat(_ARDUINO_WIND_FACTOR), false);
				printValue(serial, SignalkHelper::j_max, getValueFloat(_ARDUINO_WIND_MAX), false);
				printValue(serial, SignalkHelper::j_zeroOffset, getValueFloat(_ARDUINO_WIND_ZEROOFFSET), true);
			closeBranch(&Serial, false);
				printValue(serial, SignalkHelper::j_baudRate, getValueLong(_ARDUINO_AUTOPILOT_BAUDRATE), false);//autopilot - SPI-1
				printValue(serial, SignalkHelper::j_offcourse, getValueFloat(_ARDUINO_AUTOPILOT_OFFCOURSE), false);
				printValue(serial, SignalkHelper::j_rudderCommand, getValueFloat(_ARDUINO_AUTOPILOT_RUDDERCOMMAND), true);
			closeBranch(&Serial, true);
	closeBranch(&Serial, last);

}

void SignalkModel::printVesselWrapper(HardwareSerial* serial){
	openMessage(&Serial);
		openBranch(&Serial,SignalkHelper::j_vessels);
			openBranch(&Serial,SignalkHelper::j_self);
				printNavigationBranch(serial, false);
				printAlarmBranch(serial, false);
				printSteeringBranch(serial,false);
				printEnvironmentBranch(serial,true);
			closeBranch(serial, true);
		closeBranch(serial, true);
	closeMessage(serial);

}
void SignalkModel::printNavigationBranch(HardwareSerial* serial, bool last){
	//navigation
	openBranch(&Serial,SignalkHelper::j_navigation);
		printValue(&Serial, SignalkHelper::j_courseOverGroundTrue, getValueFloat(NAVIGATION_COURSEOVERGROUNDTRUE), false);
		printValue(&Serial, SignalkHelper::j_courseOverGroundMagnetic, getValueFloat(NAVIGATION_COURSEOVERGROUNDMAGNETIC), false);
		printValue(&Serial, SignalkHelper::j_headingMagnetic, getValueFloat(NAVIGATION_HEADINGMAGNETIC), false);
		printValue(&Serial, SignalkHelper::j_magneticVariation, getValueFloat(NAVIGATION_MAGNETICVARIATION), false);
		//printValue(&Serial, SignalkHelper::j_drift, getValueFloat(NAVIGATION_DRIFT), false);
		printValue(&Serial, SignalkHelper::j_headingTrue, getValueFloat(NAVIGATION_HEADINGTRUE), false);
		printValue(&Serial, SignalkHelper::j_pitch, getValueFloat(NAVIGATION_PITCH), false);
		printValue(&Serial, SignalkHelper::j_rateOfTurn, getValueFloat(NAVIGATION_RATEOFTURN), false);
		printValue(&Serial, SignalkHelper::j_roll, getValueFloat(NAVIGATION_ROLL), false);
		//printValue(&Serial, SignalkHelper::j_set, getValueFloat(NAVIGATION_SET), false);
		printValue(&Serial, SignalkHelper::j_speedOverGround, getValueFloat(NAVIGATION_SPEEDOVERGROUND), false);
		printValue(&Serial, SignalkHelper::j_speedThroughWater, getValueFloat(NAVIGATION_SPEEDTHROUGHWATER), false);
		printValue(&Serial, SignalkHelper::j_state, getValueCharArray(NAVIGATION_STATE), false);
		//currentRoute ;
		//destination;
		//gnss
		printAnchorBranch(serial,false);
		//position
		printPositionBranch(&Serial,true);
	closeBranch(&Serial, last);
	//closed navigation
}
void SignalkModel::printEnvironmentBranch(HardwareSerial* serial, bool last){
	openBranch(&Serial,SignalkHelper::j_environment);
		printValue(&Serial, SignalkHelper::j_airPressureChangeRateAlarm, getValueFloat(ENVIRONMENT_AIRPRESSURECHANGERATEALARM), false);
		printValue(&Serial, SignalkHelper::j_airPressure, getValueFloat(ENVIRONMENT_AIRPRESSURE), false);
		//printValue(&Serial, SignalkHelper::j_airTemp, getValueFloat(ENVIRONMENT_AIRTEMP), false);
		//printValue(&Serial, SignalkHelper::j_currentDirection, getValueFloat(ENVIRONMENT_CURRENTDIRECTION), false);
		//printValue(&Serial, SignalkHelper::j_currentSpeed, getValueFloat(ENVIRONMENT_CURRENTSPEED), false);
		//printValue(&Serial, SignalkHelper::j_humidity, getValueFloat(ENVIRONMENT_HUMIDITY), false);
		//printValue(&Serial, SignalkHelper::j_salinity, getValueFloat(ENVIRONMENT_SALINITY), false);
		printValue(&Serial, SignalkHelper::j_waterTemp, getValueFloat(ENVIRONMENT_WATERTEMP), false);
		//	DepthStruct depth;
		//	TideStruct tide;
			printWindBranch(serial,true);
	closeBranch(&Serial, last);
}

void SignalkModel::printSteeringBranch(HardwareSerial* serial, bool last){
	openBranch(&Serial,SignalkHelper::j_steering);
		printValue(&Serial, SignalkHelper::j_rudderAngle, getValueFloat(STEERING_RUDDERANGLE), false);
		printValue(&Serial, SignalkHelper::j_rudderAngleTarget, getValueFloat(STEERING_RUDDERANGLETARGET), false);
		printAutopilotBranch(serial,true);
	closeBranch(&Serial, last);
}

