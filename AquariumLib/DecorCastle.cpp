/**
 * @file DecorCastle.cpp
 * @author Palina Skakun
 */

#include "pch.h"
#include "DecorCastle.h"

using namespace std;

#include "Aquarium.h"

/// Fish filename
const wstring DecorCastleImageName = L"images/castle.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorCastleImageName)
{
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"type", L"castle");
	return itemNode;
}