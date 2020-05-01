//
// Created by Mikkel Danielsen on 01/05/2020.
//

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

void regbin(int n , int k,int temp[]){
    if (n > 1) {
        k++;
        regbin((n / 2), k, temp);

    }
    if (n ==1 )
        k++;

    *(temp+(k)) = n % 2;
}

void ADD(char input[]) {

    int bits[4] = {0, 0, 0, 1};
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

    // Her kontrolleres der om det er en immadiate værdi eller bare register
    if (input[12] == 'R') {

        printf("000");

        char reg3 = input[13];
        reg3 = reg3 - 48; //reset ASCII value
        regbin(reg3, -1, reg_bits);

        for (int l = 2; l >= 0; --l) {
            printf("%d", reg_bits[l]);
        }
    } else{

        char imm[3];
        int immadiate_counter = 0;
        for (int j = 13; j < 30 ; ++j) {
            if((input[j]>=48 && input[j]<=57) || input[j] == '-'){
                imm[immadiate_counter] = input[j];
                immadiate_counter++;
            } else
                break;
        }

        //iMMDIAtE IDENTIFIER
        printf("1");
        // Læser en char array laver den om til int.
        int immadiateint;
        immadiateint = atoi(imm);

        int immValue[5] = {0, 0, 0, 0, 0};


        //Hvis der skal adderes med - så laver den tallet om til plus der efter 1's complement.
        if(imm[0]=='-'){
            immadiateint = immadiateint * -1;
            regbin(immadiateint, -1, immValue);

            for (int i = 0; i < 5 ; ++i) {
                if(immValue[i] == 0)
                    immValue[i]=1;
                else
                    immValue[i]=0;
            }

            // Tilføjer 1 for at lave 2's complement
            int carrier = 1;
            int iterate = 0;
            do {
                if(immValue[iterate] == 0){
                    immValue[iterate]=1;
                    carrier = 0;
                } else
                    immValue[iterate]=0;
                iterate++;

            }while(carrier>0);


            for (int l = 4; l >= 0; --l) {
                printf("%d", immValue[l]);
            }

        }else {

            regbin(immadiateint, -1, immValue);
            for (int l = 4; l >= 0; --l) {
                printf("%d", immValue[l]);
            }
        }
    }
}


