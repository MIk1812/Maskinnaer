//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

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

void nzp_Operation(char* input, char* output){

    for (int j = 2; j < 5 ; ++j) {


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

int getPCoffset(char* input){
    int spaceIndex= 0;
    for (int l = 0; l < 8 ; ++l) {
        if (input[l] == '#')
            break;
        spaceIndex++;
    }
    int pcVal = input[spaceIndex+1];
    pcVal = pcVal - 48; // resetting Ascii according to PC.
    return pcVal;
}

//Start is index of first byte (zero-indexed)
//Accepts negative values if minus is included
//Only whole numbers
int charsToInt(char* input, int start, int maxLength){

    char* temp = (char*) calloc(1,maxLength + 1);

    //Isolate the chars from the input array.
    for (int i = 0; i < maxLength; ++i) {

        char charRead = input[i+start];

        if( !((charRead >= '0' && charRead <= '9') || charRead == '-') )
            break;

        temp[i] = charRead;
    }

    int out = atoi(temp);
    free(temp);

    //Convert PC Offset to int
    return out;

}

