
/*************************************************************************************************************
* Filename:                ass1.c
* Version:                 1
* Author/Student Name:     Patrick Czermak
* Student Number:          040389514
* Course Name and Number:  Numerical Computing CST8233
* Lab Section:             303
* Assignment Number:       Assignment 1
* Assignment Name:         Lagrange Interpolation
* Due Date:                February 7, 2021
* Submission Date:         February 7, 2021
* Professor's Name:        Hala Own
* Purpose:                 This console program gives the user the option to interpolate 2 different 
*                          functions (A + B) or to quit. The generated polynomial is run with orders 
*                          n=5, 10, 20 and computes the interpolation polynomial at 41 regularly spaced 
*                          nodes. For each value of xK, the lagrange polynomial approximation is output 
*						   together with the True Value and the Absolute Error. The final output produces 
*						   (regularly spaced nodes, xK value, polynomial, true value, absolute value)
**************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* fuunction declarations */
void outputFunction(int n, int method);
double functionLagrange(int n, double x, double* xK, double* fK);
double functionRegularSpacedNodes(int k, int n);
double functionA(double x);
double functionB(double x);

/******************************************************************************************************************
* Function Name:        main
* Purpose:              Main function, holds the main MENU of the program and determines which mathematical 
*                       function to execute
* In Parameters:        none
* Out parameters:       none, only prints main MENU to console
* Version:              1
* Author:               Patrick Czermak
*******************************************************************************************************************/
int main() {
	int option;
	int userInput; 
	int go = 1;

	/* main program loop */
	while (go) {
		
		do {
			printf("          Lagrange Interpolation\n");
			printf("MENU\n");
			printf("1. Function A\n");
			printf("2. Function B\n");
			printf("3. Quit\n\n");

			printf("Enter your choice: ");
			userInput = scanf("%d", &option);
		} while (userInput != 1);

		/* for function A */
		if (option == 1) { 
			printf("\nWHEN n=5\n\n");
			outputFunction(5, 1);
			printf("\nWHEN n=10\n\n");
			outputFunction(10, 1);
			printf("\nWHEN n=20\n\n");
			outputFunction(20, 1);
		}
		/* for function B */
		else if (option == 2) {
			printf("\nWHEN n=5\n\n");
			outputFunction(5, 2);
			printf("\nWHEN n=10\n\n");
			outputFunction(10, 2);
			printf("\nWHEN n=20\n\n");
			outputFunction(20, 2);
		}
		/* to exit */
		else {
			printf("Exit");
			break;
		}
		
	}
}
/*******************************************************************************************************************************************
* Function Name:      outputFunction
* Purpose:            To output the columns and rows which include the values for X, xK, P, True Value, Approximate Value.
*                     Calls the functionRegularSpacedNodes() to generate the xi values that will be used in the functionLagrange.
*                     Calls functionA, functionB,  which complete the mathematical function computation and return the values to 
*                     be used to calculate interpolation, true value, absolute error and prints them to console
* In Parameters:      int n, int method
* Out parameters:     outputs to console X, Xk, P, TrueValue, Absolute Error values in a table(columns/rows)
* Version:            1
* Author:             Patrick Czermak
********************************************************************************************************************************************/
void outputFunction(int n, int method) {

	double* xK = malloc(sizeof(double) * (n + 1));
	double* yK = malloc(sizeof(double) * (n + 1));

	/* loop to generate the xi that will be used in the functionLagrange */
	for (int i = 1; i <= n + 1; i++) {
		double point = functionRegularSpacedNodes(i, n);
		/* Ternary operator: if method is 1 complete left side of ':', if left side is false, complete right side of ':'
		*   either functionA or functionB to be calculated for each loop pass */
		double value = method == 1 ? functionA(point) : functionB(point);
		xK[i - 1] = point;
		yK[i - 1] = value;
	}
	double xToEval = -1.0000000; /* set the first x value to evalute to -1.0000000 - used to match the first row in column Xk */
	printf("%15s%10s%15s%20s%20s\n", "K", "Xk", "P", "TRUE VALUE", "ABSOLUTE ERROR");

	/* loop through 41 times to generate the interpolation, true value, and absolute error */
	for (int k = 0; k <= 40; k++) { 
		double interpolation = functionLagrange(n, xToEval, xK, yK); /* pass the values each pass to calculate the lagrange interpolation */
		/* Ternary operator: if method is 1 complete left side of ':', if left side is false, complete right side of ':' 
		*  either functionA or functionB to be calculated for each loop pass */
		double trueValue = method == 1 ? functionA(xToEval) : functionB(xToEval); 
		double absoluteError = fabs(interpolation - trueValue); /* each pass calculate the absolute error */
		printf("%15d %15f %15.9f %15.9f %15.2E\n", k, xToEval, interpolation, trueValue, absoluteError); /* output to console */
		xToEval = xToEval + 0.05; /* increase the x value to evalute by .0.05 - used to match output column Xk */
	}
}


/**********************************************************************************************************************************************
* Function Name:       functionLagrange
* Purpose:             calculates the lagrange interpolation
* In Parameters:       int n, double x, double* xK, double* fK
* Out parameters:      the calculated interpolation 
* Version:             1
* Author:              Patrick Czermak
***********************************************************************************************************************************************/
double functionLagrange(int n, double x, double* xK, double* fK) {
	double outputL = 0;

	for (int i = 0; i < n + 1; i++) {
		double p = fK[i];

		for (int j = 0; j < n + 1; j++) {

			if (j != i) {
				p = p * (x - xK[j]) / (double)(xK[i] - xK[j]);
			}

		}
		outputL = p++;

	}
	return outputL;
}


/***********************************************************************************************************************************************
* Function Name:       functionRegularlySpacedNodes
* Purpose:             to calculate a specific mathematical function to generate regularly spaced nodes
* In Parameters:       int k, int n
* Out parameters:      returns to calculated value with users values (int k, int n) passed in
* Version:             1
* Author:              Patrick Czermak
************************************************************************************************************************************************/
double functionRegularSpacedNodes(int k, int n) {
	return -1.0 + (2.0 * (k - 1)) / (double)n;
}

/************************************************************************************************************************************************
* Function Name:       functionA
* Purpose:             to calcualte a specific mathematical function and return the result to the calling function
* In Parameters:       double x
* Out parameters:      outputA (the calculated mathematical function with 'double x' value passed in)
* Version:             1
* Author:              Patrick Czermak
*************************************************************************************************************************************************/
double functionA(double x) {
	double outputA = sqrt(1.0 + x * x);
	return outputA;
}

/************************************************************************************************************************************************
* Function Name:        functionB
* Purpose:              to calcualte a specific mathematical function and return the result to the calling function  
* In Parameters:        double x
* Out parameters:       outputB (the calculated mathematical function with 'double x' value passed in)
* Version:              1
* Author:               Patrick Czermak
*************************************************************************************************************************************************/
double functionB(double x) {
	double outputB = 1.0 / (1.0 + (25.0 * x * x));
	return outputB;
}