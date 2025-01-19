/**
 * @file Dory.cpp
 * @author Palina Skakun
 */

#include "pch.h"
#include "Dory.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring DoryImageName = L"images/dory.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
Dory::Dory(Aquarium *aquarium) : Fish(aquarium, DoryImageName)
{

}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Dory::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"type", L"dory");
	return itemNode;
}


