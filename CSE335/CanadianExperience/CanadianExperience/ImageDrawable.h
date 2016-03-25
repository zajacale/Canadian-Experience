/**
* \file ImageDrawable.h
*
* \author Alex R. Zajac
*
* Images for drawing
*/
#include "Drawable.h"
#include <memory>
using namespace std;
using namespace Gdiplus;
#pragma once


/** The images for the drawable class*/
class CImageDrawable : public CDrawable
{
public:

	CImageDrawable(const std::wstring &name, const std::wstring &filename);
	/** Default constructor disabled */
	CImageDrawable() = delete;
	/** Copy constructor disabled */
	CImageDrawable(const CImageDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CImageDrawable &) = delete;
	virtual ~CImageDrawable();

	void Draw(Gdiplus::Graphics *graphics);

	bool HitTest(Gdiplus::Point pos);

	/** The image center
	* \return center The new image center */
	Gdiplus::Point GetCenter() { return mCenter; }

	/** The image center
	* \param point The new image center */
	void SetCenter(Gdiplus::Point point){ mCenter = point; }

private:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;

	/// The center of the image
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

