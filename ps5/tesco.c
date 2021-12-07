#include <stdio.h>
#include <math.h>

int main() {
    float values[13] = {100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
    float price = 0;
    printf("Enter value of your bill: ");
    scanf("%f", &price);
    if (price < 0 || price > 10000){
        printf("Wrong input!\n");
        return 1;
    }

    float numbers = 0;
    float sum = 0;
    printf("Insert money for payment: ");
    do{
//        scanf("%f", &numbers);
        if (scanf("%f", &numbers) == EOF){
            break;
        }
        for(int i = 0; i < 13; i++){
//            float check = fabs(numbers - values[i]);
//            printf("%f", check);
            if (numbers == values[i]){
                break;
            }
            if (numbers != values[i] && numbers != 0 && i == 12){
                if (numbers >= 1){
                    int number = numbers;
                    printf("%d is invalid!\n", number);
                }
                else{
                    printf("%.2f is invalid!\n", numbers);
                }
                return 1;
            }
        }
        if (numbers == 0){
            break;
        }
//        if (scanf("%f", &numbers) == EOF){
//            break;
//        }
        sum += numbers;
    } while(numbers != EOF);


    int a = sum;
    if (a == sum){
        printf("You have inserted: %.0f\n", sum);
    }
    else{
        printf("You have inserted: %.2f\n", sum);
    }
    if(sum < price){
        printf("Not enough money!\n");
        return 0;
    }

    float remain = 0;
    remain = sum - price;
    int b = remain;
    if (b == remain && b != 0){
        printf("To return: %.0f\n", remain);
    }
    if (remain == 0){
        printf("To return: 0\n");
        return 0;
    }
    if (b != remain && b != 0){
        printf("To return: %.2f\n", remain);
    }

    printf("Collect your payback:");

    while(remain >= 0.02){
        for (int j = 0; j != 12; j++){
            while (values[j] <= remain){
                int k = values[j];
                if (k == values[j]){
                    printf(" %.0f", values[j]);
                }
                else{
                    printf(" %.2f", values[j]);
                }
                remain = remain - values[j];
            }
        }
    }

//    printf("remain %f", remain);

        int m = remain;
        if (remain - m > 0.001){
            printf(" 0.01");
        }

    printf("\n");
    return 0;
}

//  gcc -std=c11 -Werror -Wall tesco.c -lm -o tesco