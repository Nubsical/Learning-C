#include <stdio.h> 
#include <limits.h> //integral types, ints, chars, shorts, and longs

main(){
    printf("signed int max: %d\n", INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("signed int min: %d\n\n", INT_MIN);
    //UINT_MIN isn't a thing bcs that would just be 0

    printf("signed char max: %d\n", CHAR_MAX);
    printf("unsigned char max: %u\n", UCHAR_MAX);
    printf("signed char min: %d\n\n", CHAR_MIN);

    printf("signed short max: %d\n", SHRT_MAX);
    printf("unsigned short max: %u\n", USHRT_MAX);
    printf("signed short min: %d\n\n", SHRT_MIN);

    printf("signed long max: %ld\n", LONG_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
    printf("signed long min: %ld\n\n", LONG_MIN);


    



}