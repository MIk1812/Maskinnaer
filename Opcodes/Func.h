//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

//start determines which bits in bits[] are to be modified
void updateRegBits(char* output, char reg, int start){

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    //Update destination bits according to register
    if((reg & 1) > 0) output[start+2] = '1';
    else output[start+2] = '0';

    if((reg & 2) > 0) output[start+1] = '1';
    else output[start+1] = '0';

    if((reg & 4) > 0) output[start] = '1';
    else output[start] = '0';
}


/**
 *
 * @param output: output arreyet som man manipulerer med.
 * @param offset: selv int værdi som bliver konveteret til bits
 * @param start: start punktet i output array(funktionen kører fra højre mod venstre.
 * @param bitcount: antalet bits man manipulerer
 */
void writeIntBits(char* output, int offset , int start,int bitcount){
    int bit=1;
    //Update destination bits according to register
    for (int i = 0; i < bitcount ; ++i) {

        if((offset & bit) > 0)
            output[start] = '1';
        else
            output[start] = '0';

        start--;
        bit = bit*2;
    }
}

void nzp_Operation(char* input, char* output){
    for (int j = 2; j < 5 ; ++j) {
        if(input[j]=='n') output[4]='1';
        else output[4]='0';

        if(input[j]=='z') output[5]='1';
        else output[5]='0';

        if(input[j]=='p') output[6]='1';
        else output[6]='0';
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
int charToInt(char* input, int start, int maxLength){

    char* temp = (char*) malloc(maxLength + 1);

    //Isolate the chars from the input array.
    for (int i = 0; i < maxLength; ++i) {

        char charRead = input[i+start];

        if( !((charRead >= '0' && charRead <= '9') || charRead == '-') )
            break;

        temp[i] = charRead;
    }

    free(temp);

    //Convert PC Offset to int
    return atoi(temp);

}

