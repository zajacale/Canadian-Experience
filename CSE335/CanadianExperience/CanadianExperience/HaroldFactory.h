/**
* \file HaroldFactory.h
*
* \author Alex R. Zajac
*
* Factory class that builds the Harold character
*/

#include <memory>
#include "ActorFactory.h"
#include "Actor.h"

#pragma once


/** Factory class that builds the Harold character*/
class CHaroldFactory: public CActorFactory
{
public:
	CHaroldFactory();
	virtual ~CHaroldFactory();

	std::shared_ptr<CActor> Create();
};

