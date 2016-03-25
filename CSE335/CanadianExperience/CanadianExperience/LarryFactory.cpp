/**
* \file LarryFactory.cpp
*
* \author Alex R. Zajac
*/

#include "stdafx.h"
#include "LarryFactory.h"
#include "PolyDrawable.h"
#include"ImageDrawable.h"
#include "HeadTop.h"
using namespace std;
using namespace Gdiplus;

CLarryFactory::CLarryFactory()
{
}


CLarryFactory::~CLarryFactory()
{
}

/** This is a concrete factory method that creates our Larry actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CLarryFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Larry");

	auto shirt = make_shared<CImageDrawable>(L"Shirt", L"images/black_coat.png");
	shirt->SetCenter(Point(44, 138));
	shirt->SetPosition(Point(0, -114));
	actor->SetRoot(shirt);
	
	auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/lleg2.png");
	lleg->SetCenter(Point(11, 9));
	lleg->SetPosition(Point(27, 0));
	shirt->AddChild(lleg);

	auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/rleg2.png");
	rleg->SetCenter(Point(39, 9));
	rleg->SetPosition(Point(-27, 0));
	shirt->AddChild(rleg);

	auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/headb3.png");
	headb->SetCenter(Point(44, 31));
	headb->SetPosition(Point(0, -130));
	shirt->AddChild(headb);

	auto headt = make_shared<CHeadTop>(L"Head Top", L"images/headt3.png");
	headt->SetCenter(Point(48, 93));
	headt->SetPosition(Point(0, -31));
	headt->AddToPoints(Point(24, 44)); //left eyebrow start
	headt->AddToPoints(Point(40, 40)); //left eyebrow finish
	headt->AddToPoints(Point(56, 40)); //right eyebrow start
	headt->AddToPoints(Point(72, 44)); //right eyebrow finish
	headt->AddToPoints(Point(35, 60)); //left eye center
	headt->AddToPoints(Point(61, 60)); //right eye center
	headb->AddChild(headt);

	auto larm = make_shared<CPolyDrawable>(L"Left Arm");
	larm->SetColor(Color::Black);
	larm->SetPosition(Point(50, -130));
	larm->AddPoint(Point(-7, -7));
	larm->AddPoint(Point(-7, 96));
	larm->AddPoint(Point(8, 96));
	larm->AddPoint(Point(8, -7));
	shirt->AddChild(larm);


	auto rarm = make_shared<CPolyDrawable>(L"Right Arm");
	rarm->SetColor(Color::Black);
	rarm->SetPosition(Point(-45, -130));
	rarm->AddPoint(Point(-7, -7));
	rarm->AddPoint(Point(-7, 96));
	rarm->AddPoint(Point(8, 96));
	rarm->AddPoint(Point(8, -7));
	shirt->AddChild(rarm);

	auto lhand = make_shared<CPolyDrawable>(L"Left Hand");
	lhand->SetColor(Color(253, 218, 180));
	lhand->SetPosition(Point(0, 96));
	lhand->AddPoint(Point(-12, -2));
	lhand->AddPoint(Point(-12, 17));
	lhand->AddPoint(Point(11, 17));
	lhand->AddPoint(Point(11, -2));
	larm->AddChild(lhand);

	auto rhand = make_shared<CPolyDrawable>(L"Right Hand");
	rhand->SetColor(Color(253, 218, 180));
	rhand->SetPosition(Point(0, 96));
	rhand->AddPoint(Point(-12, -2));
	rhand->AddPoint(Point(-12, 17));
	rhand->AddPoint(Point(11, 17));
	rhand->AddPoint(Point(11, -2));
	rarm->AddChild(rhand);


	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rhand);
	actor->AddDrawable(lhand);
	actor->AddDrawable(rleg);
	actor->AddDrawable(lleg);
	actor->AddDrawable(shirt);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);

	return actor;
}
