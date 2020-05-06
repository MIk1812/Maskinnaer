//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_TEST2_H
#define PROJEKT2_TEST2_H

#endif //PROJEKT2_TEST2_H

#include <stdbool.h>

#include "LD.h"
#include "ADD.h"
#include "BR.h"
#include "ST.h"
#include "NOT.h"

bool testAll(){

    if(testLD() != true)
        return false;

    if(testADD() != true)
        return false;

    if(testBR() != true)
        return false;

    if(testST() != true)
        return false;

    if(testNOT() != true)
        return false;

}



