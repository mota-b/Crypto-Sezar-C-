//
// Created by px-gnom on 05/01/17.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file_functions.h"

/*-----------------------------------Functions_relative to files------------------------------------------*/


// get word information from file
void get_word_info(FILE *file,char *word_catched,long *start ,long *end,long *length, int *v){

    char buffersave[255]="";


    int bufferc = 0;
    int count = 0;
    *v = -1;


    *start = ftell(file);
    bufferc = fgetc(file);

    //ignorer les blanc au debute
    while (bufferc == 10 || bufferc == 32) {//si on commence par espace (32) ou saut de ligne (10)
                                                //on commence a start +1
        *start = ftell(file);
        bufferc = fgetc(file);
    }

    char x;  // a utiliser pour ne pas confondre entre : et :=
    int j=0;  // a utiliser pour ne pas confondre entre : et :=
    int vv = -1;
    buffersave[count] = (char)bufferc;
    do{
        if(count!=0)
            if (bufferc == 10 || bufferc == 32) //espace (32) ou saut de ligne (10)
                break;

        if (is_separateur((char) bufferc) == 0 ){

            j++;
            if (j==0)
                x = (char)bufferc;
            if (j==1 && x ==':' && (char)bufferc=='='){

                    break;
            }
            if  ( ( is_operateur(&x)!=0 && is_separateur(x)!=0 )  &&   (char)bufferc==','){

                vv=0;
                break;
            }
        }

        count++;
        *end = ftell(file);

        bufferc = fgetc(file);
        buffersave[count] = (char)bufferc;

    }while(bufferc != EOF);

    if(bufferc != EOF){

        if (vv == 0){
            fseek(file,0,(int)ftell(file)-1);
            *end = ftell(file);
            bufferc = fgetc(file);
            *length =(*end-*start);
        }
        strcpy(word_catched,buffersave);
    }
    else
    {*v = 0;
    }

    printf("\n");
}

//parcourire file
void parcourire_file(FILE*file){

    long start ,end , length ;
    start = end = length = 0;
    int v =-1,counter_word = 0;

    char *word_catched =(char*)malloc(sizeof(char)*255);
    char *word_what =(char*)malloc(sizeof(char)*255);

    // catching words
    do {

        get_word_info(file,word_catched, &start, &end,&length ,&v);

        // empty file exit
        if (counter_word == 0 && v==0){
           printf("Empty file !!");
            break;
        }
        if (end!=start) {
            word_what =(char*)malloc(sizeof(char)*(strlen(word_catched)-1));

            for (int i = 0; i < (strlen(word_catched)-1); ++i) {
                word_what[i] = word_catched[i];
            }


            printf("%s <%s> length : %ld\n", word_what,what_is(word_what),strlen(word_what));

            //printf("le mot de longueur %ld commence a %ld et fini a %ld\n", strlen(word_what), start, end);
        }
        counter_word++;
    }while (v!=0 && (start != end));



    printf("%d word found \n",counter_word-1);

}

// print file char by char
void print_file_char(FILE *file){
    int bufferc = 0;

    int ligne = 0;
    int espace = 0;
    int c = 0;

    bufferc = fgetc(file);
    printf("%c",bufferc);
    do{
        bufferc = fgetc(file);
        if (bufferc == 32)
            espace++;
        else if (bufferc == 10 || bufferc ==-1)
            ligne++;
        else
            c++;

        printf("%c",bufferc);

    }while(bufferc!=EOF);



    printf("\n");
    // printf("nbr ligne = %d && nbr espace = %d nbr char = %d\n",ligne,espace,c);

}

// inside the file
void in_file(FILE *file){

    //print the file
    //printf("\n\n\tAffichage du fichier\n\n");
    //print_file_char(file);

    //parcourire le file
    printf("\n\n\tParcour du fichier\n\n");
    parcourire_file(file);

}

// open and close file
void opne_close(FILE* file,char *path) {

    /*try to open the file*/
    file = fopen(path, "r+");

    if (file != NULL){
        /*succes open*/
        printf("\n\n\tOuverture du fichier\n");
        in_file(file);
        fclose(file);
        printf("\n\n\tFermeture du fichier\n");
    }
    else
        /*error open*/
        printf("Error open file : %s\n",path);
}