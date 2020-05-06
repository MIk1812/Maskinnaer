//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include "Func.h"
#include "../Opcodes/LD.h"

void testLD1();
void testLD2();

void testLD(){

    testLD1();
    testLD2();

}

void testLD1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) calloc(1, 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    equals(output, expected, testID);

}


void testLD2(){

    char* testID = "LD2";
    char* input = "LD R1, #3";
    char* output = (char*) calloc(1, 17);

    LD(input, output);
    char* expected = "0010001000000011";

    free(output);
    equals(output, expected, testID);

}