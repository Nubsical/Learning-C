#include <stdio.h>

main(){
    int a[10];
    int i = 5;
    a[i] = i++;

    printf("%d\n", a[i]);
    printf("%d\n", a[i]);
}