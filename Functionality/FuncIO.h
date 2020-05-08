//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_FUNCIO_H
#define PROJEKT2_FUNCIO_H

#endif //PROJEKT2_FUNCIO_H

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

void createSymbolTable(int inputSize){

    //Filter out opcodes
    switch(0){

        case 1544471804:
        case 423776:
        case 377264:
        case 340860:
        case 5168:
        case 300560:
        case 517608:
        case 5412:
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
            break;
//        default:


    }
}

int multiplyChars(char* input, int firstIndex, int inputSize){

    int sum = 1;
    for (int i = firstIndex; i < inputSize; ++i) {

        //Until first blank space
        //grund til at vi tjekker ekstra input er fordi vi bare har brug for summen af BR og ikke ekstra input som n / z / p.
        if(input[i] == ' '|| input[i] == 110 || input[i] == 122 || input[i] == 112 || input[i] == '\0')
            break;

        int toMultiply = *(input+i);
        sum = sum * toMultiply;

    }

    return sum;

}

char* takeInput(int inputSize) {

    char* input = (char*) calloc(1, inputSize + 1);

    //Space for 30 characters. Scanf reads until \n
    scanf("%30[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

    return input;
}