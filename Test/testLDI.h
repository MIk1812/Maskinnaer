//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDI_H
#define PROJEKT2_TESTLDI_H

#endif //PROJEKT2_TESTLDI_H


#include "testFunc.h"
#include "../Opcodes/LDI.h"

void testLDI1();
void testLDI2();

void testLDI(){

    testLDI1();
    testLDI2();

}

void testLDI1(){

    char* testID = "LDI1";
    char* input = "LDI R7, #212";
    char* output = (char*) calloc(1, 17);

    LDI(input, output);
    char* expected = "1010111011010100";

    equals(output, expected, testID);
    free(output);

}

void testLDI2(){

    char* testID = "LDI2";
    char* input = "LDI R3, #-193";
    char* output = (char*) calloc(1, 17);

    LDI(input, output);
    char* expected = "1010011100111111";

    equals(output, expected, testID);
    free(output);

}