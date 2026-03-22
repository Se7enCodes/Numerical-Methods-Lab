/*
x = {-1, 0, 2, 5}
fx = {9, 5, 3, 15}
Use Lagrange Interpolation to find f(3.5).
*/

# include <stdio.h>
# include <math.h>

int main() {
    // Data points
    float x[] = {-1, 0, 2, 5};
    float fx[] = {9, 5, 3, 15};
    int n = 4;
    
    // Point at which we want to find the value
    float x_val = 3.5;
    float result = 0.0;
    
    for (int i = 0; i < n; i++) {
        float term = fx[i];
        
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * (x_val - x[j]) / (x[i] - x[j]);
            }
        }
        
        result += term;
    }
    
    printf("Using Lagrange Interpolation:\n");
    printf("Data points:\n");
    for (int i = 0; i < n; i++) {
        printf("  f(%.3f) = %.3f\n", x[i], fx[i]);
    }
    printf("\nf(%.3f) = %.3f\n", x_val, result);
    
    return 0;
}
