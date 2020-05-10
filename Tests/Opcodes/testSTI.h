//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_STI_H
#define PROJEKT2_STI_H

#endif //PROJEKT2_STI_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/STI.h"

void testSTI1();
void testSTI2();
void testSTI3();

void testSTI(){

    testSTI1();
    testSTI2();
    testSTI3();

}

void testSTI1(){

    char* testID = "STI1";

    LineInfo li;
    li.input = "STI R1, #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    STI(li);
    char* expected = "1011001000000011";

    equals(li.output, expected, testID);
    free(li.output);

}

void testSTI2(){

    char* testID = "STI2";

    LineInfo li;
    li.input = "STI R1, #-3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    STI(li);
    char* expected = "1011001111111101";

    equals(li.output, expected, testID);
    free(li.output);
    
}

void testSTI3(){

    char* testID = "STI3";

    LineInfo li;
    li.input = "label3 STI R1, label7";
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
    char* expected = "1011001000000010";

    equals(li.output, expected, testID);
    free(li.output);

}