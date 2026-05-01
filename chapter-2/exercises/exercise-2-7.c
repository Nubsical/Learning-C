#include <stdio.h>
//invert n bits at position p of x
//10000111100101100

unsigned invertNums(unsigned x, int p, int n){
    return x ^ (~(~0 << n) << p-n+1);
}

main(){
    printf("%d\n", invertNums(69420, 7, 5));
}
