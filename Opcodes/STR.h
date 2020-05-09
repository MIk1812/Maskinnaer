#pragma once
#ifndef PROJEKT2_STM_H
#define PROJEKT2_STM_H

#endif //PROJEKT2_STM_H
#include "../Functionality/FuncOpcodes.h"

void STR(char* input, char* output,int firstIndex) {
    output[0] = '0';
    output[1] = '1';
    output[2] = '1';
    output[3] = '1';

    char Sreg = input[5+firstIndex]; //source register
    writeRegBits(output,Sreg,4);
    char BaseR = input[9+firstIndex]; //
    writeRegBits(output,BaseR,7);
    int pcoff = charsToInt(input, 12+firstIndex, 3);
    writeIntBits(output,pcoff,15,6);

}