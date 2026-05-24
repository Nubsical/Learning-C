#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double atofNew(char num[]){

    typedef enum {STATE_OUT, STATE_IN} State;
    State s = STATE_OUT;

    char base[20];
    char power[20];

    //add to base 
    int j = 0;
    for(int i = 0; i < strlen(num); i++, j++){
        if(s == STATE_OUT){
            if(num[i] == 'e' || num[i] == 'E') {
                s = STATE_IN;
                base[j] = '\0';
                j = -1;
            }else base[j] = num[i];
        }else{
            power[j] = num[i];
        }
    }
    power[j+1] = '\0';

    printf("%s, %s\n", base, power);
    printf("%f, %f\n", atof(base), atof(power));
    return atof(base) * pow(10, atof(power));

}

main(){
    char d[] = "123.45e-6";
    printf("%lf\n", atofNew(d));
}