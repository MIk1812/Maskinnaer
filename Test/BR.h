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
    char* input = "BRnzp #10";
    char* output = (char*) calloc(1, 17);

    BR(input, output);
    char* expected = "0000111000001010";

    free(output);
    equals(output, expected, testID);

}

void testBR2(){

    char* testID = "BR2";
    char* input = "BRnz #10";
    char* output = (char*) calloc(1, 17);

    BR(input, output);
    char* expected = "0000110000001010";

    free(output);
    equals(output, expected, testID);

}