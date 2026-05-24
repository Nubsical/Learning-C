#include <stdio.h>
#include <string.h>

int strindex(char s[], char t){
    for(int i = strlen(s)-1; i > -1; i--){
        if(s[i] == t) return i;
    }
    return -1;
}

main(){
    char string[] = "ello govena";
    printf("%d\n", strindex(string, 'e'));
}