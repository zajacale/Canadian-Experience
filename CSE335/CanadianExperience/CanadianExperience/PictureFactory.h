/**
* \file PictureFactory.h
*
* \author Alex R. Zajac
*
* Builds our picture
*/

#include "Picture.h"
#include <memory>
#pragma once

/**
* A factory class that builds our picture.
*/
class CPictureFactory
{
public:
	CPictureFactory();
	virtual ~CPictureFactory();

	std::shared_ptr<CPicture> Create();
};