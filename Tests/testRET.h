//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTRET_H
#define PROJEKT2_TESTRET_H

#endif //PROJEKT2_TESTRET_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/RET.h"

void testRET1();

void testRET(){

    testRET1();

}

void testRET1(){

    char* testID = "RET1";

    LineInfo li;
    li.input = "RET";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    RET(li);
    char* expected = "1100000111000000";

    equals(li.output, expected, testID);
    free(li.output);

}