#include <stdio.h>

struct point{
    int x;
    int y;
}

main(){
    struct point pt = {100, 200};
    printf("%d, %d\n", pt.x, pt.y);

    struct rect {
        struct point pt1;
        struct point pt2;
    };

    struct rect screen;


}