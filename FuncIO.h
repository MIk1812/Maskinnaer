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
        if (data[i-1]=='\n' )
            return data;
    }

    return data;
}

void directives(char* input, char* output){

    int dotPlace = 0;
    for (int j = 0; j < 30 ; ++j) {
        if (input[j]=='.')
            break;
        else dotPlace++;
    }

    switch (input[dotPlace+1]) {
        case 'O':
            // Opcode
            output[0] = '0';
            output[1] = '0';
            output[2] = '1';
            output[3] = '1';
            char hex[4];

            int x = 0;
            for (int j = 0; j < 30 ; ++j) {
                if (input[j]=='x')
                    break;
                else x++;
            }
            for (int i = 0; i < 4 ; ++i) {
                hex[i]=input[i+(x+1)];
            }
            int value = (int)strtol(hex, NULL, 16);
            writeIntBits(output,value,15,12);

    }
}