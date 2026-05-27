#include <stdio.h>
#include <string.h>

void itoaNew(int n, char str[], int i){
    if(n < 0){
        str[0] = '-';
        n = -n;
        i++;
    }
    if(n/10){
        itoaNew(n/10, str, i-1);
    }
    str[i] = n%10 + '0';
}

main(){
    char numStr[10];
    int num = -69420;
    numStr[6] = '\0';
    itoaNew(num, numStr, 4);
    printf("%s\n", numStr);

}