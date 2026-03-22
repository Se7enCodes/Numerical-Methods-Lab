#include <stdio.h>
#include <math.h>

#define N 3
#define ITER 25

int main() {
    double a[N][N] = {
        {20,  5, -2},
        { 3, 10,  1},
        { 1, -4, 10}
    };

    double b[N] = {14, 17, 23};

    double x[N] = {0, 0, 0};
    double x_new[N];

    int i, j, k;

    for (k = 0; k < ITER; k++) {
        for (i = 0; i < N; i++) {
            double sum = b[i];
            for (j = 0; j < N; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
        }

        for (i = 0; i < N; i++)
            x[i] = x_new[i];
    }

    printf("Solution after %d iterations:\n", ITER);
    for (i = 0; i < N; i++)
        printf("x%d = %.4lf\n", i + 1, x[i]);

    return 0;
}