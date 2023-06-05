#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item_object.h"

ItemObject_t *item_object_new(uint32_t id, uint32_t product_type, uint16_t price, uint32_t order_id, uint8_t warehouse_id) {
        
        ItemObject_t *item = malloc(sizeof(ItemObject_t));
        item->id = id;
        item->product_type = product_type;
        item->price = price;
        item->warehouse_id = warehouse_id;
        return item;
}

void item_object_free(ItemObject_t *item) {
        free(item);
        return;
}