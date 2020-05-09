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
void testLDR3();

void testLDR(){

    testLDR1();
    testLDR2();
    testLDR3();

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

//Test labels
void testLDR3(){

    char* testID = "LDR3";

    LineInfo li;
    li.input = "label3 LDR R1, R2, label7";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 7;
    li.lineLength = 30;

    char* label1 = "label3";
    char* label2 = "label7";
    char** labels[] = {label1, label2};

    int* locations = (int*) calloc(1, sizeof(int) * 2);
    locations[0] = 3;
    locations[1] = 7;

    li.symbolTable.labels = labels;
    li.symbolTable.locations = locations;
    li.symbolTable.numberOfLabels = 2;
    li.lineCount = 4;

    LDR(li);
    char* expected = "0110001010000010";

    equals(li.output, expected, testID);
    free(li.output);

}