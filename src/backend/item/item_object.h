#ifndef ITEM_OBJECT_H
#define ITEM_OBJECT_H

#include <stdint.h>

typedef struct
{
        uint32_t id; // Unique ID
        char* name; // Explicit name for product type
        uint16_t price;
        uint32_t order_id; // 0 if unassigned to order
        uint8_t warehouse_id; // Warehouse ID, if 0, then in no warehouse
} ItemObject_t;

ItemObject_t *item_object_new(uint32_t id, char *name, uint16_t price, uint32_t order_id, uint8_t warehouse_id);
void item_object_free(ItemObject_t *item);

#endif // ITEM_OBJECT_H

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif