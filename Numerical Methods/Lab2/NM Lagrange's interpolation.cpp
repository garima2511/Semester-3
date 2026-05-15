#include<stdio.h>

int main() {
	int n, i , j;
	float x[20], y[20], xp, yp = 0, term;
	
	printf("\nEnter number of data points: ");
	scanf("%d", &n);
	
	printf("\nEnter the data points (x): \n");
	for(i = 0; i < n; i++) {
		scanf("%f", &x[i]);
	}
	
	printf("\nEnter the data points (y): \n");
	for(i = 0; i < n; i++) {
		scanf("%f", &y[i]);
	}
	
	printf("\nEnter the value of x to find f(x): ");
	scanf("%f", &xp);
	
	for(i = 0; i < n; i++) {
		term = y[i];
		for(j = 0; j < n; j++) {
			if(j != i) {
				term = term * (xp - x[j]) / (x[i] - x[j]);
			}
		}
		yp = yp + term;
	}
	printf("\nThe approximate value at x = %.3f is f(x) = %.3f", xp, yp);
	return 0;
}

