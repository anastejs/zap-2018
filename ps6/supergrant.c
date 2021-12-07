#include <stdio.h>
#include <math.h>

int is_prime(const int number);
int next_prime(const int prime);
int sum_digits(const long int number);
int sum_digits_n(const int n);
long int find_A_n(const int n);
int constant(const int a, const int b);

int main(){

    int a, b, suma;
    scanf("%d %d %d", &a, &b, &suma);

    if (a < 1 || a > 5000){
        printf("Wrong input!\n");
        return 1;
    }
    if (b < -20 || b > 20){
        printf("Wrong input!\n");
        return 1;
    }
    if (suma < 1000 || suma > 1000000){
        printf("Wrong input!\n");
        return 1;
    }
    double blbost = 0;
    double sale = 100 - constant(a,b);
    sale = round(sale);
    sale/= 100.0;
    blbost = suma * sale;
    printf("Supergrant: %.2f\n", blbost);

//    int number;
//    int prime;

//    int n;
//    printf("n = %d", n);
//    scanf("%d", &n);

//    printf("n = ");
//    scanf("%d", &number);
//    prime = number;
//    printf("n posledovat = ");
//    scanf("%d", &n);

//    printf("число простое (1) или нет (0): %d\n", is_prime(number));
//    printf("следующее простое число: %d\n", next_prime(prime));
//    printf("sum = %d\n", sum_digits(1234567890));
//    printf("sum posledovatelnosti = %d\n", sum_digits_n(n));
//      printf("A_n = %ld\n", find_A_n(4));
//printf("%d\n", constant(500,-15));
//printf("%d\n", constant(1234,4));

    return 0;
}

int is_prime(const int number){
    int k = 0;
    for (int i = number; i > 0; i--){
        if (number % i == 0){
            k += 1;
        }
    }
    if (k == 2){
        return 1;
    }
    return 0;
}

int next_prime(const int prime){
    int k = 0;
        for (int i = prime; i > 0; i--){
            if (prime % i == 0){
                k += 1;
            }
        }
        if (k != 2){
            return -1;
        }
    int j = prime + 1;
    while(!is_prime(j)){
        j++;
    }
    return j;
}

int sum_digits (const long int number){
    int cislo = number;
    int mas[20] = {0};
    int i = 0;
    while(cislo >= 1){
        mas [i] = cislo % 10;
//        printf(" %d ", mas[i]);
        cislo = cislo/10;
        i++;
    }
    for(int j = 0; j != 20; j++){
//        printf("%d\n", mas[j]);
    }
    i = 0;
    int sum = 0;
        for(i = 0; i <= 19; i++){
           sum += mas[i];
        //        printf("sum = %d\n", sum);
        }
    return sum;
}

 int sum_digits_n(const int n){
    int sum = 0;
    int a = 1;
    for(int i = 1; i != n; i++){
        sum += sum_digits(a);
//        printf("sum = %d\n", sum);
        a = sum;
    }
    return sum;
}

long int find_A_n(const int n){
    if(n > 1){
        return 0;
    }
    int prost[n];
    prost[0] = 2;
    for (int i = 1; i <= n; i++){
        prost[i] = next_prime(prost[i-1]);
       // printf("%d ", prost[i]);
    }
    long int A_n = n;
    //printf("%ld ", A_n);
    while(1){
        for (int i = 0; i <= n; i++){
            if (A_n % prost[i] != i){
                A_n++;
                break;
            }
            if (i == n-1){
                A_n++;
                return A_n;
            }
        }
    }
    return 0;
}

int constant(const int a, const int b){
    int fu = sum_digits_n(a);
    int k = 0;
    if (1 <= b && b <= 9){
        k = sum_digits(find_A_n(b));
    }
    else{
        k = sum_digits(fu);
    }
    int l = 0;
    if (k > fu){
        l = k/fu;
    }
    else{
        l = fu/k;
    }
    while(l > 49){
        if (l%2==0){
            l /= 2;
        }
        else{
            l= sum_digits(l);
        }
    }
    return l;
}

// gcc -std=c11 -Werror -Wall supergrant.c -lm -o supergrant