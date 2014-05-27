/*
 * Manager.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Manager.h"

Manager::Manager(Robot* robot, Plan* plan)
{
	_robot = robot;
	_plan = plan;
	_curr = plan->startPoint();
	// TODO Auto-generated constructor stub

}
void Manager::run()
{
	_robot->read();
	if(_curr->startCond() == false)
	{
		std::cout << "Manager failed to start initial behaviour" << std::endl;
		return;
	}

	_curr->action();
	while(true)
	{
		_robot->read();
		if(_curr->stopCond())
		{
			std::cout << "Manager moved to next behaviour" << std::endl;
			_curr = _curr->selectNext();
			if(!_curr)
			{
				break;
			}
		}
		_curr->action();
	}

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}
