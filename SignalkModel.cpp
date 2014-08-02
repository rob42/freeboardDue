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

	navigation.courseOverGroundMagnetic = 0.0;
	navigation.courseOverGroundTrue = 0.0;
	navigation.currentRoute.bearingActual = 0.0;
	navigation.currentRoute.bearingDirect = 0.0;
	navigation.currentRoute.courseRequired = 0.0;
	navigation.currentRoute.eta = 0;
	navigation.currentRoute.route = "";
	navigation.currentRoute.startTime =0;
	navigation.currentRoute.waypoint.lastTime = 0;
	navigation.currentRoute.waypoint.last ="";
	navigation.currentRoute.waypoint.nextEta = 0;
	navigation.currentRoute.waypoint.next = "";
	navigation.currentRoute.waypoint.xte = 0.0;
	navigation.magneticVariation  = 0.0;
	navigation.destination.eta =0;
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
	navigation.state= NAV_NOT_DEFINED;
	steering.rudderAngle = 0.0;
	steering.rudderAngleTarget = 0.0;
	steering.autopilot.state=AP_OFF;
	steering.autopilot.mode=AP_NORMAL;
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
	environment.tide.timeLow =0;
	environment.tide.timeHigh = 0;
	environment.waterTemp=0;
	environment.wind.directionApparent = 0.0;
	environment.wind.directionChangeAlarm = 0.0;
	environment.wind.directionTrue = 0.0;
	environment.wind.speedAlarm = 0.0;
	environment.wind.speedTrue = 0.0;
	environment.wind.speedApparent = 0.0;

}

float SignalkModel::getNavigationCourseOverGroundMagnetic(){
return navigation.courseOverGroundMagnetic;
}
float SignalkModel::getNavigationCourseOverGroundTrue(){
return navigation.courseOverGroundTrue;
}
float SignalkModel::getNavigationCurrentRouteBearingActual(){
return navigation.currentRoute.bearingActual;
}
float SignalkModel::getNavigationCurrentRouteBearingDirect(){
return navigation.currentRoute.bearingDirect;
}
float SignalkModel::getNavigationCurrentRouteCourseRequired(){
return navigation.currentRoute.courseRequired;
}
long SignalkModel::getNavigationCurrentRouteEta(){
return navigation.currentRoute.eta;
}
String SignalkModel::getNavigationCurrentRouteRoute(){
return navigation.currentRoute.route;
}
long SignalkModel::getNavigationCurrentRouteStartTime(){
return navigation.currentRoute.startTime;
}

long SignalkModel::getNavigationCurrentRouteWaypointLastTime(){
return navigation.currentRoute.waypoint.lastTime;
}
String SignalkModel::getNavigationCurrentRouteWaypointLast(){
return navigation.currentRoute.waypoint.last;
}
long SignalkModel::getNavigationCurrentRouteWaypointNextEta(){
return navigation.currentRoute.waypoint.nextEta;
}
String SignalkModel::getNavigationCurrentRouteWaypointNext(){
return navigation.currentRoute.waypoint.next;
}
float SignalkModel::getNavigationCurrentRouteWaypointXte(){
return navigation.currentRoute.waypoint.xte;
}
float SignalkModel::getNavigationMagneticVariation(){
return navigation.magneticVariation;
}
long SignalkModel::getNavigationDestinationEta(){
return navigation.destination.eta;
}
float SignalkModel::getNavigationDestinationLongitude(){
return navigation.destination.longitude;
}
float SignalkModel::getNavigationDestinationLatitude(){
return navigation.destination.latitude;
}
float SignalkModel::getNavigationDestinationAltitude(){
return navigation.destination.altitude;
}
float SignalkModel::getNavigationDrift(){
return navigation.drift;
}

float SignalkModel::getNavigationHeadingMagnetic(){
return navigation.headingMagnetic;
}
float SignalkModel::getNavigationHeadingTrue(){
return navigation.headingTrue;
}
float SignalkModel::getNavigationPositionLongitude(){
return navigation.position.longitude;
}
float SignalkModel::getNavigationPositionLatitude(){
return navigation.position.latitude;
}
float SignalkModel::getNavigationPositionAltitude(){
return navigation.position.altitude;
}
float SignalkModel::getNavigationPitch(){
return navigation.pitch;
}
float SignalkModel::getNavigationRateOfTurn(){
return navigation.rateOfTurn;
}
float SignalkModel::getNavigationRoll(){
return navigation.roll;
}
float SignalkModel::getNavigationSet(){
return navigation.set;
}
float SignalkModel::getNavigationSpeedOverGround(){
return navigation.speedOverGround;
}
float SignalkModel::getNavigationSpeedThroughWater(){
return navigation.speedThroughWater;
}
NavigationStateType SignalkModel::getNavigationState(){
return navigation.state;
}
float SignalkModel::getSteeringRudderAngle(){
return steering.rudderAngle;
}
float SignalkModel::getSteeringRudderAngleTarget(){
return steering.rudderAngleTarget;
}
AutopilotStateType SignalkModel::getSteeringAutopilotState(){
return steering.autopilot.state;
}
AutopilotModeType SignalkModel::getSteeringAutopilotMode(){
return steering.autopilot.mode;
}
float SignalkModel::getSteeringAutopilotTargetHeadingNorth(){
return steering.autopilot.targetHeadingNorth;
}
float SignalkModel::getSteeringAutopilotTargetHeadingMagnetic(){
return steering.autopilot.targetHeadingMagnetic;
}
float SignalkModel::getSteeringAutopilotAlarmHeadingXte(){
return steering.autopilot.alarmHeadingXte;
}
AutopilotHeadingSourceType SignalkModel::getSteeringAutopilotHeadingSource(){
return steering.autopilot.headingSource;
}
float SignalkModel::getSteeringAutopilotDeadZone(){
return steering.autopilot.deadZone;
}
float SignalkModel::getSteeringAutopilotBacklash(){
return steering.autopilot.backlash;
}
float SignalkModel::getSteeringAutopilotGain(){
return steering.autopilot.gain;
}
float SignalkModel::getSteeringAutopilotMaxDriveAmps(){
return steering.autopilot.maxDriveAmps;
}
float SignalkModel::getSteeringAutopilotMaxDriveRate(){
return steering.autopilot.maxDriveRate;
}
float SignalkModel::getSteeringAutopilotPortLock(){
return steering.autopilot.portLock;
}
float SignalkModel::getSteeringAutopilotStarboardLock(){
return steering.autopilot.starboardLock;
}
AlarmMethodType SignalkModel::getAlarmsAnchorAlarmMethod(){
return alarms.anchorAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsAnchorAlarmState(){
return alarms.anchorAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsAutopilotAlarmMethod(){
return alarms.autopilotAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsAutopilotAlarmState(){
return alarms.autopilotAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsEngineAlarmMethod(){
return alarms.engineAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsEngineAlarmState(){
return alarms.engineAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsFireAlarmMethod(){
return alarms.fireAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsFireAlarmState(){
return alarms.fireAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsGasAlarmMethod(){
return alarms.gasAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsGasAlarmState(){
return alarms.gasAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsGpsAlarmMethod(){
return alarms.gpsAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsGpsAlarmState(){
return alarms.gpsAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsMaydayAlarmMethod(){
return alarms.maydayAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsMaydayAlarmState(){
return alarms.maydayAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsPanpanAlarmMethod(){
return alarms.panpanAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsPanpanAlarmState(){
return alarms.panpanAlarmState;
}
AlarmMethodType SignalkModel::getAlarmsPowerAlarmMethod(){
return alarms.powerAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsPowerAlarmState(){
return alarms.powerAlarmState;
}
int SignalkModel::getAlarmsSilentInterval(){
return alarms.silentInterval;
}
AlarmMethodType SignalkModel::getAlarmsWindAlarmMethod(){
return alarms.windAlarmMethod;
}
AlarmStateType SignalkModel::getAlarmsWindAlarmState(){
return alarms.windAlarmState;
}
float SignalkModel::getEnvironmentAirPressureChangeRateAlarm(){
return environment.airPressureChangeRateAlarm;
}
float SignalkModel::getEnvironmentAirPressure(){
return environment.airPressure;
}
float SignalkModel::getEnvironmentAirTemp(){
return environment.airTemp;
}
float SignalkModel::getEnvironmentCurrentDirection(){
return environment.currentDirection;
}
float SignalkModel::getEnvironmentCurrentSpeed(){
return environment.currentDirection;
}
float SignalkModel::getEnvironmentDepthBelowKeel(){
return environment.depth.belowKeel;
}
float SignalkModel::getEnvironmentDepthBelowTransducer(){
return environment.depth.belowTransducer;
}
float SignalkModel::getEnvironmentDepthBelowSurface(){
return environment.depth.belowSurface;
}
float SignalkModel::getEnvironmentDepthTransducerToKeel(){
return environment.depth.transducerToKeel;
}
float SignalkModel::getEnvironmentDepthSurfaceToTransducer(){
return environment.depth.surfaceToTransducer;
}
float SignalkModel::getEnvironmentHumidity(){
return environment.humidity;
}
float SignalkModel::getEnvironmentSalinity(){
return environment.salinity;
}
float SignalkModel::getEnvironmentTideHeightHigh(){
return environment.tide.heightHigh;
}
float SignalkModel::getEnvironmentTideHeightNow(){
return environment.tide.heightNow;
}
float SignalkModel::getEnvironmentTideHeightLow(){
return environment.tide.heightLow;
}
long SignalkModel::getEnvironmentTideTimeLow(){
return environment.tide.timeLow;
}
long SignalkModel::getEnvironmentTideTimeHigh(){
return environment.tide.timeHigh;
}
float SignalkModel::getEnvironmentWaterTemp(){
return environment.waterTemp;
}
float SignalkModel::getEnvironmentWindDirectionApparent(){
return environment.wind.directionApparent;
}
float SignalkModel::getEnvironmentWindDirectionChangeAlarm(){
return environment.wind.directionChangeAlarm;
}
float SignalkModel::getEnvironmentWindDirectionTrue(){
return environment.wind.directionTrue;
}
float SignalkModel::getEnvironmentWindSpeedAlarm(){
return environment.wind.speedAlarm;
}
float SignalkModel::getEnvironmentWindSpeedTrue(){
return environment.wind.speedTrue;
}
float SignalkModel::getEnvironmentWindSpeedApparent(){
	return environment.wind.speedApparent;
}



void SignalkModel::setNavigationCourseOverGroundMagnetic(float navigationCourseOverGroundMagnetic){
	navigation.courseOverGroundMagnetic=navigationCourseOverGroundMagnetic;
}

void SignalkModel::setNavigationCourseOverGroundTrue(float navigationCourseOverGroundTrue){
	navigation.courseOverGroundTrue=navigationCourseOverGroundTrue;
}

void SignalkModel::setNavigationCurrentRouteBearingActual(float navigationCurrentRouteBearingActual){
	navigation.currentRoute.bearingActual=navigationCurrentRouteBearingActual;
}

void SignalkModel::setNavigationCurrentRouteBearingDirect(float navigationCurrentRouteBearingDirect){
	navigation.currentRoute.bearingDirect=navigationCurrentRouteBearingDirect;
}

void SignalkModel::setNavigationCurrentRouteCourseRequired(float navigationCurrentRouteCourseRequired){
	navigation.currentRoute.courseRequired=navigationCurrentRouteCourseRequired;
}

void SignalkModel::setNavigationCurrentRouteEta(long navigationCurrentRouteEta){
	navigation.currentRoute.eta=navigationCurrentRouteEta;
}

void SignalkModel::setNavigationCurrentRouteRoute(String navigationCurrentRouteRoute){
	navigation.currentRoute.route=navigationCurrentRouteRoute;
}

void SignalkModel::setNavigationCurrentRouteStartTime(long navigationCurrentRouteStartTime){
	navigation.currentRoute.startTime=navigationCurrentRouteStartTime;
}


void SignalkModel::setNavigationCurrentRouteWaypointLastTime(long navigationCurrentRouteWaypointLastTime){
	navigation.currentRoute.waypoint.lastTime=navigationCurrentRouteWaypointLastTime;
}

void SignalkModel::setNavigationCurrentRouteWaypointLast(String navigationCurrentRouteWaypointLast){
	navigation.currentRoute.waypoint.last=navigationCurrentRouteWaypointLast;
}

void SignalkModel::setNavigationCurrentRouteWaypointNextEta(long navigationCurrentRouteWaypointNextEta){
	navigation.currentRoute.waypoint.nextEta=navigationCurrentRouteWaypointNextEta;
}

void SignalkModel::setNavigationCurrentRouteWaypointNext(String navigationCurrentRouteWaypointNext){
	navigation.currentRoute.waypoint.next=navigationCurrentRouteWaypointNext;
}

void SignalkModel::setNavigationCurrentRouteWaypointXte(float navigationCurrentRouteWaypointXte){
	navigation.currentRoute.waypoint.xte=navigationCurrentRouteWaypointXte;
}

void SignalkModel::setNavigationMagneticVariation(float navigationMagneticVariation){
	navigation.magneticVariation=navigationMagneticVariation;
}

void SignalkModel::setNavigationDestinationEta(long navigationDestinationEta){
	navigation.destination.eta=navigationDestinationEta;
}

void SignalkModel::setNavigationDestinationLongitude(float navigationDestinationLongitude){
	navigation.destination.longitude=navigationDestinationLongitude;
}

void SignalkModel::setNavigationDestinationLatitude(float navigationDestinationLatitude){
	navigation.destination.latitude=navigationDestinationLatitude;
}

void SignalkModel::setNavigationDestinationAltitude(float navigationDestinationAltitude){
	navigation.destination.altitude=navigationDestinationAltitude;
}

void SignalkModel::setNavigationDrift(float navigationDrift){
	navigation.drift=navigationDrift;
}


void SignalkModel::setNavigationHeadingMagnetic(float navigationHeadingMagnetic){
	navigation.headingMagnetic=navigationHeadingMagnetic;
}

void SignalkModel::setNavigationHeadingTrue(float navigationHeadingTrue){
	navigation.headingTrue=navigationHeadingTrue;
}

void SignalkModel::setNavigationPositionLongitude(float navigationPositionLongitude){
	navigation.position.longitude=navigationPositionLongitude;
}

void SignalkModel::setNavigationPositionLatitude(float navigationPositionLatitude){
	navigation.position.latitude=navigationPositionLatitude;
}

void SignalkModel::setNavigationPositionAltitude(float navigationPositionAltitude){
	navigation.position.altitude=navigationPositionAltitude;
}

void SignalkModel::setNavigationPitch(float navigationPitch){
	navigation.pitch=navigationPitch;
}

void SignalkModel::setNavigationRateOfTurn(float navigationRateOfTurn){
	navigation.rateOfTurn=navigationRateOfTurn;
}

void SignalkModel::setNavigationRoll(float navigationRoll){
	navigation.roll=navigationRoll;
}

void SignalkModel::setNavigationSet(float navigationSet){
	navigation.set=navigationSet;
}

void SignalkModel::setNavigationSpeedOverGround(float navigationSpeedOverGround){
	navigation.speedOverGround=navigationSpeedOverGround;
}

void SignalkModel::setNavigationSpeedThroughWater(float navigationSpeedThroughWater){
	navigation.speedThroughWater=navigationSpeedThroughWater;
}

void SignalkModel::setNavigationState(NavigationStateType navigationState){
	navigation.state=navigationState;
}

void SignalkModel::setSteeringRudderAngle(float steeringRudderAngle){
	steering.rudderAngle=steeringRudderAngle;
}

void SignalkModel::setSteeringRudderAngleTarget(float steeringRudderAngleTarget){
	steering.rudderAngleTarget=steeringRudderAngleTarget;
}

void SignalkModel::setSteeringAutopilotState(AutopilotStateType steeringAutopilotState){
	steering.autopilot.state=steeringAutopilotState;
}

void SignalkModel::setSteeringAutopilotMode(AutopilotModeType steeringAutopilotMode){
	steering.autopilot.mode=steeringAutopilotMode;
}

void SignalkModel::setSteeringAutopilotTargetHeadingNorth(float steeringAutopilotTargetHeadingNorth){
	steering.autopilot.targetHeadingNorth=steeringAutopilotTargetHeadingNorth;
}

void SignalkModel::setSteeringAutopilotTargetHeadingMagnetic(float steeringAutopilotTargetHeadingMagnetic){
	steering.autopilot.targetHeadingMagnetic=steeringAutopilotTargetHeadingMagnetic;
}

void SignalkModel::setSteeringAutopilotAlarmHeadingXte(float steeringAutopilotAlarmHeadingXte){
	steering.autopilot.alarmHeadingXte=steeringAutopilotAlarmHeadingXte;
}

void SignalkModel::setSteeringAutopilotHeadingSource(AutopilotHeadingSourceType steeringAutopilotHeadingSource){
	steering.autopilot.headingSource=steeringAutopilotHeadingSource;
}

void SignalkModel::setSteeringAutopilotDeadZone(float steeringAutopilotDeadZone){
	steering.autopilot.deadZone=steeringAutopilotDeadZone;
}

void SignalkModel::setSteeringAutopilotBacklash(float steeringAutopilotBacklash){
	steering.autopilot.backlash=steeringAutopilotBacklash;
}

void SignalkModel::setSteeringAutopilotGain(float steeringAutopilotGain){
	steering.autopilot.gain=steeringAutopilotGain;
}

void SignalkModel::setSteeringAutopilotMaxDriveAmps(float steeringAutopilotMaxDriveAmps){
	steering.autopilot.maxDriveAmps=steeringAutopilotMaxDriveAmps;
}

void SignalkModel::setSteeringAutopilotMaxDriveRate(float steeringAutopilotMaxDriveRate){
	steering.autopilot.maxDriveRate=steeringAutopilotMaxDriveRate;
}

void SignalkModel::setSteeringAutopilotPortLock(float steeringAutopilotPortLock){
	steering.autopilot.portLock=steeringAutopilotPortLock;
}

void SignalkModel::setSteeringAutopilotStarboardLock(float steeringAutopilotStarboardLock){
	steering.autopilot.starboardLock=steeringAutopilotStarboardLock;
}


void SignalkModel::setAlarmsAnchorAlarmMethod(AlarmMethodType alarmsAnchorAlarmMethod){
	alarms.anchorAlarmMethod=alarmsAnchorAlarmMethod;
}

void SignalkModel::setAlarmsAnchorAlarmState(AlarmStateType alarmsAnchorAlarmState){
	alarms.anchorAlarmState=alarmsAnchorAlarmState;
}

void SignalkModel::setAlarmsAutopilotAlarmMethod(AlarmMethodType alarmsAutopilotAlarmMethod){
	alarms.autopilotAlarmMethod=alarmsAutopilotAlarmMethod;
}

void SignalkModel::setAlarmsAutopilotAlarmState(AlarmStateType alarmsAutopilotAlarmState){
	alarms.autopilotAlarmState=alarmsAutopilotAlarmState;
}

void SignalkModel::setAlarmsEngineAlarmMethod(AlarmMethodType alarmsEngineAlarmMethod){
	alarms.engineAlarmMethod=alarmsEngineAlarmMethod;
}

void SignalkModel::setAlarmsEngineAlarmState(AlarmStateType alarmsEngineAlarmState){
	alarms.engineAlarmState=alarmsEngineAlarmState;
}

void SignalkModel::setAlarmsFireAlarmMethod(AlarmMethodType alarmsFireAlarmMethod){
	alarms.fireAlarmMethod=alarmsFireAlarmMethod;
}

void SignalkModel::setAlarmsFireAlarmState(AlarmStateType alarmsFireAlarmState){
	alarms.fireAlarmState=alarmsFireAlarmState;
}

void SignalkModel::setAlarmsGasAlarmMethod(AlarmMethodType alarmsGasAlarmMethod){
	alarms.gasAlarmMethod=alarmsGasAlarmMethod;
}

void SignalkModel::setAlarmsGasAlarmState(AlarmStateType alarmsGasAlarmState){
	alarms.gasAlarmState=alarmsGasAlarmState;
}

void SignalkModel::setAlarmsGpsAlarmMethod(AlarmMethodType alarmsGpsAlarmMethod){
	alarms.gpsAlarmMethod=alarmsGpsAlarmMethod;
}

void SignalkModel::setAlarmsGpsAlarmState(AlarmStateType alarmsGpsAlarmState){
	alarms.gpsAlarmState=alarmsGpsAlarmState;
}

void SignalkModel::setAlarmsMaydayAlarmMethod(AlarmMethodType alarmsMaydayAlarmMethod){
	alarms.maydayAlarmMethod=alarmsMaydayAlarmMethod;
}

void SignalkModel::setAlarmsMaydayAlarmState(AlarmStateType alarmsMaydayAlarmState){
	alarms.maydayAlarmState=alarmsMaydayAlarmState;
}

void SignalkModel::setAlarmsPanpanAlarmMethod(AlarmMethodType alarmsPanpanAlarmMethod){
	alarms.panpanAlarmMethod=alarmsPanpanAlarmMethod;
}

void SignalkModel::setAlarmsPanpanAlarmState(AlarmStateType alarmsPanpanAlarmState){
	alarms.panpanAlarmState=alarmsPanpanAlarmState;
}

void SignalkModel::setAlarmsPowerAlarmMethod(AlarmMethodType alarmsPowerAlarmMethod){
	alarms.powerAlarmMethod=alarmsPowerAlarmMethod;
}

void SignalkModel::setAlarmsPowerAlarmState(AlarmStateType alarmsPowerAlarmState){
	alarms.powerAlarmState=alarmsPowerAlarmState;
}

void SignalkModel::setAlarmsSilentInterval(int alarmsSilentInterval){
	alarms.silentInterval=alarmsSilentInterval;
}

void SignalkModel::setAlarmsWindAlarmMethod(AlarmMethodType alarmsWindAlarmMethod){
	alarms.windAlarmMethod=alarmsWindAlarmMethod;
}

void SignalkModel::setAlarmsWindAlarmState(AlarmStateType alarmsWindAlarmState){
	alarms.windAlarmState=alarmsWindAlarmState;
}


void SignalkModel::setEnvironmentAirPressureChangeRateAlarm(float environmentAirPressureChangeRateAlarm){
	environment.airPressureChangeRateAlarm=environmentAirPressureChangeRateAlarm;
}

void SignalkModel::setEnvironmentAirPressure(float environmentAirPressure){
	environment.airPressure=environmentAirPressure;
}

void SignalkModel::setEnvironmentAirTemp(float environmentAirTemp){
	environment.airTemp=environmentAirTemp;
}

void SignalkModel::setEnvironmentCurrentDirection(float environmentCurrentDirection){
	environment.currentDirection=environmentCurrentDirection;
}

void SignalkModel::setEnvironmentCurrentSpeed(float environmentCurrentSpeed){
	environment.currentDirection=environmentCurrentSpeed;
}

void SignalkModel::setEnvironmentDepthBelowKeel(float environmentDepthBelowKeel){
	environment.depth.belowKeel=environmentDepthBelowKeel;
}

void SignalkModel::setEnvironmentDepthBelowTransducer(float environmentDepthBelowTransducer){
	environment.depth.belowTransducer=environmentDepthBelowTransducer;
}

void SignalkModel::setEnvironmentDepthBelowSurface(float environmentDepthBelowSurface){
	environment.depth.belowSurface=environmentDepthBelowSurface;
}

void SignalkModel::setEnvironmentDepthTransducerToKeel(float environmentDepthTransducerToKeel){
	environment.depth.transducerToKeel=environmentDepthTransducerToKeel;
}

void SignalkModel::setEnvironmentDepthSurfaceToTransducer(float environmentDepthSurfaceToTransducer){
	environment.depth.surfaceToTransducer=environmentDepthSurfaceToTransducer;
}

void SignalkModel::setEnvironmentHumidity(float environmentHumidity){
	environment.humidity=environmentHumidity;
}

void SignalkModel::setEnvironmentSalinity(float environmentSalinity){
	environment.salinity=environmentSalinity;
}

void SignalkModel::setEnvironmentTideHeightHigh(float environmentTideHeightHigh){
	environment.tide.heightHigh=environmentTideHeightHigh;
}

void SignalkModel::setEnvironmentTideHeightNow(float environmentTideHeightNow){
	environment.tide.heightNow=environmentTideHeightNow;
}

void SignalkModel::setEnvironmentTideHeightLow(float environmentTideHeightLow){
	environment.tide.heightLow=environmentTideHeightLow;
}

void SignalkModel::setEnvironmentTideTimeLow(long environmentTideTimeLow){
	environment.tide.timeLow=environmentTideTimeLow;
}

void SignalkModel::setEnvironmentTideTimeHigh(long environmentTideTimeHigh){
	environment.tide.timeHigh=environmentTideTimeHigh;
}

void SignalkModel::setEnvironmentWaterTemp(float environmentWaterTemp){
	environment.waterTemp=environmentWaterTemp;
}

void SignalkModel::setEnvironmentWindDirectionApparent(float environmentWindDirectionApparent){
	environment.wind.directionApparent=environmentWindDirectionApparent;
}

void SignalkModel::setEnvironmentWindDirectionChangeAlarm(float environmentWindDirectionChangeAlarm){
	environment.wind.directionChangeAlarm=environmentWindDirectionChangeAlarm;
}

void SignalkModel::setEnvironmentWindDirectionTrue(float environmentWindDirectionTrue){
	environment.wind.directionTrue=environmentWindDirectionTrue;
}

void SignalkModel::setEnvironmentWindSpeedAlarm(float environmentWindSpeedAlarm){
	environment.wind.speedAlarm=environmentWindSpeedAlarm;
}

void SignalkModel::setEnvironmentWindSpeedTrue(float environmentWindSpeedTrue){
	environment.wind.speedTrue=environmentWindSpeedTrue;
}

void SignalkModel::setEnvironmentWindSpeedApparent(float environmentWindSpeedApparent){
	 environment.wind.speedApparent=environmentWindSpeedApparent;
}
