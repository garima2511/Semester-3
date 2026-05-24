#include <stdio.h>

int main() {
    int i, n;
    float x[20], y[20];
    float sx = 0, sx2 = 0, sx3 = 0, sx4 = 0;
    float sy = 0, sxy = 0, sx2y = 0;
    float a, b, c;
    float A[3][4];

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);

        sx += x[i];
        sx2 += x[i] * x[i];
        sx3 += x[i] * x[i] * x[i];
        sx4 += x[i] * x[i] * x[i] * x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2y += x[i] * x[i] * y[i];
    }

    /* Form augmented matrix */
    A[0][0] = n;    A[0][1] = sx;   A[0][2] = sx2;  A[0][3] = sy;
    A[1][0] = sx;   A[1][1] = sx2;  A[1][2] = sx3;  A[1][3] = sxy;
    A[2][0] = sx2;  A[2][1] = sx3;  A[2][2] = sx4;  A[2][3] = sx2y;

    /* Gaussian elimination */
    for (i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            float ratio = A[j][i] / A[i][i];
            for (int k = 0; k < 4; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    /* Back substitution */
    c = A[2][3] / A[2][2];
    b = (A[1][3] - A[1][2] * c) / A[1][1];
    a = (A[0][3] - A[0][2] * c - A[0][1] * b) / A[0][0];

    printf("\nLeast square fitted polynomial:\n");
    printf("y = %.4f + %.4fx + %.4fx^2\n", a, b, c);

    return 0;
}

