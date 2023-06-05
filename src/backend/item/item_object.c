#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item_object.h"

ItemObject_t *item_object_new(uint32_t id, char *name, uint16_t price, uint32_t order_id, uint8_t warehouse_id) {
        
        ItemObject_t *item = malloc(sizeof(ItemObject_t));
        item->id = id;
        item->name = strdup(name);
        item->price = price;
        item->warehouse_id = warehouse_id;
        return item;
}

void item_object_free(ItemObject_t *item) {
        free(item->name);
        free(item);
        return;
}