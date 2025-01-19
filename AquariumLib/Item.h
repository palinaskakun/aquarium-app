/**
 * @file Item.h
 * @author Palina Skakun
 *
 * Class that describes Items in aquarium
 */

#ifndef AQUARIUM_AQUARIUMLIB_ITEM_H
#define AQUARIUM_AQUARIUMLIB_ITEM_H

#include <wx/xml/xml.h>
class Aquarium; // forward reference

/**
 * Base class for any item in our aquarium.
 */
class Item {
private:
	/// The aquarium this item is contained in
	Aquarium   *mAquarium;
	/// The underlying fish image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap we can display for this fish
	std::unique_ptr<wxBitmap> mItemBitmap;

	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
	bool mMirror = false;   ///< True mirrors the item image

public:

	/// Default constructor (disabled)
	Item() = delete;
	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	~Item();
	/// Assignment operator
	void operator=(const Item &) = delete;

	/**
     * The X location of the item
     * @return X location in pixels
     */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	/**
     * Draw this item
     * @param dc Device context to draw on
     */
	virtual void Draw(wxDC *dc);


	virtual bool HitTest(int x, int y);
	/**
	 * Getter for aquarium.
	 * @return Aquarium
	 */
	Aquarium *GetAquarium() { return mAquarium;  }

	virtual wxXmlNode *XmlSave(wxXmlNode *node);

	virtual void XmlLoad(wxXmlNode *node);

	/**
     * Handle updates for animation.
     * @param elapsed The time since the last update
     */
	virtual void Update(double elapsed) {}

	void SetMirror(bool m);

	/**
     * Getter for the height of the item.
     * @return Height
     */
	double GetItemHeight() const { return mItemBitmap->GetHeight(); }

	/**
     * Getter for the width of the item.
     * @return Width (pixels)
     */
	double GetItemWidth() const { return mItemBitmap->GetWidth();}


protected:

	Item(Aquarium *aquarium, const std::wstring &filename);


};

#endif //AQUARIUM_AQUARIUMLIB_ITEM_H
