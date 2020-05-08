#include <stdio.h>
#include <stdlib.h>

#include "Test/Start.h"
#include "Functionality/FuncIO.h"
#include "Opcodes/LD.h"
#include "Opcodes/ADD.h"
#include "Opcodes/BR.h"
#include "Opcodes/ST.h"
#include "Opcodes/NOT.h"
#include "Opcodes/STR.h"
#include "Opcodes/STI.h"
#include "Opcodes/LDR.h"
#include "Opcodes/LDI.h"
#include "Pseudo-Ops/ORIG.h"

#define inputSize 30
#define outputSize 16

int main() {

    testEverything();

    //Initialize input and output
    FILE *inStream;
    FILE *outputStream;
    outputStream = fopen("../fileOut.txt","w");
    inStream = fopen("../fileIn.txt","r");

    if (inStream != NULL && outputStream != NULL){
        printf("File read success!\n");
    }

    //Reads and saves in fromfile
    //char* fromFile = readNextLine(inStream);

    int exit = 0;
    while(exit < 4){

        char* output = (char*) calloc(1, outputSize +1);

        //By giving the address of input, we can let takeInput modify it
        //char* input = takeInput();
        char* input = readNextLine(inStream, inputSize);

        //Multiply the ASCII values of the opcode's characters in order to differentiate them
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

            //.ORIG
            case 1544471804:
                ORIG(input, output);
                break;

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

        printf("\n%s", input);
        printf("%s\n", output);

        fprintf(outputStream, "%s\n", output);

        free(input);
        free(output);

        exit++;

    }

}


















