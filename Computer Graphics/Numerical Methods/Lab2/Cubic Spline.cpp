#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], h[20];
    float alpha[20], l[20], u[20], z[20];
    float M[20];     // second derivatives
    float xp, fx;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    /* Step 1: Calculate h[i] */
    for (i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

    /* Step 2: Calculate alpha */
    alpha[0] = alpha[n - 1] = 0;
    for (i = 1; i < n - 1; i++) {
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i])
                 - (3 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    /* Step 3: Solve tridiagonal system (Thomas algorithm) */
    l[0] = 1;
    u[0] = 0;
    z[0] = 0;

    for (i = 1; i < n - 1; i++) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * u[i - 1];
        u[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1;
    z[n - 1] = 0;
    M[n - 1] = 0;

    for (j = n - 2; j >= 0; j--) {
        M[j] = z[j] - u[j] * M[j + 1];
    }

    /* Step 4: Interpolation */
    printf("Enter value of x to interpolate: ");
    scanf("%f", &xp);

    for (i = 0; i < n - 1; i++) {
        if (xp >= x[i] && xp <= x[i + 1])
            break;
    }

    fx = (M[i] * (x[i + 1] - xp) * (x[i + 1] - xp) * (x[i + 1] - xp)) / (6 * h[i])
       + (M[i + 1] * (xp - x[i]) * (xp - x[i]) * (xp - x[i])) / (6 * h[i])
       + (y[i] - M[i] * h[i] * h[i] / 6) * (x[i + 1] - xp) / h[i]
       + (y[i + 1] - M[i + 1] * h[i] * h[i] / 6) * (xp - x[i]) / h[i];

    printf("Interpolated value at x = %.4f is %.6f\n", xp, fx);

    return 0;
}

