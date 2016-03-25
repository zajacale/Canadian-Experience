/**
* \file Actor.h
*
* \author Alex R. Zajac
*
* The program actors
*/

#pragma once
#include <string>
#include <memory>
#include <vector>

class CPicture;
class CDrawable;

/**
* Class for actors in our drawings.
*
* An actor is some graphical object that consists of
* one or more parts. Actors can be animated.
*/
class CActor
{
public:
	CActor(const std::wstring &name);

	/** Default constructor disabled */
	CActor() = delete;
	/** Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;

	virtual ~CActor();

	void SetRoot(std::shared_ptr<CDrawable> root);
	void Draw(Gdiplus::Graphics *graphics);
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** Get the actor name
	* \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }

	/** Actor picture setter
	* \param picture Picture Actor belongs to */
	void SetPicture(CPicture *picture){ mPicture = picture; };

	/** Actor picture getter
	* \return mPicture Picture Actor belongs to */
	CPicture* GetPicture(){ return mPicture; };

private:
	/// Actor name
	std::wstring mName;

	/// Actor is enabled
	bool mEnabled = true;

	/// Position of the actor
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// Is the actor clickable
	bool mClickable = true;

	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;

	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

	/// The picture the actor belongs to
	CPicture *mPicture;
};

