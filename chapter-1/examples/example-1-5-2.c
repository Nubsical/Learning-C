/*#include <stdio.h>

main(){
    long nc = 0;
    while(getchar() != EOF){
        ++nc;
    }
    //%ld for long numbers
    printf("%ld\n", nc);
}*/

#include <stdio.h>

main(){
    double nc;
    for (nc=0; getchar() != EOF; ++nc);
    //semicolon is a null statement, prevents actions in loop
    //.0f prevents printing of decimal for double
    printf("%.0f\n", nc);
}