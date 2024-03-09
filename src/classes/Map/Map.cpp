//
// Created by hp on 12/02/2024.
//

#include "Map.h"

using namespace std;


Map::Map(int widthX, int heightY) {

    width = widthX;
    height = heightY;
    // Initialize Values to -1
    startX = -1;
    startY = -1;
    endX = -1;
    endY = -1;
    playerX = -1;
    playerY = -1;


    map =new Cell*[width];


    // Initialize the Map
    for(int i =0 ;i<width;i++){
        map[i] = new Cell[height];
    }

    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            map[x][y] = Cell(Cell::State::EMPTY, nullptr);
        }
    }

    // Set Up walls
    for (int i = 0;i<width;i++){
        map[i][0].setState(Cell::State::WALL, nullptr);
        map[i][height - 1].setState(Cell::State::WALL, nullptr);
    }
    for (int i =0;i<height;i++){
        map[0][i].setState(Cell::State::WALL, nullptr);
        map[width -1][i].setState(Cell::State::WALL, nullptr);
    }

}


bool Map::Place(int x, int y, char item) {
    // Check if the coordinates are not Out of the Map
    if(x < 0 && x > width - 1 || y < 0 && y > height - 1){
        cout << "Coordinates are out of the Map" << endl;
        return false;
    }
    // Check if it is trying to replace Edges
    if ((x == 0 || x == width - 1) && (y == 0 || y == height -1)){
        cout << "You cant replace the wall" << endl;
        return false;
    }


    // If Placing Start
    if(item  == 'S'){
        cout << "Successfully Placed the Starting point" <<  endl;
        startX = x;
        startY = y;
        return true;
    }
    // If Placing Exit
    if(item == 'E') {
        cout << "Successfully set exit" << endl;
        endX = x;
        endY = y;
        return  true;
    }

    // Can only place Door and wall at the edge of the Map
    if((x == 0 || x == width-1) || (y == 0 || y == height-1 )){

        if(item == '#'){
            if(startX == x && startY == y){
                startX = -1;
                startY = -1;
            }
            else if (endX == x && endY == y){
                endX = -1;
                endY = -1;
            }

            map[x][y].setState(Cell::State::WALL, nullptr);
            cout << "Successfully Placed the Wall" << endl;
            return true;

        }
        else if (item == 'D'){
            // Check if door is placed at the start position
            if(startX == x && startY == y){
                startX = -1;
                startY = -1;
            }
                // Check if door is placed at the Exit position
            else if(endX == x && endY == y) {
                endX = -1;
                endY = -1;
            }
            cout << "Successfully Placed the Door" << endl;
            map[x][y].setState(Cell::State::DOOR, nullptr);
            return true;

        }
        else{
            cout << "Invalid ! You can only place wall ,Starting point, ending point on the wall " << endl;
            return false;
        }

    }

    if(item  == '#'){
        if(startX == x && startY == y){
            startX = -1;
            startY = -1;
        }
            // Check if door is placed at the Exit position
        else if(endX == x && endY == y) {
            endX = -1;
            endY = -1;
        }
        cout << "Successfully Placed the Wall" << endl;
        map[x][y].setState(Cell::State::WALL, nullptr);
        return true;
    }

    if(item  == '.'){
        if(startX == x && startY == y){
            startX = -1;
            startY = -1;
        }
            // Check if door is placed at the Exit position
        else if(endX == x && endY == y) {
            endX = -1;
            endY = -1;
        }
        cout << "Successfully Emptied the Cell" << endl;
        map[x][y].setState(Cell::State::EMPTY, nullptr);
        return true;
    }

    if(item == 'O'){
        if(startX == x && startY == y){
            startX = -1;
            startY = -1;
        }
            // Check if door is placed at the Exit position
        else if(endX == x && endY == y) {
            endX = -1;
            endY = -1;
        }
        cout << "Successfully Placed the Opponent";
        map[x][y].setState(Cell::State::OPPONENT, nullptr);
        return true;

    }

    if(item == 'C'){
        if(startX == x && startY == y){
            startX = -1;
            startY = -1;
        }
            // Check if door is placed at the Exit position
        else if(endX == x && endY == y) {
            endX = -1;
            endY = -1;
        }
        cout << "Successfully Placed the Chest";
        map[x][y].setState(Cell::State::CHEST, nullptr);
        return true;

    }
    cout << "Invalid Inputs";
    return false;
}




// Apply BFS to find the Route from Starting to the End
bool Map::isValid() {
    // Check if we have start and End point on the Map
    if(startX == -1 || startY == -1 || endX == -1  || endY == -1 ){
        cout << "You must have one Start and End Cell";
        return false;
    }
    // Create a queue of Not Visited Nodes
    queue<Coordinate> notVisited;

    // Create a queue of Visited Notes
    queue<Coordinate> visited;

    // Create Coordinate of End
    Coordinate end =  {endX,endY};

    //Create Coordinate to be pushed on the Queue
    Coordinate c1 = {startX,startY};

    // Push the First Coordinate on the Not Visited Queue
    notVisited.push(c1);

    // Loop through until the queue is Empty
    while(!notVisited.empty()){
        // Pop the first Coordinate
        Coordinate &c2 = notVisited.front();
        notVisited.pop();

        // Push the Coordinate to the Visited Queue
        visited.push(c2);

        // Check if the Popped Coordinate is the Result
        if(c2.equalCoordinates(end)){
            cout << "Valid Map" << endl;
            return true;
        }
        // If not then Explore all the Nodes
        else {
            // Walk towards Right
            if(c2.x + 1 < width && !map[c2.x + 1][c2.y].isWall() ){
                Coordinate c = {c2.x + 1,c2.y};
                // Check if it is not in both the Queues
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }
            }

            // Walk towards Left
            if(c2.x - 1 >= 0 && !map[c2.x -1][c2.y].isWall()){
                Coordinate c = {c2.x-1,c2.y};
                // Check if it is not in both the Queues
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }

            }

            // Walk Down
            if(c2.y + 1 < height && !map[c2.x][c2.y + 1].isWall()){
                Coordinate c = {c2.x,c2.y + 1};
                // Check if it is not in both the Queues
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }
            }
            // Walk up
            if(c2.y - 1 >= 0 && !map[c2.x][c2.y - 1].isWall()){
                Coordinate c = {c2.x,c2.y - 1};
                // Check if it is not in both the Queues
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }
            }

        }
    }
    // If the While Loop finishes without Returning then throw an error and return false
    cout << "Invalid Map ! No Route from starting to ending point" << endl;
    return false;
}

/**
 * Prints the Map
 */
void Map::printMap() {
    cout << "---------------CURRENT MAP ------------------" << endl;
    for (int j = height - 1; j >= 0; j--) {
        string output;
        for (int i = 0; i < width; i++) {
            if (map[i][j].getState() == Cell::State::CHARACTER) {
                    output += map[i][j].getCharacter()->getName()[0];
            } else if (i == endX && j == endY) { // Exit cell
                output += "E";
            } else if (i == startX && j == startY) { // Start cell
                    output += "S";
            } else if (map[i][j].getState() == Cell::State::WALL) {
                output += "#";
            } else if (map[i][j].getState() == Cell::State::EMPTY) {
                output += ".";
            } else if (map[i][j].getState() == Cell::State::OPPONENT) {
                output += "O";
            } else if (map[i][j].getState() == Cell::State::CHEST) {
                output += "C";
            } else if (map[i][j].getState() == Cell::State::DOOR) {
                output += "D";
            }
        }
        cout << output << endl;
    }
    cout << "---------------------------------" << endl;
}

Map::~Map() {
    // Loop through the 2d array to delete each array
    for (int i = 0; i < height; ++i)
    {
        delete[] map[i];
    }
    delete map;
}

// Checks if the Coordinate is in the given Queue
bool Map::Contains(queue<Coordinate> q1, Coordinate &c1) {
    // Run until Queue is not Empty
    while(!q1.empty()){
        // Check and If found then return
        if(q1.front().equalCoordinates(c1))
            return true;
        // Pop the Coordinate
        q1.pop();
    }
    // Return False if no match is found
    return false;
}

// Place the Character on the Map
bool Map::startGame( Character *c) {
    if(startX != -1 && startY != -1){
        // Store the State
        prevStates[c] = map[startX][startY].getState();
        // Change the State
        map[startX][startY].setState(Cell::CHARACTER, (CellContent *) c);
        // Print Success message on the terminal
        cout << "Successfully Started the Game !" << endl;
        return true;
    }
    cout << "Error Occurred While Starting the Game "<< endl;
    return false;
}

bool Map::move(Character *c, int x, int y) {
    // Check if state is stored for the character
    auto it = prevStates.find(c);


    // If it is stored
    if(it != prevStates.end()){
        // Find the Current pos
        Cell* oldTile = GetCurrentPositionCell(c);
        // Find the Destination tile
        Cell* newTile = &map[x][y];
        // Store the Old tile state
        Cell::State oldStateTemp = prevStates[c];
        //Change the Old tile state
        oldTile->setState(oldStateTemp,NULL);
        // Store the new tile state in the map
        prevStates[c] = newTile->getState();
        // Set the new Tile State
        newTile->setState(Cell::CHARACTER,c);
        cout << "Successfully Changed the Position of the character" << endl ;
        return true;

    }
    cout << "Character Not found Please Start the Game !" << endl;
    return false;
}

bool Map::TryMove(Character *c, string dir) {

    // Boolean value whether the Character was able to move or not
    bool moved = false;


    //This is the current tile the player is on
    Cell* oldTile = GetCurrentPositionCell(c);

    // If its NullPtr then we have to Start the Game for the character
    if(oldTile == nullptr){
        cout << "Please Start the Game to Play it" << endl;
        return moved;
    }

    //This will be the target tile to move to
    Cell* newTile = NULL;

    // Get Current Coordinates
    Coordinate coordinate = getCurrentPositionCoordinate(c);



    cout << "Trying to Move "<< dir << " Direction" << endl;

    // Check the Direction in which Character wants to Move
    if(dir == "up"){
        if (coordinate.y + 1 < height){
            // TODO Add Different Cases According to the game
            // Checks if User can Move to the new Tile
            if(map[coordinate.x][coordinate.y  + 1].canMove()){
                moved = move(c,coordinate.x,coordinate.y+1);
            }
        }
    }
    // When users tries to GO down
    if(dir == "down"){
        if (coordinate.y - 1 < height){
            // TODO Add Different Cases According to the game
            // Checks if User can Move to the new Tile
            if(map[coordinate.x][coordinate.y  - 1].canMove()){
                moved = move(c,coordinate.x,coordinate.y-1);
            }

        }
    }
    // When User tries to go down right
    if(dir == "right"){
        if (coordinate.x + 1 < width){
            // TODO add More Cases According to the game
            // Checks if User can Move to the new Tile
            if(map[coordinate.x + 1][coordinate.y ].canMove()){

                moved =  move(c,coordinate.x + 1,coordinate.y);
            }
        }
    }
    // When User tries to go Left
    if(dir == "left"){
        if (coordinate.x - 1 >= 0 ){
            // TODO add More Cases According to the
            // Checks if User can Move to the new Tile
            if(map[coordinate.x - 1][coordinate.y ].canMove()){
                moved = move(c,coordinate.x - 1,coordinate.y);
            }
        }

    }
    // Finally Notify the Observers
    Notify();

    // Return the Value
    return moved;
}

Cell* Map::GetCurrentPositionCell(Character *c) {
    // Loops through the Map to find the Call which contain that character
    // TODO : Add the Coordinate of Character class to Optimize the Code
    for (int i = 0;i<width;i++){
        for (int j = 0;j<height;j++){
            // If found return the Cell
            if(map[i][j].getState() == Cell::State::CHARACTER && map[i][j].getCharacter() == c){
                return &map[i][j];
            }
        }
    }
    return nullptr;
}

Coordinate Map::getCurrentPositionCoordinate(Character *c) {
    Coordinate c1 = {-1,-1};
    // Loops through Map to find the coordinate of the Character
    // TODO : Add the Coordinate of Character class to Optimize the Code
    for (int i = 0;i<width;i++){
        for (int j = 0;j<height;j++){
            if(map[i][j].getState() == Cell::State::CHARACTER && map[i][j].getCharacter() == c ){
                // If found then changes the coordinate of the Coordinate Struct
                c1 = {i,j};
                return c1;
            }
        }
    }
    return c1;
}

