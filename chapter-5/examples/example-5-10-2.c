#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


int getline_new(char *s, int max) {
    int c, i;
    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

main(int argc, char *argv[]){
    char line[MAXLINE];
    
    long lineno = 0;

    int c, except = 0, number = 0, found = 0;

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    if(argc != 1)
        printf("Usage: find pattern\n");
    else
        while(getline_new(line, MAXLINE) > 0){
            lineno++;
            //when except is toggled the logic is inversed where if it's found it doesn't print and vice versa
            //need to compare it to null because it's a pointer not a value
            if((strstr(line, *argv) != NULL) != except){
                if(number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;

}