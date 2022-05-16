/* LAB 11 - MACLAURIN SERIES EXPANSION - PATRICK CZERMAK */

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double factorial(double number);

int main() {
	double radiansX = 0; //user input for radians(x)
	double bound = 0; //user input for relative error bound (%)
	double i = 1; // terms
	double exactValue, absoluteError;
	double approximateValue = 1.0; // set to 1 to match i(term) iteration
	double relativeError = 1; // set to 1 to match term iteration 


	printf("Enter your approx. relative error bound: \n");
	scanf("%lf", &bound);

	printf("Enter your angle in radians: \n");
	scanf("%lf", &radiansX);

	exactValue = cos(radiansX); // built in cos x function - pass in the user input of radiansX=x

	printf("%s\t%s\t\t%s\t%s\t\t%s\t\n", "N.terms", "Exact", "Approximate Value", "Absolute Error", "%Relative Error");

	/* keep looping while the user inputted relative error bound is SMALLER than the computed relativeError */
	while (bound < relativeError) {
		approximateValue += pow((-1), i) * (pow(radiansX, (2 * i)) / (factorial(2.0 * i))); // summation of cos(x) formula
		absoluteError = fabs(exactValue - approximateValue); 
		relativeError = (absoluteError / exactValue) * 100;

		printf("%.0f\t", i);
		printf("%lf\t", exactValue);
		printf("%lf\t\t", approximateValue);
		printf("%lf\t\t", absoluteError);
		printf("%lf\t\n", relativeError);
		i++; // increment i OR each term 
	}
	printf("\n----------------------------------------------------------------------------------------");
}

/* function to calculate the factorial - used in approximateValue formula at each loop when i increases */
double factorial(double number) {
	double i, result = 1;
	for (i = 1; i <= number; i++) {
		result *= i;
	}
	return result;
}