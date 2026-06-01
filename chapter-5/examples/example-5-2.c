#include <stdio.h>

void swap(int *pa, int *pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

main(){
    int a = 5;
    int b = 9;
    swap(&a, &b);
    printf("%d, %d\n", a, b);

}