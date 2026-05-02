#include <stdio.h>

void escape(char original[], char new[]){
    int j = 0;
    for(int i = 0; original[i] != '\0'; i++){
        switch(original[i]){
            case '\n': 
                new[j] = '\\';
                new[j+1] = 'n';
                j++;
                break;
            case '\t':
                new[j] = '\\';
                new[j+1] = 't';
                j++;
                break;
            default:
                new[j] = original[i];
                break;
        }
        j++;
    }
    new[j] = '\0';
}

main(){
    char original[] = "i\nlike\ndiet\n\tpepsi\n";
    printf("%s\n", original);
    int count=0;
    for(int i = 0; original[i] != '\0'; i++){
        count++;
        if(original[i] == '\n' || original[i] == '\t'){
            count++;
        }
    }

    char new[count+1];
    escape(original, new);
    printf("%s\n", new);

}