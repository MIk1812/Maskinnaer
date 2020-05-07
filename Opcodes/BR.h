//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_BR_H
#define PROJEKT2_BR_H

#endif //PROJEKT2_BR_H

#include "Func.h"

void BR(char* input, char* output) {
    output[0] = '0';
    output[1] = '0';
    output[2] = '0';
    output[3] = '0';

    // set correct operation bit n,z,p
    nzp_Operation(input, output);
    int count = 0; // count til '#' to read where pcoff begins.
    for (int i = 0; i < 30 ; ++i) {
        if(input[i] =='#')
            break;
        count++;
    }

    int pcoff = charsToInt2(input,count,4);
    writeIntBits(output,pcoff,15,9);

}