//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_JSR_H
#define PROJEKT2_JSR_H

#endif //PROJEKT2_JSR_H

#pragma once
#include "Func.h"

void JSR(char* input, char* output){

    //JSR #943
    
    output[0] = '0';
    output[1] = '1';
    output[2] = '0';
    output[3] = '0';

    output[4] = '1';
    
    int pcOffset = charsToInt(input, 5, 5);

    writeIntBits(output, pcOffset, 15, 11);

}

