#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOL 0.0001

int main() {
    float x1 = 0, x2 = 0, x3 = 0;
    float x1_new, x2_new, x3_new;
    int i;

    for(i = 1; i <= MAX_ITER; i++) {

        x1_new = (14 - 5*x2 + 2*x3) / 20;
        x2_new = (17 - 3*x1_new - x3) / 10;
        x3_new = (23 - x1_new + 4*x2_new) / 10;

        if(fabs(x1_new - x1) < TOL && fabs(x2_new - x2) < TOL && fabs(x3_new - x3) < TOL)
            break;

        x1 = x1_new;
        x2 = x2_new;
        x3 = x3_new;
        printf("\nx = %.3f\n", x1_new);
        printf("\ny = %.3f\n", x2_new);
        printf("\nz = %.3f\n", x3_new);
    }

    // for (i = 1; i <= 4; i++){
    //     printf("Solution after %d iterations:\n", i);
    //     printf("x1 = %.3f\n", x1_new);
    //     printf("x2 = %.3f\n", x2_new);
    //     printf("x3 = %.3f\n", x3_new);
    // }

    return 0;
}