//
// Created by Mikkel Danielsen on 01/05/2020.
//

#ifndef PROJEKT2_BR_H
#define PROJEKT2_BR_H

#endif //PROJEKT2_BR_H

#include "Func.h"
void Br(char* input, char* output) {
    output[0] = 0;
    output[1] = 0;
    output[2] = 0;
    output[3] = 0;

    // set correct operation bit n,z,p
    nzp_Operation(input, output);


//    int PCoff[9]={0,0,0,0,0,0,0,0,0};
//    //finding the index of space after BRnzp
//    int spaceIndex= 0;
//    for (int l = 0; l < 8 ; ++l) {
//        if (input[l] == ' ')
//            break;
//        spaceIndex++;
//    }
//    int pcVal = input[spaceIndex+2];
//    pcVal = pcVal - 48; // resetting Ascii according to PC.
//    regbin(pcVal,-1,PCoff);
//    for (int m = 8; m >= 0 ; --m) {
//        printf("%d", PCoff[m]);
//    }
}