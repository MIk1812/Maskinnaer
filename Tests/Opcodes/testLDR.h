//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDR_H
#define PROJEKT2_TESTLDR_H

#endif //PROJEKT2_TESTLDR_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/LDR.h"

void testLDR1();
void testLDR2();

void testLDR(){

    testLDR1();
    testLDR2();

}

void testLDR1(){

    char* testID = "LDR1";

    LineInfo li;
    li.input = "LDR R1, R2, #29";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LDR(li);
    char* expected = "0110001010011101";

    equals(li.output, expected, testID);
    free(li.output);

}

void testLDR2(){

    char* testID = "LDR2";

    LineInfo li;
    li.input = "LDR R1, R2, #-10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LDR(li);
    char* expected = "0110001010110110";

    equals(li.output, expected, testID);
    free(li.output);

}
