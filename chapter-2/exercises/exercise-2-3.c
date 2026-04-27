#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char digits[]);

main(){
    printf("%d", htoi("1F"));
}


int htoi(char digits[]){
    int sum = 0x0;
    for (int i = 0; i < strlen(digits); i++){
        if(i == 0 && strlen(digits) > 2 && digits[0] == '0'){
            ++i;
            continue;
        }
        int digitNum = 0;
        if(isdigit(digits[i])){
            digitNum = digits[i] - '0';
        }else if(digits[i] >= 'a' && digits[i] <= 'f'){
            digitNum = 10 + (digits[i] - 'a');
        }else if(digits[i] >= 'A' && digits[i] <= 'F'){
            digitNum = 10 + (digits[i] - 'A');
        }
        sum = 16 * sum + digitNum;
    }
    return sum;
}