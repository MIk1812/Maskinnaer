//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTAND_H
#define PROJEKT2_TESTAND_H

#endif //PROJEKT2_TESTAND_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/AND.h"

void testAND1();
void testAND2();
void testAND3();

void testAND(){

    testAND1();
    testAND2();
    testAND3();

}

void testAND1(){

    char* testID = "AND1";

    LineInfo li;
    li.input = "AND R1, R2, R3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    AND(li);
    char* expected = "0101001010000011";

    equals(li.output, expected, testID);
    free(li.output);

}

void testAND2(){

    char* testID = "AND2";

    LineInfo li;
    li.input = "AND R1, R2, #10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    AND(li);
    char* expected = "0101001010101010";

    equals(li.output, expected, testID);
    free(li.output);

}

void testAND3(){

    char* testID = "AND3";

    LineInfo li;
    li.input = "AND R1, R2, #-10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    AND(li);
    char* expected = "0101001010110110";

    equals(li.output, expected, testID);
    free(li.output);


}