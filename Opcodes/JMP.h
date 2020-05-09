//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JMP_H
#define PROJEKT2_JMP_H

#endif //PROJEKT2_JMP_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void JMP(LineInfo li) {

    //JMP R4

    li.output[0] = '1';
    li.output[1] = '1';
    li.output[2] = '0';
    li.output[3] = '0';

    li.output[4] = '0';
    li.output[5] = '0';
    li.output[6] = '0';

    char regDst = li.input[5 + li.firstIndex];

    writeRegBits(li.output, regDst, 7);

    for (int i = 0; i < 6; ++i) {
        li.output[i + 10] = '0';
    }

}