//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDI_H
#define PROJEKT2_TESTLDI_H

#endif //PROJEKT2_TESTLDI_H


#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/LDI.h"

void testLDI1();
void testLDI2();
void testLDI3();

void testLDI(){

    testLDI1();
    testLDI2();
    testLDI3();

}

void testLDI1(){
    
    char* testID = "LDI1";

    LineInfo li;
    li.input = "LDI R7, #212";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LDI(li);
    char* expected = "1010111011010100";

    equals(li.output, expected, testID);
    free(li.output);

}

void testLDI2(){

    char* testID = "LDI2";

    LineInfo li;
    li.input = "LDI R3, #-193";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LDI(li);
    char* expected = "1010011100111111";

    equals(li.output, expected, testID);
    free(li.output);

}

//Test labels
void testLDI3(){

    char* testID = "LDI3";

    LineInfo li;
    li.input = "label3 LDI R1, label7";
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

    LDI(li);
    char* expected = "1010001000000010";

    equals(li.output, expected, testID);
    free(li.output);

}