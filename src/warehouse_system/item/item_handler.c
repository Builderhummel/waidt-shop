#include <string.h>

#include "item_object.h"

int item_update(ItemObject_t* item, uint32_t id, uint32_t product_type, uint16_t price, uint32_t order_id, uint8_t warehouse_id) {
        item->id = id;
        item->product_type = product_type;
        item->price = price;
        item->order_id = order_id;
        item->warehouse_id = warehouse_id;

        return 0;
}

int item_update_status(ItemObject_t* item, uint8_t warehouse_id) {
        item->warehouse_id = warehouse_id;

        return 0;
}