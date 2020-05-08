//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTRET_H
#define PROJEKT2_TESTRET_H

#endif //PROJEKT2_TESTRET_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/RET.h"

void testRET1();

void testRET(){

    testRET1();

}

void testRET1(){

    char* testID = "RET1";
    char* input = "RET";
    char* output = (char*) calloc(1, 17);

    RET(input, output);
    char* expected = "1100000111000000";

    equals(output, expected, testID);
    free(output);

}