//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include "Func.h"

void LD(char* input, char* output){

    output[0] = '0';
    output[1] = '0';
    output[2] = '1';
    output[3] = '0';

    char reg = input[4];

    writeRegBits(output, reg, 4);

    int pcOffset = charsToInt2(input, 7, 4);

    writeIntBits(output, pcOffset, 15, 9);

}


