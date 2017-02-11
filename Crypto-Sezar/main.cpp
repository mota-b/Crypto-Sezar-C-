#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
//chrypto of 1 char
int sezar_char(char c , int n){
    if (c >= 'A'  && c <= 'Z')
        return  (c % 65) +n + 65;
    if (c >= 'a'  && c <= 'z')
        return  (c % 97) +n + 97;
}
*/

int sezar_chrypt(char c , int n){
    if (c >= 'A'  && c <= 'Z')
        return  (c % 65) +n + 65;
    if (c >= 'a'  && c <= 'z')
        return  (c % 97) +n + 97;
}

int sezar_de_chrypt(char c , int n){
    if (c >= 'A'  && c <= 'Z')
        return  (c % 65) -n + 65;
    if (c >= 'a'  && c <= 'z')
        return  (c % 97) -n + 97;
}

int main(int argc,char *argv[]) {


    /*int somme_arg = 0;*/
    char buffer[]=" ";
    sprintf(buffer,"Hello");

    printf("we are going to crypte <<Hello>> with the sezar key %s : \n",argv[1]);
    for (int i = 0,l =(int)strlen(buffer) ; i <l ; ++i) {
        printf("%c ",sezar_chrypt(buffer[i], atoi(argv[1])) );
    }
    printf("\n");


    char buffer1[]=" ";
    sprintf(buffer1,"jgnnq");

    printf("we are going to de-crypte <<%s>> with the sezar key %s : \n",buffer1,argv[1]);
    for (int i = 0,l =(int)strlen(buffer) ; i <l ; ++i) {
        printf("%c ",sezar_de_chrypt(buffer1[i], atoi(argv[1])) );
    }
    printf("\n");

    //teste sezar-char
    /*printf("%c \n",sezar_chrypt('f', atoi(argv[1]) ) );
    printf("%c \n",sezar_chrypt('c',atoi(argv[1])));
    printf("%c \n",sezar_chrypt('j',atoi(argv[1])));
    printf("%c \n",sezar_chrypt('J',atoi(argv[1])));
    printf("%c \n",sezar_chrypt('m',atoi(argv[1])));*/

    //return arg and leng of arg
    /*for (int i = 1; i <argc ; ++i) {
        printf("Arg %d :  %s de langueur %d\n",i,argv[i], (int)strlen(argv[i]));
        somme_arg += atoi(argv[i]);
    }*/

    /*printf("S =  %d \n",somme_arg);*/

    return 0;
}

