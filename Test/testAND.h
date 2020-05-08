//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTAND_H
#define PROJEKT2_TESTAND_H

#endif //PROJEKT2_TESTAND_H

#include "testFunc.h"
#include "../Opcodes/AND.h"

void testAND1();
void testAND2();
void testAND3();

void testAND(){

    testAND1();
    testAND2();
    testAND3();

}

void testAND1(){

    char* testID = "AND1";
    char* input = "AND R1, R2, R3";
    char* output = (char*) calloc(1, 17);

    AND(input, output);
    char* expected = "0101001010000011";

    equals(output, expected, testID);
    free(output);

}

void testAND2(){

    char* testID = "AND2";
    char* input = "AND R1, R2, #10";
    char* output = (char*) calloc(1, 17);

    AND(input, output);
    char* expected = "0101001010101010";

    equals(output, expected, testID);
    free(output);

}

void testAND3(){

    char* testID = "AND3";
    char* input = "AND R1, R2, #-10";
    char* output = (char*) calloc(1, 17);

    AND(input, output);
    char* expected = "0101001010110110";

    equals(output, expected, testID);
    free(output);

}