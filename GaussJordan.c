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
    double ratio;

    for (i = 0; i < N; i++) {
        double pivot = a[i][i];
        for (j = 0; j <= N; j++)
            a[i][j] /= pivot;

        for (k = 0; k < N; k++) {
            if (k != i) {
                ratio = a[k][i];
                for (j = 0; j <= N; j++)
                    a[k][j] -= ratio * a[i][j];
            }
        }
    }

    printf("Solution:\n");
    for (i = 0; i < N; i++)
        printf("x%d = %.4lf\n", i + 1, a[i][N]);

    return 0;
}