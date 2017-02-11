#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Moukhtar-lib/chrypto.h"



int main(int argc,char *argv[]) {

    char c ;

    FILE *f = NULL;
    f = fopen(argv[2],"r+");

    if (f != NULL) {
        printf("Opened : %s\n",argv[2]);
        c = (char)fgetc(f);

        if(c != EOF) {
            FILE *ff = NULL;
           // FILE *fff = NULL;
            ff = fopen(argv[3], "r+");
            //fff = fopen(argv[4], "r+");

            do {
                fputc(sezar_de_chrypt(c,atoi(argv[1])) ,ff);// chript fro onClear --> to chrypted
                //fputc(sezar_de_chrypt((char)fgetc(ff),atoi(argv[1])) ,fff);// de_chrypte from chrypted - to de-chrypted
                c = (char)fgetc(f);
            } while (c != EOF);

        }
        else
            printf("Empty file \n");


        fclose(f);
        printf("Closed : %s\n",argv[2]);

    }

/*
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
    printf("\n");*/

    return 0;
}

