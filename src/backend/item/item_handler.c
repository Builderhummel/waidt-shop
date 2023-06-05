#include "item_object.h"

int item_update(ItemObject_t* item, int id, char* name, int price, int in_warehouse) {
        item->id = id;
        item->name = strdup(name);
        item->price = price;
        item->in_warehouse = in_warehouse;

        return 0;
}

int item_update_status(ItemObject_t* item, int in_warehouse) {
        item->in_warehouse = in_warehouse;

        return 0;
}