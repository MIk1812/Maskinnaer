//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_TESTORIG_H
#define PROJEKT2_TESTORIG_H

#endif //PROJEKT2_TESTORIG_H

#include "../Functionality/FuncTest.h"
#include "../Pseudo-Ops/ORIG.h"

void testORIG1();

void testORIG(){

    testORIG1();

}

void testORIG1() {

    char *testID = "ORIG1";
    char *input = ".ORIG x3000";
    char *output = (char *) calloc(1, 17);

    ORIG(input, output);
    char *expected = "0011000000000000";

    equals(output, expected, testID);
    free(output);

}