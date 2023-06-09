#ifndef ITEM_HANDLER_H
#define ITEM_HANDLER_H

#include "item_object.h"

int item_update(ItemObject_t* item, uint32_t id, uint32_t product_type, uint16_t price, uint32_t order_id, uint8_t warehouse_id);
int item_update_status(ItemObject_t* item, int warehouse_id);

#endif // ITEM_HANDLER_H
