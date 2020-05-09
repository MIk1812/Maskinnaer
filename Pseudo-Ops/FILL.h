//
// Created by volkan on 08/05/2020.
//

#ifndef PROJEKT2_FILL_H
#define PROJEKT2_FILL_H

#endif //PROJEKT2_FILL_H
#pragma once
#include "../Functionality/FuncOpcodes.h"


void FILL(char* input, char* output,int firstInt){

    // Calculates the place of dot
    int xorhash = 0;
    for (int i = 0; i <30 ; ++i) {
        if((input[i]=='x') || (input[i]=='#')  ){
            break;
        }
        else xorhash++;
    }


    int pcOffset = charsToInt(input, xorhash+firstInt, 6);

    writeIntBits(output, pcOffset, 15, 16);

}