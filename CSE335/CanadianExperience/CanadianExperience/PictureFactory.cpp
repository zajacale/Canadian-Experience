/**
* \file PolyDrawable.cpp
*
* \author Alex R. Zajac
*/

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "LarryFactory.h"
#include "ImageDrawable.h"
#include<memory>

using namespace std;
using namespace Gdiplus;


CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}

/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
	shared_ptr<CPicture> picture = make_shared<CPicture>();

	// Create the background and add it
	auto background = make_shared<CActor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(Point(-100, 0));
	auto backgroundI =
		make_shared<CImageDrawable>(L"Background", L"images/Background.png");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);

	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(400, 500));

	picture->AddActor(harold);

	// Create and add Larry
	CLarryFactory larryfactory;
	auto larry = larryfactory.Create();

	// This is where Harold will start out.
	larry->SetPosition(Point(200, 500));

	picture->AddActor(larry);

	return picture;
}
