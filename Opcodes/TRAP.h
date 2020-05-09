//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TRAP_H
#define PROJEKT2_TRAP_H

#endif //PROJEKT2_TRAP_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void TRAP(char* input, char* output, int firstIndex){

    //TRAP x22
    //TRAP #34

    output[0] = '1';
    output[1] = '1';
    output[2] = '1';
    output[3] = '1';

    output[4] = '0';
    output[5] = '0';
    output[6] = '0';
    output[7] = '0';

    int pcOffset = charsToInt(input, 5+firstIndex, 4);

    writeIntBits(output, pcOffset, 15, 8);


}