#include<stdio.h>
#include<math.h>

double f(double x) {
	return x*x*x*x + x*x - 3*x - 4;
}

int main() {
	double a, b, c;
	int iteration = 0;
	
	printf("\n To find the root of the function f(x) = x^4 + x^2 - 3x - 4 using Secant method is: ");
	printf("\n Enter the 1st initial guess: ");
	scanf("%lf", &a);
	printf("\n Enter the 2nd initial guess: ");
	scanf("%lf", &b);
	
	while (iteration < 20) {
		iteration++;
		if(fabs(f(a) - f(b)) < 1e-6) {
			printf("\n The denominator is too small. Please enter another initial guess.");
			return 1;
		}
		c = b - f(b)*(b-a)/(fabs(f(b)-f(a)));
		printf("\nIteration %d: x = %.3f, f(x) = %.3f\n",iteration, c, f(c));
		if(fabs(c-b) < 0.0001)
		break;
		
		a = b;
		b = c;
	}
	printf("\nEstimated root: %.3f", c);
	printf("\nf(%.3f): %.3f", c, f(c));
	printf("\nTotal number of iterations: %d", iteration);
	
	return 0;
}
