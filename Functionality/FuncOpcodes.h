//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

#include "FuncIO.h"

//start determines which bits in bits[] are to be modified
//Notice: writes from left to right
void writeRegBits(char* output, char reg, int firstIndex){

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    //Update destination bits according to register
    if((reg & 1) > 0) output[firstIndex + 2] = '1';
    else output[firstIndex+2] = '0';

    if((reg & 2) > 0) output[firstIndex + 1] = '1';
    else output[firstIndex+1] = '0';

    if((reg & 4) > 0) output[firstIndex] = '1';
    else output[firstIndex] = '0';
}


/**
 * Notice: writes from right to left
 * @param output: output arreyet som man manipulerer med
 * @param intToWrite: selv int værdi som bliver konveteret til bits
 * @param start: start punktet i output array
 * @param numberOfBits: antalet bits man manipulerer
 */
void writeIntBits(char* output, int intToWrite, int lastIndex, int numberOfBits){

    int bit=1;

    //Update destination bits according to register
    for (int i = 0; i < numberOfBits ; ++i) {

        if((intToWrite & bit) > 0)
            output[lastIndex] = '1';
        else
            output[lastIndex] = '0';

        lastIndex--;
        bit = bit*2;
    }

}

void nzp_Operation(char* input, char* output, int firstIndex){

    for (int j = 2+firstIndex; j < 5+firstIndex ; ++j) {

        if (input[j] == 'n')
                output[4] = '1';
        else if(output[4] != '1')
            output[4] = '0';

        if(input[j]=='z') output[5]='1';
        else if(output[5] != '1') output[5]='0';

        if(input[j]=='p') output[6]='1';
        else if (output[6]!='1')
            output[6]='0';

    }
}

//Accepts negative values if minus is included
//Only whole numbers
//firstIndex must include predicate '#' or 'x'
//maxLength er tallets maximale længde tal som digits. Better safe than sorry.
int charsToInt(char* input, int firstIndex, int maxLength){

    char* temp = (char*) calloc(1,sizeof(char )*(maxLength + 1));

    //Isolate the chars from the input array.
    for (int i = 1; i < maxLength + 1; ++i) {

        char charRead = input[i + firstIndex];

        if(charRead == NULL || charRead == ' ')
            break;

        temp[i-1] = charRead;
    }

    //Do the proper conversion (hex or deci)
    if(input[firstIndex] == '#'){

        //Convert PC Offset to int
        int out = atoi(temp);
        free(temp);

        return out;

    } else {

        //Convert PC Offset to int
        int out = (int) strtol(temp, NULL, 16);
        free(temp);

        return out;

    }
}

void writeLabelBits(LineInfo li, int labelIndex, int labelBits, int lastIndex){

    //Isolate label from input
    char* inputLabel = (char*) calloc(1, sizeof(char) * li.lineLength);
    isolateChars(li.input, labelIndex + li.firstIndex, li.lineLength, inputLabel);

    int matchIndex = NULL;

    //Go through labels to find match
    for (int i = 0; i < li.symbolTable.numberOfLabels; ++i) {

        char* currentLabel = *(li.symbolTable.labels + i);

        //If we have a match
        if(strcmp(currentLabel, inputLabel) == 0){
            matchIndex = i;
            break;
        }
    }

    int addOfLabel = li.symbolTable.locations[matchIndex];
    int pcOffset = addOfLabel - li.lineCount - 1;

    writeIntBits(li.output, pcOffset, lastIndex, labelBits);

}

int singleCharToInt (char* input, int firstIndex){
    char alpha = input[firstIndex+1];
    int alphabet = (int)alpha;
    return alphabet;
}
