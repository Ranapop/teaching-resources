//
// Created by roxanappop on 12/15/2019.
//

#ifndef CAR_SHOP_INPUT_H
#define CAR_SHOP_INPUT_H

#define MAX_LINE 50

int getChoiceIndex(int noOfChoices, int *state);
void readPairs(FILE *f, double *prices, char **names);

#endif //CAR_SHOP_INPUT_H
