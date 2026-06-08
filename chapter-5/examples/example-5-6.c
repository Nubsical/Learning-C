#include <stdio.h>
#include <string.h>


#define MAXLINES 5000

//array of char pointers (array of strings)
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

//reads line into s and returns length
int getLine(char *s, int lim){
    int c, i;
    for(i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right){
    int i, last; 
    if(left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

main(){
    //num input lines read
    int nlines;

    //if there's at least one line
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        //runs recursive merge sort with lineptr, array of poitners to strings
        //parameters being the arr, first element, and last element index
        qsort(lineptr, 0, nlines-1);
        //write lines to the output
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("too big");
        return 1;
    }
}

#define MAXLEN 1000

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
}

//read lines into lineptr
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            //delete new line character \n
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


void writelines(char *lineptr[], int nlines){
    int i;
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

