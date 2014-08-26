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
/* NMEA Anchor alarm
 */

#include "Anchor.h"



Anchor::Anchor(SignalkModel* model) {


	this->model=model;
	resetAnchorBox(model->getSignalkValueFloat(NAVIGATION_POSITION_LATITUDE), model->getSignalkValueFloat(NAVIGATION_POSITION_LONGITUDE));
}

Anchor::~Anchor(){

}


/* Adjust the size of the anchor box. Will not go smaller than MINMTRS */
void Anchor::updateAnchorBox(float laty, float lonx) {
	//TODO: error testing around 0, 90, 180deg

	float n = laty + model->getSignalkValueFloat(_ARDUINO_ANCHOR_RADIUSDEG);
	float s = laty - model->getSignalkValueFloat(_ARDUINO_ANCHOR_RADIUSDEG);
	float e = lonx + model->getSignalkValueFloat(_ARDUINO_ANCHOR_RADIUSDEG);
	float w = lonx - model->getSignalkValueFloat(_ARDUINO_ANCHOR_RADIUSDEG);
	//shrink anchor box if we can
	if ((n - MINMTRS) > model->getSignalkValueFloat(_ARDUINO_ANCHOR_SOUTH) && n < model->getSignalkValueFloat(_ARDUINO_ANCHOR_NORTH))
		model->setSignalkValue(_ARDUINO_ANCHOR_NORTH,n);
	if ((s + MINMTRS) < model->getSignalkValueFloat(_ARDUINO_ANCHOR_NORTH) && s > model->getSignalkValueFloat(_ARDUINO_ANCHOR_SOUTH))
		model->setSignalkValue(_ARDUINO_ANCHOR_SOUTH,s);
	if ((e - MINMTRS) > model->getSignalkValueFloat(_ARDUINO_ANCHOR_WEST) && e < model->getSignalkValueFloat(_ARDUINO_ANCHOR_EAST))
		model->setSignalkValue(_ARDUINO_ANCHOR_EAST,e);
	if ((w + MINMTRS) < model->getSignalkValueFloat(_ARDUINO_ANCHOR_EAST) && w > model->getSignalkValueFloat(_ARDUINO_ANCHOR_WEST))
		model->setSignalkValue(_ARDUINO_ANCHOR_WEST,w);

}

void Anchor::resetAnchorBox(float laty, float lonx) {
	model->setSignalkValue(_ARDUINO_ANCHOR_NORTH,90.0);
	model->setSignalkValue(_ARDUINO_ANCHOR_SOUTH,-90.0);
	model->setSignalkValue(_ARDUINO_ANCHOR_EAST,180.0);
	model->setSignalkValue(_ARDUINO_ANCHOR_WEST,-180.0);
	model->setSignalkValue(_ARDUINO_ANCHOR_RADIUSDEG,model->getSignalkValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS) * LLMTRS);
	updateAnchorBox(laty, lonx);
}


/*True if the provided lat/lon is within the anchor box*/
bool Anchor::inAnchorBox(float laty, float lonx) {
	if (laty < model->getSignalkValueFloat(_ARDUINO_ANCHOR_SOUTH))
		return false;
	if (laty > model->getSignalkValueFloat(_ARDUINO_ANCHOR_NORTH))
		return false;
	if (lonx > model->getSignalkValueFloat(_ARDUINO_ANCHOR_EAST))
		return false;
	if (lonx < model->getSignalkValueFloat(_ARDUINO_ANCHOR_WEST))
		return false;
	return true;
}

float Anchor::getAnchorRadius() {
	return  model->getSignalkValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS);
}

/*set anchor radius and adjust box*/
void Anchor::setAnchorRadius(float radius) {
	if (radius < 0)
		radius = 0;
	float change = radius -  model->getSignalkValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS);
	 model->setSignalkValue(NAVIGATION_ANCHOR_ALARMRADIUS, radius);
	 model->setSignalkValue(_ARDUINO_ANCHOR_RADIUSDEG, model->getSignalkValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS) * LLMTRS);
	saveAnchorAlarmRadius(model->getSignalkValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS));

	//deal with the changed box size
	if (change <= 0) {
		return; //no need, new box is smaller, it will sort itself
	} else {
		//grow the box? - add change to all edges?
		change = change * LLMTRS;
		model->setSignalkValue(_ARDUINO_ANCHOR_NORTH,model->getSignalkValueFloat(_ARDUINO_ANCHOR_NORTH) + change);
		model->setSignalkValue(_ARDUINO_ANCHOR_SOUTH,model->getSignalkValueFloat(_ARDUINO_ANCHOR_SOUTH) - change);
		model->setSignalkValue(_ARDUINO_ANCHOR_EAST,model->getSignalkValueFloat(_ARDUINO_ANCHOR_EAST) + change);
		model->setSignalkValue(_ARDUINO_ANCHOR_WEST,model->getSignalkValueFloat(_ARDUINO_ANCHOR_WEST) - change);

	}
}
/*calc all params, and set alarm buzzer state*/
void Anchor::checkAnchor() {

	//we dont need to do this if the anchor alarm is off
	if(model->isAlarmOn(ALARMS_ANCHORALARMSTATE)){
		//TODO: if anchor distance greater than 1000 mtrs its probably a mistake so dont fire alarm?
		// check if GPS positioning was active, if we havent had a signal in a while that may be a problem....
		if ((millis() - model->getSignalkValueLong(_ARDUINO_GPS_LASTFIX) > MAX_SINCE_LAST_GPS_FIX)
				&& model->isAlarmOn(ALARMS_ANCHORALARMSTATE)) {
			model->setSignalkValue(_ARDUINO_ALARM_SNOOZE,0UL);
			model->setSignalkValue(ALARMS_ANCHORALARMSTATE, AlarmStateType(ALRM_FIRING));
		}
		//now check position - Status, V=Navigation receiver warning A=Valid
		if (model->getSignalkValueChar(_ARDUINO_GPS_STATUS)==GPS_VALID) {
			model->setSignalkValue(NAVIGATION_ANCHOR_CURRENTRADIUS,Gps::getMetersTo(model->getSignalkValueFloat(NAVIGATION_ANCHOR_POSITION_LATITUDE), model->getSignalkValueFloat(NAVIGATION_ANCHOR_POSITION_LONGITUDE),
					model->getSignalkValueFloat(NAVIGATION_POSITION_LATITUDE),model->getSignalkValueFloat(NAVIGATION_POSITION_LONGITUDE)));
			if (model->getSignalkValueFloat(NAVIGATION_ANCHOR_CURRENTRADIUS) > model->getSignalkValueFloat(NAVIGATION_ANCHOR_MAXRADIUS))
				model->setSignalkValue(NAVIGATION_ANCHOR_MAXRADIUS,model->getSignalkValueFloat(NAVIGATION_ANCHOR_CURRENTRADIUS));

			//update the anchor box
			updateAnchorBox(model->getSignalkValueFloat(NAVIGATION_POSITION_LATITUDE), model->getSignalkValueFloat(NAVIGATION_POSITION_LONGITUDE));

			// read distance to anchorPoint in meters and set anchorAlarm accordingly
			// if ( anchorAlarmOn && (anchorDistance > anchorRadius || !inAnchorBox(gps->gprmc_latitude(),gps->gprmc_longitude()))) {
			if(model->getSignalkValueFloat(NAVIGATION_ANCHOR_CURRENTRADIUS) > model->getSignalkValueFloat(NAVIGATION_ANCHOR_ALARMRADIUS)) {
				//we need to sound alarm
				if (!model->isAlarmTriggered(ALARMS_ANCHORALARMSTATE)) {
					model->setSignalkValue(_ARDUINO_ALARM_SNOOZE,0UL);
					model->setSignalkValue(ALARMS_ANCHORALARMSTATE,AlarmStateType(ALRM_FIRING));
				}
			}else{
				//turn off
				model->setSignalkValue(ALARMS_ANCHORALARMSTATE,AlarmStateType(ALRM_ENABLED));
			}
		}
	}

}

/*Set anchor position*/
void Anchor::setAnchorPoint() {
	model->setSignalkValue(NAVIGATION_ANCHOR_POSITION_LATITUDE,model->getSignalkValueFloat(NAVIGATION_POSITION_LATITUDE));
	model->setSignalkValue(NAVIGATION_ANCHOR_POSITION_LONGITUDE,model->getSignalkValueFloat(NAVIGATION_POSITION_LONGITUDE));
	model->setSignalkValue(NAVIGATION_ANCHOR_MAXRADIUS,0);

}



