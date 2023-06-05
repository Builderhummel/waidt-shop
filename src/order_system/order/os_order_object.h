#ifndef CUSTOMER_ORDER_OBJECT_H
#define CUSTOMER_ORDER_OBJECT_H

#include <stdint.h>
#include "../customer/customer_object.h"

typedef struct {
    uint32_t id; // Order ID
    CustomerObject_t *customer; // Customer object
    uint32_t *productIds; // Array of ordered product IDs
    uint32_t productIdsLength; // Length of productIds array
} CustomerOrderObject_t;

CustomerOrderObject_t *customerOrder_createCustomerOrder(CustomerObject_t *customer, uint32_t *productIds, uint32_t productIdsLength);
void customerOrder_destroyCustomerOrder(CustomerOrderObject_t *customerOrder);

#endif // ORDER_HANDLER_H