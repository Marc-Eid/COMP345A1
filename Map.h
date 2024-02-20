//
// Created by hp on 12/02/2024.
//
#include "Cell.h"
#include <iostream>
#include <queue>


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
class Map {
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


private:
    /**
     * A utility function used to determine if the coordinate is the Queue used in Breadth first search
     * @param q1
     * @param c1
     * @return
     */
    static bool Contains(queue<Coordinate> q1,Coordinate &c1);
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


};


#endif //COMP345A1_MAP_H
