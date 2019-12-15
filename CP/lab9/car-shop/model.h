//
// Created by roxanappop on 12/15/2019.
//

#ifndef CAR_SHOP_MODEL_H
#define CAR_SHOP_MODEL_H

typedef struct _model {
    char * name;
    double price;
} model;

void readModels(FILE * carDataFile, model ** modelsAddr, int noOfModels);
void displayModelOptions(model * models, int noOfModels, char * brand);
void displayModel(model * m);
void freeModel(model * m);

#endif //CAR_SHOP_MODEL_H
