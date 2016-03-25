/**
* \file PolyDrawable.h
*
* \author Alex R. Zajac
*
* Drawable polygon images
*/

#pragma once

#include "Drawable.h"

#include <string>
#include <vector>


/**
* A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
*/
class CPolyDrawable : public CDrawable
{
public:

	CPolyDrawable(const std::wstring &name);

	/** Default constructor disabled */
	CPolyDrawable() = delete;
	/** Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;
	virtual ~CPolyDrawable();


	void Draw(Gdiplus::Graphics *graphics);
	bool HitTest(Gdiplus::Point point);
	void AddPoint(Gdiplus::Point point);

	/** Set the color
	* \param color The color of the polygon*/
	void SetColor(Gdiplus::Color color){ mColor = color; };

	/** Get the color
	* \returns The color of the polygon*/
	Gdiplus::Color GetColor() { return mColor; };

private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;

	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
};

