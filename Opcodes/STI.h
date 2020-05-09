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
    int pcOffsetIndex = 8;
    int pcOffsetLength = 4;
    int pcOffsetBits = 9;
    int lastIndex = 15;

    li.output[0] = '1';
    li.output[1] = '0';
    li.output[2] = '1';
    li.output[3] = '1';

    char reg = li.input[regIndexInput + li.firstIndex];

    writeRegBits(li.output, reg, regIndexOutput);

    char labelOrNot = li.input[li.firstIndex + pcOffsetIndex];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, pcOffsetIndex + li.firstIndex, pcOffsetLength);
        writeIntBits(li.output, pcOffset, lastIndex, pcOffsetBits);

    } else{

        writeLabelBits(li, pcOffsetIndex, pcOffsetBits, lastIndex);
    }
}