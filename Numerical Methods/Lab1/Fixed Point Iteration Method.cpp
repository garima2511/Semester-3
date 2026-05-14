#include<stdio.h>
#include<math.h>

double f(double x) {
	return x*x*x*x + x*x - 3*x - 4;		    
}

double g(double x) {
	return pow(3*x + 4 - x*x*x, 0.25);
}

int main() {
    double x0,x1;
    int iteration = 0;

    printf("Function: f(x)=x^4 + x^2 - 3x -4 using fixed point iteration.\n");
    printf("Enter the initial guess: x0 = ");
    scanf("%lf", &x0);

    while(iteration<20) {
        iteration++;
        x1=g(x0);

        printf("Iteration %d: x=%.3f, f(x)=%.3f\n",iteration, x1, f(x1));
        if(fabs(x1-x0)<0.001)
        break;

        x0=x1;
    }
    printf("\nEstimated root: %.3f",x1);
    printf("\nf(%.3f):%.3f",x1,f(x1));
    printf("\nTotal no.of iterations: %d",iteration);
    return 0;
}
