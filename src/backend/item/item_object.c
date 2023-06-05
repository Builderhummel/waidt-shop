#include <stdio.h>
#include <stdlib.h>

#include "item_object.h"

ItemObject_t *item_object_new(int id, char *name, int price, int in_warehouse) {
        
        ItemObject_t *item = malloc(sizeof(ItemObject_t));
        item->id = id;
        item->name = strdup(name);
        item->price = price;
        item->in_warehouse = in_warehouse;
        return item;
}

void item_object_free(ItemObject_t *item) {
        free(item->name);
        free(item);
        return;
}