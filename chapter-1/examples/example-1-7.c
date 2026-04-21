#include <stdio.h>

//"function prototype"
int power(int m, int n);

main(){
    int i;

    for(i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    return 0;
}
//variables that are in parameters are "formal arguments"
//those that are passed onto the parameters, within the function call, are actual arguments
int power(int base, int n){
    int i, p;
    p = 1;
    for(i = 1; i <= n; ++i)
        p = p * base;
    return p;
}