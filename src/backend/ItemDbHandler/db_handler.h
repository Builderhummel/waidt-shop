#ifndef DB_HANDLER_H
#define DB_HANDLER_H

#define DBHANDLER_QUERY_BUFFER 1024

#include <mysql/mysql.h>
#include "../item/item_object.h"

MYSQL* itemDbHandler_connect();
void itemDbHandler_disconnect(MYSQL* conn);
void itemDbHandler_init_tables(MYSQL* conn);

int itemDbHandler_insert(MYSQL* conn, ItemObject_t * item);
int itemDbHandler_update(MYSQL* conn, ItemObject_t * item);
int itemDbHandler_get_free_item(MYSQL* conn, ItemObject_t* item);

#endif // DB_HANDLER_H