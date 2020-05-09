//
// Created by volkan on 08/05/2020.
//

#ifndef PROJEKT2_BLKW_H
#define PROJEKT2_BLKW_H

#endif //PROJEKT2_BLKW_H
#include "../Functionality/FuncOpcodes.h"


int BLKW(char* input, char* output,int firstInt){

    // Calculates the place of dot
    int xorhash = 0;
    for (int i = 0; i <30 ; ++i) {
        if((input[i]=='x') || (input[i]=='#')  ){
            break;
        }
        else xorhash++;
    }


    int memoryBlocks = charsToInt(input, xorhash, 6);
    writeIntBits(output, 0, 15, 16);
    return memoryBlocks;
}
