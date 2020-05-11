//
// Created by volkan on 11/05/2020.
//

#ifndef PROJEKT2_TESTBLKW_H
#define PROJEKT2_TESTBLKW_H

#endif //PROJEKT2_TESTBLKW_H
#include "../../Functionality/Structs.h"
#include "../../Pseudo-Ops/BLKW.h"
#include "../../Functionality/FuncTest.h"
#include <stdlib.h>

void testBLKW(){
    char* testID = "BLKW1";
    LineInfo li;
    li.input = ".BLKW #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;
    int blok = BLKW(li);
    char* expected = "0000000000000000";

    equals(li.output,expected,testID);

    free(li.output);

}