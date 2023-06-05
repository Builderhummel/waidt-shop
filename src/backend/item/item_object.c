#include <stdio.h>
#include <stdlib.h>

#include "item_object.h"

item_object_t *item_object_new(int id, char *name, int price, int in_warehouse) {
        
        item_object_t *item = malloc(sizeof(item_object_t));
        item->id = id;
        item->name = strdup(name);
        item->price = price;
        item->in_warehouse = in_warehouse;
        return item;
}

void item_object_free(item_object_t *item) {
        free(item->name);
        free(item);
        return;
}