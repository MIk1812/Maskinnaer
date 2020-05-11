//
// Created by buttt on 09/05/2020.
//

#ifndef PROJEKT2_TESTSTRINGZ_H
#define PROJEKT2_TESTSTRINGZ_H
#define fileOut "../../../TestFiles/writefile.txt"
#endif //PROJEKT2_TESTSTRINGZ_H
#include "../../Functionality/Structs.h"
#include "../../Pseudo-Ops/STRINGZ.h"
#include "../../Functionality/FuncTest.h"
#include <stdlib.h>

FILE *outputStream;
void testSTRINGZ1();

void testSTRINGZ(){

    testSTRINGZ1();
}

void testSTRINGZ1(){
    outputStream = fopen(fileOut,"w");
    LineInfo li;
    char* testID = "STRINGZ1";
    li.input = ".STRINGZ \"mit\"";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 100;
    int linecount = 1;

    char* m = "0000000001101101";
    char* i = "0000000001101001";
    char* t = "0000000001101001";

    char** expected[] = {m,i,t};
    STRINGZ(li,outputStream,&linecount);
    printf("%d",linecount);


}

