//
// Created by Mikkel Danielsen on 08/05/2020.
//

#ifndef PROJEKT2_FUNCIO_H
#define PROJEKT2_FUNCIO_H

#endif //PROJEKT2_FUNCIO_H

char* readNextLine(FILE* file, int inputSize){

    int i = 0;
    char* data = (char*) calloc(1,inputSize + 1);

    while (fscanf(file, "%c", &data[i]) != EOF ){

        i++;
        if (data[i-1] == '\n' )
            return data;
    }

    return data;
}

char* takeInput(int inputSize) {

    char* input = (char*) calloc(1, inputSize + 1);

    //Space for 30 characters. Scanf reads until \n
    scanf("%30[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

    return input;
}