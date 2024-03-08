//
// Created by hp on 12/02/2024.
//

#include "Cell.h"

Cell::Cell() : currentState(EMPTY),content(nullptr) {
}

Cell::Cell(Cell::State state,CellContent* content) : currentState(state),content(content) {
}

Cell::State Cell::getState() {
    return currentState;
}

void Cell::setState(State state,CellContent* pContent) {
    currentState = state;
    content =  pContent;
}

bool Cell::isWall() {
    return currentState == WALL;
}
bool Cell::isCharacter() {
    return currentState == CHARACTER;
}

bool Cell::isStart() {
    return currentState == START;
}

bool Cell::isExit() {
    return currentState == EXIT;
}

bool Cell::isEmpty() {
    return currentState == EMPTY;
}
bool Cell::isDoor(){
    return currentState == DOOR;
}


bool Cell::canMove() {
    return isStart() || isExit() || isEmpty() || isDoor();
}

Character* Cell::getCharacter() {
    if (isCharacter())
    {

        return dynamic_cast<Character*>(content);
    }
    else
    {
        return nullptr;
    }
}





