#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char string[], char str2[]){
    int length = strlen(string);
    int i, j;
    char left, right;
    for(i = 0, j = 0; string[j] != '\0'; i++, j++){
        if(string[j] == '-'){
            if((string[j+1] != '\0' && isdigit(string[j+1])) || (j > 0 && isdigit(string[j-1]))){
                //sets left to the min digit if theres nothing otherwise set it to left side
                //sets right to max digit if theres nothing otherwise set it to right side
                left = (j > 0 && string[j-1] != ' ') ? string[j-1] : '0';
                right = (j+1 != length-1 && string[j+1] != '\0') ? string[j+1] : '9';
            }else{
                left = (j > 0 && string[j-1] != ' ') ? string[j-1] : 'a';
                right = (j+1 != length-1 && string[j+1] != '\0') ? string[j+1] : 'z';
            }
            
            //fills in numbers into str2
            while(left <= right){
                str2[i] = left;
                i++;
                left++;
            }
            j+=2;
        }else{
            //just add whatever character if no dash
            if(string[j+1] != '-'){
                str2[i] = string[j];
            }else{
                i--;
            }
        }
    }
    str2[i] = '\0';

}

main(){
    char str1[] = "hello a-x ";
    char strNew[100];
    expand(str1, strNew);
    printf("%s\n", strNew);
}