//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

#include "Func.h"
#include "../Opcodes/ADD.h"

bool testADD1();
bool testADD2();

bool testADD(){

    if(testADD1() != true)
        return false;

    if(testADD2() != true)
        return false;

}

bool testADD1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}

bool testADD2(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}