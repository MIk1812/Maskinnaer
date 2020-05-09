//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

void NOT(char input[], char output[],int fistIndex){

    // Opcode
    output[0] = '1';
    output[1] = '0';
    output[2] = '0';
    output[3] = '1';

    //Register DR
    char dr = input[5+fistIndex];
    writeRegBits(output, dr, 4);

    //Register SR1
    char sr1 = input[9+fistIndex];
    writeRegBits(output, sr1, 7);

    output[10] = '1';
    output[11] = '1';
    output[12] = '1';
    output[13] = '1';
    output[14] = '1';
    output[15] = '1';
}