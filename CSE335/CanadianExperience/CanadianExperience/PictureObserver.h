/**
* \file PictureObserver.h
*
* \author Alex R. Zajac
*
* Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
*/
#include <memory>

#pragma once

class CPicture;

/** The picture observer */
class CPictureObserver
{
public:
	virtual ~CPictureObserver();

	//! Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	//! Assignment Operator (Disabled)
	CPictureObserver &operator=(const CPictureObserver &) = delete;

	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;

	/** Getter for the Picture
	* \returns The picture the observer is on*/
	std::shared_ptr<CPicture> GetPicture(){ return mPicture; }

	void SetPicture(std::shared_ptr<CPicture> picture);


protected:
	CPictureObserver();

private:
	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;


};

