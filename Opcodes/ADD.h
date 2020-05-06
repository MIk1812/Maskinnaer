//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

#include "Func.h"

void ADD(char input[], char output[]) {
    // Opcode
    output[0] = '0';
    output[1] = '0';
    output[2] = '0';
    output[3] = '1';

    //Register DR
    char dr = input[5];
    writeRegBits(output, dr, 4);

    //Register SR1
    char sr1 = input[9];
    writeRegBits(output, sr1, 7);

    // Her kontrolleres der om det er en immadiate værdi eller bare register
    if (input[12] == 'R') {
        output[10] = '0';
        output[11] = '0';
        output[12] = '0';

        char sr2 = input[13];
        writeRegBits(output, sr2, 13);
    } else{
        char imm[3];
        int immDigits = 0;
        for (int j = 13; j < 30 ; ++j) {
            if((input[j]>='0' && input[j]<='9') || input[j]=='-'){
                imm[immDigits] = input[j];
                immDigits++;
            }
            else
                break;
        }

        //iMM IDENTIFIER
        output[10] = '1';
        // Læser en char array laver den om til int.
        int immInt;
        immInt = atoi(imm);
        writeIntBits(output,immInt,15,5);
    }
}