#include <stdlib.h>
#include "customer_object.h"

CustomerObject_t *customer_createCustomer(char *name, char *address) {
        CustomerObject_t *customer = malloc(sizeof(CustomerObject_t));
        customer->name = name;
        customer->address = address;
        return customer;
}

void customer_destroyCustomer(CustomerObject_t *customer) {
        free(customer);
}