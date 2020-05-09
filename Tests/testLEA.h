//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TESTLDR_H
#define PROJEKT2_TESTLDR_H

#endif //PROJEKT2_TESTLDR_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/LEA.h"


void testLEA1();
void testLEA2();
void testLEA3();

void testLEA(){

    testLEA1();
    testLEA2();

    char* label1 = "label3";
    char* label2 = "label7";
    char** labels[] = {label1, label2};

    int* locations = (int*) malloc(sizeof(int) * 2);
    locations[0] = 3;
    locations[1] = 7;

    testLEA3(labels, locations);

}

void testLEA1(){

    char* testID = "LEA1";
    char* input = "LEA R1, #13";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LEA(input, output,0, NULL, 0, NULL, 30,0);
    char* expected = "1110001000001101";

    equals(output, expected, testID);
    free(output);

}

void testLEA2(){

    char* testID = "LEA2";
    char* input = "LEA R3, #-26";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LEA(input, output,0, NULL, 0, NULL, 30,0);
    char* expected = "1110011111100110";

    equals(output, expected, testID);
    free(output);

}

//Test labels
void testLEA3(char** labels, int locations[]){

    char* testID = "LEA3";
    char* input = "label3 LEA R3, label7";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LEA(input, output, 7, labels, 2, locations, 30,4);
    char* expected = "1110011000000010";

    equals(output, expected, testID);
    free(output);

}