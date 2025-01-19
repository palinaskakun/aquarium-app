/**
 * @file Dory.h
 * @author Palina Skakun
 *
 * Class that creates Dory as another fish.
 */

#ifndef AQUARIUM_AQUARIUMLIB_DORY_H
#define AQUARIUM_AQUARIUMLIB_DORY_H

#include "Item.h"
#include "Fish.h"
/**
 * Class for a fish of type Dory
 */

class Dory: public Fish {
private:


public:
	/// Default constructor (disabled)
	Dory() = delete;

	/// Copy constructor (disabled)
	Dory(const Dory &) = delete;

	Dory(Aquarium *aquarium);
	/// Assignment operator
	void operator=(const Dory &) = delete;

	wxXmlNode *XmlSave(wxXmlNode *node) override;
};


#endif //AQUARIUM_AQUARIUMLIB_DORY_H
