//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JSRRR_H
#define PROJEKT2_JSRRR_H

#endif //PROJEKT2_JSRRR_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/JSRR.h"

void testJSRR1();
void testJSRR2();

void testJSRR(){

    testJSRR1();
    testJSRR2();

}

void testJSRR1(){

    char* testID = "JSRR1";

    LineInfo li;
    li.input = "JSRR R4";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    JSRR(li);
    char* expected = "0100000100000000";

    equals(li.output, expected, testID);
    free(li.output);

}


void testJSRR2(){

    char* testID = "JSRR1";

    LineInfo li;
    li.input = "JSRR R7";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    JSRR(li);
    char* expected = "0100000111000000";

    equals(li.output, expected, testID);
    free(li.output);

}
