//
// Created by px-gnom on 11/02/17.
//

#include "chrypto.h"
// sezar chrypt
int sezar_chrypt(char c , int n){
    int base;

    if (c >= 'A'  && c <= 'Z') /*Maj*/
        base = 65;
    else
        if (c >= 'a'  && c <= 'z') /*Min*/
            base = 97;
        else
            return c;

    return ((c+n)-base)%26+base; /*Code*/

}

int sezar_de_chrypt(char c , int n){
    int base;

    if (c >= 'A'  && c <= 'Z') /*Maj*/{
        base = 65;
        return ((c-n)+base)%26+base; /*Decode*/
    }
    else
        if (c >= 'a'  && c <= 'z') /*Min*/{
            base = 97;
            return ((c-n)+base-12)%26+base; /*Decode*/
        }

        else
            return c;


}
