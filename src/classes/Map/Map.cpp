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
        map[height -1][i].setState(Cell::State::WALL, nullptr);
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
    if(startX == -1 || startY == -1 || endX == -1  || endY == -1 ){
        cout << "You must have one Start and End Cell";
        return false;
    }
    queue<Coordinate> notVisited;
    queue<Coordinate> visited;

    Coordinate end = Coordinate();
    end.x = endX;
    end.y = endY;


    Coordinate c1 = Coordinate();
    c1.x = startX;
    c1.y = startY;

    notVisited.push(c1);

    while(!notVisited.empty()){
        // Pop the first Coordinate
        Coordinate &c2 = notVisited.front();

        notVisited.pop();

        visited.push(c2);

        // Check if it is the Goal
        if(c2.equalCoordinates(end)){
            cout << "Valid Map" << endl;
            return true;
        }
        // If not then
        else {
            // Walk towards Right
            if(c2.x + 1 < width && !map[c2.x + 1][c2.y].isWall() ){
                Coordinate c = Coordinate();
                c.x = c2.x + 1;
                c.y = c2.y;
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }
            }

            // Walk towards Left
            if(c2.x - 1 >= 0 && !map[c2.x -1][c2.y].isWall()){
                Coordinate c = Coordinate();
                c.x = c2.x-1;
                c.y = c2.y;
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }

            }

            // Walk Down
            if(c2.y + 1 < height && !map[c2.x][c2.y + 1].isWall()){
                Coordinate c = Coordinate();
                c.x = c2.x;
                c.y = c2.y + 1;
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }
            }
            // Walk up
            if(c2.y - 1 >= height && !map[c2.x][c2.y - 1].isWall()){
                Coordinate c = Coordinate();
                c.x = c2.x;
                c.y = c2.y - 1;
                if(!Contains(notVisited,c) && !Contains(visited,c)){
                    notVisited.push(c);
                }
            }

        }
    }
    cout << "Invalid Map ! No Route from starting to ending point" << endl;
    return false;

}
/**
 * Prints the Map
 */
void Map::printMap() {
    cout << endl << "---------------MAP------------------" << endl;
    for (int j = height - 1 ; j >= 0  ;j--){

        string output;
        for (int i = 0;i < width ; i++){

            if(map[i][j].getState() == Cell::State::CHARACTER){
                // It will use first Character to represent on the Map
                output += map[i][j].getCharacter()->getName()[0];
            }
            else{
                if(map[i][j].getState() == Cell::State::WALL){
                    output += "#";

                }
                if(map[i][j].getState() == Cell::State::EMPTY){
                    output += " ";
                }
                if(map[i][j].getState() == Cell::State::OPPONENT){
                    output += "O";
                }

                if(map[i][j].getState() == Cell::State::CHEST){
                    output += "C";
                }

                if(map[i][j].getState() == Cell::State::DOOR){
                    output += "D";
                }
            }
        }
        cout << endl << output << endl;
    }
    cout << "---------------------------------" << endl;

}

Map::~Map() {
    for (int i = 0; i < height; ++i)
    {
        delete[] map[i];
    }
    delete map;
}

bool Map::Contains(queue<Coordinate> q1, Coordinate &c1) {
    while(!q1.empty()){
        if(q1.front().equalCoordinates(c1))
            return true;
        q1.pop();
    }
    return false;
}

// Place the Character on the Map
void Map::startGame( Character *c) {
    if(startX != -1 && startY != -1){
        // Store the State
        prevStates[c] = map[startX][startY].getState();
        // Change the State
        map[startX][startY].setState(Cell::CHARACTER, (CellContent *) c);

    }
}

void Map::move(Character *c, int x, int y) {
    auto it = prevStates.find(c);
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
        cout << "Successfully Changed the Position of the character" ;

    }
    else{
        cout << "Character Not found Please Start the Game !";

    }


}

void Map::TryMove(Character *c, string dir) {

    //This is the current tile the player is on
    Cell* oldTile = GetCurrentPositionCell(c);
    if(oldTile == nullptr){
        cout << "Please Start the Game to Play it";
        return;
    }
    //This will be the target tile to move to
    Cell* newTile = NULL;
    // Get Current Coordinates
    Coordinate coordinate = getCurrentPositionCoordinate(c);

    // Check the Direction in which Character wants to Move
    if(dir == "up"){
        if (coordinate.y + 1 < height){
            // TODO Add Different Cases According to the game
            if(map[coordinate.x][coordinate.y  + 1].canMove()){
                move(c,coordinate.x,coordinate.y+1);
            }

        }
    }
    // When users tries to GO down
    if(dir == "down"){
        if (coordinate.y - 1 < height){
            // TODO Add Different Cases According to the game
            if(map[coordinate.x][coordinate.y  - 1].canMove()){
                move(c,coordinate.x,coordinate.y-1);
            }

        }
    }
    // When User tries to go down right
    if(dir == "right"){
        if (coordinate.x + 1 < width){
            // TODO add More Cases According to the game
            if(map[coordinate.x + 1][coordinate.y ].canMove()){
                move(c,coordinate.x + 1,coordinate.y);
            }
        }
    }
    // When User tries to go Left
    if(dir == "left"){
        if (coordinate.x - 1 >= 0 ){
            // TODO add More Cases According to the game
            if(map[coordinate.x - 1][coordinate.y ].canMove()){
                move(c,coordinate.x - 1,coordinate.y);
            }
        }

    }
    Notify();
}

Cell* Map::GetCurrentPositionCell(Character *c) {
    for (int i = 0;i<width;i++){
        for (int j = 0;j<height;j++){
            if(map[i][j].getState() == Cell::State::CHARACTER && map[i][j].getCharacter() == c){
                return &map[i][j];
            }
        }
    }
    return nullptr;
}

Coordinate Map::getCurrentPositionCoordinate(Character *c) {
    Coordinate c1 = {-1,-1};
    for (int i = 0;i<width;i++){
        for (int j = 0;j<height;j++){
            if(map[i][j].getState() == Cell::State::CHARACTER && map[i][j].getCharacter() == c ){
                c1 = {i,j};
                return c1;
            }
        }
    }
    // If not found return Coordinate Struct with -1,-1

    return c1;
}




