#include <stdio.h>
void takeInput(char input[]);

int main() {

    char input[10];
    scanf("%9[^\n]", &input);
    printf("%s", input);
}




//void takeInput(char input[]){
//
//    char temp[10];
//    scanf("%9[^\n]", &temp);
//    for (int i = 0; i < 10 ; ++i) {
//        input[i] = temp[i];
//    }
