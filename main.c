#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void takeInput(char input[]);
void LD(char input[]);
void ADD(char input[]);
void regbin(int n , int k,int temp[] );

int main() {

    int exit = 0;
    while(exit == 0){

        char input[30];
        takeInput(input);

        int sum = 0;
        for (int i = 0; i < 30; ++i) {

            if(input[i] == ' ') //ASCII value for space
                break;

            sum = sum + input[i];
        }

        switch(sum){

            //LD
            case 144:
                LD(input);
                break;

                //ADD
            case 201:
                ADD(input);
                break;

                //NOT
            case 241:
                break;

                //BR
            case 148:
                break;

                //LDR
            case 226:
                break;

                //ST
            case 167:
                break;

        }

        exit = 1;

    }

}

void LD(char input[]){

    int bits[16] = {0,0,1,0};

    char reg = input[5];
    reg = reg - 48; //reset ASCII value

    if(reg & 1 > 0)
        bits[4] = 1;
    if(reg & 2 > 0)
        bits[5] = 1;
    if(reg & 3 > 0)
        bits[6] = 1;


    for (int i = 0; i < 16; ++i) {
        printf("%d", bits[i]);
    }






}

//https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
void bin(char n){
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    printf("%d", n % 2);
}

void regbin(int n , int k,int temp[] ){
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


void takeInput(char input[]){

    char temp[30];
    scanf("%29[^\n]", &temp);
    for (int i = 0; i < 30 ; ++i) {
        input[i] = temp[i];
    }

}