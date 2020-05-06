//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

#include "Func.h"
#include "../Opcodes/NOT.h"

void testNOT1();
void testNOT2();

void testNOT(){

    testNOT1();
    testNOT2();

}

void testNOT1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    equals(output, expected, testID);

}

void testNOT2(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    equals(output, expected, testID);

}