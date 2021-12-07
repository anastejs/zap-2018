#include <stdio.h>
#include <math.h>

int main(){

    int o;
    scanf("%d", &o);
    if ( o < 0 || o > 20 ){
        printf("Wrong input!\n");
        return 1;
    }
    int n = o*2 + 1;
    int hodnoty [n];
    hodnoty[0] = o;

    for (int i = 1; i < n; i++){
        scanf ("%d", &hodnoty[i]);
        if (hodnoty[i] != 1 && hodnoty[i] != 2){
            printf("Wrong input!\n");
            return 1;
        }
        i++;
    }
    for (int i = 2; i < n; i++){
        scanf ("%d", &hodnoty[i]);
        if (hodnoty[i] < 0){
            printf("Wrong input!\n");
            return 1;
        }
        i++;
    }

        return 0;
}