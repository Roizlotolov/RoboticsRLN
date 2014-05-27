/*
 * GoForward.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef GOFORWARD_H_
#define GOFORWARD_H_

#include <iostream>
#include "Behavior.h"
#include "../Robot.h"
class GoForward: public Behavior {
public:
	GoForward(Robot* robot);
	bool startCond();
	bool stopCond();
	void action();
	virtual ~GoForward();
	static const float FAST_FORWARD_SPEED = 0.5;
	static const float SLOW_FORWARD_SPEED = 0.5;
	static const float MIN_FORWARD_DISTANCE = 0.8;
	static const float FAST_FORWARD_DISTANCE = 3.0;
	static const float CLEAR_FORWARD_SLICE = 0.1;

	static bool IsWayForwardClear(Robot* robot, float distance, float slice)
	{
		for (int i = (Robot::LASER_SPREAD / 2 - Robot::LASER_SPREAD * slice); i < (Robot::LASER_SPREAD / 2 + Robot::LASER_SPREAD * slice); i++)
			{
				if (robot->getLaserDistance(i) < distance)
				{
					std::cout << "Obstacle spotted at " << i << " distance " << robot->getLaserDistance(i) << std::endl;
					return false;
				}
			}
			return true;
	}
};

#endif /* GOFORWARD_H_ */
