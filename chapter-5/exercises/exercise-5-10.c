#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 

#define MAXSTACKLENGTH 1000
#define NUMBER 1
#define OTHER 2


int stack[MAXSTACKLENGTH];
int *stackptr = stack;

//push num onto stack
void push(int val){
    *stackptr++ = val;
}

//pop num from stack
int pop(){
     return *(--stackptr);
}

//get argument value and return number, op, or other
char get_arg_val(char *argv[]){
    char *val = *argv;
    if(strcmp(val, "+") == 0 || strcmp(val, "-") == 0 || strcmp(val, "*") == 0 || strcmp(val, "/") == 0) return *val;
    if(atoi(val) || strcmp(val, "0") == 0) return NUMBER;
    return OTHER;
}

main(int argc, char *argv[]){
    int poptemp;
    while(--argc > 0){
        switch(get_arg_val(++argv)){
            case '+':
                push(pop() + pop());
                break;
            case '-':
                poptemp = pop();
                push(pop() - poptemp);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                poptemp = pop();
                push(pop() / poptemp);
                break;      
            case NUMBER:
                push(atoi(*argv));     
                break;
            default:
                printf("Invalid argument used\n");
                break;
        }
    }

    printf("%d\n", *stack);

}