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
    int pcOffsetIndex = 8;
    int pcOffsetLength = 4;
    int pcOffsetBits = 9;
    int lastIndex = 15;

    li.output[0] = '1';
    li.output[1] = '1';
    li.output[2] = '1';
    li.output[3] = '0';


    char regDst = li.input[regIndex+li.firstIndex];

    writeRegBits(li.output, regDst, pcOffsetLength);

    char labelOrNot = li.input[li.firstIndex + pcOffsetIndex];

    //Test wether or not instruction contains label reference
    if(labelOrNot == '#' || labelOrNot == 'x' || labelOrNot == 'X'){

        int pcOffset = charsToInt(li.input, 8 + li.firstIndex, pcOffsetLength);
        writeIntBits(li.output, pcOffset, lastIndex, pcOffsetBits);

    } else{

        writeLabelBits(li, pcOffsetIndex, pcOffsetBits, lastIndex);

//        //Isolate label from input
//        char* inputLabel = (char*) calloc(1, sizeof(char) * li.lineLength);
//        isolateChars(li.input,  8 + li.firstIndex, li.lineLength, inputLabel);
//
//        int matchIndex = NULL;
//
//        //Go through labels to find match
//        for (int i = 0; i < li.symbolTable.numberOfLabels; ++i) {
//
//            char* currentLabel = *(li.symbolTable.labels + i);
//
//            //If we have a match
//            if(strcmp(currentLabel, inputLabel) == 0){
//                matchIndex = i;
//                break;
//            }
//        }
//
//        int addOfLabel = li.symbolTable.locations[matchIndex];
//        int pcOffset = addOfLabel - li.lineCount - 1;
//
//        writeIntBits(li.output, pcOffset, 15, 9);
    }




}