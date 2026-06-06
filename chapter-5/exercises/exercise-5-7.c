
/* readlines old

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
*/

//new readlines
int MAXLINES = 9999;
int MAXLEN = 9999; 


int readlines(char *storedLinesPtr, char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    char *end = storedLinesPtr + MAXLINES * MAXLEN;

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || storedLinesPtr + len >= end){
            return -1;
        }else{
            line[len - 1] = '\0';
            strcpy(storedLinesPtr, line);
            lineptr[nlines++] = storedLinesPtr;
            storedLinesPtr += len;

        }
    return nlines;
}