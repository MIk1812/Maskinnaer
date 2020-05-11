//
// Created by volkan on 08/05/2020.
//

#ifndef PROJEKT2_FILL_H
#define PROJEKT2_FILL_H

#endif //PROJEKT2_FILL_H
#pragma once
#include "../Functionality/FuncOpcodes.h"

void FILL(LineInfo li){


    // Calculates the place of dot
    int xorhash = 0;
    for (int i = 0; i < li.lineLength ; ++i) {
        if((li.input[i]=='x') || (li.input[i]=='#')  ){
            break;
        }
        else xorhash++;
    }

    int pcOffset = charsToInt(li.input,xorhash,6);

    writeIntBits(li.output, pcOffset, 15, 16);

}