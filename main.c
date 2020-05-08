#include <stdio.h>
#include <stdlib.h>

#include "Tests/Start.h"
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
#define fileIn "../fileIn.txt"
#define fileOut "../fileOut.txt"

int main() {

    testEverything();

    FILE *inStream;
    FILE *outputStream;

    createSymbolTable(fileIn, inputSize);


//
//    //Initialize input and output
//    outputStream = fopen(fileOut,"w");
//    inStream = fopen(fileIn,"r");
//
//    if (inStream != NULL && outputStream != NULL){
//        printf("\nFile read success!\n");
//    }
//
//    //Marks when EOF is reached
//    int exit = 0;
//
//    //Until EOF
//    while(exit == 0){
//
//        char* output = (char*) calloc(1, outputSize +1);
//
//        //char* input = takeInput();
//        char* input = readNextLine(inStream, inputSize, &exit);
//
//        //Multiply the ASCII values of the opcode's characters in order to differentiate them
//        int sum = multiplyChars(input, 0, inputSize);
//
//        //Identify opcode
//        switch(sum){
//
//            case 1544471804:
//                ORIG(input, output);
//                break;
//            case 423776:
//                LDR(input, output);
//                break;
//            case 377264:
//                LDI(input, output);
//                break;
//            case 340860:
//                LEA(input, output);
//                break;
//            case 5168:
//                LD(input, output);
//                break;
//            case 300560:
//                ADD(input, output);
//                break;
//            case 517608:
//                NOT(input, output);
//                break;
//
//            //Various BR(nzp) statements
//            case 5412:
//            case 595320:
//            case 72629040:
//            case 66675840:
//            case -455482112:
//            case 660264:
//            case 73949568:
//            case 606144:
//                BR(input, output);
//                break;
//
//            case 6972:
//                ST(input, output);
//                break;
//            case 508956:
//                STI(input,output);
//                break;
//            case 571704:
//                STR(input,output);
//                break;
//            case 503644:
//                JSR(input, output);
//                break;
//            case 41298808:
//                JSRR(input, output);
//                break;
//            case 455840:
//                JMP(input, output);
//                break;
//            case 475272:
//                RET(input, output);
//                break;
//            case 502824:
//                RTI(input, output);
//                break;
//            case 344760:
//                ADD(input, output);
//                break;
//            case 35817600:
//                TRAP(input, output);
//                break;
//
//        }
//
//        printf("\n%s", input);
//        if(exit == 1) printf("\n");
//        printf("%s\n", output);
//
//        fprintf(outputStream, "%s\n", output);
//
//        free(input);
//        free(output);
//
//    }

}
















