#include <stdio.h>
#include "backend/item/item_object.h"

int main (int argc, char** argv) {
        ItemObject_t *item = item_object_new(1, "Test", 100, 1);
        printf("Item: %s\n", item->name);
        item_object_free(item);

        return 0;
}