//
// Created by hp on 12/02/2024.
//
#include "../Cell/Cell.h"
#include "../ObserverPattern/Subject.h"
#include <iostream>
#include <queue>
#include <map>


#ifndef COMP345A1_MAP_H
#define COMP345A1_MAP_H

using namespace std;


struct Coordinate {
    int x;
    int y;
    bool equalCoordinates(const Coordinate& c1) {
        if(x == c1.x && y == c1.y ){
            return true;
        }
        return false;
    }
};

/**
 * @class Map
 * @brief Container class for the Cells
 *
 * Game Rules: Creates a Map with walls around, dungeon master can place Starting point,Ending point,Opponent,etc
 * and design the map
 *
 * Libraries: <queue>
 */
class Map : public Subject{
public:
    /**
     * @brief Accepts width and height of the map and initializes a two dimensional array with Wall arround
     * @param width
     * @param height
     */
    Map(int width, int height);

    /**
     * @brief Responsible for destructing the Map object
     */
    ~Map();

    /**
     * @brief Places the item on the inputted coordinates
     * @param x
     * @param y
     * @param item (Accepts : '#' : Wall, 'S' : Starting Point, 'E' : "Ending Point", 'D' : Door, 'C' : Chest)
     * @return
     */
    bool Place(int x, int y,char item);

    

    /**
     * Determines whether there is path from starting point to the Ending point using Breadth first Search
     * @return
     */
    bool isValid ();


    /**
     * Prints the Map on the Terminal
     */
    void printMap();

    /**
     * Start the Game
     */
    bool startGame(Character* c);
     /**
      * Takes character pointer, direction and tries it to move on the map
      * @param c
      * @param dir
      */
     bool TryMove (Character* c,string dir);

    /**
        * @brief Returns the width of the Map
        * @return width of map
        */
    int getWidth() const;

    /**
     * @brief Returns the height of the Map
     * @return height of map
     */
    int getHeight() const;

    /**
    * @brief Returns Object of a cell given the cooridnate
    * @param x
    * @param y
    * @return Cell - content of the cell
    */
    Cell* getCell(int x, int y);


private:
    /**
     * A utility function used to determine if the coordinate is the Queue used in Breadth first search
     *
     * @param q1
     * @param c1
     * @return
     */
    static bool Contains(queue<Coordinate> q1,Coordinate &c1);

    /**
     * Takes Character Pointer and returns the Current Position Cell
     * @param c
     * @return
     */
    Cell* GetCurrentPositionCell(Character* c);

    /**
     * Takes Character Pointer and returns the Coordinate
     * @param c
     * @return
     */
     Coordinate getCurrentPositionCoordinate(Character* c);

     /**
      * Takes Character pointer and moves it to move Position (X,Y)
      * @param c
      * @param x
      * @param y
      */
    bool move(Character* c,int x ,int y);
private:
    /**
     * Stores 2 dimensional Array
     */
    Cell** map;
    /**
     * Stores the Width of the array
     */
    int width;
    /**
     * Stores the Heigth of the array
     */
    int height;

    /**
     * Stores starting and ending coordinates of the Character
     */
    int startX,startY,endX,endY;

    /**
     * Stores the coordinates of the Player
     */
    int playerX,playerY;

    /**
     * Stores state which is been taken by the character
     */
     std::map<Character*,Cell::State> prevStates;
};


#endif //COMP345A1_MAP_H
