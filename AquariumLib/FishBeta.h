/**
 * @file FishBeta.h
 * @author Palina Skakun
 *
 * Class that describes beta fish
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for a fish of type Beta
 */
class FishBeta : public Fish {
private:



public:
	/// Default constructor (disabled)
	FishBeta() = delete;

	/// Copy constructor (disabled)
	FishBeta(const FishBeta &) = delete;

	FishBeta(Aquarium *aquarium);
	/// Assignment operator
	void operator=(const FishBeta &) = delete;

	wxXmlNode *XmlSave(wxXmlNode *node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H
