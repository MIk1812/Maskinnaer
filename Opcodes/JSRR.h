//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JSRRR_H
#define PROJEKT2_JSRRR_H

#endif //PROJEKT2_JSRRR_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void JSRR(char* input, char* output, int firstIndex){

    //JSRR R4

    output[0] = '0';
    output[1] = '1';
    output[2] = '0';
    output[3] = '0';

    output[4] = '0';
    output[5] = '0';
    output[6] = '0';

    char regDst = input[6+firstIndex];

    writeRegBits(output, regDst, 7);

    for (int i = 0; i < 6; ++i) {
        output[i+10] = '0';
    }

}
