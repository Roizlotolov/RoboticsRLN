/*
 * Behavior.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot) {
	// TODO Auto-generated constructor stub
	_next = NULL;
	_arrSize = 0;
	_robot = robot;
}
Behavior* Behavior::addNext(Behavior* beh)
{
	int i;
	Behavior** tmp = new Behavior*[_arrSize+1];
	if(!tmp)
		return NULL;
	for(i=0;i<_arrSize;i++)
		tmp[i] = _next[i];
	tmp[i] = beh;
	delete []_next;
	_next=tmp;
	_arrSize++;
	return this;
}
Behavior* Behavior::selectNext()
{
	int i;
	for(i=0;i<_arrSize;i++)
		if(_next[i]->startCond())
			return _next[i];

	return NULL;
}
Behavior::~Behavior() {
	// TODO Auto-generated destructor stub
	delete [] _next;
}
