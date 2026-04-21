#include <stdio.h>

//gets characters in the form of a pointer iterating through the stream

main(){
    int c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}