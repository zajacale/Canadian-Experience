/**
* \file HeadTop.h
*
* \author Alex R. Zajac
*
* The top part of the head
*/

#include "ImageDrawable.h"

#include <string>
using namespace std;

#pragma once
class CDrawable;

/** The top part of the head */
class CHeadTop : public CImageDrawable
{
public:

	CHeadTop(const std::wstring &name, const std::wstring &filename);
	
	/** Default constructor disabled */
	CHeadTop() = delete;
	/** Copy Constructor (Disabled) */
	CHeadTop(const CHeadTop &) = delete;
	/** Assignment Operator (Disabled) 
	* \returns CHeadTop*/
	CHeadTop &operator=(const CHeadTop &) = delete;

	virtual ~CHeadTop();

	/** Virtual function for draw
	* \param graphics Graphics context is drawn*/
	void Draw(Gdiplus::Graphics *graphics) override;

	/** Virtual function for is movable
	* \returns The false*/
	virtual bool IsMovable() override { return true; }

	/** Adds a point to the facial features vector
	* \param point The point of the facial feature*/
	void AddToPoints(Gdiplus::Point point){ mPoints.push_back(point); }

	Gdiplus::Point TransformPoint(Gdiplus::Point p);
	void DrawEyebrow(Point p1, Point p2, Gdiplus::Graphics *graphics);
	void DrawEye(Point p1, Gdiplus::Graphics *graphics);

private:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;

	/// A vector filled with points for the eyes and eyebrows
	std::vector<Gdiplus::Point> mPoints;
};

