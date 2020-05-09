//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ST_H
#define PROJEKT2_ST_H

#endif //PROJEKT2_ST_H

#include "../Functionality/FuncTest.h"
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

    ST(input, output,NULL);
    char* expected = "0011001000000011";

    equals(output, expected, testID);
    free(output);

}

void testST2(){

    char* testID = "ST2";
    char* input = "ST R1, #-3";
    char* output = (char*) calloc(1, 17);

    ST(input, output,NULL);
    char* expected = "0011001111111101";

    equals(output, expected, testID);
    free(output);

}