//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_FUNCIO_H
#define PROJEKT2_FUNCIO_H

#endif //PROJEKT2_FUNCIO_H

#pragma once

#include "FuncOpcodes.h"

int multiplyChars(char* input, int firstIndex, int inputSize);
bool isLabel(char* line, int firstIndex, int inputSize, char* labelToReturn, int* stringTestedLength);

char* readNextLine(FILE* file, int inputSize, int* statusEOF){

    int i = 0;
    char* data = (char*) calloc(1,sizeof(char )*(inputSize + 1));

    while (fscanf(file, "%c", &data[i]) != EOF ){

        i++;
        if (data[i-1] == '\n' )
            return data;
    }

    *statusEOF = 1;
    return data;
}

int countNumberOfLabels(char* filePath, int inputSize){

    FILE* inStream;
    inStream = fopen(filePath,"r");

    int count = 0;

    int statusEOF = 0;
    while(statusEOF == 0){

        char* str = (char*) calloc(1, sizeof(char) * inputSize);
        int strLength;

        char* nextLine = readNextLine(inStream, inputSize, &statusEOF);
        bool opcodeStatus = isLabel(nextLine, 0, inputSize, str, &strLength);

        if(opcodeStatus)
            count++;

        free(str);
    }
    return count;

}

//The method return the string in stringToReturn
int isolateChars(char* string, int firstIndex, int inputSize, char* stringToReturn){

    //First, copy the chars to stringTested
    for (int i = firstIndex; i < inputSize + 1; ++i) {

        //Until first blank space
        if(string[i] == ' ' || string[i] == '\0' || string[i] == '\n')
            return i;

        stringToReturn[i-firstIndex] = string[i];
    }
}

//The method also returns the chars it tests, and therefor requires char* stringTested
bool isLabel(char* line, int firstIndex, int inputSize, char* stringTested, int* stringTestedLength){

    //First, copy the chars to stringTested
    *stringTestedLength = isolateChars(line, firstIndex, inputSize, stringTested);

    //Multiply the ASCII values of the characters in the first word in order to differentiate them
    int product = multiplyChars(line, firstIndex, inputSize);

    switch(product){

        case 1544471804:
        case 423776:
        case 377264:
        case 340860:
        case 5168:
        case 300560:
        case 517608:
        case 5412:
        case 595320:
        case 72629040:
        case 66675840:
        case -455482112:
        case 660264:
        case 73949568:
        case 606144:
        case 6972:
        case 508956:
        case 571704:
        case 503644:
        case 41298808:
        case 455840:
        case 475272: //RET
        case 502824: //RTI
        case 344760:
        case 35817600:
        case 1357706560: //.FILL
        case 1505552400: //.BLKW
        case 16834896: //.END
        case -823617216: //.STRINGZ
            return false;
        default:
            return true;
    }
}

void incrementSTRINGZ(char* currentLine, int firstIndex, int* lineNumber){

    int currentIndex = 10;

    while(true){

        char currentChar = currentLine[firstIndex + currentIndex++];

        if(currentChar == '"')
            break;

        (*lineNumber)++;
    }
}

void incrementBLKW(char* currentLine, int firstIndex,  int* lineNumber){

    int numberOfBlocks = charsToInt(currentLine, firstIndex + 6, 30);

    *lineNumber = *lineNumber + numberOfBlocks - 1;

}

//Indirect return through char** labels and int* locations
void createSymbolTable(char* filePath, int inputSize, SymbolTable symbolTable){

    FILE* inStream;
    inStream = fopen(filePath, "r");

    int lineNumber = 0;
    int statusEOF = 0;
    int labelCounter = 0;

    while(statusEOF == 0){

        char* currentLine = readNextLine(inStream, inputSize, &statusEOF);
        char* currentLabel = (char*) calloc(1, sizeof(char) * inputSize);
        char* currentOpcode = (char*) calloc(1, sizeof(char) * inputSize);
        int currentLabelLength = 0;

        //If current line contains a label
        if( isLabel(currentLine, 0, inputSize, currentLabel, &currentLabelLength) ){

            //Record the lable's chars in the symbol table
            for (int i = 0; i < inputSize +1; ++i) {
                *(*(symbolTable.labels + labelCounter)+i) = *(currentLabel+i);
            }

            //And the lineNumber
            *(symbolTable.locations + labelCounter) = lineNumber;
            labelCounter++;

            currentLabelLength++;

        } else
            currentLabelLength = 0;

        //If currentLine is .STRINGZ or .BLKW we need to increment lineNumber accordingly
        isolateChars(currentLine, currentLabelLength, inputSize, currentOpcode);

        //.STRINGZ
        if(currentOpcode[0] == '.' && currentOpcode[1] == 'S')
            incrementSTRINGZ(currentLine, currentLabelLength, &lineNumber);

        //.BLKW
        if(currentOpcode[0] == '.' && currentOpcode[1] == 'B')
            incrementBLKW(currentLine, currentLabelLength, &lineNumber);

        lineNumber++;
        free(currentLabel);
        free(currentOpcode);
    }
}

//Multiplies the ASCII values of chars from firstIndex to ' ' or '\0'.
int multiplyChars(char* input, int firstIndex, int inputSize){

    int sum = 1;
    for (int i = firstIndex; i < inputSize + 1; ++i) {

        //Until first blank space
        if(input[i] == ' '|| input[i] == '\0' || input[i] == '\n')
            break;

        int toMultiply = *(input+i);
        sum = sum * toMultiply;

    }
    return sum;
}
