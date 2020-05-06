//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_ST_H
#define PROJEKT2_ST_H

#endif //PROJEKT2_ST_H
#include "Func.h"
void ST(char* input, char* output){
    output[0] = 0;
    output[1] = 0;
    output[2] = 1;
    output[3] = 1;

    char reg = input[4];

    updateRegBits(output, reg, 4);
    int pcOff = getPCoffset(input);

    writeIntBits(output,pcOff,15,9);

//    int LabelBits[9]={0,0,0,0,0,0,0,0,0};
//
//    //ASCii value of Label
//    int sum = 0;
//    for (int i = 7; i < 30; ++i) {
//        //Until no input
//        if(!input[i])
//            break;
//        sum = sum + input[i];
//    }
//    //conversion of ASCII value of Label to bits
//    regbin(sum,-1,LabelBits);
//
//    for (int l = 8; l >= 0; --l) {
//        printf("%d", LabelBits[l]);
//    }
}
