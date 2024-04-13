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
                campaign =loadPregeneratedCampaign();
                campaign->printCampaign();
                break;
            }
            case 2: {
                MapEditor *mapEditor = new MapEditor();
                campaign = mapEditor->runCampaignEditor();
                campaign->printCampaign();
                return true;
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
        //Character* npc1 =characterEditor.runNpcEditor();
        //campaign->maps[pCharacter->currentMap]->placeOpponent(npc1, 5, 5);
        if(pCharacter != nullptr){
            // Gameplay Logic
            cout << "-----------------------------------------------\n";
            cout << "Welcome to DND WORLD\n";
            cout << "-----------------------------------------------";
            bool gameIsRunning = true;
            campaign->printCampaign();
            campaign->maps[pCharacter->currentMap]->placeCharacter(pCharacter);
                while(gameIsRunning){
                    campaign->maps[pCharacter->currentMap]->getAllCharacters();
                    vector<Character*> characters = campaign->maps[pCharacter->currentMap]->getAllCharacters();
                    characters = initiativeRoll(characters);
                    for(auto* character : characters) {
                        cout << "\n------------------------------" << endl;
                        cout << character->getName() << "'s play turn" << endl;
                        cout << "------------------------------" << endl;
                        if (character->strategy->getStrategyType() == "Human"){
                            bool playerTurn = true;
                            bool moved = false;
                            bool attacked = false;
                            while (playerTurn) {
                                int input;
                                cout << "\nChoose an option:" << endl;
                                cout << "1: Move" << endl;
                                cout << "2: Attack" << endl;
                                cout << "3: Perform Action" << endl;
                                cout << "4: Wear Items" << endl;
                                cout << "5: Check Your Character Sheet"<< endl;
                                cout << "6: Quit" << endl;
                                cout << "Enter option: ";
                                cin >> input;

                                switch (input) {
                                    case 1: {
                                        if (!moved) {
                                            character->move(campaign->maps[pCharacter->currentMap]);
                                            moved = true;
                                        }
                                        else{
                                            cout << "You have already moved this round.\n";
                                        }
                                        break;
                                    }
                                    case 2: {
                                        if (!attacked) {
                                            character->attack(campaign->maps[pCharacter->currentMap]);
                                            attacked = true;
                                        }
                                        else{
                                            cout << "You have already attacked this round.\n";
                                        }
                                        break;
                                    }
                                    case 3: {
                                        character->freeAction(campaign->maps[pCharacter->currentMap]);
                                        break;
                                    }
                                    case 4 : {
                                        characterEditor.updateWornItemEditor(pCharacter);
                                        break;
                                    }
                                    case 5 : {
                                        character->displayCharacterSheet();
                                        break;
                                    }
                                    case 6: {

                                        playerTurn = false;
                                        break;
                                    }
                                    default: {
                                        cout << "Invalid option. Please try again." << endl;
                                        continue;
                                    }
                                }
                            }
                        }
                        else{
                            character->move(campaign->maps[pCharacter->currentMap]);
                            character->attack(campaign->maps[pCharacter->currentMap]);
                        }
                    }
                }
        }
    }
    else{
        cout << "Thank you for Playing !";
    }
}

Campaign* Game::loadPregeneratedCampaign() {

    while (true){
        int input;
        cout << "\nChoose the Campaign You want to Play: -1 to exit" << endl;
        cout << "1: The Kingdoms of Thaloria" << endl;
        cin >>input;
        switch (input) {
            case 1 : {
                MapEditor* mapEditor = new MapEditor();
                Campaign* camp = mapEditor->runCampaignEditor("pre-generated");
                camp->printCampaign();
                return camp;
            }
            case -1 : {
                return nullptr;
            }
            default: {
                cout << "Error";
                continue;
            };
        }


    }
    return nullptr ;
}

vector<Character*> Game::initiativeRoll(vector<Character*> chars) {
    cout << "Initiative Roll for the all the players" << endl;

    std::map<int,Character*> map ;
    vector<Character*> sorted_array;
    Dice dice;
    for(auto & i : chars){
        map[dice.roll("1d20")] =i ;
    }

    for (auto it = map.rbegin(); it != map.rend(); ++it) {
        sorted_array.push_back(it->second);
    }


    cout << "Order of Characters :";
    for(auto & i : sorted_array){
     cout << i->getName() << ", ";
    }
    return sorted_array;

}
