/*first solution, doesn't work because c=getchar() isn't meant to be called if i<lim-1 (left to right)

#include <stdio.h>

main(){
    for(i=0; (i<lim-1) + ((c=getchar()) != '\n') + (c != EOF) == 3; ++i){
        s[i] = c;
    }
}

*/

//second solution, nested ifs allow for not running the next part if not first not true
#include <stdio.h>

main(){
    for(i=0; (i<lim-1); ++i){
        if(c == \n){
            break;
        }    
        if(c == EOF){
            break;
        }
        s[i] = c;
    }
}