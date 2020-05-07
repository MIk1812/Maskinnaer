//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LEA_H
#define PROJEKT2_LEA_H

#endif //PROJEKT2_LEA_H

#include "Func.h"

void LEA(char* input, char* output){

    //LEA R1, #10

    output[0] = '1';
    output[1] = '1';
    output[2] = '1';
    output[3] = '0';

    char regDst = input[5];

    writeRegBits(output, regDst, 4);

    int pcOffset = charsToInt2(input, 8,4);

    writeIntBits(output, pcOffset, 15, 9);

}