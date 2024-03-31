//
// Created by hp on 30/03/2024.
//



#ifndef COMP345A1_CHARACTEREDITOR_H
#define COMP345A1_CHARACTEREDITOR_H

#include "../Character/Character.h"
#include "../Builder/NimbleBuilder.h"
#include "../Builder/BullyBuilder.h"
#include "../Builder/TankBuilder.h"
#include "../ItemContainerEditor/ItemContainerEditor.h"


class CharacterEditor {

public:
    CharacterEditor() = default;
    void runNpcEditor();
    void runCharacterEditor();
    void loadCharacter();
    void loadNpc();
    void createNpc();
private:
    void createCharacter();
    void abilityMenu(Character *pCharacter);
    // Pointer to character which we are currently editing
    Character* character;

};


#endif //COMP345A1_CHARACTEREDITOR_H
