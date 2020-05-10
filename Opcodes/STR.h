#pragma once
#ifndef PROJEKT2_STM_H
#define PROJEKT2_STM_H

#endif //PROJEKT2_STM_H
#include "../Functionality/FuncOpcodes.h"

void STR(LineInfo li) {

    //STR R1, R2, #3
    //STR R1, R2, LABEL

    int regIndexInput1 = 5;
    int regIndexOutput1 = 4;

    int regIndexInput2 = 9;
    int regIndexOutput2 = 7;

    int labelIndexInput = 12;
    int labelLengthInput = 4;
    int labelBitsOutput = 6;
    int lastIndex = 15;

    li.output[0] = '0';
    li.output[1] = '1';
    li.output[2] = '1';
    li.output[3] = '1';

    char Sreg = li.input[regIndexInput1 + li.firstIndex]; //source register
    writeRegBits(li.output, Sreg, regIndexOutput1);

    char BaseR = li.input[regIndexInput2 + li.firstIndex]; //
    writeRegBits(li.output, BaseR, regIndexOutput2);

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);
    }

}