#include <stdio.h>

main(){
    int c, i, nwhite, nother;
    //array of 10 ints
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF){
        //relies on character representation of digits
        if(c >= '0' && c <= '9')
            //difference between int of c and int of character 0 is gonna be the int of c
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n,", nwhite, nother);
    
}