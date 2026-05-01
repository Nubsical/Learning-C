#include <stdio.h>
#include <limits.h>

//shift to the right, the lost bits should be added to the left, "rotating" effect

unsigned rightrot(unsigned x, int n){
    return (x >> n) | ((x & ~(~0 << n)) << (sizeof(unsigned int) * CHAR_BIT - n));
}


main(){
    printf("%u\n", rightrot(6942,3));
}


