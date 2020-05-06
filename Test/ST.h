//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ST_H
#define PROJEKT2_ST_H

#endif //PROJEKT2_ST_H

#include "Func.h"
#include "../Opcodes/ST.h"

bool testST1();
bool testST2();

bool testST(){

    if(testST1() != true)
        return false;

    if(testST2() != true)
        return false;

}

bool testST1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}

bool testST2(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}