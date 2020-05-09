//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_RET_H
#define PROJEKT2_RET_H

#endif //PROJEKT2_RET_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void RET(LineInfo li){

    //RET

    char* str = "1100000111000000";

    for (int i = 0; i < 16; ++i) {
        li.output[i] = *(str+i);
    }

}