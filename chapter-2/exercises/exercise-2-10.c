#include <stdio.h>
#include <ctype.h>

main(){
    char word[] = "HelLo";

    for(int i = 0; word[i] != '\0'; i++){        
        char letter = word[i];
        word[i] = (letter >= 'A' && letter <= 'Z') ? (tolower(letter)) : letter;

    }
    printf("%s\n", word);
}