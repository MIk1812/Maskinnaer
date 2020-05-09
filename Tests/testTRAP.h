//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTTRAP_H
#define PROJEKT2_TESTTRAP_H

#endif //PROJEKT2_TESTTRAP_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/TRAP.h"

void testTRAP1();
void testTRAP2();

void testTRAP(){

    testTRAP1();
    testTRAP2();

}

void testTRAP1(){

    char* testID = "TRAP1";
    char* input = "TRAP #34";
    char* output = (char*) calloc(1, 17);

    TRAP(input, output,NULL);
    char* expected = "1111000000100010";


    equals(output, expected, testID);
    free(output);
}

void testTRAP2(){

    char* testID = "TRAP2";
    char* input = "TRAP x22";
    char* output = (char*) calloc(1, 17);

    TRAP(input, output,NULL);
    char* expected = "1111000000100010";


    equals(output, expected, testID);
    free(output);
}