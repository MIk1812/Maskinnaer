//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/NOT.h"

void testNOT1();
void testNOT2();

void testNOT(){

    testNOT1();
    testNOT2();

}

void testNOT1(){

    char* testID = "NOT1";

    LineInfo li;
    li.input = "NOT R1, R2";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    NOT(li);
    char* expected = "1001001010111111";

    equals(li.output, expected, testID);
    free(li.output);

}

void testNOT2(){

    char* testID = "NOT2";

    LineInfo li;
    li.input = "NOT R2, R1";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    NOT(li);
    char* expected = "1001010001111111";

    equals(li.output, expected, testID);
    free(li.output);

}