//
// Created by Mikkel Danielsen on 01/05/2020.
//

#ifndef PROJEKT2_NOT_H
#define PROJEKT2_NOT_H

#endif //PROJEKT2_NOT_H

void NOT(char input[]){
    int bits[4] = {1,0,0,1};
    for (int i = 0; i < 4; ++i) {
        printf("%d", bits[i]);
    }

    int reg_bits[3] = {0, 0, 0};
    //printer register DR1
    char reg1 = input[5];
    reg1 = reg1 - 48; //reset ASCII value
    regbin(reg1, -1, reg_bits);

    for (int l = 2; l >= 0; --l) {
        printf("%d", reg_bits[l]);
    }
    //printer register SR1
    char reg2 = input[9];
    reg2 = reg2 - 48; //reset ASCII value
    regbin(reg2, -1, reg_bits);

    for (int l = 2; l >= 0; --l) {
        printf("%d", reg_bits[l]);
    }
    int lastbits[6] = {1,1,1,1,1,1};
    for (int i = 0; i < 6; ++i) {
        printf("%d", lastbits[i]);
    }

}