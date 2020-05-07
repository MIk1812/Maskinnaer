//
// Created by Mikkel Danielsen on 01/05/2020.
//
#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

//start determines which bits in bits[] are to be modified
void writeRegBits(char* output, char reg, int start){

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    //Update destination bits according to register
    if((reg & 1) > 0) output[start+2] = '1';
    else output[start+2] = '0';

    if((reg & 2) > 0) output[start+1] = '1';
    else output[start+1] = '0';

    if((reg & 4) > 0) output[start] = '1';
    else output[start] = '0';
}


/**
 *
 * @param output: output arreyet som man manipulerer med.
 * @param intToWrite: selv int værdi som bliver konveteret til bits
 * @param start: start punktet i output array(funktionen kører fra højre mod venstre.
 * @param numberOfBits: antalet bits man manipulerer
 */
void writeIntBits(char* output, int intToWrite, int start, int numberOfBits){

    int bit=1;

    //Update destination bits according to register
    for (int i = 0; i < numberOfBits ; ++i) {

        if((intToWrite & bit) > 0)
            output[start] = '1';
        else
            output[start] = '0';

        start--;
        bit = bit*2;
    }

}

void nzp_Operation(char* input, char* output){

    for (int j = 2; j < 5 ; ++j) {

        if(input[j]=='n') output[4]='1';
        else output[4]='0';

        if(input[j]=='z') output[5]='1';
        else output[5]='0';

        if(input[j]=='p') output[6]='1';
        else output[6]='0';

    }
}

int getPCoffset(char* input){
    int spaceIndex= 0;
    for (int l = 0; l < 8 ; ++l) {
        if (input[l] == '#')
            break;
        spaceIndex++;
    }
    int pcVal = input[spaceIndex+1];
    pcVal = pcVal - 48; // resetting Ascii according to PC.
    return pcVal;
}

//Start is index of first byte (zero-indexed)
//Accepts negative values if minus is included
//Only whole numbers
int charsToInt(char* input, int start, int maxLength){

    char* temp = (char*) calloc(1,maxLength + 1);

    //Isolate the chars from the input array.
    for (int i = 0; i < maxLength; ++i) {

        char charRead = input[i+start];

        if( !((charRead >= '0' && charRead <= '9') || charRead == '-') )
            break;

        temp[i] = charRead;
    }


    int out = atoi(temp);
    free(temp);

    //Convert PC Offset to int
    return out;

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