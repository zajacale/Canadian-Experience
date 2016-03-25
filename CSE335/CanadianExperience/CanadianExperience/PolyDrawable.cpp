/**
* \file PolyDrawable.cpp
*
* \author Alex R. Zajac
*/

#include "stdafx.h"
#include "PolyDrawable.h"
#include "Drawable.h"
using namespace Gdiplus;
#include <vector>
using namespace std;


/** Constructor
* \param name The drawable name */
CPolyDrawable::CPolyDrawable(const std::wstring &name) : CDrawable(name)
{
}

/** Destructor */
CPolyDrawable::~CPolyDrawable()
{
}

/** Draw our polygon.
* \param  graphics The graphics context to draw on
*/
void CPolyDrawable::Draw(Gdiplus::Graphics *graphics)
{
	SolidBrush brush(mColor);

	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	graphics->FillPolygon(&brush, &points[0], (int)points.size());
}

/** Test to see if we hit this object with a mouse click
* \param pos Click position
* \returns true it hit
*/
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	GraphicsPath path;
	path.AddPolygon(&points[0], (int)points.size());
	return path.IsVisible(pos) ? true : false;
}

/**
* Adds a point to the vector of points
* \param point Point added to the vector
*/
void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
	mPoints.push_back(point);
}
