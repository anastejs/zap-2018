#include <karel.h>
#include <stdio.h>
#include <math.h>

void turnRight();
void turnAround();
int number();
int calculator();
void trasa();

int main(){
	setStepDelay(50);
	turnOn("ps3.kw");
	int n = 0 ;                             //ввели переменную n
	n = number();                           //определяем количество ячеек в массиве
    int a[n];                               //создаём массив а с количеством ячеек n
    for (int j = 0 ; j != n ; j++){         //в каждую ячейку массива записываем количество биперов
        a[j] = calculator();
        movek();
    }
    int cislo = 0;                          //определяем заданное число в десятичном виде
    for (int j = 0 ; j != n ; j++){
        int q = n-j-1;
        cislo = cislo + a[j]*pow (10, q);
    }
    trasa();
    movek();
    int y = 0;
    int x = 0;
    do{
        y = pow (2, x);
        x++;
    }while(y < cislo);
//    printf("%d" , x);
    int q = x-1;                            //количество ячееек в массиве b
    int b[q];
    int cislo2 = cislo;
    float remain = 0;
    for (int j = 0 ; j < q; j++){

            remain = cislo2 % 2;

            if(remain == 0){
                b[j] = 0;
            }
            if(remain > 0){
                b[j] = 1;
            }
            cislo2 = cislo2 / 2;
    }
//    for (int j = 0; j <= x-1; j++){
//        printf("%d", b[j]);
//    }
    for(int j = q-1; j >= 0; j-- ){
        loop(b[j]){
            putBeeper();
        }
        movek();
    }
    turnOff();
	return 0;
}



int calculator(){
    int i = 0;
    while(beepersPresent()){
        pickBeeper();
        i++;
    }
    loop(i){
        putBeeper();
    }
    return i;
}

int number(){
    int i = 0;
    movek();
    while (beepersPresent()){
        movek();
        i++;
    }
    turnAround();
    loop(i){
        movek();
    }
    turnAround();
//    gcc -std=c11 -Werror -Wall ps3.c -lkarel -lcurses -lm -o ps3
    return i;
}

void trasa(){
    turnAround();
    movek();
    while(beepersPresent()){
        movek();
    }
    turnLeft();
    movek();
    turnLeft();

}

void turnRight(){
	turnLeft();
	turnLeft();
	turnLeft();
}

void turnAround(){
turnLeft();
turnLeft();
}