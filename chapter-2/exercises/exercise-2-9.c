/*
x &= (x-1) deletes the rightmost 1 bit in x 
in a two's complement number system because the 1
subtracted results in the rightmost being converted to
0 with 1s being transferred to next places, and those
are canceld out by the zeros since that previous 1 was the 
rightmost one.

1010010100
1010010011
1010010000

*/

#include <stdio.h>

int bitcount(unsigned x){
    int b = 0; 
    while(x != 0){
        x &= x-1;
        b++;
    }
    return b; 
}

main(){
    //111
    printf("%d\n", bitcount(7));
}