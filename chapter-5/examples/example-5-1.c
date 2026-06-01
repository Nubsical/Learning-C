#include <stdio.h>


//declaring pointer *dp that returns double
//declaring function atof that returns double and takes a pointer to char as parameter
double *dp, atof(char *);


main(){
    int x = 1, y = 2, z[10]; //declaring/defining x an y, setting up z array
    int *ip; //declaring ip as pointer to int
    ip = &x; // setting ip pointer to address of x
    y = *ip; // setting y to data that ip points to: x
    *ip = 0; // setting the data ip points to to 0: x=0
    ip = &z[0]; // ip points to z[0]
}