/* LAB 12 - NUMERICAL DIFFERENTIATION - PATRICK CZERMAK */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//using namespace std;
/* function declarations */
double findYData(double x);
double findFirstDerivative(double x);
double findForwardDifference(double x);
double findBackwardDifference(double x);
double findCenteredDifference(double x);

double h = 0.25; /* constant value of h */

int main() {
	/* column title's */
	printf("\n\n");
	printf("x\t");
	printf("y\t\t");
	printf("Exact Derivative\t");
	printf("Centered\t");
	printf("Forward\t\t");
	printf("Backward\t\n");

	/* loop through all rows until reaching value 4, and each iterating value of h pass to each function 
	   to compute y, first derivative, forward/backward/centered differences. Print out all */
	for (double i = 0; i <= 4; i += h) {
		double y = findYData(i);
		double exact = findFirstDerivative(i);
		double forward = findForwardDifference(i);
		double backward = findBackwardDifference(i);
		double centered = findCenteredDifference(i);

		printf("%.2lf\t", i);

		/* print y Data */ 
		if (y >= 10 || y <= -10) {
			printf("%.4lf\t", y);
		}
		else {
			printf("%.4lf\t\t", y);
		}

		/* print exact derivative */
		if (exact <= -10) {
			printf("%.4lf\t\t", exact);
		}
		else {
			printf("%.4lf\t\t\t", exact);
		}

		/* print forward, backward, centered */
		if (i == 0) {
			printf("-\t\t");
			/* forward */
			if (forward <= -10) {
				printf("%.4lf\t", forward);
			}
			else {
				printf("%.4lf\t\t", forward);
			}
			printf("-\t\t");
		}
		else if (i == 4) {
			printf("-\t\t");
			printf("-\t\t");
			/* backward */
			if (backward <= -10) {
				printf("%.4lf\t", backward);
			}
			else {
				printf("%.4lf\t\t", backward);
			}
		}
		else {
			/* centered */
			if (centered <= -10) {
				printf("%.4lf\t", centered);
			}
			else {
				printf("%.4lf\t\t", centered);
			}
			/* forward */
			if (forward <= -10) {
				printf("%.4lf\t", forward);
			}
			else {
				printf("%.4lf\t\t", forward);
			}
			/* backward */
			if (backward <= -10) {
				printf("%.4lf\t", backward);
			}
			else {
				printf("%.4lf\t\t", backward);
			}
		}
		printf("\n");
	}
	return 0;
}

/* evaluating the function for each value of x to generate y data */
double findYData(double x) {
	double y = x * sin(pow(x, 2)) + 1;
	return y;
}

/* exact solution given by following formula */
double findFirstDerivative(double x) {
	double exact = sin(pow(x, 2)) + 2 * pow(x, 2) * cos(pow(x, 2));
	return exact;
}

/* computing Forward Difference */
double findForwardDifference(double x) {
	double forward = (findYData(x + h) - findYData(x)) / h;
	return forward;
}

/* computing Backward Difference */
double findBackwardDifference(double x) {
	double backward = (findYData(x) - findYData(x - h)) / h;
	return backward;
}

/* computing Cenetered Difference */
double findCenteredDifference(double x) {
	double centered = (findYData(x + h) - findYData(x - h)) / (2 * h);
	return centered;
}