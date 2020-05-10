//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_STR_H
#define PROJEKT2_STR_H

#endif //PROJEKT2_STR_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/STR.h"

void testSTR1();
void testSTR2();

void testSTR(){

    testSTR1();
    testSTR2();

}

void testSTR1(){

    char* testID = "STI1";

    LineInfo li;
    li.input = "STR R1, R2, #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    STR(li);
    char* expected = "0111001010000011";

    equals(li.output, expected, testID);
    free(li.output);
    
}

void testSTR2(){

    char* testID = "STI2";

    LineInfo li;
    li.input = "STR R1, R3, #-3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    STR(li);
    char* expected = "0111001011111101";

    equals(li.output, expected, testID);
    free(li.output);
    
}
