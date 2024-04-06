//
// Created by hp on 01/04/2024.
//

#include "Game.h"

bool Game::getCampaign() {

    while (true) {
        int input;
        cout << "\nChoose an option:" << endl;
        cout << "1: Use Pre-generated Campaigns" << endl;
        cout << "2: Create/Load campaign" << endl;
        cout << "3: Continue" << endl;
        cout << "4: Quit" << endl;
        cout << "Enter option: ";
        cin >> input;

        switch (input) {
            case 1: {
                // TBD Load Pre-generated Campaign
                loadPregeneratedCampaign();
                break;
            }
            case 2: {
                MapEditor mapEditor;
                Campaign* campaign1 = mapEditor.runCampaignEditor();
                campaign1->printCampaign();
                campaign = campaign1;
                break;
            }
            case 3: {
                if(campaign == nullptr){
                    cout << "You haven't selected any Campaign Yet" << endl;
                }
                return false;
            }
            case 4 : {
                return false;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
        // If map is not initialized, continue to the next iteration
        return true;
    }
}

void Game::play()
{
    cout << "-----------------------------------------------\n";
    cout << "Welcome to the Dungeon and Dragon : Basic Fantasy RPG\n";
    cout << "-----------------------------------------------";
    bool campaignSet = getCampaign();
    if(campaignSet == true){
        // ALL THE LOGIC OF SELECTING THE CHARACTER


    }
    else{
        cout << "Thank you for Playing !";
    }

}

bool Game::loadPregeneratedCampaign() {
    return true ;
}
