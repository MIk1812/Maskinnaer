//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_STR_H
#define PROJEKT2_STR_H

#endif //PROJEKT2_STR_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/STR.h"

void testSTR1();
void testSTR2();

void testSTR(){

    testSTR1();
    testSTR2();

}

void testSTR1(){

    char* testID = "STI1";

    LineInfo li;
    li.input = "STR R1, R2, #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    STR(li);
    char* expected = "0111001010000011";

    equals(li.output, expected, testID);
    free(li.output);
    
}

void testSTR2(){

    char* testID = "STI2";

    LineInfo li;
    li.input = "STR R1, R3, #-3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    STR(li);
    char* expected = "0111001011111101";

    equals(li.output, expected, testID);
    free(li.output);
    
}

void testSTR3(){

    char* testID = "STR3";

    LineInfo li;
    li.input = "label3 STR R1, R2, label7";
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

    STI(li);
    char* expected = "0111001010000010";

    equals(li.output, expected, testID);
    free(li.output);

}