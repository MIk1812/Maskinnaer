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
void testST3();

void testST(){

    testST1();
    testST2();
    testST3();

}

void testST1(){

    char* testID = "ST1";

    LineInfo li;
    li.input = "ST R1, #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    ST(li);
    char* expected = "0011001000000011";

    equals(li.output, expected, testID);
    free(li.output);

}

void testST2(){

    char* testID = "ST2";

    LineInfo li;
    li.input = "ST R1, #-3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    ST(li);
    char* expected = "0011001111111101";

    equals(li.output, expected, testID);
    free(li.output);

}

void testST3(){

    char* testID = "ST3";

    LineInfo li;
    li.input = "label3 ST R1, label7";
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

    ST(li);
    char* expected = "0011001000000010";

    equals(li.output, expected, testID);
    free(li.output);
    
}