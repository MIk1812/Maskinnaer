//
// Created by volkan on 08/05/2020.
//

#ifndef PROJEKT2_BLKW_H
#define PROJEKT2_BLKW_H

#endif //PROJEKT2_BLKW_H
#include "../Functionality/FuncOpcodes.h"
#pragma once


int BLKW(LineInfo li){

    // Calculates the place of dot
    int xorhash = 0;
    for (int i = 0; i <30 ; ++i) {
        if((li.input[i]=='x') || (li.input[i]=='#')  ){
            break;
        }
        else xorhash++;
    }


    int memoryBlocks = charsToInt(li.input, xorhash, 6);
    writeIntBits(li.output, 0, 15, 16);
    return memoryBlocks;
}
