
#ifndef PROJEKT2_FILL_H
#define PROJEKT2_FILL_H

#endif //PROJEKT2_FILL_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void ORIG(char* input, char* output){

    int pcOffset = charsToInt(input, 6, 6);

    writeIntBits(output, pcOffset, 15, 16);

}