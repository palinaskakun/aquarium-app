/**
 * @file Fish.h
 * @author Palina Skakun
 *
 * Base class for fish
 */
#include "Item.h"
#include "Aquarium.h"

#ifndef AQUARIUM_AQUARIUMLIB_FISH_H
#define AQUARIUM_AQUARIUMLIB_FISH_H

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:
	/// Fish speed in the X direction
	/// in pixels per second
	double mSpeedX;

	/// Fish speed in the Y direction
	/// in pixels per second
	double mSpeedY;

public:
	/// Default constructor (disabled)
	Fish() = delete;

	/// Copy constructor (disabled)
	Fish(const Fish &) = delete;


/// Assignment operator
	void operator=(const Fish &) = delete;
	void Update(double elapsed);

protected:
	Fish(Aquarium *aquarium, const std::wstring &filename);
};

#endif //AQUARIUM_AQUARIUMLIB_FISH_H
