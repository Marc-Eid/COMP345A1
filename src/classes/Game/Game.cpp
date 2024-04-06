//
// Created by hp on 01/04/2024.
//

#include "Game.h"

Campaign* Game::getCampaign() {

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
                // TODO Load Pre-generated Campaign
                loadPregeneratedCampaign();
                break;
            }
            case 2: {
                MapEditor *mapEditor = new MapEditor();
                Campaign* campaign1 = mapEditor->runCampaignEditor();
                if(campaign1 != nullptr){
                    campaign1->printCampaign();
                    this->campaign = campaign1;
                    this->campaign->printCampaign();
                    return campaign1;
                }
                break;
            }
            case 3: {
                if(campaign == nullptr){
                    cout << "You haven't selected any Campaign Yet" << endl;
                    continue;
                }
                else{
                    this->campaign->printCampaign();
                    return campaign;
                }

            }
            case 4 : {
                return nullptr;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                continue;
            }
        }

    }
}

void Game::play()
{
    cout << "-----------------------------------------------\n";
    cout << "Welcome to the Dungeon and Dragon : Basic Fantasy RPG\n";
    cout << "-----------------------------------------------";
    Campaign* campaignSet = getCampaign();
    campaignSet->printCampaign();
    if(campaignSet != nullptr){
        // ALL THE LOGIC OF SELECTING THE CHARACTER
        CharacterEditor *characterEditor = new CharacterEditor();
        Character* pCharacter = characterEditor->runCharacterEditor();
        if(pCharacter != nullptr){
            // Gameplay Logic
            cout << "-----------------------------------------------\n";
            cout << "Welcome DND WORLD\n";
            cout << "-----------------------------------------------";
            // Display the Map
            campaignSet->maps[0]->printMap();

            // Display Character Sheet
            pCharacter->displayCharacterSheet();

            // placing the character on the game
            campaignSet->maps[0]->placeCharacter(pCharacter);


            campaignSet->playCampaign();

        }


    }
    else{
        cout << "Thank you for Playing !";
    }

}

bool Game::loadPregeneratedCampaign() {

    // Load Pre-generated Campaing
    return true ;
}
