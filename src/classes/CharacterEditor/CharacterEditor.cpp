//
// Created by hp on 30/03/2024.
//

#include "CharacterEditor.h"


void CharacterEditor::runCharacterEditor() {
    int input;
    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1: Create new Character" << endl;
        cout << "2: Quit" << endl;
        cout << "Enter option: ";
        cin >> input;

        switch (input) {
            case 1: {
                createCharacter();
                break;
            }
            case 2: {
                return;
            }
        }
        if(character == nullptr){
            continue;
        }
        else {
            break;
        }
    }
}
/**
 * Initially Character are created with level One with no Wepons
 */
void CharacterEditor::createCharacter() {
    string name ;
    int level = 1;
    int typeOfCharacter;
    // get the name of the character from the User
    cout << "Enter the Name of the New Character :" << endl;
    cin >> name;
    while(true){
        cout << "What Type of Fighter You want to Make" << endl;
        cout << "\nChoose an option:" << endl;
        cout << "1: Nimble" << endl;
        cout << "2: Bully" << endl;
        cout << "3: Fighter" << endl;
        cout << "4: Quit" << endl;
        cout << "Enter option: ";
        cin >> typeOfCharacter;

        switch (typeOfCharacter) {
            case 1: {
                NimbleBuilder *builder = new  NimbleBuilder();
                builder->createFighter(name,level);
                character = builder->getFighter();
                break;
            }
            case 2:{
                BullyBuilder *bullyBuilder = new BullyBuilder();
                bullyBuilder->createFighter(name,level);
                character = bullyBuilder->getFighter();
                break;
            }
            case 3: {
                TankBuilder *tankBuilder = new TankBuilder();
                tankBuilder->createFighter(name,level);
                character = tankBuilder->getFighter();
                break;
            }
            case 4:{
                return;
            }
        }
        if(character != nullptr){
            HumanPlayerStrategy *humanPlayerStrategy = new HumanPlayerStrategy();
            character->setStrategy(humanPlayerStrategy);
            break;
        }
    }

}



/**
 * NPC RELATED CODE
 *
 */
void CharacterEditor::runNpcEditor() {
    int input;
    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1: Create new NPC" << endl;
        cout << "2: Load from a file" << endl;
        cout << "3: Quit" << endl;
        cout << "Enter option: ";
        cin >> input;

        switch (input) {
            case 1: {
                createNpc();
                break;
            }
            case 3 : {
                loadNpc();
                break;
            }
            case 2: {
                return;
            }
        }
        if(character == nullptr){
            continue;
        }
        else {
            break;
        }
    }
}

void CharacterEditor::loadNpc() {

}

void CharacterEditor::createNpc() {
    string name ;
    int typeOfNPC;
    int level = 1;
    int typeOfCharacter;
    // get the name of the character from the User
    cout << "Enter the Name of the New Character :" << endl;
    cin >> name;


    while(true){
        // Loop for level
        while(true){
            cout << "What is the level of the NPC " << endl;
            cin >> level;
            if(level > 0 && level <= 5){
                break;
            }
        }
        // loop to create different strategies
        while(true){
            cout << "What type of NPC do you want to Create " << endl;
            cout << "1: Aggressor" << endl;
            cout << "2: Friendly" << endl;
            cin >> typeOfNPC;
            if(typeOfNPC == 1 || typeOfNPC == 2){
                break;
            }
        }

        cout << "What Type of Fighter You want to Make" << endl;
        cout << "\nChoose an option:" << endl;
        cout << "1: Nimble" << endl;
        cout << "2: Bully" << endl;
        cout << "3: Fighter" << endl;
        cout << "4: Quit" << endl;
        cout << "Enter option: ";
        cin >> typeOfCharacter;

        switch (typeOfCharacter) {
            case 1: {
                NimbleBuilder *builder = new  NimbleBuilder();
                builder->createFighter(name,level);
                character = builder->getFighter();
                break;
            }
            case 2:{
                BullyBuilder *bullyBuilder = new BullyBuilder();
                bullyBuilder->createFighter(name,level);
                character = bullyBuilder->getFighter();
                break;
            }
            case 3: {
                TankBuilder *tankBuilder = new TankBuilder();
                tankBuilder->createFighter(name,level);
                character = tankBuilder->getFighter();
                break;
            }
            case 4:{
                return;
            }
        }
        // For Ability Menu
        while(true){
            int input ;
            cout << "Do you want to EDIT Ability Scores of NPC : Input 1 to Edit" << endl;
            cin >> input;
            if(input == 1){
                abilityMenu(character);
            }
            break;
        }

        character->getItemContainer()->printContainer();

        while (true){
           int input;
           cout << "Input the index of the Item You want to Wear : Input -1 to Exit";
           cin >> input;
           if(input == -1 ){
               break;
           }
           character->wearItem(input);
        }

        while(true) {
            int input;
            cout << "Do you want to Equip NPC  : Input 1 to Equip" << endl;
            cin >> input;

            if(input == 1){
                ItemContainerEditor itemContainerEditor;
                itemContainerEditor.run();
                ItemContainer* container = itemContainerEditor.getItemContainer();
                character->setItemContainer(container);
            }
            break;
        }


        if(character != nullptr && (typeOfNPC == 1 || typeOfNPC == 2)){
            if(typeOfNPC == 1){
                AggressorStrategy *aggressorStrategy = new AggressorStrategy();
                character->setStrategy(aggressorStrategy);
            }
            else {
                FriendlyStrategy *friendlyStrategy = new FriendlyStrategy();
                character->setStrategy(friendlyStrategy);
            }
            break;
        }

    }

}

void CharacterEditor::abilityMenu(Character *pCharacter) {
    int input;
    while(true){
        cout << "What Scores do you want Edit for the NPC (Value should be not greater then 5)" << endl;
        cout << "\nChoose an option:" << endl;
        cout << "1: Strength" << endl;
        cout << "2: Dexterity" << endl;
        cout << "3: Constitution" << endl;
        cout << "4: Intelligence" << endl;
        cout << "5: Wisdom" << endl;
        cout << "6: Intelligence" << endl;
        cout << "7 :Damage Bonus" << endl;
        cout << "8 :Hit Points" << endl;
        cout << "9:Armor Class" << endl;
        cout << "10:Quit" << endl;
        cin >>input;

        switch (input) {
            case 1 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setAbilityScores("Strength",score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 2 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setAbilityScores("Dexterity",score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 3 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setAbilityScores("Wisdom",score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 4 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setAbilityScores("Intelligence",score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;

            }
            case 5 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setAbilityScores("Wisdom",score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 6 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setAbilityScores("Intelligence",score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }

            case 7 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setDamageBonus(score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 8 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setHitpoints(score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 9 : {
                int score;
                cout << "Set a score: "<< endl;
                cin >> score;
                if(score > 0 && score <= 5){
                    pCharacter->setArmorClass(score);
                }
                else {
                    cout << "Value is less then equal to 0 or greater then 5 "<<endl;
                }
                break;
            }
            case 10 : {
                return;
            }
        }
    }
}

