/**
* \file HeadTop.cpp
*
* \author Alex R. Zajac
*/

#include "stdafx.h"
#include "HeadTop.h"


/** Constructor
* \param name The drawable name
* \param filename The filename for the image */
CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename) : 
CImageDrawable(name, filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/** Destructor */
CHeadTop::~CHeadTop()
{
}

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;
/**
* Draw the head top drawable
* \param graphics Graphics context to draw on
*/
void CHeadTop::Draw(Gdiplus::Graphics *graphics)
{
	/// Calls the original verison
	CImageDrawable::Draw(graphics);

	// Draws the left and right eyebrow
	DrawEyebrow(mPoints[0], mPoints[1], graphics);
	DrawEyebrow(mPoints[2], mPoints[3], graphics);

	// Draws the left and right eye
	DrawEye(mPoints[4], graphics);
	DrawEye(mPoints[5], graphics);

}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/** Draws the eyebrow onto Head Top
* \param  p1 Point to start
* \param  p2 Point to finish
* \param graphics Graphics context to draw on
*/
void CHeadTop::DrawEyebrow(Point p1, Point p2, Gdiplus::Graphics *graphics)
{
	Gdiplus::Point start = TransformPoint(p1);
	Gdiplus::Point finish = TransformPoint(p2);

	Pen eyebrowPen(Color::Black, 2);
	graphics->DrawLine(&eyebrowPen, start, finish);
}

/** Draws the eyebrow onto Head Top
* \param  p1 Point to finish
* \param graphics Graphics context to draw on
*/
void CHeadTop::DrawEye(Point p1, Gdiplus::Graphics *graphics)
{
	float wid = 12.5f;
	float hit = 20.0f;

	Gdiplus::Point center = TransformPoint(p1);

	SolidBrush brush(Color::Black);
	auto state = graphics->Save();
	graphics->TranslateTransform(center.X, center.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
}