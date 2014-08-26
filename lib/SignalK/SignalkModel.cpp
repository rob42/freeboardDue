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
//#include "freeboardDue.h"

SignalkModel::SignalkModel() {

	navigation.courseOverGroundMagnetic = 0.0;
	navigation.courseOverGroundTrue = 0.0;
	navigation.currentRoute.bearingActual = 0.0;
	navigation.currentRoute.bearingDirect = 0.0;
	navigation.currentRoute.courseRequired = 0.0;
	navigation.currentRoute.eta = 0;
	navigation.currentRoute.route = "";
	navigation.currentRoute.startTime = 0;
	navigation.currentRoute.waypoint.lastTime = 0;
	navigation.currentRoute.waypoint.last = "";
	navigation.currentRoute.waypoint.nextEta = 0;
	navigation.currentRoute.waypoint.next = "";
	navigation.currentRoute.waypoint.xte = 0.0;
	navigation.magneticVariation = 0.0;
	navigation.destination.eta = 0;
	navigation.destination.longitude = 0.0;
	navigation.destination.latitude = 0.0;
	navigation.destination.altitude = 0.0;
	navigation.drift = 0.0;
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
	alarms.anchorAlarmMethod = ALRM_SOUND;
	alarms.anchorAlarmState = ALRM_DISABLED;
	alarms.autopilotAlarmMethod = ALRM_SOUND;
	alarms.autopilotAlarmState = ALRM_DISABLED;
	alarms.engineAlarmMethod = ALRM_SOUND;
	alarms.engineAlarmState = ALRM_DISABLED;
	alarms.fireAlarmMethod = ALRM_SOUND;
	alarms.fireAlarmState = ALRM_DISABLED;
	alarms.gasAlarmMethod = ALRM_SOUND;
	alarms.gasAlarmState = ALRM_DISABLED;
	alarms.gpsAlarmMethod = ALRM_SOUND;
	alarms.gpsAlarmState = ALRM_DISABLED;
	alarms.maydayAlarmMethod = ALRM_SOUND;
	alarms.maydayAlarmState = ALRM_DISABLED;
	alarms.panpanAlarmMethod = ALRM_SOUND;
	alarms.panpanAlarmState = ALRM_DISABLED;
	alarms.powerAlarmMethod = ALRM_SOUND;
	alarms.powerAlarmState = ALRM_DISABLED;
	alarms.silentInterval = 300; //seconds?
	alarms.windAlarmMethod = ALRM_SOUND;
	alarms.windAlarmState = ALRM_DISABLED;
	alarms.genericAlarmMethod = ALRM_SOUND;
	alarms.genericAlarmState = ALRM_DISABLED;
	alarms.radarAlarmMethod = ALRM_SOUND;
	alarms.radarAlarmState = ALRM_DISABLED;
	alarms.mobAlarmMethod = ALRM_SOUND;
	alarms.mobAlarmState = ALRM_DISABLED;
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

}

int findInArray(const char *array[], const char* value) {

	for (unsigned int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
		if ((strcmp(array[i], value) == 0)) {
			return i;
		}
	}
	return -1;
}

void SignalkModel::setSignalkValue(char* attribute, bool value) {
	unsigned long key = hash(attribute);
	setSignalkValue(key, value);

}
void SignalkModel::setSignalkValue(unsigned long key, bool value) {
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
void SignalkModel::setSignalkValue(char* attribute, char value) {
	unsigned long key = hash(attribute);
	setSignalkValue(key, value);
}

void SignalkModel::setSignalkValue(unsigned long key, char value) {

	switch (key) {

	case _ARDUINO_GPS_STATUS:
		_arduino.gps.status = value;
		break;
	}
}

void SignalkModel::setSignalkValue(unsigned long key, double value) {

	switch (key) {

	case _ARDUINO_AUTOPILOT_OFFCOURSE:
		_arduino.autopilot.offcourse = value;
		break;
	}
}

void SignalkModel::setSignalkValue(char* attribute, char* value) {
	unsigned long key = hash(attribute);
	setSignalkValue(key, value);
}

void SignalkModel::setSignalkValue(unsigned long key, char* value) {

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
void SignalkModel::setSignalkValue(char* attribute, int value) {
	setSignalkValue(hash(attribute), (int) value);
	//Serial.print(" setSignalkValue:");
	//Serial.println(key);
}
void SignalkModel::setSignalkValue(unsigned long key, int value) {

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

void SignalkModel::setSignalkValue(char* attribute, unsigned long value) {
	setSignalkValue(hash(attribute), (unsigned long) value);
	//Serial.print(" setSignalkValue:");
	//Serial.println(key);
}
void SignalkModel::setSignalkValue(unsigned long key, unsigned long value) {

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
	}
}

void SignalkModel::setSignalkValue(char* attribute, float value) {
	setSignalkValue(hash(attribute), value);
	//Serial.print(" setSignalkValue:");
	//Serial.println(key);
}
void SignalkModel::setSignalkValue(unsigned long key, float value) {

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
		break;

	}

}
int SignalkModel::getSignalkValueInt(unsigned long key) {
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
	return NAN;
}

unsigned long SignalkModel::getSignalkValueLong(unsigned long key) {
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
	return NAN;
}


double SignalkModel::getSignalkValueDouble(unsigned long key) {
	switch (key) {
	case _ARDUINO_AUTOPILOT_OFFCOURSE:
		return _arduino.autopilot.offcourse;
		break;
	case _ARDUINO_AUTOPILOT_RUDDERCOMMAND:
		return _arduino.autopilot.rudderCommand;
		break;
	}
	return NAN;
}

float SignalkModel::getSignalkValueFloat(unsigned long key) {
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

char SignalkModel::getSignalkValueChar(unsigned long key) {

	switch (key) {
	case _ARDUINO_GPS_STATUS:
		return _arduino.gps.status;
		break;
	}
	return NULL;
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

unsigned long SignalkModel::hash(const char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

