/*
Find the following integration using Simpson's (3/8)th method in sub-intervals divisible by 3.
Find absolute and maximum errors also.

I = integral dx/(1 + x), from a to b
*/

#include <stdio.h>
#include <math.h>

double f(double x) { return 1.0 / (1.0 + x); }

int main(void) {
    double a, b;
    int n; /* must be positive and divisible by 3 for Simpson's 3/8 rule */
    printf("Enter lower limit a, upper limit b, and sub-interval count n (divisible by 3): ");
    if (scanf("%lf %lf %d", &a, &b, &n) != 3) return 1;

    if (a <= -1.0 || b <= -1.0) {
        printf("Invalid interval: x = -1 is a singular point for 1/(1+x).\n");
        return 1;
    }
    if (n <= 0 || n % 3 != 0) {
        printf("n must be positive and divisible by 3 for Simpson's 3/8 rule.\n");
        return 1;
    }

    double h = (b - a) / n;
    double sum_coef3 = 0.0, sum_coef2 = 0.0;
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        if (i % 3) sum_coef3 += f(xi);  /* i % 3 == 1 or 2 */
        else sum_coef2 += f(xi);        /* i % 3 == 0 */
    }

    double simpson_value = (3.0 * h / 8.0) * (f(a) + f(b) + 3.0 * sum_coef3 + 2.0 * sum_coef2);
    double exact_value = log(1.0 + b) - log(1.0 + a);
    double absolute_error = fabs(exact_value - simpson_value);

    /* f''''(x) = 24/(1+x)^5, max on [a,b] occurs at the smaller endpoint */
    double min_x = (a < b) ? a : b;
    double m4 = 24.0 / pow(1.0 + min_x, 5.0);
    double max_error_bound = ((b - a) / 80.0) * pow(h, 4.0) * m4;

    printf("\nUsing Simpson's 3/8 Rule with n = %d\n", n);
    printf("Approximate integral  = %.6lf\n", simpson_value);
    printf("Exact integral        = %.6lf\n", exact_value);
    printf("Absolute error        = %.6lf\n", absolute_error);
    printf("Maximum error bound   = %.6lf\n", fabs(max_error_bound));
    printf("\nTotal sub-intervals used: %d\n", n);
    return 0;
}