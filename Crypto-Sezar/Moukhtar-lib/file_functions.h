//
// Created by px-gnom on 05/01/17.
//
#include <stdlib.h>
#include <stdio.h>
#ifndef ANALYSER_LEX_FILE_FUNCTIONS_H
#define ANALYSER_LEX_FILE_FUNCTIONS_H

// print a word form file
void print_word(FILE *file,long start,long end);

// get word information from file
void get_word_info(FILE *file,char *word_catched,long *start ,long *end,long *length, int *v);

//parcourire file
void parcourire_file(FILE*file);

// print file char by char
void print_file_char(FILE *file);

// inside the file
void in_file(FILE *file);

// open and close file
void opne_close(FILE* file,char *path);

#endif //ANALYSER_LEX_FILE_FUNCTIONS_H
