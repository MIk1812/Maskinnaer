//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JSR_H
#define PROJEKT2_JSR_H

#endif //PROJEKT2_JSR_H

#include "testFunc.h"
#include "../Opcodes/JSR.h"

void testJSR1();
void testJSR2();

void testJSR(){

    testJSR1();
    testJSR2();

}

void testJSR1(){

    char* testID = "JSR1";
    char* input = "JSR #932";
    char* output = (char*) calloc(1, 17);

    JSR(input, output);
    char* expected = "0100101110100100";

    equals(output, expected, testID);
    free(output);

}


void testJSR2(){

    char* testID = "JSR2";
    char* input = "JSR #-336";
    char* output = (char*) calloc(1, 17);

    JSR(input, output);
    char* expected = "0100111010110000";

    equals(output, expected, testID);
    free(output);

}