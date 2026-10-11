#include <stdio.h>
#include <math.h>

int main() {
    int i, n;
    float x[20], y[20];
    float sumx = 0, sumY = 0, sumxY = 0, sumx2 = 0;
    float A, B, a, b, Y;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);

        Y = log10(y[i]);   // logarithmic transformation

        sumx += x[i];
        sumY += Y;
        sumxY += x[i] * Y;
        sumx2 += x[i] * x[i];
    }

    /* Least square formulas */
    B = (n * sumxY - sumx * sumY) / (n * sumx2 - sumx * sumx);
    A = (sumY - B * sumx) / n;

    /* Back substitution */
    a = pow(10, A);
    b = B / log10(exp(1));

    printf("\nLeast square fitted curve:\n");
    printf("y = %.4f e^(%.4fx)\n", a, b);

    return 0;
}

