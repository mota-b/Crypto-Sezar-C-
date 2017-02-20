#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Moukhtar-lib/chrypto.h"


/* Open and work in a file */
void open_file(FILE* file_src,int argc,char *argv[]){

    char buffer ;
    file_src = fopen(argv[3],"r+");

    // Test if the file is opened
    if (file_src != NULL) {
        printf("Opened : %s\n",argv[3]);
        buffer = (char)fgetc(file_src);

        // Test if the file is not empty
        if(buffer != EOF) {

            // Declarate and open File Dest
            FILE *file_dest = NULL;
            file_dest = fopen(argv[4], "w");


            // Read from file1 ---> chrypte/de-Chrypte ---> Write in file2
            if (strcmp(argv[1],"-c") == 0) {

                do {
                    fputc(sezar_chrypt(buffer, atoi(argv[2])), file_dest);
                    buffer = (char) fgetc(file_src);
                } while (buffer != EOF);
            }
            else if (strcmp(argv[1],"-p") == 0) {
                printf(" i am de-chryptig \n");
                do {
                    fputc(sezar_de_chrypt(buffer,atoi(argv[2])) ,file_dest);
                    buffer = (char)fgetc(file_src);
                } while (buffer != EOF);
            }
            else
                printf(" Not expected option \n");
        }
        else
            printf("Empty file \n");


        fclose(file_src);
        printf("Closed : %s\n",argv[3]);

    }

}


/*Main Class*/
int main(int argc,char *argv[]) {

    if (argc !=5){
            printf("nbr arg = %d Need more parametters\n"
                           "Syntax ex : \n\n"
                           "./code [option -p/-c] [Key] src.txt dest.txt\n",argc);
    }
    else{

        //Open file with r/w right
        FILE *file_src = NULL;
        open_file(file_src,argc,argv);

    }




    return 0;

}

