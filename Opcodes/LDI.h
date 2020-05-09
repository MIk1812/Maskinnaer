//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LDI_H
#define PROJEKT2_LDI_H

#endif //PROJEKT2_LDI_H

#include "../Functionality/FuncOpcodes.h"

void LDI(LineInfo li) {

    //LDI R1, #10
    //LDI R1, LABEL

    int regIndexInput = 5;
    int regIndexOutput = 4;
    int labelIndexInput = 8;
    int labelLengthInput = 4;
    int labelBitsOutput = 9;
    int lastIndex = 15;

    li.output[0] = '1';
    li.output[1] = '0';
    li.output[2] = '1';
    li.output[3] = '0';

    char regDst = li.input[regIndexInput + li.firstIndex];

    writeRegBits(li.output, regDst, regIndexOutput);

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);
    }

}