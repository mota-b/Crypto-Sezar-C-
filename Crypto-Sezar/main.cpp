#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//chrypto of 1 char
int sezar_char(char c , int n){
    if (c >= 'A'  && c <= 'Z')
        return  (c % 65) +n + 65;
    if (c >= 'a'  && c <= 'z')
        return  (c % 97) +n + 97;
}

//convert str to int
/*int str_to_int(char* t,int len){
    if (len == 1)
        return (int) t;
    else return (pow(t)t*10^len)+str_to_int();
}*/

int main(int argc,char *argv[]) {

    int somme_arg = 0;

    //teste sezar-char
   /* printf("%c \n",sezar_char('f',2));
    printf("%c \n",sezar_char('c',2));
    printf("%c \n",sezar_char('j',2));
    printf("%c \n",sezar_char('J',2));
    printf("%c \n",sezar_char('m',2));*/

    //return arg and leng of arg
    for (int i = 1; i <argc ; ++i) {
        printf("Arg %d :  %s de langueur %d\n",i,argv[i], strlen(argv[i]));
    }


    return 0;
}

