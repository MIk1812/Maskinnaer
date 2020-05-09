//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_AND_H
#define PROJEKT2_AND_H

#endif //PROJEKT2_AND_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void AND(char* input, char* output, int firstIndex){

    //AND R1, R2, R3
    //AND R1, R2, #11
    
    output[0] = '0';
    output[1] = '1';
    output[2] = '0';
    output[3] = '1';

    char regDst = input[5 + firstIndex];
    char regSrc1 = input[9 + firstIndex];

    writeRegBits(output, regDst, 4);
    writeRegBits(output, regSrc1, 7);

    //If register mode
    if(input[12+firstIndex] != '#'){

        char regSrc2 = input[13+firstIndex];
        writeRegBits(output, regSrc2, 13+firstIndex);

        output[10] = '0';
        output[11] = '0';
        output[12] = '0';

    } else{

        output[10] = '1';

        int pcOffset = charsToInt(input, 12+firstIndex, 3);

        writeIntBits(output, pcOffset, 15, 5);

    }

}