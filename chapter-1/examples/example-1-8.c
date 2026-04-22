//making use of local varibles in parameters

#include <stdio.h>

int power(int base, int n);

main(){
    printf("%d", power(2, 5));
}

//can freely modify n since it doesn't affect actual
int power(int base, int n){
    int p;

    for(p=1; n>0; --n){
        p = p * base;
    }
    return p;
}