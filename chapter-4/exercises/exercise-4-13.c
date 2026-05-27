#include <stdio.h>

void swap(char v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void reverse(char str[], int i, int j){
    if(i >= j){
        return;
    }
    swap(str, i, j);
    reverse(str, i+1, j-1);
}

main(){
    char str[] = "asdf";
    reverse(str, 0, 3);
    printf("%s\n", str);
}