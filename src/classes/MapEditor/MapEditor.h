#ifndef COMP345A1_MAPEDITOR_H
#define COMP345A1_MAPEDITOR_H

#include <iostream>
#include "../Map/Map.h"
#include "../Campaign/Campaign.h"


class MapEditor {
public:
    MapEditor(); // Constructor
    ~MapEditor(); // Destructor
    void runEditor();
    void runMapEditor();
    void runCampaignEditor();

private:
    Map* map; // Pointer to a Map object

    Campaign* campaign;

    // Function to create a new map
    void createNewMap();
    void createNewCampaign();

    // Function to edit the map
    void editMap();
    void editCampaign();
    void editMapInCampaign(int mapIndex);
    void addNewMapToCampaign();

    // Function to parse user input
    bool parseInput(const std::string& input, int& x, int& y, char& item);

    // Function to save the map to a file
    void saveMapToFile();
    void saveCampaignToFile();

    // Function to load map from a file
    void loadMapFromFile();
    void loadCampaignFromFile();

    //deallocates memory for the current map and sets the map pointer to nullptr, effectively clearing the current map. This function is called when the user chooses to return to the main menu
    void clearMap();

    void clearCampaign();
};

#endif //COMP345A1_MAPEDITOR_H
