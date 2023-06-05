#ifndef ITEM_HANDLER_H
#define ITEM_HANDLER_H

#include "item_object.h"

int update_item(ItemObject_t* item, int id, char* name, int price, int in_warehouse);
int update_item_status(ItemObject_t* item, int in_warehouse);

#endif // ITEM_HANDLER_H
