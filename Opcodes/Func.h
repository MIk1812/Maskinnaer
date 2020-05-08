//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

//start determines which bits in bits[] are to be modified
//Notice: writes from left to right
void writeRegBits(char* output, char reg, int firstIndex){

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    //Update destination bits according to register
    if((reg & 1) > 0) output[firstIndex + 2] = '1';
    else output[firstIndex+2] = '0';

    if((reg & 2) > 0) output[firstIndex + 1] = '1';
    else output[firstIndex+1] = '0';

    if((reg & 4) > 0) output[firstIndex] = '1';
    else output[firstIndex] = '0';
}


/**
 * Notice: writes from right to left
 * @param output: output arreyet som man manipulerer med
 * @param intToWrite: selv int værdi som bliver konveteret til bits
 * @param start: start punktet i output array
 * @param numberOfBits: antalet bits man manipulerer
 */
void writeIntBits(char* output, int intToWrite, int lastIndex, int numberOfBits){

    int bit=1;

    //Update destination bits according to register
    for (int i = 0; i < numberOfBits ; ++i) {

        if((intToWrite & bit) > 0)
            output[lastIndex] = '1';
        else
            output[lastIndex] = '0';

        lastIndex--;
        bit = bit*2;
    }

}

void nzp_Operation(char* input, char* output){

    for (int j = 2; j < 5 ; ++j) {

        if (input[j] == 'n')
                output[4] = '1';
        else if(output[4] != '1')
            output[4] = '0';

        if(input[j]=='z') output[5]='1';
        else if(output[5] != '1') output[5]='0';

        if(input[j]=='p') output[6]='1';
        else if (output[6]!='1')
            output[6]='0';

    }
}

//Accepts negative values if minus is included
//Only whole numbers
//Only capitilized letters
//firstIndex must include predicate '#' or 'x'
//maxLength er tallets maximale længde tal som digits. Better safe than sorry.
int charsToInt(char* input, int firstIndex, int maxLength){

    char* temp = (char*) calloc(1,maxLength + 1);

    //Isolate the chars from the input array.
    for (int i = 1; i < maxLength + 1; ++i) {

        char charRead = input[i + firstIndex];

        if(charRead == NULL || charRead == ' ')
            break;

        temp[i-1] = charRead;
    }

    //Do the proper conversion
    if(input[firstIndex] == '#'){

        //Convert PC Offset to int
        int out = atoi(temp);
        free(temp);

        return out;

    } else {

        //Convert PC Offset to int
        int out = (int)strtol(temp, NULL, 16);
        free(temp);

        return out;

    }

}

char* readFile(FILE* file){
    int i = 0;
    char* data = (char*) calloc(1,30 + 1);

    while (fscanf(file,"%c",&data[i]) != EOF ){

        printf("%c",data[i]);
        i++;
        if (data[i-1]=='\n' )
            return data;
    }

    return data;
}

void directives(char* input,char* output){
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