#include<stdio.h>
#include<math.h>

//Define the function f(x) = x^4 + x^2 - 3x -4
double f(double x) {
	return x*x*x*x + x*x - 3*x - 4;
}

int main() {
	double a, b, c;
	int iteration = 0;
	
	a = 1;
	b = 2;
		
	if(f(a)*f(b) >= 0) {
		printf("Invalid Interval: f(a) and f(b) must have oppposite signs.\n ");
		return 1;
	}
	
		printf("To find the root of x^4 + x^2 - 3x - 4 by using bisection method upto 4 decimal digits.\n ");
		printf("Initial interval: [%.3f, %.3f]\n\n", a, b);
		
		while((b-a) >= 0.0001) {
			iteration++;
			c = (a + b) / 2.0;
			
			printf("Iteration %d: a = %.3f, b = %.3f, c = %.3f, f(c) = %.3f\n", iteration, a, b, c, f(c));
			
			if(fabs(f(c)) < 0.0001) {
				break;
			}
			
			if(f(a) * f(c) < 0) 
				b = c;
			
			else
			 a = c;
		}
		printf("\nThe approximate root after %d iterations: %.3f\n", iteration, c);
		return 0;
}

