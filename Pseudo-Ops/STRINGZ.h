#include <stdio.h>
#ifndef PROJEKT2_STRINGZ_H
#define PROJEKT2_STRINGZ_H

#endif //PROJEKT2_STRINGZ_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void STRINGZ(char* input, char* output, FILE *outputStream){
    int mask = 1;
    int countfirstindex = 0;
    int countchars = 0;
    for (int i = 0; i < 30; ++i) {
        if (input[i]=='"') {
            for (int j = i+1; j < 30; ++j) {
                if (input[j] == '"') {
                    mask = 0;
                    goto end;
                } else
                    countchars++;
            }
            }
        countfirstindex++;
        end:
        if (mask == 0)
        break;
    }

    for (int k = 0; k < countchars ; ++k) {
        printf("%c: ", input[countfirstindex+(k+1)]);
        int pcoff = singleCharToInt(input,countfirstindex+k);
        writeIntBits(output,pcoff, 15, 16);
        printf("%s\n", output);
        fprintf(outputStream, "%s\n", output);
    }

}