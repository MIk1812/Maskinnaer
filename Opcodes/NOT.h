//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

void NOT(LineInfo li){

    // Opcode
    li.output[0] = '1';
    li.output[1] = '0';
    li.output[2] = '0';
    li.output[3] = '1';

    //Register DR
    char dr = li.input[5 + li.firstIndex];
    writeRegBits(li.output, dr, 4);

    //Register SR1
    char sr1 = li.input[9 + li.firstIndex];
    writeRegBits(li.output, sr1, 7);

    li.output[10] = '1';
    li.output[11] = '1';
    li.output[12] = '1';
    li.output[13] = '1';
    li.output[14] = '1';
    li.output[15] = '1';
}