//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

#include "testFunc.h"
#include "../Opcodes/NOT.h"

void testNOT1();
void testNOT2();

void testNOT(){

    testNOT1();
    testNOT2();

}

void testNOT1(){

    char* testID = "NOT1";
    char* input = "NOT R1, R2";
    char* output = (char*) calloc(1, 17);

    NOT(input, output);
    char* expected = "1001001010111111";


    equals(output, expected, testID);
    free(output);
}

void testNOT2(){

    char* testID = "NOT2";
    char* input = "NOT R2, R1";
    char* output = (char*) calloc(1, 17);

    NOT(input, output);
    char* expected = "1001010001111111";


    equals(output, expected, testID);
    free(output);
}