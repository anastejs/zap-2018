#include <stdio.h>
int check_letter_start(const char text[], const int j);
int check_letter_end(const char text[], const int j);
int check_letter_end_s(const char text[], const int s);
int check_letter_end_u(const char text[], const int u);

int main (int argc, char **argv){

    FILE * fp;

    if (argc != 3) {
        printf("You forgot to enter the filename.\n");
        return 1;
    }
    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    char ch;
    int i = 0;
    char text[10000] = {'0'};
    while (ch != EOF) {
        ch = fgetc(fp);
        text[i] = ch;
        i++;
    }
//    for (int j = 0; j < i; j++){               //CHECK TEXT
//        printf("%c", text[j]);
//    }
//    printf("\n");
    fclose(fp);

    fp = fopen(argv[2], "w");

    if (i == 0){
        fclose(fp);
        return 0;
    }

    int j = 0;
    for (j = 0; j < i; j++){
        if(check_letter_start(text, j)){
            break;
        }
    }
    j += 5;
//    printf("i = %d\n", i);

    while(j < i){
//        printf("j = %c\n", text[j]);
        j++;
        if(check_letter_end(text, j)){
            break;
        }
        while(text[j] != ' '){
            j++;
        }
        j++;
//        printf("letter = %c\n", text[j]);
        if(check_letter_end(text, j)){
            break;
        }
        while(text[j] != ' '){
            fputc (text[j], fp);
            j++;
        }
        int s = j+1;
        int u = s;
        while (text[u] != ' '){
            u++;
        }
        u++;
//        printf("u = %c\n", text[u]);
        if(check_letter_end_u(text, u)){
            break;
        }
        if(check_letter_end_s(text, s)){
            break;
        }
        fputc (' ', fp);
    }

    fclose(fp);
    return 0;
}

int check_letter_start(const char text[], const int j){
    int a = j + 1;
    int b = j + 2;
    int c = j + 3;
    int d = j + 4;
    if (text[j] == 'S'){
        if (text[a] == 'T'){
            if (text[b] == 'A'){
                if (text[c] == 'R'){
                    if (text[d] == 'T'){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int check_letter_end(const char text[], const int j){
    int a = j + 1;
    int b = j + 2;
    int c = j + 3;
    if (text[j] == 'S'){
        if (text[a] == 'T'){
            if (text[b] == 'O'){
                if (text[c] == 'P'){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int check_letter_end_s(const char text[], const int s){
    int a = s + 1;
    int b = s + 2;
    int c = s + 3;
    if (text[s] == 'S'){
        if (text[a] == 'T'){
            if (text[b] == 'O'){
                if (text[c] == 'P'){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int check_letter_end_u(const char text[], const int u){
    int a = u + 1;
    int b = u + 2;
    int c = u + 3;
    if (text[u] == 'S'){
        if (text[a] == 'T'){
            if (text[b] == 'O'){
                if (text[c] == 'P'){
                    return 1;
                }
            }
        }
    }
    return 0;
}

// gcc -std=c11 -Werror -Wall every_seconds.c -lm -o every_seconds