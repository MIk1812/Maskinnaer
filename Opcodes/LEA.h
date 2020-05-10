//
// Created by Mikkel Danielsen on 07/05/2020.
//
#pragma once

#ifndef PROJEKT2_LEA_H
#define PROJEKT2_LEA_H

#endif //PROJEKT2_LEA_H

#include "../Functionality/FuncOpcodes.h"
#include "../Functionality/FuncIO.h"

void LEA(LineInfo li){

    //LEA R1, #10

    int regIndex = 5;
    int labelIndexInput = 8;
    int labelLengthInput = 4;
    int labelBitsOutput = 9;
    int lastIndex = 15;

    li.output[0] = '1';
    li.output[1] = '1';
    li.output[2] = '1';
    li.output[3] = '0';


    char regDst = li.input[regIndex+li.firstIndex];

    writeRegBits(li.output, regDst, labelLengthInput);

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, 8 + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);

    }

}