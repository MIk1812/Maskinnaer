//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_RTI_H
#define PROJEKT2_RTI_H

#endif //PROJEKT2_RTI_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void RTI(char* input, char* output,int firstIndex){

    //RTI

    char* str = "1000000000000000";

    for (int i = 0; i < 16; ++i) {
        output[i] = *(str+i);
    }

}