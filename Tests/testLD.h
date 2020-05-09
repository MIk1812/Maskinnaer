//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/LD.h"

void testLD1();
void testLD2();
void testLD3(char** labels, int* locations);

void testLD(){

    testLD1();
    testLD2();

    char* label1 = "label3";
    char* label2 = "label7";
    char** labels[] = {label1, label2};

    int* locations = (int*) malloc(sizeof(int) * 2);
    locations[0] = 3;
    locations[1] = 7;

    testLD3(labels, locations);

}

void testLD1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LD(input, output, 0, NULL, 0, NULL, 30, 0);
    char* expected = "0010001111111101";

    equals(output, expected, testID);
    free(output);

}


void testLD2(){

    char* testID = "LD2";
    char* input = "LD R1, #3";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LD(input, output, 0, NULL, 0, NULL, 30,0);
    char* expected = "0010001000000011";

    equals(output, expected, testID);
    free(output);

}

//Test labels
void testLD3(char** labels, int locations[]){

    char* testID = "LD3";
    char* input = "label3 LD R1, label7";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    LD(input, output, 7, labels, 2, locations, 30,4);
    char* expected = "0010001000000010";

    equals(output, expected, testID);
    free(output);

}