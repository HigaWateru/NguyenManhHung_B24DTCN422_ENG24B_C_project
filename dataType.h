#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char id[10];
    char categoryName[20];
} category;

typedef struct {
    char id[10];
    char productName[20];
    char categoryID[10];
    long long priceImport;
    long long priceSale;
    int quantity;
} product;

#endif // DATATYPE_H
