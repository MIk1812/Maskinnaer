//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_LDI_H
#define PROJEKT2_LDI_H

#endif //PROJEKT2_LDI_H

#include "func.h"

void LDI(char* input, char* output) {

    //LDI R1, #10

    output[0] = '1';
    output[1] = '0';
    output[2] = '1';
    output[3] = '0';

    char regDst = input[5];

    writeRegBits(output, regDst, 4);

    int pcOffset = charsToInt(input, 9, 4);

    writeIntBits(output, pcOffset, 15, 9);

}