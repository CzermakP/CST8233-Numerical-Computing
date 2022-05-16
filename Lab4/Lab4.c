/* NUMERICAL COMPUTING Lab 4 - Part B 
Lagrange Interpolation Polynomials 
Patrick Czermak 040389514 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {
	int interpolation;
	int numberOfDataPoints;
	int i;
	int j;
	double smallX;
	double largeX;

	printf("Enter number of data: ");
	scanf("%d", &numberOfDataPoints);

	double* x = new double[numberOfDataPoints];
	double* y = new double[numberOfDataPoints];
	// taking user inputs for x and y points based on number of data points user inputs
	for (i = 0; i < numberOfDataPoints; i++) {
		printf("x[%d]: ", i + 1);
		scanf("%lf", &x[i]);
		printf("y[%d]: ", i + 1);
		scanf("%lf", &y[i]);
	}
	// putting user inputs into x and y arrays based on number of data points user inputs 
	smallX = x[0];
	largeX = x[0];
	for (i = 0; i < numberOfDataPoints; i++) {
		if (smallX > x[i]) {
			smallX = x[i];
		}
		if (largeX < x[i]) {
			largeX = x[i];
		}
	}
	
	while (true) {
		printf("Enter interpolation point or any character to exit: ");
		if (!scanf("%d", &interpolation)) { // !scanf for any non-integer input 
			break;
		}
		if ((interpolation < smallX) || (interpolation > largeX)) {
			printf("Invalid Point\n");
			continue;
		}
		double yp = 0; //interpolation point value
		double p; //interpolation point
		double numerator; // for testing/understanding
		double denominator; // for testing/understanding
		for (i = 0; i < numberOfDataPoints; i++) {
			p = 1;
			for (j = 0; j < numberOfDataPoints; j++) {
				if (i != j) {
					numerator = (interpolation - x[j]);
					denominator = (x[i] - x[j]);
					p = p * (numerator / denominator);  // p = p * (interpolation - x[j]) / (x[i] - x[j]);

				}
			}
			//double temp = y[i]; // for testing
			yp = yp + p * y[i];
		}
		printf("Valid Point\nInterpolated value at %d is %f\n\n", interpolation, yp);
	}
}


