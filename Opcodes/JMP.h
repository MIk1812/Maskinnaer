//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JMP_H
#define PROJEKT2_JMP_H

#endif //PROJEKT2_JMP_H

#pragma once
#include "Func.h"

void JMP(char* input, char* output) {

    //JMP R4

    output[0] = '1';
    output[1] = '1';
    output[2] = '0';
    output[3] = '0';

    output[4] = '0';
    output[5] = '0';
    output[6] = '0';

    char regDst = input[5];

    writeRegBits(output, regDst, 7);

    for (int i = 0; i < 6; ++i) {
        output[i + 10] = '0';
    }

}