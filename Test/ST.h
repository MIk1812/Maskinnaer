//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ST_H
#define PROJEKT2_ST_H

#endif //PROJEKT2_ST_H

#include "Func.h"
#include "../Opcodes/ST.h"

void testST1();
void testST2();

void testST(){

    testST1();
    testST2();

}

void testST1(){

    char* testID = "ST1";
    char* input = "ST R1, #3";
    char* output = (char*) calloc(1, 17);

    LD(input, output);
    char* expected = "0011001000000011";

    free(output);
    equals(output, expected, testID);

}

void testST2(){

    char* testID = "ST2";
    char* input = "ST R1, #-3";
    char* output = (char*) calloc(1, 17);

    LD(input, output);
    char* expected = "0011001111111101";

    free(output);
    equals(output, expected, testID);

}