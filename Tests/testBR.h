//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_BR_H
#define PROJEKT2_BR_H

#endif //PROJEKT2_BR_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/BR.h"

void testBR1();
void testBR2();
void testBR3();

void testBR(){

    testBR1();
    testBR2();
    testBR3();

}

void testBR1(){

    char* testID = "BR1";

    LineInfo li;
    li.input = "BRnzp #10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    BR(li);
    char* expected = "0000111000001010";

    equals(li.output, expected, testID);
    free(li.output);

}

void testBR2(){

    char* testID = "BR2";

    LineInfo li;
    li.input = "BRnz #10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    BR(li);
    char* expected = "0000110000001010";

    equals(li.output, expected, testID);
    free(li.output);

}

//Test labels
void testBR3(){

    char* testID = "BR3";

    LineInfo li;
    li.input = "label3 BRp label7";
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

    BR(li);
    char* expected = "0000001000000010";

    equals(li.output, expected, testID);
    free(li.output);

}