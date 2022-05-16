/*****************************************************************************************
* Filename: ass3.c
* Version: 1.0
* Author/Student Name: Patrick Czermak
* Student Number: 040389514
* Course Name and Number: Numerical Computing CST8233_300
* Lab Section Number: 303
* Assignment Number: 3
* Assignment Name: Maclaurin Series Application
* Due Date: Friday April 9, 2021
* Submission Date: Monday April 5, 2021
* Professor's Name: Hala Own
* Purpose:  This program is a model of the motion response of a tall building hit by strong
*		    winds that set it in vibration that builds up catastrophically. The program output 
*			shows the vibration oscillations growing catastrophically in time (along the x-axis)
*			over a large number of oscillations. (As noted in assignment instructions "purpose").
******************************************************************************************/

/* defines and includes */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* function declarations */
void menu();
void calculateT(double t, double terms);

/*****************************************************************************************
* Function Name: main()
* Purpose: To output to console the main menu and take in user input for the number of 
*		   terms to be calculated and the range of time, passing these values tp the called 
*		   funcion calculateT(double, double)
* Function In Parameters: none
* Function Out Parameters: 0
* Version: 1.0
* Author/Student Name: Patrick Czermak
*****************************************************************************************/
int main() {
	int termNum; // number of non-zero terms to be calculated 
	int userInput = 0; // userInput variable for main menu, if NOT 1 will exit  
	double range; //the value of t (in seconds)

	while (userInput != 2) {
		termNum = 0;
		range = -1;

		menu(); // function call
		scanf("%d", &userInput);

		/* 1=complete calculations */
		if (userInput == 1) { 
			printf("\nEvaluating the series\n");

			/* loop until valid termNum is entered by user */
			while (termNum < 1 || termNum > 6) {
				printf("Please enter the number of (non-zero) terms in the series (1, 2, 3, 4, 5 or 6) : \n");
				scanf("%d", &termNum);
				if (termNum < 1 || termNum > 6) {
					printf("\nERROR... terms in the series must be from 1-6 inclusive\n");
				}
			}
			/* loop until valid range entered by user */
			while (range < 0.0 || range > 4.0) {
				printf("\nPlease enter the range of t to evaluate in 10 increments (0.0 < t < +4.0) : ");
				scanf("%lf", &range);
				if (!range < 0.0 || !range > 4.0) {
					printf("ERROR...range must be from 0.0-4.0\n");
				}
			}
			calculateT(range, termNum); // function call passing in 'range + termNum' 
		}
	}
	return 0;
}

/********************************************************************************************************
* Function Name: menu()
* Purpose: To print/display the programs main menu to console.
* Function In Parameters: none
* Function Out Parameters: 0
* Version: 1.0
* Author/Student Name: Patrick Czermak
*********************************************************************************************************/
void menu() {
	printf("\nEvaluate the Maclaurin Series approximation to D(t) = exp(t)*cos(t)\n\n");
	printf("1: Evaluate the series\n");
	printf("2: quit\n\n");
}

/********************************************************************************************************
* Function Name: calculateT()
* Purpose: To calculate the increment value of t from 0 to userInput value, calculate the rue value of D(t),
*		   the series value, first truncation term, exact error, and truncation error, and displaying to 
*		   console.
* Function In Parameters: double terms - non-zero terms to be calculated 
* Function Out Parameters: none/void
* Version: 1.0
* Author/Student Name: Patrick Czermak
*********************************************************************************************************/
void calculateT(double t, double terms) {
	double tTemp; // for new calculated t value for that specific term
	double i; // for iterator
	double dtExact; // for exact calculations 
	double maclaurin = 0; // for series calculations 
	double truncation; // for first truncation term 
	double exactErr; // for exact error calculation - percentage
	double truncationErr; // for truncation error calculation - percentage

	printf("\nMACLAURIN SERIES\n");
	printf("t\t\t");
	printf("D(t) Series\t");
	printf("D(t) Exact\t");
	printf("%RExactE\t\t");
	printf("%RSerE\n");

	t = t / 10; // calculate value of 't' so when incrementedd 10 times will equal user input

	for (i = 0; i <= 10; i++) { // loop to calculate all values for 10 terms 
		tTemp = t * i; // t value is calculated for this term 
		/*  calculate exact value with built in c function 
			"NOTE: when changed to 'dtExact = (tTemp * tTemp) * cos(tTemp)' , truncation results inaccurate" */
		dtExact = exp(tTemp) * cos(tTemp);   

		/* Based on the number of terms entered, series will be calculated by 1 + t - t^3 / 3 - t^4 / 6 - t^5 / 30 + t^7 / 630 */
		/* First truncation error will be calculated also but depending on the number of terms (always the term after the final 
		   calculated term of the series) 
		   WITHOUT USING BUILT IN C FUNCTIONS FOR CALCULATIONS - The purpose of the series approximation is to 
		   speed up its execution so no functions are used in the evaluation of the terms of the series */
		if (terms == 1) {
			maclaurin = 1;
			truncation = tTemp;
		}
		if (terms == 2) {
			maclaurin = 1 + tTemp;
			truncation = (tTemp * tTemp * tTemp) / 3;
		}
		if (terms == 3) {
			maclaurin = 1 + tTemp - (tTemp * tTemp * tTemp) / 3;
			truncation = (tTemp * tTemp * tTemp * tTemp) / 6;
		}
		if (terms == 4) {
			maclaurin = 1 + tTemp - (tTemp * tTemp * tTemp) / 3 - (tTemp * tTemp * tTemp * tTemp) / 6;
			truncation = (tTemp * tTemp * tTemp * tTemp * tTemp) / 30;
		}
		if (terms == 5) {
			maclaurin = 1 + tTemp - (tTemp * tTemp * tTemp) / 3 - (tTemp * tTemp * tTemp * tTemp) / 6 - (tTemp * tTemp * tTemp * tTemp * tTemp) / 30;
			truncation = (tTemp * tTemp * tTemp * tTemp * tTemp * tTemp * tTemp) / 630;
		}
		if (terms == 6) {
			maclaurin = 1 + tTemp - (tTemp * tTemp * tTemp) / 3 - (tTemp * tTemp * tTemp * tTemp) / 6 - (tTemp * tTemp * tTemp * tTemp * tTemp) / 30 + (tTemp * tTemp * tTemp * tTemp * tTemp * tTemp * tTemp) / 630;
			truncation = (tTemp * tTemp * tTemp * tTemp * tTemp * tTemp * tTemp * tTemp) / 2520;
		}
		/* exact error calculation */
		exactErr = 100 * (dtExact - maclaurin) / dtExact;
		/* truncation error calculation */
		truncationErr = 100 * (truncation / maclaurin);
		/* print all calcualted values */
		printf("%.3e\t", tTemp);
		printf("%.5e\t", maclaurin);
		printf("%.5e\t", dtExact);
		printf("%.5e\t", exactErr);
		printf("%.5e\n", truncationErr);
	}
	//printf("\n");
}