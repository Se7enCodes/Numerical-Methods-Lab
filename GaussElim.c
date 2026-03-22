#include <stdio.h>
#include <math.h>

#define N 3

int main() {
    double a[N][N + 1] = {
        {20,  5, -2, 14},
        { 3, 10,  1, 17},
        { 1, -4, 10, 23}
    };

    int i, j, k;
    double factor;

    //Fwd elim
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            factor = a[j][i] / a[i][i];
            for (k = i; k <= N; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    //Back Sub
    double x[N];

    for (i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %.4lf\n", i + 1, x[i]);
    }

    return 0;
}