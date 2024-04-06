
#include "CharacterStrategy.h"

//--------------------HumanPlayerStrategy--------------------


string HumanPlayerStrategy::round(Character *c, Map *map) {

    int input;
    cout << "\n------------------------------" << endl;
    cout << c->getName() << "'s play turn" << endl;
    cout << "------------------------------" << endl;

    /// TODO ALLOW USER to both move and attack both in one turn
    while (true){

        cout << "\nChoose an option:" << endl;
        cout << "1: Move" << endl;
        cout << "2: Attack" << endl;
        cout << "3: Free Action" << endl;
        cout << "4: Go to Next Map"<<endl;
        cout << "5: Go to Previous Map"<< endl;
        cout << "Enter option: ";
        cin >> input;

        switch (input) {
            case 1: {
                this->move(c,map);
                return "Movement";
            }
            case 2: {
                this->attack(c,map);
                return "Attack";
            }
            case 3 : {
                this->freeAction();
                return "Action";
            }
            case 4 : {
                Map* mp = map->hasCompleted(c);
                if(mp == nullptr){
                    if(mp->CanComplete(c)){
                        return "COMPLETED";
                    }
                    else{
                        return "NOTCOMPLETED";
                    }
                }
                return "COMPLETED";
            }
            case 5 : {
                Map* mp = map->goPreviousMap(c);
                if(mp == nullptr){
                    return "NOTEXITED";
                }
                return "EXITED";
            }
        }
    }

}
void HumanPlayerStrategy::move(Character* c, Map* map){
    int input;


    int moveDistance = 5;
    while (moveDistance > 0) {
        cout << "\nChoose a movement option:" << endl;
        cout << "1: Up" << endl;
        cout << "2: Down" << endl;
        cout << "3: Left" << endl;
        cout << "4: Right" << endl;
        cout << "5: Stay at current position" << endl;
        cout << "You have " << moveDistance << " moves left." << endl;

        cout << "Enter option: ";
        cin >> input;

        switch (input) {
            case 1: {
                map->tryMove(c, "up");
                moveDistance--;
                break;
            }
            case 2: {
                map->tryMove(c, "down");
                moveDistance--;
                break;
            }
            case 3: {
                map->tryMove(c, "left");
                moveDistance--;
                break;
            }
            case 4: {
                map->tryMove(c, "right");
                moveDistance--;
                break;
            }
            case 5: {
                return;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    }
}

void HumanPlayerStrategy::attack(Character* source, Map* map) {
    // Find adjacent enemies
    std::vector<Character*> adjacentEnemies = map->findAdjacentCharacters(source);

    if (adjacentEnemies.empty()) {
        std::cout << "No enemies nearby to attack." << std::endl;
        return; // Early return if no enemies are found
    }

    // Display enemies to user
    std::cout << "Select an enemy to attack (or select " << adjacentEnemies.size() + 1 << " to not attack):" << std::endl;
    for (size_t i = 0; i < adjacentEnemies.size(); ++i) {
        std::cout << i + 1 << ". " << adjacentEnemies[i]->getName() << std::endl; // Assuming Character has a getName() method
    }
    std::cout << adjacentEnemies.size() + 1 << ". Do not attack" << std::endl;

    // Get user input
    int choice = 0;
    std::cin >> choice;

    // Validate input (assumes choice is 1-indexed, plus one additional option to not attack)
    while (std::cin.fail() || choice < 1 || choice > adjacentEnemies.size() + 1) {
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to next line
        std::cout << "Invalid selection. Please try again: ";
        std::cin >> choice;
    }

    // Check if user chose not to attack
    if (choice == adjacentEnemies.size() + 1) {
        std::cout << "No attack this turn." << std::endl;
        return; // Early return if user chooses not to attack
    }

    // Adjust for 0-indexed vector
    Character* target = adjacentEnemies[choice - 1];

    // Attack selected target
    Dice dice;
    int damage = dice.roll("1d6"); // Roll for damage
    source->attack(target, damage); // Perform the attack
    if (target->hitPoints <= 0) {
        // Character has been defeated
        map->removeCharacterFromMap(target);
    }
}

void HumanPlayerStrategy::freeAction() {
    int input;

    while (true) {
        cout << "\nChoose a free action:" << endl;
        cout << "1: Say hello" << endl;
        cout << "2: Say a cool quote" << endl;
        cout << "3: Quit" << endl;

        cout << "Enter option: ";
        cin >> input;

        switch (input) {
            case 1: {
                cout << "Hey, loosers!" << endl;
                break;
            }
            case 2: {
                cout << "If you do something to get revenge it means that more people suffer." << endl;
                break;
            }
            case 3: {
                return;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    }
}

//--------------------AggressorStrategy--------------------


string AggressorStrategy::round(Character *c, Map *map) {
    std::vector<Character*> adjacentEnemies = map->findAdjacentCharacters(c);

    if(adjacentEnemies.empty()){
        this->move(c,map);
        return "MOVE";
    }
    else{
        this->attack(c,map);
        return "ATTACK";
    }
}



void AggressorStrategy::move(Character* c, Map* map){
    cout << "\n------------------------------" << endl;
    cout << c->getName() << "'s play turn" << endl;
    cout << "------------------------------\n" << endl;
    cout << "Automatically moving towards player character." << endl;
    map->moveNextTo(c, 5);
}

void AggressorStrategy::attack(Character* source, Map* map) {
    std::vector<Character*> adjacentEnemies = map->findAdjacentCharacters(source);
    Dice dice;
    for (Character* enemy : adjacentEnemies) {
        int damage = dice.roll("1d6"); // Roll for damage
        source->attack(enemy, damage);
    }
}


//--------------------FriendlyStrategy--------------------

string FriendlyStrategy::round(Character *c, Map *map) {
    std::vector<Character*> adjacentEnemies = map->findAdjacentCharacters(c);

    if(adjacentEnemies.empty()){
        this->move(c,map);
        return "MOVE";
    }
    else{
        this->attack(c,map);
        return "ATTACK";
    }
}

void FriendlyStrategy::move(Character* c, Map* map){
    cout << "\n------------------------------" << endl;
    cout << c->getName() << "'s play turn" << endl;
    cout << "------------------------------\n" << endl;
    cout << "Automatically moving towards player character." << endl;
    map->moveNextTo(c, 5);
}

void FriendlyStrategy::attack(Character* source, Map* map) {
    cout << "Hi, I'm friendly. But don't test the limits of my kindness." << endl;
}