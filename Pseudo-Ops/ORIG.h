//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_ORIG_H
#define PROJEKT2_ORIG_H

#endif //PROJEKT2_ORIG_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void ORIG(LineInfo li){

    int pcOffset = charsToInt(li.input, 6, 6);

    writeIntBits(li.output, pcOffset, 15, 16);

}