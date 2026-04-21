//counting blanks tabs and newlines
#include <stdio.h>

main(){
    int c, count;
    count=0;
    while((c=getchar()) != EOF){
        //looked at ascii table for reference
        if(c == '\n' || c == 9 || c == ' '){
            ++count;
        }
    }
    printf("%d\n", count);
}