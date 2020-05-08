//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_ORIG_H
#define PROJEKT2_ORIG_H

#endif //PROJEKT2_ORIG_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void ORIG(char* input, char* output){

    int pcOffset = charsToInt(input, 6, 6);

    writeIntBits(output, pcOffset, 15, 16);

}