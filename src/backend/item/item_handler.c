#include "item_object.h"

int update_item(ItemObject_t* item, int id, char* name, int price, int in_warehouse) {
        item->id = id;
        item->name = strdup(name);
        item->price = price;
        item->in_warehouse = in_warehouse;

        return 0;
}

int update_item_status(ItemObject_t* item, int in_warehouse) {
        item->in_warehouse = in_warehouse;

        return 0;
}