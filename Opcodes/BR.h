//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_BR_H
#define PROJEKT2_BR_H

#endif //PROJEKT2_BR_H

#include "../Functionality/FuncOpcodes.h"

void BR(LineInfo li) {

    //BRnpz #10
    //BRnzp LABEL

    int labelLengthInput = 5;
    int labelBitsOutput = 9;
    int lastIndex = 15;

    li.output[0] = '0';
    li.output[1] = '0';
    li.output[2] = '0';
    li.output[3] = '0';

    // set correct operation bit n,z,p
    nzp_Operation(li.input, li.output,li.firstIndex);

    // labelIndexInput to record where pcoff/label begins
    int labelIndexInput = 0;

    for (int i = li.firstIndex; i < li.lineLength ; ++i) {

        if( (li.input[i]) == ' '){
            labelIndexInput++;
            break;
        }
        labelIndexInput++;
    }

    char labelOrNot = li.input[li.firstIndex + labelIndexInput];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, labelIndexInput + li.firstIndex, labelLengthInput);
        writeIntBits(li.output, pcOffset, lastIndex, labelBitsOutput);

    } else{

        writeLabelBits(li, labelIndexInput, labelBitsOutput, lastIndex);
    }

}