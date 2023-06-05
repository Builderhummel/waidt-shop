#ifndef ITEM_HANDLER_H
#define ITEM_HANDLER_H

#include "item_object.h"

int item_update(ItemObject_t* item, uint32_t id, char* name, uint16_t price, uint32_t order_id, uint8_t in_warehouse);
int item_update_status(ItemObject_t* item, int in_warehouse);

#endif // ITEM_HANDLER_H
