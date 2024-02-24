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
            map[x][y] = Cell(Cell::State::EMPTY);
        }
    }

    // Set Up walls
    for (int i = 0;i<width;i++){
        map[i][0].setState(Cell::State::WALL);
        map[i][height - 1].setState(Cell::State::WALL);
    }
    for (int i =0;i<height;i++){
        map[0][i].setState(Cell::State::WALL);
        map[height -1][i].setState(Cell::State::WALL);
    }

}


bool Map::Place(int x, int y, char item) {
    // Check if the coordinates are not Out of the Map
    if(x < 0 && x > width - 1 || y < 0 && y > height - 1){
        cout << "Coordinates are out of the Map";
        return false;
    }
    // Check if it is trying to replace Edges
    if ((x == 0 || x == width - 1) && (y == 0 || y == height -1)){
        cout << "You cant replace the wall";
        return false;
    }


    // If Placing Start
    if(item  == 'S'){
        // If the start Exist
        if (startX != -1 || startY != -1){
            if ((startX == 0 || startX == width-1) || (startY == 0 || startY == height-1))
                map[startX][startY].setState(Cell::State::WALL);
            else
                map[startX][startY].setState(Cell::State::EMPTY);
        }
        //Set the Start coordinates
        cout << "Successfully Placed the Starting point";
        startX = x;
        startY = y;
        return true;
    }
    // If Placing Exit
    if(item == 'E') {
        // If the Exit Exist
        if (endX != -1 || endY != -1){
            if ((endX == 0 || endX == width-1) || (endY == 0 || endY == height-1))
                map[endX][endY].setState(Cell::State::WALL);
            else
                map[endX][endY].setState(Cell::State::EMPTY);
        }
        // Set the Exit Coordinates

        cout << "Successfully set exit";
        endX = x;
        endY = y;
        return  true;
    }

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

            map[x][y].setState(Cell::State::WALL);
            cout << "Successfully Placed the Wall";
            return true;

        }
        else{
            cout << "Invalid ! You can only place wall ,Starting point, ending point on the wall " << endl;
            return false;
        }

    }

    // If Placing Door
    if(item == 'D'){
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
        map[x][y].setState(Cell::State::DOOR);
        return true;
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
        map[x][y].setState(Cell::State::WALL);
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
        map[x][y].setState(Cell::State::EMPTY);
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
        map[x][y].setState(Cell::State::OPPONENT);
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
        map[x][y].setState(Cell::State::CHEST);
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

    for (int j = height - 1 ; j >= 0  ;j--){
        string output;
        for (int i = 0;i < width ; i++){

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
        cout << endl << output << endl;

    }
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
