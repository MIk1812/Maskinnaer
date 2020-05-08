//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_FUNCIO_H
#define PROJEKT2_FUNCIO_H

#endif //PROJEKT2_FUNCIO_H

int multiplyChars(char* input, int firstIndex, int inputSize);
bool isLabel(char* line, int firstIndex, int inputSize, char* labelToReturn);

char* readNextLine(FILE* file, int inputSize, int* statusEOF){

    int i = 0;
    char* data = (char*) calloc(1,inputSize + 1);

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
    char* str = (char*) calloc(1, inputSize);

    int count = 0;

    int statusEOF = 0;
    while(statusEOF == 0){

        char* nextLine = readNextLine(inStream, inputSize, &statusEOF);
        bool opcodeStatus = isLabel(nextLine, 0, inputSize, str);

        if(opcodeStatus)
            count++;
    }

//    free(str);
    return count;

}

//The method also returns the chars it tests, and therefor requires char* stringTested
bool isLabel(char* line, int firstIndex, int inputSize, char* stringTested){

    //First, copy the chars to stringTested
    for (int i = firstIndex; i < inputSize; ++i) {

        //Until first blank space
        if(line[i] == ' ' || line[i] == '\0')
            break;

        stringTested[i] = line[i];
    }

    //Multiply the ASCII values of the characters in the first word in order to differentiate them
    int product = multiplyChars(line, firstIndex, inputSize);

    switch(product){

        //todo mangler de sidste opcodes !!
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
        case 475272:
        case 502824:
        case 344760:
        case 35817600:
            return false;
        default:
            return true;
    }
}


char** createSymbolTable(char* filePath, int inputSize){

    int numberOfLabels = countNumberOfLabels(filePath, inputSize);
    char** symbolTable = (char**) calloc(2, numberOfLabels);

    FILE* inStream;
    inStream = fopen(filePath,"r");

    int lineNumber = 0;
    int statusEOF = 0;
    while(statusEOF == 0){

        int symbolTableIndex = 0;
        char* currentLabel = (char*) calloc(1, inputSize);
        char* input = readNextLine(inStream, inputSize, &statusEOF);

        if(isLabel(input, 0, inputSize, currentLabel)){

            printf("\ncurrentLabel: %s\n", currentLabel);

//            symbolTable[symbolTableIndex][0] = currentLabel;
//            symbolTable[symbolTableIndex][1] = lineNumber;
        }

        lineNumber++;
    }

    return symbolTable;
}

//Multiplies the ASCII values of chars from firstIndex to ' ' or '\0'.
int multiplyChars(char* input, int firstIndex, int inputSize){

    int sum = 1;
    for (int i = firstIndex; i < inputSize; ++i) {

        //Until first blank space
        if(input[i] == ' '|| input[i] == '\0')
            break;

        int toMultiply = *(input+i);
        sum = sum * toMultiply;

    }
    return sum;
}

//todo slet
//char* takeInput(int inputSize) {
//
//    char* input = (char*) calloc(1, inputSize + 1);
//
//    //Space for 30 characters. Scanf reads until \n
//    scanf("%30[^\n]s", input);
//
//    //Clears line (\n)
//    scanf("%*c");
//
//    return input;
//}