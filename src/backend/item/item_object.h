#ifndef ITEM_OBJECT_H
#define ITEM_OBJECT_H

#define ITEM_NAME_LEN 64

#endif

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif


typedef struct
{
        int id;
        char* name;
        int price;
        int in_warehouse; //Bool, Warehouse location, if 0, then in no warehouse
} item_object_t;

item_object_t *item_object_new(int id, char *name, int price, int in_warehouse);
void item_object_free(item_object_t *item);