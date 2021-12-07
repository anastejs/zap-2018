#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include "hangman.h"
#include <ctype.h>

int letters_chek (const char guessed_word_1[], const char letters_guessed[], char available_letters[], int i);
//int slovo (const char secret[], const char letters_guessed[], const int n);


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

void get_guessed_word (const char secret[], const char letters_guessed[], char guessed_word[]){      //ДЛЯ АРЕНЫ
    int n = strlen(secret);
    int b = strlen(letters_guessed);
    for (int i = 0; i < n; i++){                 // первоначально
        guessed_word[i] = '_';
    }
    if(b!=0){
        for (int i = 0; i < 23; i++){
            for (int j = 0; j < n; j++){
                if (letters_guessed[i] == secret[j]){
                    guessed_word[j] = secret[j];
                }
            }
        }
    }
//    for (int i = 0; i < n; i++){
//        printf("%c", guessed_word[i]);
//    }
//    printf("\n");
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
    int a = 0;
    int n = 0;
    int q = strlen(letters_guessed);
    for (int i = 0; i < 15; i++){
        if (secret[i] == 0){
            break;
        }
        n++;
    }
    for (int i = 0; i < n; i++){
        if (secret[i] == 0){
            break;
        }
        for (int j = 0; j < q; j++){
            if (secret[i] == letters_guessed[j]){
                a++;
                break;
            }
        }
    }
    if (a == n){
        return 1;                //ak tajné slovo bolo uhádnuté
    }
    return 0;                    //ak tajné slovo neuhádnuté
}

void get_guessed_word_1_1(const char secret[], const char letters_guessed[], char guessed_word_1[]){
    int n = 0;
    for (int i = 0; i < 15; i++){
        if (secret[i] == 0){
            break;
        }
        n++;
    }
    int m = n*2-1;                      //длина массива guessed_word_1
    int j = 0;
    for (int i = 0; i < m; i += 2){
        guessed_word_1[i] = '_';
        j++;
    }
     for (int i = 0; letters_guessed[i] > 0; i++){
        for (int j = 0; j < n; j++){
            if (letters_guessed[i] == secret[j]){
                guessed_word_1[j*2] = secret[j];
            }
        }
     }
    for (int i = 0; i < m; i++){
        printf("%c", guessed_word_1[i]);
    }
    printf("\n");
}


void get_available_letters(const char letters_guessed[], char available_letters[]){
//    char result [26];
//    for (int i = 0; i < 26; i++){
//        result[i] = available_letters[i];
//    }
//    for (int i = 0; i < 26; i++){
//        for (int j = 0; j < 23; j++){
//            if (letters_guessed[j] == available_letters[i]){
//                break;
//            }
//            if (letters_guessed[j] != available_letters[i] && j == 22){
//                result[i] = letters_guessed[j];
//            }
//        }
//        break;
//    }
    char result [26] = {0};
    int k = 0;
    int q = strlen(letters_guessed);
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < q; j++){
            if (letters_guessed[j] == available_letters[i]){
                break;
            }
            if (j == q-1){
                result[k] = available_letters[i];
                k++;
            }
        }
    }
    for (int i = 0; result[i] > 0; i++){
        printf("%c", result[i]);
    }
    printf("\n");
}


void hangman(const char secret[15]){

    int q = strlen(secret);                       //тоже длина массива с тайным словом
    char guessed_word[q];
    char guessed_word_1[28];                      // масиив, какие буквы угаданы/какие нет _o_tai_er
    for (int i = 0; i < 28; i++){                 // первоначально пустой (без мусора)
        guessed_word_1[i] = ' ';
    }
    char letters_guessed[23] = {' '};
//    char available_letters[26];
    char ch = 'a', available_letters[26];         // массив с алфавитом
    for(int i = 0; i < 26; i++){                  // помещаем каждую букву в массив
        available_letters[i] = ch++;
    }


    printf("Welcome to the game, Hangman!\n");
    int n = 0;                                    //считаю, сколько букв в тайном слове
    for (int i = 0; i < 15; i++){
        if (secret[i] == 0){
            break;
        }
        n++;
    }   
    printf("I am thinking of a word that is %d letters long.\n", n);
//    for (int i = 0; i < n; i++){                  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        printf("%c", secret[i]);
//    }
//    printf("\n");

    int guess = 8;
    int i = 0;
    while (!is_word_guessed (secret, letters_guessed) && guess > 0){

        printf("-------------\n");
        printf("You have %d guesses left.\n", guess);
        printf("Available letters: ");
//            for (int i; i < 23; i++){
//                     printf("%c\n", letters_guessed[i]);
//            }
        get_available_letters (letters_guessed, available_letters);

        printf("Please guess a letter: ");
        scanf(" %c", &letters_guessed[i]);
        letters_guessed[i] = tolower (letters_guessed[i]);

//        slovo(letters_guessed, secret, n);
//        if (slovo(letters_guessed, secret, n)){
//            printf("Congratulations, you won!\n");
//            return;
//        }

        if (letters_chek (guessed_word_1, letters_guessed, available_letters, i) == 2){
            printf("Oops! You've already guessed that letter: ");
            get_guessed_word_1_1(secret, letters_guessed, guessed_word_1);
            continue;
        }

        if (letters_chek (guessed_word_1, letters_guessed, available_letters, i)){
            printf("Oops! '%c' is not a valid letter: ", letters_guessed[i]);
            get_guessed_word_1_1(secret, letters_guessed, guessed_word_1);
            continue;
        }

        for (int j = 0; j < n; j++){
            if (letters_guessed[i] == secret[j]){
                printf("Good guess: ");
                get_guessed_word_1_1(secret, letters_guessed, guessed_word_1);
                break;
            }
            if (letters_guessed[i] != secret[j] && j == q-1){
                printf("Oops! That letter is not in my word: ");

                get_guessed_word_1_1(secret, letters_guessed, guessed_word_1);
                guess--;
            }
        }
        i++;
    }
    if (guess == 0){
        printf("-------------\n");
        printf("Sorry, you ran out of guesses. The word was ");
        for (int i = 0; i < n; i++){
            printf("%c", secret[i]);
        }
        printf(".\n");
    }
    if (is_word_guessed (secret, letters_guessed)){
        printf("-------------\n");
        printf("Congratulations, you won!\n");
    }
//    get_guessed_word_1("container", "arpstxgoieyu", guessed_word_1);     //CHECK
//    get_available_letters("arpstxgoieyu", available_letters);           //CHECK
    get_guessed_word("highwayman", "aghimnwy", guessed_word);
//    get_available_letters("", available_letters);
}

int letters_chek (const char guessed_word_1[], const char letters_guessed[], char available_letters[], int i){
    for (int p = 0; p < 26; p++){

            if (available_letters[p] == letters_guessed[i]){
                break;
            }
            if (available_letters[p] != letters_guessed[i] && p == 25){
                return 1;
            }

    }
    int n = strlen(guessed_word_1);
//    for (int p = 0; p < 23; p++){
//        printf("= %c\n", letters_guessed[i]);
//    }
    int x = 0;
    for (int k = 0; k < n; k++){
        if (letters_guessed[k] == letters_guessed[i]){
            x++;
        }
    }
    if (x == 2){
        return 2;
    }
    return 0;
}

//int slovo (const char secret[], const char letters_guessed[], const int n){
//    int k = 0;
//    printf("n = %d\n", n);
//    for (int i = 0; i < n; i++){
//            if (secret[i] == letters_guessed[i]){
//            k++;
//            }
//    }
//    printf("k = %d\n", k);
//    if (k == n){
//        return 1;
//    }
//    return 0;
//}



//    printf("%d\n", is_word_guessed("secret", "etsrce"));              //CHECK
