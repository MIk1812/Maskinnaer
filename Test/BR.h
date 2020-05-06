//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_BR_H
#define PROJEKT2_BR_H

#endif //PROJEKT2_BR_H

#include "Func.h"
#include "../Opcodes/BR.h"

void testBR1();
void testBR2();

void testBR(){

    testBR1();
    testBR2();

}

void testBR1(){

    char* testID = "BR1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    equals(output, expected, testID);

}

void testBR2(){

    char* testID = "BR2";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    equals(output, expected, testID);

}