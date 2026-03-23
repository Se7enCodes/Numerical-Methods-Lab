/*
x = {-2, -1 ,0, 1, 3, 4}
fx = {9, 16, 17, 18, 44, 81}
WAP to implement Newton divided difference to find the value of f(0.5)
*/

#include <stdio.h>

int main() {
    float x[] = {-2, -1, 0, 1, 3, 4};
    float fx[] = {9, 16, 17, 18, 44, 81};
    int n = 6;
    
    float dd[n][n];
    
    // Fill first column with function values
    for (int i = 0; i < n; i++) {
        dd[i][0] = fx[i];
    }
    
    // Build divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    
    // Print table
    printf("\nDivided Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%.3f", dd[i][j]);
        }
        printf("\n");
    }
    
    // Calculate f(0.5)
    float result = dd[0][0];
    float term = 1.0;
    
    for (int i = 1; i < n; i++) {
        term = term * (0.5 - x[i-1]);
        result = result + dd[0][i] * term;
    }
    
    printf("\nf(0.5) = %.3f\n\n", result);
    
    return 0;
}
