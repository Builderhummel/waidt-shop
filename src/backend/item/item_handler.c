#include "item_object.h"

int item_update(ItemObject_t* item, uint32_t id, char* name, uint16_t price, uint32_t order_id, uint8_t in_warehouse) {
        item->id = id;
        item->name = strdup(name);
        item->price = price;
        item->order_id = order_id;
        item->in_warehouse = in_warehouse;

        return 0;
}

int item_update_status(ItemObject_t* item, uint8_t in_warehouse) {
        item->in_warehouse = in_warehouse;

        return 0;
}