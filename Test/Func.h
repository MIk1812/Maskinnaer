//
// Created by Mikkel Danielsen on 06/05/2020.
//

#pragma once

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

bool equals(char* output, char* expected, char* testID){

    bool status = true;

    for (int i = 0; i < 16; ++i) {

        //If bytes do not match, print statement
        if( *(output + i) != *(expected + i)-48) {

            printf("\nTest %s failed \n", testID);

            printf("Received: ");
            for (int j = 0; j < 16; ++j) {
                printf("%d", *(output + j));
            }
            printf("\n");

            printf("Expected: ");
            for (int k = 0; k < 16; ++k) {
                printf("%d", *(expected + k)-48);
            }
            printf("\n\n");

            status = false;
            break;
        }
    }

    return status;
}
