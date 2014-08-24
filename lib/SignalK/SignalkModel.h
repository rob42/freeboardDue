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
 * SignalkModel.h
 *
 *Holds all the global model vars
 *
 *  Created on: Mar 28, 2012
 *      Author: robert
 */

#ifndef SIGNALKMODEL_H_
#define SIGNALKMODEL_H_
#define DEBUG true
#include "Arduino.h"

//uncomment to support different GPS
#define GPS_GENERIC 0
#define GPS_EM_406A 1
#define GPS_MTEK_3329 2

//EM406A pin 3 = RX to arduino TX - pin18, RX to pin19
//GPS pins are Serial1
#define GPS_RX_PIN 19
#define GPS_TX_PIN 18

//#include "StreamJsonReader.h"
//#include "FreeboardConstants.h"
#define NAVIGATION_COURSEOVERGROUNDMAGNETIC 177632231UL
#define NAVIGATION_COURSEOVERGROUNDTRUE 1495033343UL
#define NAVIGATION_MAGNETICVARIATION 3733725560UL
#define NAVIGATION_DESTINATION_LONGITUDE 250998974UL
#define NAVIGATION_DESTINATION_LATITUDE 2077664687UL
#define NAVIGATION_HEADINGMAGNETIC 390698939UL
#define NAVIGATION_HEADINGTRUE 1129234387UL
#define NAVIGATION_POSITION_LONGITUDE 4257320113UL
#define NAVIGATION_POSITION_LATITUDE 2329218882UL
#define NAVIGATION_POSITION_ALTITUDE 2999027170UL
#define NAVIGATION_PITCH 2242652731UL
#define NAVIGATION_RATEOFTURN 1051834157UL
#define NAVIGATION_ROLL 588639420UL
#define NAVIGATION_SPEEDOVERGROUND 3375602335UL
#define NAVIGATION_SPEEDTHROUGHWATER 2011270296UL
#define NAVIGATION_STATE 2246585668UL
#define NAVIGATION_ANCHOR_MAXRADIUS 3688841722UL
#define NAVIGATION_ANCHOR_CURRENTRADIUS 2152304183UL
#define NAVIGATION_ANCHOR_POSITION_ALTITUDE 3067744843UL
#define NAVIGATION_ANCHOR_POSITION_LATITUDE 2397936555UL
#define NAVIGATION_ANCHOR_POSITION_LONGITUDE 2230036026UL
#define STEERING_AUTOPILOT_STATE 1414591300UL
#define STEERING_AUTOPILOT_MODE 3296408520UL
#define STEERING_AUTOPILOT_TARGETHEADINGNORTH 1763947237UL
#define STEERING_AUTOPILOT_TARGETHEADINGMAGNETIC 542499234UL
#define STEERING_AUTOPILOT_ALARMHEADINGXTE 2225422449UL
#define STEERING_AUTOPILOT_HEADINGSOURCE 1161926884UL
#define STEERING_AUTOPILOT_DEADZONE 3691686605UL
#define STEERING_AUTOPILOT_BACKLASH 3570446012UL
#define STEERING_AUTOPILOT_GAIN 3296177826UL
#define STEERING_AUTOPILOT_MAXDRIVEAMPS 3211458388UL
#define STEERING_AUTOPILOT_MAXDRIVERATE 3212056367UL
#define ALARMS_ANCHORALARMMETHOD 2783435100UL
#define ALARMS_ANCHORALARMSTATE 1003034460UL
#define ALARMS_AUTOPILOTALARMMETHOD 1469117826UL
#define ALARMS_AUTOPILOTALARMSTATE 3305916098UL
#define ALARMS_ENGINEALARMMETHOD 3992095383UL
#define ALARMS_ENGINEALARMSTATE 2991918391UL
#define ALARMS_FIREALARMMETHOD 133189895UL
#define ALARMS_FIREALARMSTATE 662422951UL
#define ALARMS_GASALARMMETHOD 3929525820UL
#define ALARMS_GASALARMSTATE 3380473916UL
#define ALARMS_GPSALARMMETHOD 2429115595UL
#define ALARMS_GPSALARMSTATE 2814404843UL
#define ALARMS_MAYDAYALARMMETHOD 67311014UL
#define ALARMS_MAYDAYALARMSTATE 1441329766UL
#define ALARMS_PANPANALARMMETHOD 1695331519UL
#define ALARMS_PANPANALARMSTATE 3963523679UL
#define ALARMS_POWERALARMMETHOD 3887776462UL
#define ALARMS_POWERALARMSTATE 1296800398UL
#define ALARMS_SILENTINTERVAL 357415143UL
#define ALARMS_WINDALARMMETHOD 1899960179UL
#define ALARMS_WINDALARMSTATE 3449122451UL
//TODO: hash codes
#define ALARMS_GENERICALARMMETHOD 6UL
#define ALARMS_GENERICALARMSTATE 7UL
#define ENVIRONMENT_WIND_DIRECTIONAPPARENT 3267532580UL
#define ENVIRONMENT_WIND_DIRECTIONCHANGEALARM 4209206332UL
#define ENVIRONMENT_WIND_DIRECTIONTRUE 1752542857UL
#define ENVIRONMENT_WIND_SPEEDALARM 2559123686UL
#define ENVIRONMENT_WIND_SPEEDTRUE 1900346521UL
#define ENVIRONMENT_WIND_SPEEDAPPARENT 531262772UL
#define _ARDUINO_GPS_MODEL 260479757UL
#define _ARDUINO_SERIAL_BAUD0 1806063390UL
#define _ARDUINO_SERIAL_BAUD1 1806063391UL
#define _ARDUINO_SERIAL_BAUD2 1806063392UL
#define _ARDUINO_SERIAL_BAUD3 1806063393UL
#define _ARDUINO_ALARM_LEVEL1_UPPER 2104985698UL
#define _ARDUINO_ALARM_LEVEL1_LOWER 2094284095UL
#define _ARDUINO_ALARM_LEVEL2_UPPER 3396453667UL
#define _ARDUINO_ALARM_LEVEL2_LOWER 3385752064UL
#define _ARDUINO_ALARM_LEVEL3_UPPER 392954340UL
#define _ARDUINO_ALARM_LEVEL3_LOWER 382252737UL
#define _ARDUINO_SEATALK 3540059849UL
//TODO: get hash
#define _ARDUINO_WIND_ZEROOFFSET 0UL
#define _ARDUINO_WIND_LASTUPDATE 1UL
#define _ARDUINO_GPS_LASTFIX 1UL
#define _ARDUINO_GPS_UTC 3UL
#define _ARDUINO_GPS_STATUS 4UL
#define _ARDUINO_GPS_DECODE 5UL
#define _ARDUINO_AUTOPILOT_BAUDRATE 6UL
#define _ARDUINO_AUTOPILOT_OFFCOURSE 7UL
#define _ARDUINO_AUTOPILOT_RUDDERCOMMAND 8UL
#define _ARDUINO_WIND_AVERAGE 2851759217UL
#define _ARDUINO_WIND_FACTOR 1428475061UL
#define _ARDUINO_WIND_MAX 287358556UL
#define _ARDUINO_ALARM_SNOOZE 2215576829UL
#define _ARDUINO_ANCHOR_RADIUSDEG 439059557UL
#define _ARDUINO_ANCHOR_NORTH 3020492120UL
#define _ARDUINO_ANCHOR_SOUTH 3026424992UL
#define _ARDUINO_ANCHOR_EAST 3214803994UL
#define _ARDUINO_ANCHOR_WEST 3215455216UL

typedef enum {ALRM_MESSAGE,ALRM_SOUND,ALRM_SMS,ALRM_EMAIL,ALRM_DSC} AlarmMethodType;
static const char *AlarmMethodString[] = {"message", "sound","sms","email","dsc",};
typedef enum {ALRM_DISABLED,ALRM_ENABLED,ALRM_FIRING,ALRM_SILENT} AlarmStateType;
static const char *AlarmStateString[] = {"disabled", "enabled", "firing", "silent",};

typedef enum {AP_ON,AP_OFF,AP_ALARM} AutopilotStateType;
static const char *AutopilotStateString[] = {"on", "off", "alarm",};
typedef enum {AP_POWERSAVE,AP_NORMAL,AP_ACCURATE} AutopilotModeType;
static const char *AutopilotModeString[] = { "powersave", "normal", "accurate",};

typedef enum {NAV_UNDERWAY_ENGINE,NAV_ANCHORED,NAV_NOT_UNDER_COMMAND, NAV_RESTRICTED_MANOUVERABILITY, NAV_CONSTRAINED_BY_DRAFT,
	NAV_MOORED,NAV_AGROUND,NAV_FISHING,NAV_SAILING,NAV_NOT_DEFINED} NavigationStateType;
static const char *NavigationStateString[] = {
		"Under way using engine",
		"At anchor",
        "Not under command",
        "Restricted manoeuverability",
        "Constrained by her draught",
        "Moored",
        "Aground",
        "Engaged in Fishing",
        "Under way sailing",
        "Not defined (example)",
};

typedef enum {AP_COMPASS,AP_WIND,AP_GPS} AutopilotHeadingSourceType;
static const char *AutopilotHeadingSourceString[] = { "compass", "wind", "gps",};
typedef struct {
	float longitude;
	float latitude;
	float altitude;
} Position ;
typedef struct {
		int upper;
		int lower;
	}LevelStruct;

class SignalkModel {
public:

	SignalkModel();
	void setSignalkValue(char* attribute, bool value);
	void setSignalkValue(char* attribute, char* value);
	void setSignalkValue(char* attribute, char value);
	void setSignalkValue(char* attribute, float value);
	void setSignalkValue(char* attribute, long value);
	void setSignalkValue(char* attribute, unsigned long value);
	void setSignalkValue(char* attribute, int value);

	void setSignalkValue(unsigned long key, bool value);
	void setSignalkValue(unsigned long key, char* value);
	void setSignalkValue(unsigned long key, char value);
	void setSignalkValue(unsigned long key, float value);
	void setSignalkValue(unsigned long key, double value);
	void setSignalkValue(unsigned long key, long value);
	void setSignalkValue(unsigned long key, unsigned long value);
	void setSignalkValue(unsigned long key, int value);

	bool getSignalkValueBool(unsigned long key);
	char* getSignalkValueChar(unsigned long key);
	float getSignalkValueFloat(unsigned long key);
	double getSignalkValueDouble(unsigned long key);
	long getSignalkValueLong(unsigned long key);
	int getSignalkValueInt(unsigned long key);
	volatile bool isAlarmTriggered() ;
	volatile bool isAutopilotOn() ;
	volatile bool isAlarmTriggered(unsigned long key);
	unsigned long hash(const char *str);


private:

	struct Navigation {
			float courseOverGroundMagnetic;
			float courseOverGroundTrue;
			struct CurrentRoute {
				float bearingActual;
				float bearingDirect;
				float courseRequired;
				long eta;
				String route;
				long startTime;
				struct Waypoint {
					long lastTime;
					String last;
					long nextEta;
					String next;
					float xte;
				} waypoint;
			} currentRoute ;
			float magneticVariation;
			struct Destination {
				long eta;
				float longitude;
				float latitude;
				float altitude;
			} destination;
			float drift;
			//gnss
			float headingMagnetic;
			float headingTrue;
			Position  position ;
			float pitch;
			float rateOfTurn;
			float roll;
			float set;
			float speedOverGround;
			float speedThroughWater;
			NavigationStateType state;
			struct Anchor {
				Position  position ;
				float maxRadius;
				float currentRadius;
			}anchor;
		} navigation;


	struct Steering {
		float rudderAngle;
		float rudderAngleTarget;
		struct Autopilot {
			AutopilotStateType state;
			AutopilotModeType mode;
			float targetHeadingNorth;
			float targetHeadingMagnetic;
			float alarmHeadingXte;
			AutopilotHeadingSourceType headingSource;
			float deadZone;
			float backlash;
			int gain;
			float maxDriveAmps;
			float maxDriveRate;
			float portLock;
			float starboardLock;
		} autopilot ;
	} steering ;
	struct Alarms {
		AlarmMethodType anchorAlarmMethod;
		AlarmStateType anchorAlarmState;
		AlarmMethodType autopilotAlarmMethod;
		AlarmStateType autopilotAlarmState;
		AlarmMethodType  engineAlarmMethod;
		AlarmStateType engineAlarmState;
		AlarmMethodType  fireAlarmMethod;
		AlarmStateType fireAlarmState;
		AlarmMethodType  gasAlarmMethod;
		AlarmStateType gasAlarmState;
		AlarmMethodType  gpsAlarmMethod;
		AlarmStateType gpsAlarmState;
		AlarmMethodType  maydayAlarmMethod;
		AlarmStateType maydayAlarmState;
		AlarmMethodType  panpanAlarmMethod;
		AlarmStateType panpanAlarmState;
		AlarmMethodType  powerAlarmMethod;
		AlarmStateType powerAlarmState;
		int  silentInterval;
		AlarmMethodType windAlarmMethod;
		AlarmStateType windAlarmState;
		AlarmMethodType genericAlarmMethod;
		AlarmStateType genericAlarmState;
	} alarms ;

	struct WindStruct {
					float directionApparent;
					float directionChangeAlarm;
					float directionTrue;
					float speedAlarm;
					float speedTrue;
					float speedApparent;
				} wind;
		struct TideStruct {
			float heightHigh;
			float heightNow;
			float heightLow;
			long timeLow;
			long timeHigh;
		} tide ;

		struct DepthStruct {
			float belowKeel;
			float belowTransducer;
			float belowSurface;
			float transducerToKeel;
			float surfaceToTransducer;
		} depth;

	struct EnvironmentStruct {
		float airPressureChangeRateAlarm;
		float airPressure;
		float airTemp;
		float currentDirection;
		float currentSpeed;
		float humidity;
		float salinity;
		float waterTemp;
		DepthStruct depth;
		TideStruct tide;
		WindStruct wind;
	} environment ;


	struct ConfigStruct {
		struct GpsStruct {
			bool decode;
			int model;
			unsigned long lastFix;
			unsigned long utc;
			char status;
		}gps;
		struct SerialStruct{
			long baud0;
			long baud1;
			long baud2;
			long baud3;
		}serial;
		struct AlarmStruct{
			LevelStruct level1;
			LevelStruct level2;
			LevelStruct level3;
			long snooze;
			long last;
		}alarm;
		struct AnchorStruct{
			float radiusDeg;
			float north;
			float south;
			float east;
			float west;
		}anchor;
		bool seatalk;
		struct WindStruct{
			long lastUpdate;
			float average;
			float factor;
			float max;
			float zeroOffset;
		}wind;
		struct AutopilotStruct{
			long baudRate;
			double offcourse;
			double rudderCommand;
		}autopilot;

	}_arduino;
};



			/*
gpsState.gpsDecode = false; //flag to indicate a new sentence was decoded.
	gpsState.gpsLastFix = 0; //time of last good gps fix.
	gpsState.gpsUtc = 0; // decimal value of UTC term in last full GPRMC sentence
	gpsState.gpsStatus = 'V'; //  status character in last full GPRMC sentence ('A' or 'V')


			"_arduino.gps.model",
			"_arduino.serial.baud0",
			"_arduino.serial.baud1",
			"_arduino.serial.baud2",
			"_arduino.serial.baud3",
			"_arduino.alarm.level1.upper",
			"_arduino.alarm.level1.lower",
			"_arduino.alarm.level2.upper",
			"_arduino.alarm.level2.lower",
			"_arduino.alarm.level3.upper",
			"_arduino.alarm.level3.lower",
			"_arduino.seatalk",
			"_arduino.windAverage ",
			"_arduino.windFactor ",
			"_arduino.windMax",
			"_arduino.alarm.snooze",
			"_arduino.anchorRadiusDeg ",
			"_arduino.anchorDistance",
			"_arduino.anchorMaxDistance"
					};*/

/*
_arduino.gps.model
_arduino.serial.baud0
_arduino.serial.baud1
_arduino.serial.baud2
_arduino.serial.baud3
_arduino.alarm.level1.upper
_arduino.alarm.level1.lower
_arduino.alarm.level2.upper
_arduino.alarm.level2.lower
_arduino.alarm.level3.upper
_arduino.alarm.level3.lower
_arduino.seatalk

_arduino.windLastUpdate //32 bits (4 bytes). non neg
_arduino.windAverage //16 bits (2 bytes)
_arduino.windFactor		//32 bits (4 bytes). 
_arduino.windMax
_arduino.alarm.last //toggle to make alarm beep - beep beep
_arduino.alarm.snooze
	
_arduino.anchorRadiusDeg //anchor alarm radius in decimal degrees, eg 1deg = 60NM.
_arduino.anchorDistance
_arduino.anchorMaxDistance
//a box around the anchor, shrinks with every GPS reading to home in on the anchor itself
_arduino.anchorN
_arduino.anchorS
_arduino.anchorE
_arduino.anchorW

*/

#endif /* SIGNALKMODEL_H_ */
