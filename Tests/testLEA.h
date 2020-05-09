//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDR_H
#define PROJEKT2_TESTLDR_H

#endif //PROJEKT2_TESTLDR_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/LEA.h"


void testLEA1();
void testLEA2();

void testLEA(){

    testLEA1();
    testLEA2();

}

void testLEA1(){

    char* testID = "LEA1";
    char* input = "LEA R1, #13";
    char* output = (char*) calloc(1, 17);

    LEA(input, output,0, NULL, 0, NULL, 30);
    char* expected = "1110001000001101";

    equals(output, expected, testID);
    free(output);

}

void testLEA2(){

    char* testID = "LEA2";
    char* input = "LEA R3, #-26";
    char* output = (char*) calloc(1, 17);

    LEA(input, output,0, NULL, 0, NULL, 30);
    char* expected = "1110011111100110";

    equals(output, expected, testID);
    free(output);

}