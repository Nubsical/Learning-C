#include <stdio.h>

main(){
    const double e = 2.7185293054;
    printf("%.100lf\n", e);
    //can't do here:
    e = 5.4;
}