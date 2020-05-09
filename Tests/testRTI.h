//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_RESTRTI_H
#define PROJEKT2_RESTRTI_H

#endif //PROJEKT2_RESTRTI_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/RTI.h"

void testRTI1();

void testRTI(){

    testRTI1();

}

void testRTI1(){

    char* testID = "RTI1";
    char* input = "RTI";
    char* output = (char*) calloc(1, 17);

    RTI(input, output,NULL);
    char* expected = "1000000000000000";

    equals(output, expected, testID);
    free(output);

}