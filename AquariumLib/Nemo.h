/**
 * @file Nemo.h
 * @author Palina Skakun
 *
 * Class that creates Nemo as another fish.
 */

#ifndef AQUARIUM_AQUARIUMLIB_NEMO_H
#define AQUARIUM_AQUARIUMLIB_NEMO_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for a fish of type Nemo
 */
 
class Nemo: public Fish {
private:


public:
	/// Default constructor (disabled)
	Nemo() = delete;

	/// Copy constructor (disabled)
	Nemo(const Nemo &) = delete;

	Nemo(Aquarium *aquarium);
	/// Assignment operator
	void operator=(const Nemo &) = delete;

	wxXmlNode *XmlSave(wxXmlNode *node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_NEMO_H
