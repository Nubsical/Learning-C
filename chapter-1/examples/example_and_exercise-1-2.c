#include <stdio.h>

//comment
/*
multiline comment
*/

main(){
    //modified for c -> f
    float fahr, celsius, lower, upper, step;
    lower = 0;
    upper = 150;
    step = 20.1; //did .1 to experiment with $.f

    celsius = lower;


    while (celsius <= upper){
        fahr = (celsius * 9.0/5.0) + 32;
        printf("%3.1f \t %6.2f\n", celsius, fahr);
        //first %d refers to celsius and second refers to fahr, references respective one
        //%f refers to floats insead
        celsius = celsius + step;
    }

}

