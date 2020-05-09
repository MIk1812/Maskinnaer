//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LDR_H
#define PROJEKT2_LDR_H

#endif //PROJEKT2_LDR_H

#include "../Functionality/FuncOpcodes.h"

void LDR(char* input, char* output, int firstIndex){

    //LDR R1, R2, #3

    output[0] = '0';
    output[1] = '1';
    output[2] = '1';
    output[3] = '0';

    char regDst = input[5+firstIndex];
    char regBase = input[9+firstIndex];

    writeRegBits(output, regDst, 4);
    writeRegBits(output, regBase, 7);

    int pcOffset = charsToInt(input, 12+firstIndex, 3);

    writeIntBits(output, pcOffset, 15, 6);

}