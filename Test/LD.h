//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include "Func.h"

bool testLD1();
bool testLD2();

bool testLD(){

    if(testLD1() != true)
        return false;

    if(testLD2() != true)
        return false;

}

bool testLD1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    return equals(output, expected, testID);

}

bool testLD2(){

    char* testID = "LD2";
    char* input = "LD R1, #3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001000000011";

    free(output);
    return equals(output, expected, testID);

}