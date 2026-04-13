/*
Use Runge-Kutta method (4th order)
dy/dx = (x + y), y(0) = 1, h = 0.2, y(0.4) = ?
*/

#include <stdio.h>

/* Differential equation: dy/dx = x + y */
double f(double x, double y) {
    return x + y;
}

/* Runge-Kutta 4th Order Method */
double rk4(double x0, double y0, double h, double xtgt) {
    double x = x0;
    double y = y0;
    int steps = (int)((xtgt - x0) / h);
    
    printf("Step\tx\ty\t\tk1\t\tk2\t\tk3\t\tk4\n");
    printf("---\t---\t---\t\t---\t\t---\t\t---\t\t---\n");
    printf("%d\t%.1f\t%.6f\n", 0, x, y);
    
    for (int i = 0; i < steps; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + (h / 2) * k1);
        double k3 = f(x + h / 2, y + (h / 2) * k2);
        double k4 = f(x + h, y + h * k3);
        
        y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;
        
        printf("%d\t%.1f\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\n", i + 1, x, y, k1, k2, k3, k4);
    }
    
    return y;
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.2;
    double xtgt = 0.4;
    
    double result = rk4(x0, y0, h, xtgt);
    
    printf("\n");
    printf("dy/dx = x + y, y(0) = 1, h = 0.2\n");
    printf("y(0.4) = %.6f\n", result);
    
    return 0;
}

