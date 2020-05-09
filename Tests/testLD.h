//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/LD.h"
#include "Struct.h"

void testLD1();
void testLD2();
void testLD3();

void testLD(){

    testLD1();
    testLD2();
    testLD3();

}

void testLD1(){

    char* testID = "LD1";

    LineInfo li;
    li.input = "LD R1, #-3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LD(li);
    char* expected = "0010001111111101";

    equals(li.output, expected, testID);
    free(li.output);

}


void testLD2(){

    char* testID = "LD2";

    LineInfo li;
    li.input = "LD R1, #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    LD(li);

    char* expected = "0010001000000011";

    equals(li.output, expected, testID);
    free(li.output);

}

//Test labels
void testLD3(){

    char* testID = "LD3";

    LineInfo li;
    li.input = "label3 LD R1, label7";
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

    LD(li);
    char* expected = "0010001000000010";

    equals(li.output, expected, testID);
    free(li.output);

}