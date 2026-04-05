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
    double x = 0.2, y = 2.0, h = 0.2, x_target = 1.0;
    
    printf("Euler's Basic Method\n");
    printf("x\t\ty\n");
    printf("%.1f\t\t%.4f\n", x, y);
    
    while (x < x_target) {
        y = y + h * f(x, y);
        x = x + h;
        printf("%.1f\t\t%.4f\n", x, y);
    }
    
    printf("\nAnswer: y(1.0) = %.4f\n", y);
    return 0;
}