#include <stdio.h>

#define IN 1
#define OUT 0

main(){
    int c;
    short state = IN;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            putchar('\n');
        }
        if(state){
            putchar(c);
        }
    }
}