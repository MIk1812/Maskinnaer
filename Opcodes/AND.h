//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_AND_H
#define PROJEKT2_AND_H

#endif //PROJEKT2_AND_H

#pragma once
#include "Func.h"

void AND(char* input, char* output){

    //AND R1, R2, R3
    //AND R1, R2, #11
    
    output[0] = '0';
    output[1] = '1';
    output[2] = '0';
    output[3] = '1';

    char regDst = input[5];
    char regSrc1 = input[9];

    writeRegBits(output, regDst, 4);
    writeRegBits(output, regSrc1, 7);

    //If register mode
    if(input[12] != '#'){

        char regSrc2 = input[13];
        writeRegBits(output, regSrc2, 13);

        output[10] = '0';
        output[11] = '0';
        output[12] = '0';

    } else{

        output[10] = '1';

        int pcOffset = charsToInt(input, 13, 3);

        writeIntBits(output, pcOffset, 15, 5);

    }

}