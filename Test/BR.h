//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_BR_H
#define PROJEKT2_BR_H

#endif //PROJEKT2_BR_H

#include "Func.h"
#include "../Opcodes/BR.h"

bool testBR1();
bool testBR2();

bool testBR(){

    if(testBR1() != true)
        return false;

    if(testBR2() != true)
        return false;

}

bool testBR1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}

bool testBR2(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}