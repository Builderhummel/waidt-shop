#ifndef CUSTOMER_OBJECT_H
#define CUSTOMER_OBJECT_H

#include <stdint.h>

typedef struct {
    uint32_t id; // Customer ID (Running count)
    char *name; // Customer name
    char *address; // Customer address
} CustomerObject_t;

CustomerObject_t *customer_createCustomer(char *name, char *address);
void customer_destroyCustomer(CustomerObject_t *customer);

#endif // CUSTOMER_OBJECT_H