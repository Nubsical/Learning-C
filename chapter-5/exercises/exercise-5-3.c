#include <stdio.h>

void strcat(char *s, char *t){
    while(*s) s++;
    while(*s++ = *t++);
    *s = '\0';
}


main(){
    char first[] = "Arihant";
    char last[] = "Kalithkar";
    strcat(first, last);
    printf("%s\n", first);
}