#include <stdio.h>
#include <stdlib.h>

#include "Tests/Opcodes/Start.h"
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
#include "Pseudo-Ops/FILL.h"
#include "Pseudo-Ops/BLKW.h"
#include "Pseudo-Ops/END.h"
#include "Pseudo-Ops/STRINGZ.h"
#include "Functionality/Structs.h"

#define inputSize 30
#define outputSize 16
#define fileIn "../Files/fileIn.txt"
#define fileOut "../Files/fileOut.txt"


int main() {

    //todo brugerinterface?

    testEverything();

    //Find number of labels in file
    int numberOfLabels = countNumberOfLabels(fileIn, inputSize);

    char** labels;
    int* locations;

    //If we have any labels
    if(numberOfLabels > 0){

        //To hold pointers to all the Labels
        labels = (char**) calloc(1, sizeof(char*)*(numberOfLabels));

        for (int i = 0; i < numberOfLabels; ++i) {
            *(labels+i) = (char*) calloc(1, sizeof(char )*(inputSize));
        }

        //To hold all the locations
        locations = (int*) calloc(1, sizeof(int)*(numberOfLabels));

        createSymbolTable(fileIn, inputSize, labels, locations);
    }

    //todo integrer når psedoups er færdige
    SymbolTable symbolTable;
    symbolTable.labels = labels;
    symbolTable.numberOfLabels = numberOfLabels;
    symbolTable.locations = locations;

    FILE *inStream;
    FILE *outputStream;

    //Initialize input and output
    outputStream = fopen(fileOut,"w");
    inStream = fopen(fileIn,"r");

    //todo slet
    if (inStream != NULL && outputStream != NULL){
        printf("\nFile read success!\n");
    }

    //Marks when EOF is reached
    int exit = 0;

    //To track what line number we are currently on
    int lineCount = 0;

    //To track how many labels we have passed
    int labelCount = 0;

    //Until EOF
    while(exit == 0){

        LineInfo li;
        li.symbolTable = symbolTable;
        li.lineLength = inputSize;
        li.lineCount = lineCount;

        //Used to skip any predicate labels
        int firstIndex = 0;

        //To hold output
        char* output = (char*) calloc(1, sizeof(char) * (outputSize+1));
        li.output = output;

        //To hold input
        char *input = readNextLine(inStream, inputSize, &exit);
        li.input = input;

        //todo hvad er blocks?
        int blocks = 0;

        //If we have any labels, change firstIndex accordingly
        if(numberOfLabels > 0 ){

            //If we are currently on a line with a label referencing it
            if(lineCount == *(locations + labelCount)){

                labelCount++;

                //Update firstIndex accordingly
                do{
                    char currentChar = input[firstIndex];
                    if(currentChar == ' ' || currentChar == '\0' || currentChar == '\n'){
                        firstIndex++;
                        break;
                    }
                    else firstIndex++;
                } while(true);
            }
        }

        li.firstIndex = firstIndex;

        //Multiply the ASCII values of the opcode's characters in order to differentiate them
        int sum = multiplyChars(input, firstIndex, inputSize);

        //Identify opcode
        switch(sum){
            case 1544471804:
                ORIG(li);
                break;
            case 1357706560:
                FILL(li);
                break;
            case 1505552400:
                blocks = BLKW(li);
                break;
            case 168348960:
                END(&exit);
                break;
            case -823617216 :
                STRINGZ(li, outputStream, inputSize);
                break;
                //LDR
            case 423776:
                LDR(li);
                break;
            case 377264:
                LDI(li);
                break;
            case 340860:
                LEA(li);
                break;
            case 5168:
                LD(li);
                break;
            case 300560:
                ADD(li);
                break;
            case 517608:
                NOT(li);
                break;

            //Various BR(nzp) statements
            case 5412:
            case 595320:
            case 72629040:
            case 66675840:
            case -455482112:
            case 660264:
            case 73949568:
            case 606144:
                BR(li);
                break;

            case 6972:
                ST(li);
                break;
            case 508956:
                STI(li);
                break;
            case 571704:
                STR(li);
                break;
            case 503644:
                JSR(li);
                break;
            case 41298808:
                JSRR(li);
                break;
            case 455840:
                JMP(li);
                break;
            case 475272:
                RET(li);
                break;
            case 502824:
                RTI(li);
                break;
            case 35817600:
                TRAP(li);
                break;
            case 344760:
                AND(li);
                break;
        }

        //todo slet udskrifter
        //todo hvad er -823617216
        if (sum != -823617216) {
//            printf("\n%s", input);
            if (exit == 1) printf("\n");


            if (blocks > 0) {
                // lineCount = lineCount-1;
                int getlines = 0;
                for (int i = 0; i < blocks; ++i) {
//                    printf("%s\n", output);
                    fprintf(outputStream, "%s\n", output);
                }

            } else if (exit==0) {
//
                fprintf(outputStream, "%s\n", output);
            }
        }

        lineCount++;

            free(input);
            free(output);
            blocks = 0;


    }

    free(labels);
    free(locations);
}