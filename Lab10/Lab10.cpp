/* PATRICK CZERMAK - LAB 10 Taylor Series Expansion */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	
	double x;
	double i;
	int num = 100; // for lab either 10 or 100, see below for ouputs 
	double approximateValue = 0, trueValue, absoluteError, relativeError;

	printf("Enter the value of x: ");
	scanf("%lf", &x);
	printf("The number Of terms: %d\n", num);

	trueValue = log(x);

	for (i = 1; i < num; i++) {
		approximateValue += pow(-1, i - 1) * (pow(x - 1, i) / i); // given formula in instructions 
	}
	absoluteError = fabs(trueValue - approximateValue); // fabs() returns the 'absolute value' of param calc
	relativeError = (absoluteError / trueValue) * 100;

	printf("True value = %lf\n", trueValue);
	printf("Approximate value = %lf\n", approximateValue);
	printf("Absolute error = %lf\n", absoluteError);
	printf("Relative error = %lf\n", relativeError);

	return 0;
}
/* num = 10:  accurate up to 2.0, at 3.3 it becomes really off
	 
	Enter the value of x: 0.5
	The number Of terms: 10
	True value = -0.693147
	Approximate value = -0.692967
	Absolute error = 0.000180
	Relative error = -0.025966

		Enter the value of x: 1.5
		The number Of terms: 10
		True value = 0.405465
		Approximate value = 0.405532
		Absolute error = 0.000067
		Relative error = 0.016573

			Enter the value of x: 2.0
			The number Of terms: 10
			True value = 0.693147
			Approximate value = 0.745635
			Absolute error = 0.052488
			Relative error = 7.572380

				Enter the value of x: 3.3
				The number Of terms: 10
				True value = 1.193922
				Approximate value = 135.794385
				Absolute error = 134.600462
				Relative error = 11273.802614


   num = 100:  accurate up to 2.0, at 3.3 it becomes really off
    
    Enter the value of x: 0.5
	The number Of terms: 100
	True value = -0.693147
	Approximate value = -0.693147
	Absolute error = 0.000000
	Relative error = -0.000000

		Enter the value of x: 1.5
		The number Of terms: 100
		True value = 0.405465
		Approximate value = 0.405465
		Absolute error = -0.000000
		Relative error = -0.000000

			Enter the value of x: 2.0
			The number Of terms: 100
			True value = 0.693147
			Approximate value = 0.698172
			Absolute error = 0.005025
			Relative error = 0.724954

				Enter the value of x: 3.3
				The number Of terms: 100
				True value = 1.193922
				Approximate value = 4542530192737179786625044728250368.000000
				Absolute error = 4542530192737179786625044728250368.000000
				Relative error = 380471120419496359415659796298203136.000000


    
*/