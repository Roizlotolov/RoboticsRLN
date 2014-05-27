/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoForward.h"

GoForward::GoForward(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}
bool GoForward::startCond()
{
	if(IsWayForwardClear(_robot, MIN_FORWARD_DISTANCE, CLEAR_FORWARD_SLICE))
	{
		std::cout << "Starting GoForward behaviour" << std::endl;
		return true;
	}
	return false;
}
void GoForward::action()
{
	if(_robot->getLaserDistance(333) > FAST_FORWARD_DISTANCE)
	{
		_robot->setSpeed(FAST_FORWARD_SPEED,0.0);
	}
	else
	{
		_robot->setSpeed(SLOW_FORWARD_SPEED,0.0);
	}
}
bool GoForward::stopCond()
{
	if(!IsWayForwardClear(_robot, MIN_FORWARD_DISTANCE, CLEAR_FORWARD_SLICE))
	{
		std::cout << "Ending GoForward behaviour" << std::endl;
		return true;
	}
	return false;
}

GoForward::~GoForward() {
	// TODO Auto-generated destructor stub
}
