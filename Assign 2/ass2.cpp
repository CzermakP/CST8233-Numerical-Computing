/***************************************************************************************** 
* Filename: ass2.cpp
* Version: 1.0
* Author/Student Name: Patrick Czermak
* Student Number: 040389514
* Course Name and Number: Numerical Computing CST8233_300
* Lab Section Number: 303
* Assignment Number: 2
* Assignment Name: Linear Regression Least-Squares Method
* Due Date: Friday March 19, 2021
* Submission Date: Friday March 19, 2021 
* Professor's Name: Hala Own
* Purpose:  The purpose of this program is to read a file (data.txt), output the contents 
*			of the file and output a Data summary which computes the Mean, Median, Range, 
*			Mode, Standard Deviation, Linear Regression Fit, and the Standard Error. 
*			Additionally it allows the user to extrapolate the prognostic_index of any point
*			within the date range.
******************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/* functions */
void readFile();
void dataSummaryCalc(vector<double> x, vector<double> y, int recordCount);
void nonLinearRegressionCalc(vector<double> x, vector<double> y, int recordCount);

/*****************************************************************************************
* Function Name: main()
* Purpose: To output to console the main menu
* Function In Parameters: none
* Function Out Parameters: none / calls the readFile() function 
* Version: 1.0
* Author/Student Name: Patrick Czermak
*****************************************************************************************/
int main() {
	int userInput;
	/* main menu */
	while (1) {
		cout << "LEAST_SQUARES LINEAR REGRESSION\n" << endl;
		cout << "MENU" << endl;
		cout << " 1. Exponential Fit" << endl;
		cout << " 2. Quit" << endl;

		/* if input is not an integer */
		if (!(cin >> userInput)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, must be a '1' or '2' only!" << endl;
			continue;
		}
		/* to quit program */
		if (userInput == 2) {
			break;
		}
		/* if input is not a 1 or 2 but still an integer */
		else if (userInput != 1) {
			cout << "Invalid input, must be a '1' or a '2' only!!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		/* if userInput '1' is successfully accepted */
		else {
			
			bool result = false;
			while (!result) {
				readFile();
			}


		}
	}
}

/*********************************************************************************************
* Function Name: readFile()
* Purpose: To read in a file and to print to console the data and the amount of records 
* Function In Parameters: none
* Function Out Parameters: calls the dataSummaryCalc() and nonLinearRegressionCalc() function 
*						   passing the x and y vectors and the recordCount.
* Version: 1.0
* Author/Student Name: Patrick Czermak
**********************************************************************************************/
void readFile() {
	vector<double> x;
	vector<double> y;
	string fileName;
	int newLine = 0, recordCount = 0;
	string firstLine, word, line;
	int days, pI, i = 0;

	cout << "Please enter the name of the file to open: ";
	cin >> fileName;

	/* creating file stream object and passing in fileName */
	ifstream file; 
	file.open(fileName.c_str());

	/* do the following if the file can be opened, or display error message */
	if (file.is_open()) { 
		for (recordCount = 0; getline(file, word); recordCount++);
		file.clear();
		file.seekg(0);

		getline(file, firstLine);
		cout << firstLine << endl;
		/* keep looping while checking ahead to make sure the file ins't empty */
		while (getline(file, line)) {  // file.peek() != ifstream::traits_type::eof()
			istringstream iSS(line);
			cout << line << endl;
			
			iSS >> days >> pI;
			x.push_back(days);
			y.push_back(pI);
		}
	
		recordCount = recordCount -2; // need to subrtact 2 lines to be able to print accurate record count
		x.pop_back(); //removing duplicate values generated: the last '65' gets duplicated ?? 
		y.pop_back(); //removing duplicate values generated: the last '6' gets duplicated ??
		cout << "There are " << recordCount << " records.\n" << endl;
		file.close();
		dataSummaryCalc(x, y, recordCount);
		nonLinearRegressionCalc(x, y, recordCount);
	}
	else {
		cout << "ERROR opening file! Try re-typing file name!" << endl;
	}
}

/**********************************************************************************************
* Function Name: dataSummaryCalc()
* Purpose: To calculate the Mean, Median, Range, Mode, Standard Deviation of the files data. 
*		   To output a sub-menu which gives user option to extrapolate the prognostic_index for 
*		   any date in the date range, or to return to the Main menu.
* Function In Parameters: vector<double> x, vector<double> y, int recordCount
* Function Out Parameters: none
* Version: 1.0
* Author/Student Name: Patrick Czermak
***********************************************************************************************/
void dataSummaryCalc(vector<double> x, vector<double> y, int recordCount) {
	int days;
	int userInput = 0;
	double prognosticIndex = 0;
	double mean = 0, median = 0, range = 0, mode = 0, standardDeviation = 0, standardError = 0;
	double sumX = 0, sumY = 0, squaredX = 0, sumXY = 0, a0 = 0, a1 = 0;

	/* data sums */
	for (int i = 0; i < recordCount; i++) {
		sumX += x[i];
		sumY += y[i];
		squaredX += x[i] * x[i];
		sumXY += x[i] * y[i];
	}

	/* MEAN - sum of y / total amount of records */
	mean = sumY / recordCount;
	cout << "Data summary (Prognostic index):" << endl;
	cout << "Mean = " << mean << endl;

	/* MEDIAN - sort y vector smallest to largest and then take middle value or average if uneven amount of records*/
	sort(y.begin(), y.end());  /* sort the 'y' data vector (procnostic_index data) to be able to calculate median, range, and mode */
	if (recordCount % 2 != 0) {
		median = y[recordCount / 2];
	} 
	else {
		median = (y[(recordCount - 1) / 2] + y[recordCount / 2]) / 2.0;
	}
	cout << "Median = " << median << endl;

	/* RANGE - largest value - smallest value */
	range = y.back() - y.front();
	cout << "Range = " << range << endl;

	/* MODE */
	int modeCount = 2, count = 0, j = 0, boolean = 1;
	vector<int> modeVector;
	while (j < y.size()) {
		for (int i = 0; i < y.size(); i++) {
			if (mode == y[i]) {
				count++;
			}
		}
		if (count >= modeCount) {
			if (modeVector.empty()) {
				modeVector.push_back(mode);
			}
			else {
				if (count == modeCount) {
					for (int i = 0; i < modeVector.size(); i++) {
						if (mode == modeVector[i]) {
							boolean = 0;
						}
					}
					if (boolean == 1) {
						modeVector.push_back(mode);
					}
				}
				else {
					modeVector.clear();
					modeVector.push_back(mode);
				}
			}
			modeCount = count;
		}
		count = 0;
		j++;
		boolean = 1;
		if (j < y.size()) {
			mode = y[j];
		}
	}
	cout << "Mode = ";
	if (modeVector.empty()) {
		cout << "No mode available" << endl;
	}
	else {
		for (int i = 0; i < modeVector.size(); i++) {
			cout << modeVector[i] << "";
		}
		cout << endl;
	}

	/* STANDARD DEVIATION - loop through y vector and for each record compute pow(y[i] - mean, 2) */
	for (int i = 0; i < y.size(); i++) {
		standardDeviation += pow(y[i] - mean, 2);
	}
	standardDeviation = sqrt(standardDeviation / (recordCount - 1));
	cout << "Standard Deviation = " << standardDeviation << endl;

}

/**********************************************************************************************
* Function Name: nonLinearRegressionCalc()
* Purpose: To calculate the Non Linear Regression Fit, and Standard Error of the files data. 
		   To output a sub-menu which gives user option to extrapolate the prognostic_index for 
		   any date in the date range, or t0 return to the Main menu.
* Function In Parameters: vector<double> x, vector<double> y, int recordCount
* Function Out Parameters: none
* Version: 1.0
* Author/Student Name: Patrick Czermak
***********************************************************************************************/
void nonLinearRegressionCalc(vector<double> x, vector<double> y, int recordCount) {
	int days;
	int userInput = 0;
	double prognosticIndex = 0;
	double standardDeviation = 0, standardError = 0;
	double sumX = 0, sumY = 0, squaredX = 0, sumXY = 0, a0 = 0, a1 = 0; //  meanX = 0, meanY = 0,

	/* LINEAR REGRESSION FIT */
 
/* data sums with the y vector data converted to log */
	for (int i = 0; i < recordCount; i++) {
		sumX += x[i];					//sum x
		sumY += log(y[i]);				//sum Ln(y)
		squaredX += x[i] * x[i];		//x squared
		sumXY += x[i] * log(y[i]);		//x*ln(y)
	}
	a1 = ((recordCount * sumXY) - (sumX * sumY)) / (recordCount * squaredX - (pow(sumX, 2)));
	a0 = (sumY - a1 * sumX) / recordCount;
	//double a = exp(a0); //rough 55.  = I get 56.7 ok
	//double b = a1; // shoudl be '-'  (< 0) == I get -0.038 ok

	cout << "\nLinear regression Fit:  Prognostic_index = " << round(10 * exp(a0)) / 10 << "*exp " << round(1000 * a1) / 1000 << "*days" << endl;

	/* STANDARD ERROR  - equation is accurate but doesn't output proper value as Standard Deviation in calculated
						based on the sorted y vector and i'm still trying to figure out how to unsort the vector */
	standardError = sqrt(standardDeviation / recordCount - 2);
	cout << "Standard Error = " << standardError << "\n" << endl;

	/* SUB-MENU with EXTRAPOLATION and back to main menu */
	while (userInput != 2) {
		printf("MENU\n");
		printf(" 1. Extrapolation\n");
		printf(" 2. Main Menu\n");

		/* confirm input is an integer */
		if (!(cin >> userInput)) {
			cin.clear();
			cin.ignore(256, '\n');
			printf("ERROR, invalid input, must be a '1' or '2', try again!");
			continue;
		}
		/* userInput = 2 returns to main where main menu is */
		if (userInput == 2) {
			main();
		}
		/* userInput is integer, but not 1 or 2 */
		else if (userInput != 1) {
			printf("ERROR, invalid input, must be a '1' or '2', try again!");
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		/* UserInput confirmed 1, perform extrapolation*/
		else {
			printf("Please enter the days to extrapolate to: ");
			/* confirm days input is an integer */
			if (!(cin >> days)) {
				cin.clear();
				cin.ignore(256, '\n');
				printf("ERROR, Invalid day input!");
			}
			/* EXTRAPOLATION */
			else {
				cout << "days =" << days << endl;
				prognosticIndex = a0 * exp(a1 * days);
				cout << "Prognostic_index = " << round(100 * prognosticIndex) / 100 << endl;
			}
		}
	}
}

