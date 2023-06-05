#ifndef ITEM_HANDLER_H
#define ITEM_HANDLER_H

#include "item_object.h"

int item_update(ItemObject_t* item, int id, char* name, int price, int in_warehouse);
int item_update_status(ItemObject_t* item, int in_warehouse);

#endif // ITEM_HANDLER_H
