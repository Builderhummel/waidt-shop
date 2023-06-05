#include <stdio.h>
#include "warehouse_system/item/item_object.h"

int main (int argc, char** argv) {
        ItemObject_t *item = item_object_new(1, 69, 100, 1, 1);
        printf("Item: %d\n", item->product_type);
        item_object_free(item);

        return 0;
}