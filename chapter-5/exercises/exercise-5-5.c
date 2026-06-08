#include <stdio.h>

char *strncat_new(char *dest, char *src, int num_chars){
    char *dest_start = dest;
    while(*dest != '\0') dest++;
    for(int i = 0; i < num_chars && *src != '\0'; i++)
        *dest++ = *src++;
    *dest = '\0';
    return dest_start;
}

main(){
    char dest[20] = "Hello, ";
    char src[] = "World!!";
    strncat_new(dest, src, 5);
    printf("%s\n", dest);
}