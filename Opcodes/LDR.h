//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LDR_H
#define PROJEKT2_LDR_H

#endif //PROJEKT2_LDR_H

#include "../Functionality/FuncOpcodes.h"

void LDR(LineInfo li){

    //LDR R1, R2, #3
    //LDR R1, R2, LABEL

    int regIndexInput1 = 5;
    int regIndexOutput1 = 4;

    int regIndexInput2 = 9;
    int regIndexOutput2 = 7;

    int labelIndexInput = 12;
    int labelLengthInput = 3;
    int labelBitsOutput = 6;
    int lastIndex = 15;

    li.output[0] = '0';
    li.output[1] = '1';
    li.output[2] = '1';
    li.output[3] = '0';

    char regDst = li.input[regIndexInput1 + li.firstIndex];
    char regBase = li.input[regIndexInput2 + li.firstIndex];

    writeRegBits(li.output, regDst, regIndexOutput1);
    writeRegBits(li.output, regBase, regIndexOutput2);

    int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
    writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

}