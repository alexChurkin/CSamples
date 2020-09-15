#include <stdio.h>
#include <math.h>
//TODO
void main() {
    float a, b, c;
    scanf_s("%f %f %f", &a, &b, &c);
    if(a == 0 || b == 0 || c == 0) printf("Incorrect coefficients");

    //Равносторонний
    if(a == b && b == c) {
        printf("1 Равносторонний");
    } else if(a )
}