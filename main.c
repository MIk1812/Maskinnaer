#include <stdio.h>
#include <stdbool.h>

void takeInput(char input[]);
void LD(char input[]);
void Br(char input[]);
void ST(char input[]);
void regbin(int n , int k,int temp[] );
int length = 0;


void bin(char n);

int main() {
    int exit = 0;
    while(exit == 0){

        char input[30];

        //By giving the address of input, we can let takeInput modify it
        takeInput(input);

        //Sum the ASCII values of the opcode's characters
        int sum = 0;
        for (int i = 0; i < 30; ++i) {
            //Until first blank space
            if(input[i] == ' ' || input[i] == 110 || input[i] == 122 || input[i] == 112)
                break;
            sum = sum + input[i];
        }



        //Identify opcode
        switch(sum){

            //LD
            case 144:
                LD(input);
                break;

            //ADD
            case 201:
                break;

            //NOT
            case 241:
                break;

            //BR
            case 148:
                Br(input);
                break;

            //LDR
            case 226:
                break;

            //ST
            case 167:
                ST(input);
                break;

        }
        length = 0;

        exit = 1;

    }

}

void LD(char input[]){

    int bits[16] = {0,0,1,0};

    char reg = input[4];

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    printf("%d\n", reg);

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

void Br(char input[]) {

    int OPC_Bits[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i) {
        printf("%d", OPC_Bits[i]);
    }
    int OPR_Bits[3] = {0, 0, 0};
    // set correct operation bit n,z,p
    for (int j = 2; j < 5 ; ++j) {
        if(input[j]=='n'){
            OPR_Bits[0]=1;
        }
        else if(input[j]=='z'){
            OPR_Bits[1]=1;
        }
        else if(input[j]=='p'){
            OPR_Bits[2]=1;
        }
    }
    for (int k = 0; k < 3 ; ++k) {
        printf("%d", OPR_Bits[k]);
    }

    int PCoff[9]={0,0,0,0,0,0,0,0,0};
    //finding the index of space after BRnzp
    int spaceIndex= 0;
    for (int l = 0; l < 8 ; ++l) {
        if (input[l] == ' ')
            break;
        spaceIndex++;
    }
    int pcVal = input[spaceIndex+2];
    pcVal = pcVal - 48; // resetting Ascii according to PC.
    regbin(pcVal,-1,PCoff);
    for (int m = 8; m >= 0 ; --m) {
        printf("%d", PCoff[m]);
    }

    //todo labels are not implemented for BR

}

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



//https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
void bin(char n){
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    printf("%d", n % 2);
}

void regbin(int n , int k,int temp[]){
    if (n > 1) {
        k++;
        regbin((n / 2), k, temp);

    }
    if (n ==1 )
        k++;

    *(temp+(k)) = n % 2;
}

void takeInput(char input[]){

    //Space for 29 characters. Scanf reads until \n
    scanf("%29[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

}












