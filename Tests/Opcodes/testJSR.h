//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JSR_H
#define PROJEKT2_JSR_H

#endif //PROJEKT2_JSR_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/JSR.h"

void testJSR1();
void testJSR2();
void testJSR3();

void testJSR(){

    testJSR1();
    testJSR2();
    testJSR3();

}

void testJSR1(){

    char* testID = "JSR1";

    LineInfo li;
    li.input = "JSR #932";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    JSR(li);
    char* expected = "0100101110100100";

    equals(li.output, expected, testID);
    free(li.output);

}


void testJSR2(){

    char* testID = "JSR2";

    LineInfo li;
    li.input = "JSR #-336";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    JSR(li);
    char* expected = "0100111010110000";

    equals(li.output, expected, testID);
    free(li.output);

}


//Test labels
void testJSR3(){

    char* testID = "JSR3";

    LineInfo li;
    li.input = "label3 JSR label7";
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

    JSR(li);
    char* expected = "0100100000000010";

    equals(li.output, expected, testID);
    free(li.output);

}