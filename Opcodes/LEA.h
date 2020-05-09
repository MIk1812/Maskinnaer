//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LEA_H
#define PROJEKT2_LEA_H

#endif //PROJEKT2_LEA_H

#include "../Functionality/FuncOpcodes.h"

void LEA(char* input, char* output, int firstIndex, char** labels, int numberOfLabels, int* locations, int inputSize){

    //LEA R1, #10

    output[0] = '1';
    output[1] = '1';
    output[2] = '1';
    output[3] = '0';

    char regDst = input[5+firstIndex];

    writeRegBits(output, regDst, 4);

    char labelOrNot = input[firstIndex + 8];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(input, 8 + firstIndex, 4);
        writeIntBits(output, pcOffset, 15, 9);

    } else{

        //Isolate label from input
        char* inputLabel = (char*) calloc(1, inputSize);
        isolateChars(input,  8 + firstIndex, inputSize, inputLabel);

        int matchIndex = NULL;

        //Go through labels to find match
        for (int i = 0; i < numberOfLabels; ++i) {

            char* currentLabel = *(labels + i);

            //If we have a match
            if(strcmp(currentLabel, inputLabel) == 0){
                matchIndex = i;
                break;
            }
        }

        writeIntBits(output, locations[matchIndex], 15, 9);
    }




}