/**
* \file LarryFactory.h
*
* \author Alex R. Zajac
*
* Factory class that builds the Larry character
*/

#include <memory>
#include "ActorFactory.h"
#include "Actor.h"

#pragma once


/** Factory class that builds the Larry character*/
class CLarryFactory : public CActorFactory
{
public:
	CLarryFactory();
	virtual ~CLarryFactory();

	std::shared_ptr<CActor> Create();
};

