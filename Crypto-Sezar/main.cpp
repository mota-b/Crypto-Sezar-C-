#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/chrypto.h"



int main(int argc,char *argv[]) {

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


    return 0;
}

