/*
dy/dx = -(y)/(1 + x)
y(0.2) = 2, h = 0.2
y(1.0) = ? (Euler's basic method)
*/

#include <stdio.h>

double f(double x, double y) {
    return -(y) / (1.0 + x);
}

int main(void) {
    double x = 0.2, y = 2.0, h = 0.2, x_tgt = 1.0;
    
    printf("Euler's Basic Method\n");
    printf("x\t\ty\n");
    printf("%.3f\t\t%.3f\n", x, y);

    while (x < x_tgt) {
        y = y + h * f(x, y);
        x = x + h;
        printf("%.3f\t\t%.3f\n", x, y);
    }
    
    printf("\nAnswer: y(1.0) = %.3f\n", y);
    return 0;
}