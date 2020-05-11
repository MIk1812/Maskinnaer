//
// Created by volkan on 11/05/2020.
//

#include "../../Functionality/Structs.h"
#include "../../Pseudo-Ops/FILL.h"
#include "../../Functionality/FuncTest.h"
#include <stdlib.h>
#ifndef PROJEKT2_TESTFILL_H
#define PROJEKT2_TESTFILL_H

#endif //PROJEKT2_TESTFILL_H

void testFILL(){
    char* testID = ".FILL1";

    LineInfo li;
    li.input = ".FILL #3";
    li.output = (char*) calloc(1, sizeof(char) * 17);
    li.firstIndex = 0;
    li.lineLength = 30;
    FILL(li);
    char* expected = "0000000000000011";
    equals(li.output,expected,testID);
    free(li.output);

}