//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LDI_H
#define PROJEKT2_LDI_H

#endif //PROJEKT2_LDI_H

#include "Func.h"

void LDI(char* input, char* output) {

    //LDI R1, #10

    output[0] = '1';
    output[1] = '0';
    output[2] = '1';
    output[3] = '0';

    char regDst = input[5];

    writeRegBits(output, regDst, 4);

    int pcOffset = charsToInt2(input, 8, 4);

    writeIntBits(output, pcOffset, 15, 9);

}