/*
 * PlnObstacleAvoid.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef PLNOBSTACLEAVOID_H_
#define PLNOBSTACLEAVOID_H_

#include "Plan.h"
#include "Behaviours/GoForward.h"
#include "Behaviours/TurnLeft.h"
#include "Behaviours/TurnRight.h"

class PlnObstacleAvoid: public Plan {
public:
	PlnObstacleAvoid(Robot* robot);
	 Behavior* startPoint();
	virtual ~PlnObstacleAvoid();
};

#endif /* PLNOBSTACLEAVOID_H_ */
