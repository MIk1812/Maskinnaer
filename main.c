#include <stdio.h>

char * takeInput(void);

int main() {

//    char input[10] = "Hej sa";
//    printf("%s", input);

    char * input;
    input = takeInput();
    printf("%s", input);


}

char * takeInput(void){

    char input[10];
    scanf("%9[^\n]", &input);
    return input;

}
