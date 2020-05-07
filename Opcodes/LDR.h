//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LDR_H
#define PROJEKT2_LDR_H

#endif //PROJEKT2_LDR_H

#include "Func.h"

void LDR(char* input, char* output){

    //LDR R1, R2, #3

    output[0] = '0';
    output[1] = '1';
    output[2] = '1';
    output[3] = '0';

    char regDst = input[5];
    char regBase = input[9];

    writeRegBits(output, regDst, 4);
    writeRegBits(output, regBase, 7);

    int pcOffset = charsToInt(input, 13,3);

    writeIntBits(output, pcOffset, 15, 6);

}