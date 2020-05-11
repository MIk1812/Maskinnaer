//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

#include "../../Functionality/FuncTest.h"
#include "../../Opcodes/ADD.h"

void testADD1();
void testADD2();
void testADD3();

void testADD(){

    testADD1();
    testADD2();
    testADD3();

}

void testADD1(){

    char* testID = "ADD1";

    LineInfo li;
    li.input = "ADD R1, R2, R3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    ADD(li);
    char* expected = "0001001010000011";

    equals(li.output, expected, testID);
    free(li.output);

}

void testADD2(){

    char* testID = "ADD2";

    LineInfo li;
    li.input = "ADD R1, R2, #10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    ADD(li);
    char* expected = "0001001010101010";

    equals(li.output, expected, testID);
    free(li.output);
}

void testADD3(){

    char* testID = "ADD3";

    LineInfo li;
    li.input = "ADD R1, R2, #-10";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;

    ADD(li);
    char* expected = "0001001010110110";

    equals(li.output, expected, testID);
    free(li.output);

}