//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include <string.h>

#include "../Functionality/FuncOpcodes.h"
#include "../Functionality/FuncIO.h"

void LD(char* input, char* output, int firstIndex, char** labels, int numberOfLabels, int* locations, int inputSize){

    //LD R1, #3
    //LD R1, x3
    //LD R1, LABEL

    output[0] = '0';
    output[1] = '0';
    output[2] = '1';
    output[3] = '0';

    char reg = input[4 + firstIndex];

    writeRegBits(output, reg, 4);


    char labelOrNot = input[firstIndex + 7];

    //Test wether instructin constains label reference or not
    if( labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(input, 7 + firstIndex, 4);
        writeIntBits(output, pcOffset, 15, 9);

    } else{

        //Isolate labels from input
        char* inputLabel = isolateChars(input,  7 + firstIndex, inputSize);

//
//
//
//        //Go through labels to find match
//        for (int i = 0; i < numberOfLabels; ++i) {
//
//            char* currentLabel = *(labels+i);
//
//            //If we have a match
//            if(strcmp(currentLabel, ))
//
//        }

    }



}


