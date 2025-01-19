
/**
 * @file Aquarium.h
 * @author Palina Skakun
 *
 * Class for aquarium background
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUM_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUM_H

#include<memory>
#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <random>

class Item;

/**
 * The main aquarium class.
 */
class Aquarium
{
private:
	std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<Item>> mItems;

	/// Random number generator
	std::mt19937 mRandom;

public:
	Aquarium();

	void OnDraw(wxDC *dc);

	void Add(std::shared_ptr<Item> item);
	std::shared_ptr<Item> HitTest(int x, int y);
	void EditList(std::shared_ptr<Item> item);
	void Save(const wxString &filename);

	void Load(const wxString &filename);
	void Clear();
	void XmlItem(wxXmlNode *node);

	void Update(double elapsed);

	/**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
	std::mt19937 &GetRandom() {return mRandom;}

	/**
     * Get the width of the aquarium
     * @return Aquarium width in pixels
     */
	int GetWidth() const { return mBackground->GetWidth(); }

	/**
	 * Get the height of the aquarium
	 * @return Aquarium height in pixels
	 */
	int GetHeight() const { return mBackground->GetHeight(); }
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUM_H
