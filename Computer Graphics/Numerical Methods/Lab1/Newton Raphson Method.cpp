#include<stdio.h>
#include<math.h>

//function is x^4 + x^2 - 3x - 4
double f(double x) {
	return x*x*x*x + x*x - 3*x - 4;
}

double f_derivative(double x) {
	return 4*x*x*x + 2*x - 3;
}

int main() {
	double x0, x1;
	int iteration = 0;
	
	printf("To find the root of the funtion x^4 + x^2 - 3x - 4 using newton raphson method: \n");
	printf("\n Enter the initial guess: ");
	scanf("%lf", &x0);
	
	while (iteration < 20) {
		iteration++;
		if(fabs(f_derivative(x0)) < 1e-6) {
			printf("\n The derivative is zero. Please enter another initial guess.\n");
			return 1;
		}
		
		x1 = x0 - f(x0)/f_derivative(x0);
		printf("\n Iteration %d: x = %.3f, f(x) = %.3f\n", iteration, x1, f(x1));
		
		if(fabs(x0-x1) < 0.001)
		break;
		
		x0 = x1;
	}
	printf("\nEstimated root = %.3f", x1);
	printf("\nf(%.3f) = %.3f", x1, f(x1));
	printf("\nTotal number of iterations = %d", iteration);
	
	return 0;	
}
