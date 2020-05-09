//
// Created by buttt on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_STI_H
#define PROJEKT2_STI_H

#endif //PROJEKT2_STI_H
#include "../Functionality/FuncOpcodes.h"
void STI(LineInfo li) {

    //STI R1, #3
    //STI R1, LABEL

    int regIndexInput = 5;
    int regIndexOutput = 4;
    int labelIndexInput = 8;
    int labelLengthInput = 4;
    int labelBitsOutput = 9;
    int lastIndex = 15;

    li.output[0] = '1';
    li.output[1] = '0';
    li.output[2] = '1';
    li.output[3] = '1';

    char reg = li.input[regIndexInput + li.firstIndex];

    writeRegBits(li.output, reg, regIndexOutput);

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);
    }
}