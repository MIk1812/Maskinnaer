//
// Created by Mikkel Danielsen on 06/05/2020.
//

#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

void equals(char* output, char* expected, char* testID){

    for (int i = 0; i < 16; ++i) {

        //If bytes do not match, print statement
        if(*(output + i) != *(expected + i)) {

            printf("\nTest %s failed \n", testID);

            printf("Received: ");
            printf("%s", output);
            printf("\n");

            printf("Expected: ");
            printf("%s", expected);
            printf("\n");

            break;
        }
    }
}
