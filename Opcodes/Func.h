//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

void regbin(int n , int k,int temp[]){
    if (n > 1) {
        k++;
        regbin((n / 2), k, temp);

    }
    if (n ==1 )
        k++;

    *(temp+(k)) = n % 2;
}

//start determines which bits in bits[] are to be modified
void updateRegBits(char* output, char reg, int start){

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    //Update destination bits according to register
    if((reg & 1) > 0)
        output[start+2] = 1;
    if((reg & 2) > 0)
        output[start+1] = 1;
    if((reg & 4) > 0)
        output[start] = 1;
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
            output[start] = 1;
        start--;
        bit = bit*2;
    }
}

void nzp_Operation(char* input, char* output){
    for (int j = 2; j < 5 ; ++j) {
        if(input[j]=='n'){
            output[4]=1;
        }
        else if(input[j]=='z'){
            output[5]=1;
        }
        else if(input[j]=='p'){
            output[6]=1;
        }
    }

}
int  getPCoffset (char* input){
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

//Length is number of chars, e.g. 'Mikkel' = 6
//Start is index of first byte (zero-indexed)
//Accepts negative values if minus is includes
//Only whole numbers
int charToInt(char* input, int start, int maxLength){

    char* temp = (char*) malloc(maxLength + 1);

    //Isolate the chars from the input array.
    for (int i = 0; i < maxLength; ++i) {
        temp[i] = input[i+start];
    }

    free(temp);

    //Convert PC Offset to int
    return atoi(temp);

}

