//
// Created by hp on 01/04/2024.
//

#ifndef COMP345A1_GAME_H
#define COMP345A1_GAME_H

#include "../Campaign/Campaign.h"


class Game {
    Game(Campaign* compaign);
    void play();
private:
    Campaign *campaign;
};


#endif //COMP345A1_GAME_H
