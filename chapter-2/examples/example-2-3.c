//not exactly and example but gonna but anyways
//just to enforce it
#include <stdio.h>

int strlen_myv(char s[]);

main(){
    printf("%d\n", strlen_myv("Arihant"));
}

int strlen_myv(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        ++i;
    }
    return i;
}
