//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_TESTORIG_H
#define PROJEKT2_TESTORIG_H

#endif //PROJEKT2_TESTORIG_H

#include "../../Functionality/FuncTest.h"
#include "../../Pseudo-Ops/ORIG.h"
#include "../../Functionality/Structs.h"

void testORIG1();

void testORIG(){

    testORIG1();

}

void testORIG1() {
    LineInfo li;
    li.input = ".ORIG x3000";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;
    char *testID = "ORIG1";

    ORIG(li);
    char *expected = "0011000000000000";

    equals(li.output, expected, testID);

}