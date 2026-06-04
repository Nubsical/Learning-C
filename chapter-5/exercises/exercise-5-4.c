#include <stdio.h>

int strend(char *s, char *t){
    char *startt = t;
    while(*s) s++;
    while(*t) t++;
    while(t >= startt){
        if(*t != *s) return 0;
        t--, s--;
    }
    return 1;
}

main(){
    char first[] = "ArihantKalithkar";
    char last[] = "Kalithkar";
    printf("%d\n", strend(first, last));
}