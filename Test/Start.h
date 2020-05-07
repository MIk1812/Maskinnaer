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
#include "testNOT.h"
#include "testLDI.h"
#include "testLEA.h"
#include "testJSR.h"
#include "testJSRR.h"

void testEverything(){

    testLEA();
    testLD();
    testLDR();
    testLDI();
    testADD();
    testBR();
    testST();
    testNOT();
    testJSR();
    testJSRR();

}



