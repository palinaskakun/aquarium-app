/**
 * @file DecorCastle.h
 * @author Palina Skakun
 *
 * Class that describes an aquarium decoration - a castle
 */

#ifndef AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
#define AQUARIUM_AQUARIUMLIB_DECORCASTLE_H

#include "Item.h"
class DecorCastle: public Item {
private:

public:
	/// Default constructor (disabled)
	DecorCastle() = delete;

	/// Copy constructor (disabled)
	DecorCastle(const DecorCastle &) = delete;

	DecorCastle(Aquarium *aquarium);
	/// Assignment operator
	void operator=(const DecorCastle &) = delete;

	wxXmlNode *XmlSave(wxXmlNode *node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
