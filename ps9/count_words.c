#include <stdio.h>
int check_letter(const char a[], const int j);

    int main(int argc, char *argv[]) {

    FILE * fp;
    char text;
    if (argc != 2) {
    printf("You forgot to enter the filename.");
    return 1;
    }
    if((fp = fopen(argv[1], "r+")) == NULL) {
    printf("Cannot open file.");
    return 1;
    }

    int i = 0;
    char a[10000] = {'0'};
    while (text != EOF) {
        text = fgetc(fp);
        a[i] = text;
        i++;
    }
//    printf("i = %d", i);
//    a[i] = '\0';
//    for (int j = 0; j < i; j++){               //CHECK TEXT
//        printf("%c", a[j]);
//    }
    int n = 0;
    for (int j = 0; j < i; j++){
        if(check_letter(a, j)){
            n++;
        }
    }
//    printf("n = %d\n", n);
    int m = n;
    int q = 0;
    int nn = n;                //потом раскоментить!!!
    while(nn >= 1){
        q++;
        nn = nn / 10;
//        printf("nn = %d\n", nn);
    }
    int p = q;
//    printf("p = (2) %d\n", p);

    int result [p];
//    printf("n massiv = %d ", p);
    for (int j = 0; j < p; j++){
        result[j] = n % 10;
        n = (n - result[j])/10;
    }
//    for (int j = 0; j < p; j++){
//        printf(".%d ", result[j]);
//    }
    fclose(fp);

    fp = fopen(argv[1], "w");
    if(m == 0){
        fputc ('0', fp);
    }
    for (int j = p-1; j > -1; j--){
        char c = result[j] + '0';
        fputc (c, fp);
    }
    fclose(fp);

    return 0;
}

int check_letter(const char a[], const int j){
    int aa = j + 1;
    int b = j + 2;
    int c = j + 3;
    int d = j + 4;
    int e = j + 5;
    if (a[j] == 'a' || a[j] == 'A'){
        if (a[aa] == 'n' || a[aa] == 'N'){
            if (a[b] == 'a' || a[b] == 'A'){
                if (a[c] == 'n' || a[c] == 'N'){
                    if (a[d] == 'a' || a[d] == 'A'){
                        if (a[e] == 's' || a[e] == 'S'){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// gcc -std=c11 -Werror -Wall count_words.c -lm -o count_words