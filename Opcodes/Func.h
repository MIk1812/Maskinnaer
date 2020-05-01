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