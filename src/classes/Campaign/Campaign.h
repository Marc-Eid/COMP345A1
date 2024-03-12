
#ifndef COMP345A1_CAMPAIGN_H
#define COMP345A1_CAMPAIGN_H

#include "../Map/Map.h"

class Campaign {
public:
    Campaign(int initialWidth, int initialHeight);
    ~Campaign();

    void addMap(Map* map);
    void printCampaign();
    bool isValid();
    int getNumMaps();
    Map* getMap(int index);

    // Serialization methods
    friend std::ostream& operator<<(std::ostream& os, const Campaign& campaign);
    friend std::istream& operator>>(std::istream& is, Campaign& campaign);

private:
    Map** maps; // Regular array to store maps
    int numMaps;
};

#endif //COMP345A1_CAMPAIGN_H
