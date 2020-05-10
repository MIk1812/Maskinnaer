//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_RESTRTI_H
#define PROJEKT2_RESTRTI_H

#endif //PROJEKT2_RESTRTI_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/RTI.h"

void testRTI1();

void testRTI(){

    testRTI1();

}

void testRTI1(){

    char* testID = "RTI1";

    LineInfo li;
    li.input = "RTI";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    RTI(li);
    char* expected = "1000000000000000";

    equals(li.output, expected, testID);
    free(li.output);

}