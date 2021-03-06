/*
 * GoForward.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"
#include "../Robot.h"
class TurnRight: public Behavior {
public:
	TurnRight(Robot* robot);
	bool startCond();
	bool stopCond();
	void action();
	virtual ~TurnRight();
};

#endif /* TurnRight_H_ */
