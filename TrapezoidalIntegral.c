/*
Find the following integration using Trapezoidal rule in 8 sub-intervals.
Find absolute and maximum errors also, upto 6 decimal places.

I = integral dx/(1 + x), from a to b
*/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + x);
}

int main(void) {
    //Number of sub-intervals
    int n = 8;
    double a, b;
    double h, sum = 0.0;
    double trapVal, exact, absError;
    double m2, maxErr;

    printf("Enter lower limit a and upper limit b: ");
    scanf("%lf %lf", &a, &b);

    if (a <= -1.0 || b <= -1.0) {
        printf("Invalid interval: x = -1 is a singular point for 1/(1+x).\n");
        return 1;
    }

    h = (b - a) / n;

    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        sum += f(xi);
    }

    trapVal = (h / 2.0) * (f(a) + f(b) + 2.0 * sum);

    /* Exact integral of 1/(1+x) is ln(1+x) */
    exact = log(1.0 + b) - log(1.0 + a);
    absError = fabs(exact - trapVal);

    /* f''(x) = 2/(1+x)^3; max on [a,b] occurs at smaller endpoint */
    double min_x = (a < b) ? a : b;
    m2 = 2.0 / pow(1.0 + min_x, 3.0);
    maxErr = ((b - a) / 12.0) * pow(h, 2.0) * m2;

    printf("\nUsing Trapezoidal Rule with n = %d\n", n);
    printf("Approximate integral  = %.6lf\n", trapVal);
    printf("Exact integral        = %.6lf\n", exact);
    printf("Absolute error        = %.6lf\n", absError);
    printf("Maximum error bound   = %.6lf\n", fabs(maxErr));

    return 0;
}
