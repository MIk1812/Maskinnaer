//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

#include "../Functionality/FuncOpcodes.h"

void ADD(LineInfo li) {

    //ADD R1, R2, R3

    // Opcode
    li.output[0] = '0';
    li.output[1] = '0';
    li.output[2] = '0';
    li.output[3] = '1';

    //Register DR
    char dr = li.input[li.firstIndex + 5];
    writeRegBits(li.output, dr, 4);

    //Register SR1
    char sr1 = li.input[li.firstIndex + 9];
    writeRegBits(li.output, sr1, 7);

    // Her kontrolleres der om det er en immadiate værdi eller bare register
    if (li.input[li.firstIndex + 12] == 'R') {
        li.output[10] = '0';
        li.output[11] = '0';
        li.output[12] = '0';

        char sr2 = li.input[li.firstIndex + 13];
        writeRegBits(li.output, sr2, 13);
    } else{
        char imm[3];
        int immDigits = 0;
        for (int j = 13; j < li.lineLength ; ++j) {
            if((li.input[li.firstIndex + j]>='0' && li.input[li.firstIndex + j]<='9') || li.input[li.firstIndex + j]=='-'){
                imm[immDigits] = li.input[li.firstIndex + j];
                immDigits++;
            }
            else
                break;
        }

        //iMM IDENTIFIER
        li.output[10] = '1';
        // Læser en char array laver den om til int.
        int immInt;
        immInt = atoi(imm);
        writeIntBits(li.output,immInt,15,5);
    }
}