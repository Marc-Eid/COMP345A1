//
// Created by hp on 30/03/2024.
//

#ifndef COMP345A1_ITEMCONTAINEREDITOR_H
#define COMP345A1_ITEMCONTAINEREDITOR_H

#include "../ItemContainer/ItemContainer.h"
#include "../Item/Item.h"


class ItemContainerEditor {
public:
    ItemContainerEditor() {container = new ItemContainer();};
    void run();
    ItemContainer* getItemContainer();

private:
    void weaponSelector();
    void abilityMenu(Item *item);
    ItemContainer *container;

};


#endif //COMP345A1_ITEMCONTAINEREDITOR_H
