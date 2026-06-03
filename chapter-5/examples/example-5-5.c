#include <stdio.h>

void strcpyNew(char *s, char *t){
    while(*s++ = *t++);
}

int strcmpNew(char *s, char *t){
    for(; *s == *t; s++, t++)
        if(!*s) return 0;
    return *s - *t;
}

main(){
    char b[] = "Arihant";
    char a[] = "Kalithkar";
    printf("%d\n", strcmpNew(b, a));
    strcpyNew(a, b);
    printf("%s\n", b);


}