/* NUMERICAL COMPUTING - Lab 2_Part2
Author: Partick Czermak 040389514*/  

#include <stdio.h>
#include <stdlib.h>

void menu();
void decimalToBinary(int userNum);
void binaryToDecimal(int userNumum);

int main() {
	int userNum;
	int menuOption = 0;

	while (menuOption != 3) {
		menu();
		scanf_s("%d", &menuOption);
		if (menuOption == 1) {
			printf("Enter a DECIMAL number: ");
			scanf_s("%d", &userNum);
			decimalToBinary(userNum);
		}
		if (menuOption == 2) {
			printf("Enter a BINARY number: ");
			scanf_s("%d", &userNum);
			binaryToDecimal(userNum);
		}
		if (menuOption == 3) {
			printf("Exiting Program...");
			break;
		}
	}
	return 1;
}

void menu() {
	printf("What conversion method do you want to complete? \n");
	printf("1 = Convert from DECIMAL to BINARY\n");
	printf("2 = Convert from BINARY to DECIMAL\n");
	printf("3 = Exit Program\n");
}

/* function to convert user input from decimal to binary number system. remainderArray[] used to hold the binary remainder values after each iteration */
void decimalToBinary(int userNum) {
	int remainderArray[16]; 
	int i = 0;

	while (userNum != 0) {
		if (userNum % 2 == 0) { //modulos 2 because looking for binary and binary is base 2
			remainderArray[i] = 0;
		}
		else {
			remainderArray[i] = 1;
		}
		userNum = userNum / 2;
		i++;
	}
	printf("BINARY value = ");
	for (i = i - 1; i >= 0; i--) {
		printf("%d", remainderArray[i]);
	}
	printf("\n\n");
}

/* function to convert user input from binary to decimal number system */
void binaryToDecimal(int userNum) {
	int remainder;
	int decimalNumber = 0;
	int exponent = 1;

	while (userNum > 0) {
		remainder = userNum % 10; // modulos 10 becuase looing for decimal and decimal is base 10
		decimalNumber = decimalNumber + remainder * exponent;
		userNum = userNum / 10;
		exponent = exponent * 2;
	}
	printf("The number in DECIMAL format is: %d\n", decimalNumber);
}