/* NUMERICAL COMPUTING LAB 7 - Simple Linear Regression 
*  PATRICK CZERMAK 040389514 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;

double* x;
double* y;
double* yFitted;
int numDataPairs;
string yPredictedFormula;

void linearRegression();

int main() {
	printf("Enter the no. of data pairs to be entered:\n");
	scanf("%d", &numDataPairs);

	x = new double[numDataPairs];
	y = new double[numDataPairs];
	yFitted = new double[numDataPairs];

	printf("\n");
	printf("Enter the x-axis values:\n");
	for (int i = 0; i < numDataPairs; i++) {
		scanf("%lf", &x[i]);
	}
	printf("\n");
	printf("Enter the y-axis values:\n");
	for (int i = 0; i < numDataPairs; i++) {
		scanf("%lf", &y[i]);
	}
	printf("\n");
	linearRegression();

	printf("S.no\tx\t\ty(observed)\t\ty(fitted)\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < numDataPairs; i++) {
		printf("%d", i + 1);
		printf("\t%.1f", x[i]);
		printf("\t\t%.1f", y[i]);
		printf("\t\t\t%.3f\n", yFitted[i]);
	}
	printf("\n");
	printf("The linear fit line is of the form:\n\n");
	cout << yPredictedFormula;
	
}

/* function to calculate the linear regression aka: [ y predicted = a1x+a0 ]  */
void linearRegression() {
	double a0, a1;
	double sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0;

	for (int i = 0; i < numDataPairs; i++) {
		sumX += x[i];
		sumY += y[i];
		sumX2 += (pow(x[i], 2));
		sumXY += (x[i] * y[i]);
	}


	a1 = ((numDataPairs * sumXY) - (sumX * sumY)) / (numDataPairs * sumX2 - pow(sumX, 2));
	a0 = (sumY - a1 * sumX) / numDataPairs;
	//a0 = sumY - a1 * sumX;
	//??? WHEN NOT DIVIDED BY numDataPairs I GET ACCURATE VALUES AS PER SLIDES, BUT NOT FOR THE LAB EXAMPLE ?????
	// slides wk5 pg.11 = sumY - a1 * sumX ????? 

	/* loop through all insert x values into yFitted formula */
	for (int i = 0; i < numDataPairs; i++) {
		yFitted[i] = a1 * x[i] + a0;
	}

	/* cast a1 a0 from double to string in order to print proper output format */
	string a1string = to_string(a1);
	string a0string = to_string(a0);

	yPredictedFormula = "y = " + a1string + "x + " + a0string;
}