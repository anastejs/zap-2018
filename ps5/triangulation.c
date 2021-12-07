#include <stdio.h>
#include <math.h>
# define M_PI	     3.14159265358979323846
float to_radians(const int angle);

int main(){
    int angle;
    printf("angle = ");
    scanf("%d", &angle);
    printf("%.3f\n", to_radians(angle));

    return 0;
}

float to_radians (const int angle){
    if (angle <= 0 || angle >= 360 ){
        return -1;
    }
    float rad = angle * M_PI / 180;
    printf("%f\n", rad);
    return rad;
}

// gcc -std=c11 -Werror -Wall triangulation.c -lm -o triangulation