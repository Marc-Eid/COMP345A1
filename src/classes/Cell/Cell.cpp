//
// Created by hp on 12/02/2024.
//

#include "Cell.h"

Cell::Cell() {
    currentState = EMPTY;
}

Cell::Cell(Cell::State state) {
    currentState = state;
}

Cell::State Cell::getState() {
    return currentState;
}

void Cell::setState(State state) {
    currentState = state;
}

bool Cell::isWall() {
    return currentState == WALL;
}

