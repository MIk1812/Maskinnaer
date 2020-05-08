//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_STR_H
#define PROJEKT2_STR_H

#endif //PROJEKT2_STR_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/STR.h"

void testSTR1();
void testSTR2();

void testSTR(){

    testSTR1();
    testSTR2();

}

void testSTR1(){

    char* testID = "STR1";
    char* input = "STR R1, R2, #3";
    char* output = (char*) calloc(1, 17);

    STR(input, output);
    char* expected = "0111001010000011";


    equals(output, expected, testID);
    free(output);
}

void testSTR2(){

    char* testID = "STR2";
    char* input = "STR R1, R3, #-3";
    char* output = (char*) calloc(1, 17);

    STR(input, output);
    char* expected = "0111001011111101";


    equals(output, expected, testID);
    free(output);
}