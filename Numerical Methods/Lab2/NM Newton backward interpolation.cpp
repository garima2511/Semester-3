#include<stdio.h>

int main() {
	int n, i, j;
	float x[20], y[20][20], xp, h, u, sum, term;
	
	printf("\nEnter the number of data points: ");
	scanf("%d", &n);
	
	printf("\nEnter the values of x: \n");
	for(i = 0; i < n; i++) {
		scanf("%f", &x[i]);
	}
	
	printf("\nEnter the values of y: \n");
	for(i = 0; i < n; i++) {
		scanf("%f", &y[i][0]);
	}
	
	for(i = 1; i < n; i++) {
		for(j = n-1; j >= i ; j--) {
			y[j][i] = y[j][i-1] - y[j-1][i-1];
		}
	}
	
	printf("\nEnter values of x to find f(x): ");
	scanf("%f", &xp);
	
	h = x[1] - x[0];
	u = (xp - x[n-1]) / h;
	
	sum = y[n-1][0];
	term = 1;
	
	for(i = 1; i < n; i++) {
		term = term * (u + (i-1)) / i;
		sum = sum + term * y[n-1][i];
	}
	
	printf("\nThe approximate value at x = %.3f is f(x) = %.3f\n", xp, sum);
	return 0;
	
}
