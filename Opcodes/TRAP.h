//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_TRAP_H
#define PROJEKT2_TRAP_H

#endif //PROJEKT2_TRAP_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void TRAP(LineInfo li){

    //TRAP x22
    //TRAP #34

    li.output[0] = '1';
    li.output[1] = '1';
    li.output[2] = '1';
    li.output[3] = '1';

    li.output[4] = '0';
    li.output[5] = '0';
    li.output[6] = '0';
    li.output[7] = '0';

    int pcOffset = charsToInt(li.input, 5 + li.firstIndex, 4);

    writeIntBits(li.output, pcOffset, 15, 8);


}