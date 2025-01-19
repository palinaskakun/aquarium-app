/**
 * @file Nemo.cpp
 * @author Palina Skakun
 *
 */
 
#include "pch.h"
#include "Nemo.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring NemoImageName = L"images/nemo.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
Nemo::Nemo(Aquarium *aquarium) : Fish (aquarium, NemoImageName)
{

}

wxXmlNode* Nemo::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"type", L"nemo");
	return itemNode;
}

