#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal for if num found

// signal for if function (sin pow etc) found
#define SIN '1' 
#define EXP '2'
#define POW '3'
#define VARIABLE '4'

#define MAXVAL 100

#define BUFSIZE 100

double vars[26];

double recentlyPrinted;

/*
char buf[BUFSIZE];
int bufp = 0;
*/
char buf = EOF;

/*
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
*/

int getch(void){
    int tempBuf;
    if(buf == EOF){
        return getchar();
    }else{
        tempBuf = buf;
        buf = EOF;
        return tempBuf;
    }
}

/*
void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("too many chars\n");
    else
        buf[bufp++] = c;
}
*/

void ungetch(int c){
    buf = c;
}

void unget(char s[]){
    if(strlen(s) < BUFSIZE-bufp){
        for(int i = strlen(s)-1; i >= 0; i--)
            ungetch(s[i]);
    }else{
        printf("too big");
    }
}


int getop(char s[]){
    int i, c, n;
    int counter = 0;
    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-' && !isalpha(c)) return c;

    if(isalpha(c)){
        while(isalpha(s[++counter] = c = getch()));
        s[counter] = '\0';
        if(!strcmp(s, "sin")){
            return SIN;
        }else if(!strcmp(s, "exp")){
            return EXP;
        }else if(!strcmp(s, "pow")){
            return POW;
        }else{
            s[1] = '\0';
            return c;
        }
    }

    if(isalpha(s[0])){
        return VARIABLE;
    }

    
    if(c == '-' && ((n = getch()) == ' ' || n == '\n' || n == EOF)){
        ungetch(n);
        return '-';
    }else if(c == '-'){
        ungetch(n);
    }

    i = 0;

    if(isdigit(c) || c == '-')
        while(isdigit(s[++i] = c = getch()));
    if(c == '.')
        while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int sp = 0;
double val[MAXVAL];

void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else   
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

void printTopElements(void){
    if(sp > 0) printf("%f\n", val[sp-1]);
    else       printf("none in stack");
}

void dupStack(void){
    if(sp * 2 >= MAXVAL){
        printf("can't dup, too many vals");
    }else{
        int temp = sp;
        for(int i = 0; i < temp; i++){
            push(val[i]);
        }
    }
}

void swapTopElements(void){
    double temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}

void clearStack(void){
    sp = 0;
}



main(){

    int type;
    double op2;
    char s[MAXOP];

    while((type=getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case SIN:
                push(sin(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case EXP:
                push(exp(pop())); 
                break;
            case '=':
                vars[s[0] - 'a'] = pop();
                break;
            case VARIABLE:
                push(vars[s[0] - 'a']);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0) push(pop() / op2);
                else printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0) push((int) pop() % (int) op2);
                else printf("error: zero modulo\n");
                break;
            case '\n':
                recentlyPrinted = pop();
                printf("\t%.8g\n", recentlyPrinted);
                break;
            default:
                printf("unknown command\n");
                break;
        }
        
    }
    return 0;
}

