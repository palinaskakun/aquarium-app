/**
 * @file AquariumApp.h
 * @author Palina Skakun
 *
 * Main application class
 */

#ifndef AQUARIUM__AQUARIUMAPP_H
#define AQUARIUM__AQUARIUMAPP_H
#include <wx/wx.h>

/**
 * Main application class
 */
class AquariumApp  : public wxApp {
private:

public:
	bool OnInit() override;

};

#endif //AQUARIUM__AQUARIUMAPP_H
