#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

//will return pointer
char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }else return 0;
}

//frees up to pointer
char afree(char *p){
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
