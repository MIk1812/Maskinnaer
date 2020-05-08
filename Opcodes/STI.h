//
// Created by buttt on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_STI_H
#define PROJEKT2_STI_H

#endif //PROJEKT2_STI_H
#include "../Functionality/FuncOpcodes.h"
void STI(char* input, char* output) {
    output[0] = '1';
    output[1] = '0';
    output[2] = '1';
    output[3] = '1';

    char reg = input[5];

    writeRegBits(output, reg, 4);
    int pcoff = charsToInt(input, 8, 4);
    writeIntBits(output, pcoff, 15, 9);
}