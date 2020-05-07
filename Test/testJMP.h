//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JMP_H
#define PROJEKT2_JMP_H

#endif //PROJEKT2_JMP_H

#include "testFunc.h"
#include "../Opcodes/JMP.h"

void testJMP1();
void testJMP2();

void testJMP(){

    testJMP1();
    testJMP2();

}

void testJMP1(){

    char* testID = "JMP1";
    char* input = "JMP R4";
    char* output = (char*) calloc(1, 17);

    JMP(input, output);
    char* expected = "1100000100000000";

    equals(output, expected, testID);
    free(output);

}

void testJMP2(){

    char* testID = "JMP2";
    char* input = "JMP R2";
    char* output = (char*) calloc(1, 17);

    JMP(input, output);
    char* expected = "1100000010000000";

    equals(output, expected, testID);
    free(output);

}