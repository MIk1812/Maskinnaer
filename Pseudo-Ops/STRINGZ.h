#include <stdio.h>
#ifndef PROJEKT2_STRINGZ_H
#define PROJEKT2_STRINGZ_H

#endif //PROJEKT2_STRINGZ_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void STRINGZ(char* input, char* output, FILE *outputStream, int inputSize, int firstIndex){
    int mask = 1;
    int countfirstindex = 0;
    int countchars = 0;
    for (int i = 10+firstIndex; i <inputSize ; ++i) {

        if (input[i] == '"') {
            break;
        } else
            countchars++;
    }

    printf("\n%s",input);
    for (int k = 0; k < countchars ; ++k) {

        int alphaindex = (10+firstIndex+k);
        int charIndex = (9+firstIndex+k);

        printf("%c: ", input[alphaindex]);

        int pcoff = singleCharToInt(input,charIndex);
        writeIntBits(output,pcoff, 15, 16);
        printf("%s\n", output);
        fprintf(outputStream, "%s\n", output);

    }

}

