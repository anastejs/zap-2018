#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<time.h>
#include <ctype.h>
#include "hangman.h"
//#include "hangman.c"


int main(){

    srand(time(NULL));

    char secret[15] = {0};
    get_word (secret);
    hangman (secret);

    return 0;
}