/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "TurnRight.h"

TurnRight::TurnRight(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}
bool TurnRight::startCond()
{
	if(_robot->getLaserDistance(333) > 0.8)
		return true;
	return false;
}
void TurnRight::action()
{
	if(_robot->getLaserDistance(333) > 3.0)
		_robot->setSpeed(1.0,0.0);
	else
		_robot->setSpeed(0.5,0.0);
}
bool TurnRight::stopCond()
{
	if(_robot->getLaserDistance(333) < 0.8)
		return true;
	return false;
}
TurnRight::~TurnRight() {
	// TODO Auto-generated destructor stub
}
