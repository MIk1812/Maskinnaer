//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_TEST2_H
#define PROJEKT2_TEST2_H

#endif //PROJEKT2_TEST2_H

#include <stdbool.h>

#include "testLD.h"
#include "testLDR.h"
#include "testADD.h"
#include "testBR.h"
#include "testST.h"
#include "testSTI.h"
#include "testNOT.h"
#include "testSTR.h"
#include "testLDI.h"
#include "testLEA.h"
#include "testJSR.h"
#include "testJSRR.h"
#include "testJMP.h"
#include "testRET.h"
#include "testRTI.h"
#include "testAND.h"
#include "testTRAP.h"
#include "testORIG.h"

void testEverything(){

    testNOT();
    testLEA();
    testLD();
    testLDR();
    testLDI();
    testADD();
    testBR();
    testST();
    testSTR();
    testSTI();
    testNOT();
    testJSR();
    testJSRR();
    testJMP();
    testRET();
    testRTI();
    testAND();
    testTRAP();
    testORIG();

    printf("\nTests completed successfully");

}



