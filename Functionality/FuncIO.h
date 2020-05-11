//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_FUNCIO_H
#define PROJEKT2_FUNCIO_H

#endif //PROJEKT2_FUNCIO_H

#pragma once

int multiplyChars(char* input, int firstIndex, int inputSize);
bool isLabel(char* line, int firstIndex, int inputSize, char* labelToReturn);

void readNextLine(FILE* file, int* statusEOF, char* lineToReturn){

    int i = 0;

    while (fscanf(file, "%c", &lineToReturn[i]) != EOF ){

        i++;
        if (lineToReturn[i-1] == '\n' )
            return;
    }

    *statusEOF = 1;
    return;
}

int countNumberOfLabels(char* filePath, int inputSize){

    FILE* inStream;
    inStream = fopen(filePath,"r");

    int count = 0;

    char* str = (char*) calloc(1, sizeof(char) * inputSize);
    char* nextLine = (char*) calloc(1,sizeof(char )*(inputSize + 1));

    int statusEOF = 0;
    while(statusEOF == 0){


        readNextLine(inStream, &statusEOF, nextLine);

        bool opcodeStatus = isLabel(nextLine, 0, inputSize, str);

        if(opcodeStatus)
            count++;

    }

    free(str);
    free(nextLine);
    return count;

}

//The method return the string in stringToReturn
void isolateChars(char* string, int firstIndex, int inputSize, char* stringToReturn){

    //First, copy the chars to stringTested
    for (int i = firstIndex; i < inputSize + 1; ++i) {

        //Until first blank space
        if(string[i] == ' ' || string[i] == '\0' || string[i] == '\n')
            break;

        stringToReturn[i-firstIndex] = string[i];
    }
}

//The method also returns the chars it tests, and therefor requires char* stringTested
bool isLabel(char* line, int firstIndex, int inputSize, char* stringTested){

    //First, copy the chars to stringTested
    isolateChars(line, firstIndex, inputSize, stringTested);

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

//Indirect return through char** labels and int* locations
void createSymbolTable(char* filePath, int inputSize, SymbolTable symbolTable){

    FILE* inStream;
    inStream = fopen(filePath, "r");

    int lineNumber = 0;
    int statusEOF = 0;
    int labelCounter = 0;

    char* currentLine = (char*) calloc(1,sizeof(char )*(inputSize + 1));;
    char* currentLabel = (char*) calloc(1, sizeof(char) * inputSize);

    while(statusEOF == 0){

        readNextLine(inStream, &statusEOF, currentLine);

        //If current line contains a label
        if( isLabel(currentLine, 0, inputSize, currentLabel) ){

            //Record the lable's chars
            for (int i = 0; i < inputSize +1; ++i) {
                *(*(symbolTable.labels + labelCounter)+i) = *(currentLabel+i);
            }

            //And record the lineNumber
            *(symbolTable.locations + labelCounter) = lineNumber;
            labelCounter++;
        }

//        //If currentLine is .STRINGZ or .BLKW we need to increment lineNumber accordingly
//        if()

        lineNumber++;
    }
    free(currentLabel);
    free(currentLine);

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

char* takeInput(int inputSize) {

    char* input = (char*) calloc(1, sizeof(char) * inputSize + 1);

    //Space for 30 characters. Scanf reads until \n
    scanf("%30[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

    return input;
}