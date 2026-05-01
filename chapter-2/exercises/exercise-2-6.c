#include <stdio.h>

/*
returns
x with the n bits beginning at p set to the n digits at the right of y

we're gonna get n bits from y by 
- setting ~0 to get full set of 1s
- << n
- ~ to get whatever 000000000111 with n ones
- setting y = y & that to get just the n bits

now that we got n bits from y, we're gonna slap that into x
- y = y << p to shift/align it with x 
- need y to override x
    - new unsigned int var = ~0
    - var << n, full 1 set with n 0s on the right
    - var = ~var to get set of 0s with 1 at end
    - var = << p to get 0s on right
    - var = ~var, 1s, 0s, 1s at proper places
    - x = x & var to mask it and get 0 for the place we're replacing
    - x = x | y to get the new pieces in their intended places



*/


unsigned setbits(unsigned x, int p, int n, unsigned y){
    x = (x & ~(~(~0 << n) << p-n+1)) | ((y & ~(~0 << n)) << p-n+1);
    return x;
}

main(){
    //x: 69420, p: 5, n: 3, y: 676767
    printf("%d\n", setbits(69420, 5, 3, 676767));
}