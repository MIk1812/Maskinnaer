//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDR_H
#define PROJEKT2_TESTLDR_H

#endif //PROJEKT2_TESTLDR_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/LDR.h"

void testLDR1();
void testLDR2();

void testLDR(){

    testLDR1();
    testLDR2();

}

void testLDR1(){

    char* testID = "LDR1";
    char* input = "LDR R1, R2, #29";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LDR(input, output,0);
    char* expected = "0110001010011101";

    equals(output, expected, testID);
    free(output);

}

void testLDR2(){

    char* testID = "LDR2";
    char* input = "LDR R1, R2, #-10";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LDR(input, output,0);
    char* expected = "0110001010110110";

    equals(output, expected, testID);
    free(output);

}