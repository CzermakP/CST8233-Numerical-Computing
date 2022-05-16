

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES //needed to uses 'pow'=power;  'sqrt'=square root;  'M_E'=exponent; 
#include <stdio.h>
#include <math.h> //needed to uses 'pow'=power;  'sqrt'=square root;


//int main() {
//	int i;
//	float n, x;
//	n = 1.0;
//
//	for (i = 0; i <= 127; i++) {
//		n = n * 2.0;
//		x = 1.0 / n;
//		printf("%d %e %E\n", i, x, n);
//	}
//	return 0;
//}


int main() {
	float approximation, absolute, relative;
	float i, n = 1, nFactorial = 1;
	float pi = acos(-1.0);

	printf("N       n!        Approximation          Absolute error          Relative error\n");

	while (n < 11) {
		for (i = 1; i <= n; i++) { // for loop to produce factorial of 'n' as it increases each iteration, it's increases until it is matched to be the n for the specific iteration 
			nFactorial = nFactorial * i; 
		}
		approximation = pow(n / M_E, n) * sqrt(2.0 * pi * n); // Stirlings approximation formula - was googled!! 
		absolute = nFactorial - approximation;
		relative = absolute / nFactorial;

		printf("%0.0f      %0.0f         %f               %f              %f\n", n, nFactorial, approximation, absolute, relative);
		n++;
		nFactorial = 1; //need to reset nFactorial always to 1 in order for the loop to work properly  
	}

}
// The accuracy INCREASES as n increases....based on the RELATIVE ERROR Output column, it gets more and more accurate!?

