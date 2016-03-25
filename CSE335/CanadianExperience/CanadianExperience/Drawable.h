/**
* \file Drawable.h
*
* \author Alex R. Zajac
*
* Drawable Elements
*/

#pragma once

#include <memory>
#include <string>
#include <vector>

class CActor;

/**
* Abstract base class for drawable elements of our picture.
*
* A drawable is one part of an actor. Drawable parts can be moved
* independently.
*/
class CDrawable
{
public:
	virtual ~CDrawable();

	/** Default constructor disabled */
	CDrawable() = delete;
	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;

	void SetActor(CActor *actor);

	/** Virtual function for draw 
	* \param graphics Graphics context is drawn*/
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;

	void Place(Gdiplus::Point offset, double rotate);
	void AddChild(std::shared_ptr<CDrawable> child);

	/** Virtual function for hit test 
	* \param pos Position to test for a hit
	* \return The bool of the result*/
	virtual bool HitTest(Gdiplus::Point pos) = 0;

	/** Virtual function for is movable 
	* \returns false */
	virtual bool IsMovable() { return false; }

	void Move(Gdiplus::Point delta);

	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }

	/** Set the parent of the child
	* \param parent The parent of the child*/
	void SetParent(CDrawable* parent) { mParent = parent; }

	/** Gets the parent of the child
	* \returns The parent of the child*/
	CDrawable* GetParent(){ return mParent; }

protected:
	CDrawable(const std::wstring &name);
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);


	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor using this drawable
	CActor *mActor = nullptr;

	/// The Parent
	CDrawable *mParent;

	/// THe children the parent holds
	std::vector<std::shared_ptr<CDrawable>> mChildren;
};
