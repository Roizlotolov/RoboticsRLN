/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}
bool TurnLeft::startCond()
{
	std::cout << "Starting turn left behaviour" << std::endl;
	return true;
}
void TurnLeft::action()
{
	_robot->setSpeed(0, TURN_SPEED);
}
bool TurnLeft::stopCond()
{
	if(GoForward::IsWayForwardClear(_robot, GoForward::MIN_FORWARD_DISTANCE, GoForward::CLEAR_FORWARD_SLICE))
	{
		std::cout << "Ending turn left behaviour" << std::endl;
		return true;
	}
	return false;
}
TurnLeft::~TurnLeft() {
	// TODO Auto-generated destructor stub
}
