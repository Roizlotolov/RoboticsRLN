/*
 * PlnObstacleAvoid.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "PlnObstacleAvoid.h"

PlnObstacleAvoid::PlnObstacleAvoid(Robot* robot):Plan(robot) {
	// TODO Auto-generated constructor stub

	//Creating behaviors
	_behArr = new Behavior*[2];
	_behArr[0] = new GoForward(_robot);
	_behArr[1] = new TurnLeft(_robot);
	//_behArr[2] = new TurnRight(_robot);

	//Connecting behaviors
	_behArr[0]->addNext(_behArr[1]);//->addNext(_behArr[2]);
	_behArr[1]->addNext(_behArr[0]);
	//_behArr[2]->addNext(_behArr[1]);

	_starBeh = _behArr[0];
}

Behavior* PlnObstacleAvoid::startPoint()
{
	return _starBeh;
}

PlnObstacleAvoid::~PlnObstacleAvoid() {
	// TODO Auto-generated destructor stub
	delete _behArr[0];
	delete _behArr[1];
	delete[] _behArr;
}
