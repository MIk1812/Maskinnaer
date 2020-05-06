//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

#include "Func.h"
#include "../Opcodes/NOT.h"

bool testNOT1();
bool testNOT2();

bool testNOT(){

    if(testNOT1() != true)
        return false;

    if(testNOT2() != true)
        return false;

}

bool testNOT1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}

bool testNOT2(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}