#include <stdio.h>
#include <stdbool.h>

void takeInput(char input[]);
void LD(char input[]);
void BRnzp(char input[]);
int length = 0;

void bin(char n);

int main() {
    bin(10);
    int exit = 0;
    while(exit == 0){

        char input[30];
        takeInput(input);

        int sum = 0;
        for (int i = 0; i < 30; ++i) {

            if(input[i] == ' ') //ASCII value for space
                break;
            length++;
            sum = sum + input[i];
        }
        printf("%d", length);

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
                break;

            //LDR
            case 226:
                break;

            //ST
            case 167:
                break;

        }
        length = 0;

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

void BRnzp(char input[]){

    int bits[16]={0,0,0,0,1,1,1};
    for (int i = 0; i < 16; ++i) {

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


void takeInput(char input[]){

    char temp[30];
    scanf("%29[^\n]", &temp);
    for (int i = 0; i < 30 ; ++i) {
        input[i] = temp[i];
    }

}