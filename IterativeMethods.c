// Iterative methods for finding roots of f(x) = x³ - 3x + 1.06

#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - 3*x + 1.06;
}

float df(float x) {
    return 3*x*x - 3;
}

void bisectionMethod(float a, float b, float tolerance) {
    float error = 1.0;
    float c, prev_c = 0.0;
    int iteration = 0;
    int max_iterations = 13;
    
    printf("\nBisection Method\n");
    printf("Iteration\tRoot\n");
    printf("-------------------\n");
    
    while (error > tolerance && iteration < max_iterations) {
        iteration++;
        c = (a + b) / 2.0;
        
        if (iteration > 1) {
            error = fabs(c - prev_c);
        }
        
        printf("%d\t\t%.3f\n", iteration, c);
        
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        prev_c = c;
    }
    
    printf("\nRoot: %.3f\n", c);
}

void secantMethod(float x0, float x1, float tolerance) {
    float error = 1.0;
    float x2;
    int iteration = 0;
    int max_iterations = 6;
    
    printf("\n=== Secant Method ===\n");
    printf("Iteration\tRoot\n");
    printf("-------------------\n");
    
    while (error > tolerance && iteration < max_iterations) {
        iteration++;
        
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        error = fabs(x2 - x1);
        
        printf("%d\t\t%.3f\n", iteration, x2);
        
        x0 = x1;
        x1 = x2;
    }
    
    printf("\nRoot: %.3f\n", x2);
}

void regulaFalsiMethod(float a, float b, float tolerance) {
    float error = 1.0;
    float c, prev_c = 0.0;
    int iteration = 0;
    int max_iterations = 4;
    
    printf("\n=== Regula Falsi (False Position) Method ===\n");
    printf("Iteration\tRoot\n");
    printf("-------------------\n");
    
    while (error > tolerance && iteration < max_iterations) {
        iteration++;
        
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        
        if (iteration > 1) {
            error = fabs(c - prev_c);
        }
        
        printf("%d\t\t%.3f\n", iteration, c);
        
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        prev_c = c;
    }
    
    printf("\nRoot: %.3f\n", c);
}

void newtonRaphsonMethod(float x, float tolerance) {
    float error = 1.0;
    float x_new;
    int iteration = 0;
    int max_iterations = 4;
    
    printf("\n=== Newton-Raphson Method ===\n");
    printf("Iteration\tRoot\n");
    printf("-------------------\n");
    
    while (error > tolerance && iteration < max_iterations) {
        iteration++;
        
        x_new = x - f(x) / df(x);
        error = fabs(x_new - x);
        
        printf("%d\t\t%.3f\n", iteration, x_new);
        
        x = x_new;
    }
    
    printf("\nPositive Root: %.3f\n", x);
}

int main() {
    float tolerance = 1e-4;
    int choice;
    
    printf("\n   f(x) = x^3 - 3x + 1.06\n");
    printf("   Interval: [0, 1]\n");
    
    printf("Select a method:\n");
    printf("1. Bisection Method\n");
    printf("2. Secant Method\n");
    printf("3. Regula Falsi (False Position)\n");
    printf("4. Newton-Raphson Method\n");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            bisectionMethod(0.0, 1.0, tolerance);
            break;
        case 2:
            secantMethod(0.0, 1.0, tolerance);
            break;
        case 3:
            regulaFalsiMethod(0.0, 1.0, tolerance);
            break;
        case 4:
            newtonRaphsonMethod(0.5, tolerance);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    return 0;
}