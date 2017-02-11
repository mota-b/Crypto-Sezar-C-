//
// Created by px-gnom on 11/02/17.
//

#include "chrypto.h"

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
