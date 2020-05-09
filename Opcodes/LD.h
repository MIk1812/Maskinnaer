//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H

#include <string.h>

#include "../Structs.h"
#include "../Functionality/FuncOpcodes.h"
#include "../Functionality/FuncIO.h"

void writeLabelBits(LineInfo li, int labelIndex, int labelBits, int lastIndex);

void LD(LineInfo li){

    //LD R1, #3
    //LD R1, x3
    //LD R1, LABEL

    int regIndex = 4;
    int labelIndexInput = 7;
    int labelLengthInput = 4;
    int labelBitsOutput = 9;
    int lastIndex = 15;

    li.output[0] = '0';
    li.output[1] = '0';
    li.output[2] = '1';
    li.output[3] = '0';

    char reg = li.input[regIndex + li.firstIndex];

    writeRegBits(li.output, reg, regIndex);

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);
    }
}



