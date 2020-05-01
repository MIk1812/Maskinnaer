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

void convertOffsetOrInt(char* output, int offset , int start,int bitcount){

    int bit=1;
    int bitplace = 15;
    //Update destination bits according to register
    for (int i = 0; i < bitcount ; ++i) {
        if((offset & bit) > 0)
            output[bitplace] = 1;
        bitplace--;
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