/* NUMERICAL COMPUTING LAB 5 - Descriptive Statistics
* Patrick Czermak 040389514 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

//using namespace std;

double meanCalc(double* array, int numberItems);
double medianCalc(double* array, int numberItems);
double standardDeviation(double* array, int numberItems);
//double* copyAndSort(double* array, int numberItems);

int main() {

	/* loop menu, no exit, must manually stop/close program */
	while (true) {
		/* getting number of data items user wants results on, max 10  */
		int numberItems = 0;

		while (true) {
			printf("Input total number of data items you want calculations on : ");
			if (!(std::cin >> numberItems)) {
				printf("Must be an interger value, try again!");
				std::cin.clear();
				std::cin.ignore(100000, '\n');
				continue;
			}
			//scanf("%d", numberItems);

			if (numberItems < 1) {
				printf("Must be a positive integer, try again!\n");
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
			else {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				break;
			}
		}


		/* filling an array with and getting the users specific data points */
		double* array = new double[numberItems];
		int i = 0;
		while (true) {
			if (i == numberItems) {
				break;
			}
			printf("Data Point %d: ", i + 1);
			if (!(std::cin >> array[i])) {
				printf("Must be an integer number, try again!");
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
			else {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				i++;
			}
		}

		double output1 = meanCalc(array, numberItems);
		printf("\nMean = %lf\n", output1);
		double output2 = medianCalc(array, numberItems);
		printf("Median = %lf\n", output2);
		double output3 = standardDeviation(array, numberItems);
		printf("Standard Deviation = %lf\n\n", output3);
	}
}

/* function to calculate MEAN - CONFIRMED CORRECT OUTPUT FOR LAB SAMPLE INPUT */
double meanCalc(double* array, int numberItems) {
	double sum = 0;
	double mean;

	for (int i = 0; i < numberItems; i++) {
		sum += array[i];
	}
	mean = sum / numberItems;

	return mean;
}

/* function to calculate MEDIAN - ????? */
double medianCalc(double* array, int numberItems) {
	double median;
	double* tempArray = new double[numberItems];

	/* put array values into a temp array for sorting */
	for (int i = 0; i < numberItems; i++) {
		tempArray[i] = array[i];
	}

	/* sort the temp array values */
	for (int i = 0; i < numberItems; i++) {
		for (int j = i + 1; j < numberItems; j++) {
			if (tempArray[i] < tempArray[j]) {
				int temp = tempArray[i];
				tempArray[i] = tempArray[j];
				tempArray[j] = temp;
			}
		}
	}

	//std::sort(tempArray, tempArray + numberItems );

	/* get the middle value in the sorted tempArray, which is the median */
	if (numberItems % 2 != 0) { /* if total numbers isn't even, simply divide tempArray in half an dreturn that value */
		median = tempArray[numberItems / 2];
	}
	else { /* if total numbers is even ?????*/
		median = ( tempArray[(numberItems - 1) / 2] + tempArray[numberItems / 2] ) / 2.0;
		//median = ((tempArray[(numberItems / 2) - 1])  + (tempArray[numberItems / 2]) / 2.0);
		//median = median - 1;
	}
	return median;
}

/* function to calcualte STANDARD DEVIATION - CONFIRMED CORRECT OUTPUT FOR LAB SAMPLE INPUT */
double standardDeviation(double* array, int numberItems) {
	double sd = 0;
	double mean = meanCalc(array, numberItems);

	for (int i = 0; i < numberItems; i++) {
		sd += pow(array[i] - mean, 2);
	}
	sd = sqrt(sd / (numberItems - 1));

	return sd;
}
