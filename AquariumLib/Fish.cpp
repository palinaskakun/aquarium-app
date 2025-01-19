/**
 * @file Fish.cpp
 * @author Palina Skakun
 */
#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"
#include "Item.h"


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
	Item(aquarium, filename)
{
	std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
	mSpeedX = distribution(aquarium->GetRandom());
	mSpeedY = 0;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);

	const int pixelsFromEnd = 10;

	if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth() - pixelsFromEnd - GetItemWidth()/2)
	{
		mSpeedX = -mSpeedX;
		SetMirror(true);
	}
	else if (GetX() <= 0 + pixelsFromEnd + GetItemWidth()/2 && mSpeedX < 0)
	{
		mSpeedX = -(mSpeedX);
		SetMirror(false);
	}
}