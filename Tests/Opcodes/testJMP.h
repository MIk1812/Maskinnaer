//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JMP_H
#define PROJEKT2_JMP_H

#endif //PROJEKT2_JMP_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/JMP.h"

void testJMP1();
void testJMP2();

void testJMP(){

    testJMP1();
    testJMP2();

}

void testJMP1(){

    char* testID = "JMP1";

    LineInfo li;
    li.input = "JMP R4";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    JMP(li);
    char* expected = "1100000100000000";

    equals(li.output, expected, testID);
    free(li.output);

}

void testJMP2(){

    char* testID = "JMP2";

    LineInfo li;
    li.input = "JMP R2";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    JMP(li);
    char* expected = "1100000010000000";

    equals(li.output, expected, testID);
    free(li.output);

}