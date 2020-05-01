//
// Created by Mikkel Danielsen on 01/05/2020.
//

#ifndef PROJEKT2_FUNC_H
#define PROJEKT2_FUNC_H

#endif //PROJEKT2_FUNC_H

void regbin(int n , int k,int temp[]){
    if (n > 1) {
        k++;
        regbin((n / 2), k, temp);

    }
    if (n ==1 )
        k++;

    *(temp+(k)) = n % 2;
}
