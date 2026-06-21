#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int reverse;

int readline(char *s, int lim) {
    int c, i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p;
    char line[1000];

    while ((len = readline(line, 1000)) > 0) {
        if (nlines >= maxlines)
            return -1;
        p = malloc(len + 1);
        if (p == NULL)
            return -1;
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s", lineptr[i]);
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//parameter comp takes two pointers and returns an int, with this parameter being a pointer to the function
void qsort_new(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i, last;
    if(left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_new(v, left, last-1, comp);
    qsort_new(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return reverse ? 1 : -1;
    else if(v1 > v2)
        return reverse ? -1 : 1;
    else 
        return 0;
}

main(int argc, char *argv[]){
    int nlines; //num lines read
    int numeric = 0; //1 if it's numeric sort
    
    reverse = 0;

    while(argc > 1){
        if(*argv[--argc] == '-'){
            switch(*(argv[argc] + 1)){
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            }
        }
    }
        
    
    
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort_new((void**) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }
}

