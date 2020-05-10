//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTTRAP_H
#define PROJEKT2_TESTTRAP_H

#endif //PROJEKT2_TESTTRAP_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/TRAP.h"

void testTRAP1();
void testTRAP2();

void testTRAP(){

    testTRAP1();
    testTRAP2();

}

void testTRAP1(){

    char* testID = "TRAP1";

    LineInfo li;
    li.input = "TRAP #34";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    TRAP(li);
    char* expected = "1111000000100010";

    equals(li.output, expected, testID);
    free(li.output);

}

void testTRAP2(){

    char* testID = "TRAP2";

    LineInfo li;
    li.input = "TRAP x22";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    TRAP(li);
    char* expected = "1111000000100010";

    equals(li.output, expected, testID);
    free(li.output);

}