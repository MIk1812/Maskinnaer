#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Test/Start.h"
#include "Opcodes/LD.h"
#include "Opcodes/ADD.h"
#include "Opcodes/BR.h"
#include "Opcodes/ST.h"
#include "Opcodes/NOT.h"
#include "Opcodes/STR.h"
#include "Opcodes/STI.h"
#include "Opcodes/LDR.h"
#include "Opcodes/LDI.h"

char* takeInput(void);

#define inputSize 30
#define outputSize 16

int main() {

    testEverything();

    int exit = 0;
    while(exit == 0){

        char* output = (char*) calloc(1, outputSize +1);

        //By giving the address of input, we can let takeInput modify it
        char* input = takeInput();

        //Sum the ASCII values of the opcode's characters
        int sum = 1;
        for (int i = 0; i < inputSize; ++i) {

            //Until first blank space
            //grund til at vi tjekker ekstra input er fordi vi bare har brug for summen af BR og ikke ekstra input som n / z / p.
            if(input[i] == ' '|| input[i] == 110 || input[i] == 122 || input[i] == 112 || input[i] == '\0')
                break;

            int toMultiply = *(input+i);
            sum = sum * toMultiply;

        }

        //Identify opcode
        switch(sum){

            //LDR
            case 423776:
                LDR(input, output);
                break;

            //LDI
            case 377264:
                LDI(input, output);
                break;

            //LEA
            case 340860:
                LEA(input, output);
                break;

            //LD
            case 5168:
                LD(input, output);
                break;

            //ADD
            case 300560:
                ADD(input, output);
                break;

            //NOT
            case 517608:
                NOT(input, output);
                break;

            //BR
            case 5412:
                BR(input, output);
                break;

            //ST
            case 6972:
                ST(input, output);
                break;

            //STI
            case 508956:
                STI(input,output);
                break;

            //STR
            case 571704:
                STR(input,output);
                break;

            //JSR
            case 503644:
                JSR(input, output);
                break;

            //JSRR
            case 41298808:
                JSRR(input, output);
                break;

            //JMP
            case 455840:
                JMP(input, output);
                break;

            //RET
            case 475272:
                RET(input, output);
                break;

            //RTI
            case 502824:
                RTI(input, output);
                break;

            //AND
            case 344760:
                ADD(input, output);
                break;

            //TRAP
            case 35817600:
                TRAP(input, output);
                break;

        }

        printf("%s", output);

        free(output);
        exit = 0;

    }

}

char* takeInput(void) {

    char* input = (char*) calloc(1,inputSize + 1);

    //Space for 30 characters. Scanf reads until \n
    scanf("%30[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

    return input;
}
















