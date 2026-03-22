/*
x = {0.1, 0.2, 0.3, 0.4, 0.5}
fx = {1.40, 1.56, 1.76, 2.00, 2.28}
Apply Newton's Forward / Backward Difference (choice using user input) to find the value at x = 0.25
*/

#include <stdio.h>
#include <math.h>

int main() {
    // Data points
    float x[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    float fx[] = {1.40, 1.56, 1.76, 2.00, 2.28};
    int n = 5;
    float h = 0.1;  // Step size
    float x_val = 0.25;  // Point where we want to find the value
    
    // difference table
    float diff[n][n];
    
    // Initialize first column with function values
    for (int i = 0; i < n; i++) {
        diff[i][0] = fx[i];
    }
    
    // difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }
    
    // Display difference table
    printf("Difference Table:\n");
    printf("x\t\tf(x)\t\tDelta1\t\tDelta2\t\tDelta3\t\tDelta4\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f\t\t%.3f", x[i], diff[i][0]);
        for (int j = 1; j < n - i; j++) {
            printf("\t\t%.3f", diff[i][j]);
        }
        printf("\n");
    }
    
    int choice;
    printf("\nKonsa karana hai sir???\n");
    printf("1. Forward Difference\n");
    printf("2. Backward Difference\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    float result = 0.0;
    
    if (choice == 1) {
        // Forward Difference (near beginning: x = 0.1)
        float p = (x_val - x[0]) / h;
        result = diff[0][0];
        
        float fact = 1.0;
        float p_coeff = p;
        
        for (int j = 1; j < n; j++) {
            fact *= j;
            result += (p_coeff / fact) * diff[0][j];
            p_coeff *= (p - j);
        }
        
        printf("\nUsing Newton's Forward Difference Formula:\n");
        printf("p = (%.3f - %.3f) / %.3f = %.3f\n", x_val, x[0], h, p);
    }
    else if (choice == 2) {
        // Backward Difference (near end: x = 0.5)
        float p = (x_val - x[n - 1]) / h;
        result = diff[n - 1][0];
        
        float fact = 1.0;
        float p_coeff = p;
        
        for (int j = 1; j < n; j++) {
            fact *= j;
            result += (p_coeff / fact) * diff[n - 1 - j][j];
            p_coeff *= (p + j);
        }
        
        printf("\nUsing Newton's Backward Difference Formula:\n");
        printf("p = (%.3f - %.3f) / %.3f = %.3f\n", x_val, x[n - 1], h, p);
    }
    else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    printf("f(%.3f) = %.3f\n", x_val, result);
    
    return 0;
}

