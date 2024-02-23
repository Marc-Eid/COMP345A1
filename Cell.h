//
// Created by hp on 12/02/2024.
//

#ifndef COMP345A1_CELL_H
#define COMP345A1_CELL_H

/**
 * This file implements the Cell class which holds the State of each cell on the Map
 * Other than it provides basic Getters and setters
 */
class Cell {
public:
    /**
     * These are all the States which an Cell can contain
     */
    enum State{
        EMPTY,
        EXIT,
        START,
        WALL,
        OPPONENT,
        CHARACTER,
        CHEST,
        DOOR
    };
public:
    /**
     * Constructor which will create an Empty Cell object
     */
    Cell();
    /**
     * @brief Constructor which accepts state and creates the Cell according t
     * @param state
     */
    Cell(State state);

    /**
     * @brief Destructor
     */
    virtual ~Cell() = default;

    /**
     * @brief Check whether the Cell is a Wall or not
     * @return
     */
    bool isWall();
    /**
     * @brief Gets the State of the cell
     * @return
     */
    State getState();
    /**
     * @brief Sets the State of the Cell
     * @param state
     */
    void setState(State state);
private:
    /**
     * @brief Stores the State of the Cell
     */
    State currentState;
};


#endif //COMP345A1_CELL_H
