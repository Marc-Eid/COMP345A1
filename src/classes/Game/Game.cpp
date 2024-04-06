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
                if(campaign1 != nullptr){
                    campaign = campaign1;
                    continue;
                }
            }
            case 3: {
                if(campaign == nullptr){
                    cout << "You haven't selected any Campaign Yet" << endl;
                    continue;
                }
                else{
                    return true;
                }

            }
            case 4 : {
                return false;
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
    bool campaignSet = getCampaign();
    if(campaignSet){
        // ALL THE LOGIC OF SELECTING THE CHARACTER
        CharacterEditor characterEditor;
        Character* pCharacter = characterEditor.runCharacterEditor();
        if(pCharacter != nullptr){
            // Gameplay Logic
            cout << "-----------------------------------------------\n";
            cout << "Welcome DND WORLD\n";
            cout << "-----------------------------------------------";

            cout << "camp";
            campaign->printCampaign();
            cout << "camp1";
            // placing the character on the game
            campaign->maps[0]->placeCharacter(pCharacter);


            campaign->playCampaign();

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
