#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Test/Start.h"
#include "Opcodes/LD.h"
#include "Opcodes/ADD.h"
#include "Opcodes/BR.h"
#include "Opcodes/ST.h"
#include "Opcodes/NOT.h"

void takeInput(char input[]);

int main() {

    testAll();

    char* input = (char*) malloc(31);
    char* output = (char*) calloc(1, 17);
    int exit = 0;

    while(exit == 0){

        //By giving the address of input, we can let takeInput modify it
        takeInput(input);

        //Sum the ASCII values of the opcode's characters
        int sum = 0;
        for (int i = 0; i < 30; ++i) {

            //Until first blank space
            if(input[i] == ' '|| input[i] == 110 || input[i] == 122 || input[i] == 112)
                break;
            sum = sum + input[i];
        }

        //Identify opcode
        switch(sum){

            //LD
            case 144:
                LD(input, output);
                break;

            //ADD
            case 201:
                ADD(input, output);
                break;

            //NOT
            case 241:
                NOT(input, output);
                break;

            //BR
            case 148:
                Br(input,output);
                break;

            //LDR
            case 226:
                break;

            //ST
            case 167:
                ST(input, output);
                break;

        }

        for (int i = 0; i < 16; ++i) {
            printf("%d", output[i]);
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
















