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
                fputc(sezar_chrypt(c,atoi(argv[1])) ,ff);// chript fro onClear --> to chrypted
                //fputc(sezar_de_chrypt((char)fgetc(ff),atoi(argv[1])) ,fff);// de_chrypte from chrypted - to de-chrypted
                c = (char)fgetc(f);
            } while (c != EOF);

        }
        else
            printf("Empty file \n");


        fclose(f);
        printf("Closed : %s\n",argv[2]);

    }
    /*int n = 5;
    for (int i = 'a'; i <='z' ; ++i) {
        //printf("%c",i);
       printf("%c | %c | %c  \n",i,sezar_chrypt(i,n),sezar_de_chrypt(sezar_chrypt(i,n),n));
    }
    return 0;*/
}

