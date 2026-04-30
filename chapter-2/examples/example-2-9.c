#include <stdio.h>
/*
assuming called with x, p:4, n:3
69420: 10000111100101100 
(x >> (p+1-n))
00100001111001011, shifted right by the places we want to start returning - the number of places we return
~(~0 << n)
~0 fills out the var with 1 bits
1111111111111111
1111111111111000
0000000000000111
now combining first and send term via &

00100001111001011
00000000000000111
00000000000000011
              011

these are the 3 bits at position r and to the right
*/


unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}

main(){
    printf("%d", getbits(69420, 9, 7));
    /*
    69420: 10000111100101100
                  1100101   

    */ 

}