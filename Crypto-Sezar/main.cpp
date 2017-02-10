#include <stdlib.h>
#include <stdio.h>

int sezar_char(char c , int n){
    if (c >= 'A'  && c <= 'Z')
        return  (c % 65) +n + 65;
    if (c >= 'a'  && c <= 'z')
        return  (c % 97) +n + 97;
}

int main(int argc,char *argv[]) {

    printf("%c \n",sezar_char('f',2));
    printf("%c \n",sezar_char('c',2));
    printf("%c \n",sezar_char('j',2));
    printf("%c \n",sezar_char('J',2));
    printf("%c \n",sezar_char('m',2));
    return 0;
}

