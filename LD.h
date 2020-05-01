//
// Created by Mikkel Danielsen on 01/05/2020.
//

#ifndef PROJEKT2_LD_H
#define PROJEKT2_LD_H

#endif //PROJEKT2_LD_H


void LD(char input[]){

    int bits[16] = {0,0,1,0};

    char reg = input[4];

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    //Update destination bits according to register
    if((reg & 1) > 0)
        bits[6] = 1;
    if((reg & 2) > 0)
        bits[5] = 1;
    if((reg & 4) > 0)
        bits[4] = 1;

    for (int i = 0; i < 16; ++i) {
        printf("%d", bits[i]);
    }


}