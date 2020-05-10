#include <stdio.h>
#ifndef PROJEKT2_STRINGZ_H
#define PROJEKT2_STRINGZ_H

#endif //PROJEKT2_STRINGZ_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void STRINGZ(LineInfo li, FILE *outputStream){
    int mask = 1;
    int countfirstindex = 0;
    int countchars = 0;
    for (int i = 10+li.firstIndex; i <li.lineLength ; ++i) {

        if (li.input[i] == '"') {
            break;
        } else
            countchars++;
    }

    printf("\n%s",li.input);
    for (int k = 0; k < countchars ; ++k) {

        int alphaindex = (10+li.firstIndex+k);
        int charIndex = (9+li.firstIndex+k);

        printf("%c: ", li.input[alphaindex]);

        int pcoff = singleCharToInt(li.input,charIndex);
        writeIntBits(li.output,pcoff, 15, 16);
        printf("%s\n", li.output);
        fprintf(outputStream, "%s\n", li.output);

    }

}

