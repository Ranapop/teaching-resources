//
// Created by roxanappop on 12/15/2019.
//

#ifndef CAR_SHOP_BRAND_H
#define CAR_SHOP_BRAND_H

#include "model.h"
#include "brand.h"

typedef struct _brand {
    char * name;
    int noOfModels;
    model * models;
} brand;

void readBrandsWithModels(FILE *carDataFile, int *noOfBrandsAddr, brand ** brandsAddr);
void displayBrandOptions(int noOfBrands, brand * brands);
void freeBrands(brand * brands, int noOfBrands);

#endif //CAR_SHOP_BRAND_H
