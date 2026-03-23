/*
Find the following integration using Simpson's method in 8 sub-intervals.
Find absolute and maximum errors also.

I = integral dx/(1 + x), from a to b
*/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + x);
}

int main(void) {
    int n = 8; /* Number of sub-intervals (must be even for Simpson's 1/3 rule) */
    double a, b;
    double h, sum_odd = 0.0, sum_even = 0.0;
    double simpson_value, exact_value, absolute_error;
    double m4, max_error_bound;

    printf("Enter lower limit a and upper limit b: ");
    scanf("%lf %lf", &a, &b);

    if (a <= -1.0 || b <= -1.0) {
        printf("Invalid interval: x = -1 is a singular point for 1/(1+x).\n");
        return 1;
    }

    h = (b - a) / n;

    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        if (i % 2 == 0) {
            sum_even += f(xi);
        } else {
            sum_odd += f(xi);
        }
    }

    simpson_value = (h / 3.0) * (f(a) + f(b) + 4.0 * sum_odd + 2.0 * sum_even);

    /* Exact integral of 1/(1+x) is ln(1+x) */
    exact_value = log(1.0 + b) - log(1.0 + a);
    absolute_error = fabs(exact_value - simpson_value);

    /* f''''(x) = 24/(1+x)^5, max on [a,b] occurs at smaller endpoint */
    double min_x = (a < b) ? a : b;
    m4 = 24.0 / pow(1.0 + min_x, 5.0);
    max_error_bound = ((b - a) / 180.0) * pow(h, 4.0) * m4;

    printf("\nUsing Simpson's 1/3 Rule with n = %d\n", n);
    printf("Approximate integral  = %.3lf\n", simpson_value);
    printf("Exact integral        = %.3lf\n", exact_value);
    printf("Absolute error        = %.3lf\n", absolute_error);
    printf("Maximum error bound   = %.3lf\n", fabs(max_error_bound));

    printf("Total number of sub-intervals used is: 8");

    return 0;
}
