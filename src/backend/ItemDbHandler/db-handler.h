#ifndef DB-HANDLER_H
#define DB-HANDLER_H

#include <mysql/mysql.h>
#include "../item/item_object.h"

MYSQL* itemDbHandler_connect();
void itemDbHandler_disconnect(MYSQL* conn);
void itemDbHandler_init_tables(MYSQL* conn);

int itemDbHandler_insert(MYSQL* conn, ItemObject_t * item);
int itemDbHandler_update(MYSQL* conn, ItemObject_t * item);
int itemDbHandler_get_free_item(MYSQL* conn, int id);

#endif // DB-HANDLER_H