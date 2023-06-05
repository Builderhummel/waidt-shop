#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>

#include "db_handler.h"
#include "../item/item_object.h"

MYSQL* itemDbHandler_new_mysql_object() {
        MYSQL *mysql = mysql_init(NULL);
        return mysql;
}

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

MYSQL* itemDbHandler_connect(MYSQL* mysql, char *host, char *user, char *passwd, char *database) {
        mysql_init(mysql);
        mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"your_prog_name");

        if (!mysql_real_connect(mysql,host,user,passwd,database,0,NULL,0))
        {
                fprintf(stderr, "Failed to connect to database: Error: %s\n",
                mysql_error(mysql));
        }

        return mysql;
}

void itemDbHandler_disconnect(MYSQL* conn) {
        mysql_close(conn);
}

void itemDbHandler_init_table(MYSQL* conn) {
        if (conn == NULL) {
                fprintf(stderr, "Failed to connect to database: Error: %s\n",
                mysql_error(conn));
        }
        
        // Create table items
        if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS items(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255), price INT, order_id INT, warehouse_id INT))"))
        {
                finish_with_error(conn);
        }        
}

int itemDbHandler_insert(MYSQL* conn, ItemObject_t * item) {
        char query[DBHANDLER_QUERY_BUFFER];
        sprintf(query, "INSERT INTO items (name, price, order_id, warehouse_id) VALUES ('%s', %d, %d, %d)", item->name, item->price, item->order_id, item->warehouse_id);
        if (mysql_query(conn, query))
        {
                finish_with_error(conn);
        }
        return 0;
}


int itemDbHandler_update(MYSQL* conn, ItemObject_t * item) {
        char query[DBHANDLER_QUERY_BUFFER];
        sprintf(query, "UPDATE items SET name='%s', price=%d, order_id=%d, warehouse_id=%d WHERE id=%d", item->name, item->price, item->order_id, item->warehouse_id, item->id);
        if (mysql_query(conn, query))
        {
                finish_with_error(conn);
        }
        return 0;
}


// Fetch item where order_id = 0
// Return 1, when no free item is found
int itemDbHandler_get_free_item(MYSQL* conn, ItemObject_t* item) {
        MYSQL_RES *result;
        MYSQL_ROW row;
        char query[DBHANDLER_QUERY_BUFFER];
        sprintf(query, "SELECT * FROM items WHERE order_id=0 AND warehouse_id=%d LIMIT 1", item->warehouse_id);
        if (mysql_query(conn, query))
        {
                finish_with_error(conn);
        }
        result = mysql_store_result(conn);
        if (result == NULL)
        {
                finish_with_error(conn);
        }
        row = mysql_fetch_row(result);
        if (row == NULL)
        {
                return 1;
        }
        item->id = atoi(row[0]);
        item->name = strdup(row[1]);
        item->price = atoi(row[2]);
        item->order_id = atoi(row[3]);
        item->warehouse_id = atoi(row[4]);
        mysql_free_result(result);
        return 0;
}

