//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_STI_H
#define PROJEKT2_STI_H

#endif //PROJEKT2_STI_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/STI.h"

void testSTI1();
void testSTI2();

void testSTI(){

    testSTI1();
    testSTI2();

}

void testSTI1(){

    char* testID = "STI1";
    char* input = "STI R1, #3";
    char* output = (char*) calloc(1, 17);

    STI(input, output);
    char* expected = "1011001000000011";

    equals(output, expected, testID);
    free(output);

}

void testSTI2(){

    char* testID = "STI2";
    char* input = "STI R1, #-3";
    char* output = (char*) calloc(1, 17);

    STI(input, output);
    char* expected = "1011001111111101";

    equals(output, expected, testID);
    free(output);

}