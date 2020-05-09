//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDR_H
#define PROJEKT2_TESTLDR_H

#endif //PROJEKT2_TESTLDR_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/LEA.h"


void testLEA1();
void testLEA2();
void testLEA3();

void testLEA(){

    testLEA1();
    testLEA2();
    testLEA3();

}

void testLEA1(){

    char* testID = "LEA1";

    LineInfo li;
    li.input = "LEA R1, #13";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LEA(li);
    char* expected = "1110001000001101";

    equals(li.output, expected, testID);
    free(li.output);

}

void testLEA2(){

    char* testID = "LEA2";

    LineInfo li;
    li.input = "LEA R3, #-26";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LEA(li);
    char* expected = "1110011111100110";

    equals(li.output, expected, testID);
    free(li.output);

}

//Test labels
void testLEA3(){

    char* testID = "LEA3";

    LineInfo li;
    li.input = "label3 LEA R3, label7";
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

    LEA(li);
    char* expected = "1110011000000010";

    equals(li.output, expected, testID);
    free(li.output);

}