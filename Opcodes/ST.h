//
// Created by Mikkel Danielsen on 01/05/2020.
//

#ifndef PROJEKT2_ST_H
#define PROJEKT2_ST_H

#endif //PROJEKT2_ST_H

void ST(char input[]){
    int bits[4]={0,0,1,1};
    for (int i = 0; i < 4; ++i) {
        printf("%d", bits[i]);
    }
    int SR_bits[3]={0,0,0};
    int SR_reg = input[4];
    SR_reg = SR_reg - 48; //reset ASCII value
    // convert SR value to binary
    regbin(SR_reg,-1,SR_bits);
    for (int l = 2; l >= 0; --l) {
        printf("%d", SR_bits[l]);
    }
    int LabelBits[9]={0,0,0,0,0,0,0,0,0};

    //ASCii value of Label
    int sum = 0;
    for (int i = 7; i < 30; ++i) {
        //Until no input
        if(!input[i])
            break;
        sum = sum + input[i];
    }
    //conversion of ASCII value of Label to bits
    regbin(sum,-1,LabelBits);

    for (int l = 8; l >= 0; --l) {
        printf("%d", LabelBits[l]);
    }
}
