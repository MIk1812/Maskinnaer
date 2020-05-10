//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JSR_H
#define PROJEKT2_JSR_H

#endif //PROJEKT2_JSR_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void JSR(LineInfo li){

    //JSR #943
    //JSR LABEL

    int labelIndexInput = 4;
    int labelLengthInput = 5;
    int labelBitsOutput = 11;
    int lastIndex = 15;
    
    li.output[0] = '0';
    li.output[1] = '1';
    li.output[2] = '0';
    li.output[3] = '0';

    li.output[4] = '1';

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);
    }

}

