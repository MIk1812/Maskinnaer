#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LD.h"
#include "ADD.h"
#include "BR.h"
#include "ST.h"
#include "NOT.h"

void takeInput(char input[]);

int main() {

    char* input = (char*) malloc(30);
    int exit = 0;

    while(exit == 0){

        //By giving the address of input, we can let takeInput modify it
        takeInput(input);

        //Sum the ASCII values of the opcode's characters
        int sum = 0;
        for (int i = 0; i < 30; ++i) {

            //Until first blank space
            if(input[i] == ' ')
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
                ADD(input);
                break;

            //NOT
            case 241:
                NOT(input);
                break;

            //BR
            case 148:
                break;

            //LDR
            case 226:
                break;

            //ST
            case 167:
                ST(input);
                break;

        }

        exit = 1;

    }

}

void takeInput(char input[]) {

    //Space for 29 characters. Scanf reads until \n
    scanf("%29[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");
}
















