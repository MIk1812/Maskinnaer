//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_AND_H
#define PROJEKT2_AND_H

#endif //PROJEKT2_AND_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void AND(LineInfo li){

    //AND R1, R2, R3
    //AND R1, R2, #11
    
    li.output[0] = '0';
    li.output[1] = '1';
    li.output[2] = '0';
    li.output[3] = '1';

    char regDst = li.input[5 + li.firstIndex];
    char regSrc1 = li.input[9 + li.firstIndex];

    writeRegBits(li.output, regDst, 4);
    writeRegBits(li.output, regSrc1, 7);

    //If register mode
    if(li.input[12 + li.firstIndex] != '#'){

        char regSrc2 = li.input[13 + li.firstIndex];
        writeRegBits(li.output, regSrc2, 13 + li.firstIndex);

        li.output[10] = '0';
        li.output[11] = '0';
        li.output[12] = '0';

    } else{

        li.output[10] = '1';

        int pcOffset = charsToInt(li.input, 12 + li.firstIndex, 3);

        writeIntBits(li.output, pcOffset, 15, 5);

    }

}