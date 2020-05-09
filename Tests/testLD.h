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
void testLD3();

void testLD(){

    testLD1();
    testLD2();

    char labels[2][30] = {
            "labelNotToUse",
            "labelToUse"
    };

    int* locations = {3,7};

    testLD3(labels, locations);

}

void testLD1(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) calloc(1, 17);

    LD(input, output, 0, NULL, 0, NULL, 30);
    char* expected = "0010001111111101";

    equals(output, expected, testID);
    free(output);

}


void testLD2(){

    char* testID = "LD2";
    char* input = "LD R1, #3";
    char* output = (char*) calloc(1, 17);

    LD(input, output, 0, NULL, 0, NULL, 30);
    char* expected = "0010001000000011";

    equals(output, expected, testID);
    free(output);

}


void testLD3(char** labels, int* locations){
//
//    char* testID = "LD3";
//    char* input = "labelNotToUse LD R1, labelToUse";
//    char* output = (char*) calloc(1, 17);
//
//    LD(input, output, 14, labels, 2, locations, 30);
//    char* expected = "0010001000000011";
//
//    equals(output, expected, testID);
//    free(output);

}