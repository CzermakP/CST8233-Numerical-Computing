/* NUMERICAL COMPUTING - Lab 3
Patrick Czermak 040389514 */


/* PART A */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

// difference between FLOAT and DOUBLE = 
// FLOAT will show that the number will continue to grow infinitely (INF)  
// DOUBLE will only show to the highest number which my computer will handle (64 bit) 
// They both produce the same outputs only FLOAT will show that the value will go indefinitely 

int main()
{
	int i;
	double n, x;
	n = 1.0;
	for (i = 0; i <= 127; i++)
	{
		n = n * 2.0;
		x = 1.0 / n;
		printf("%d %e %E\n", i, x, n);
	}

	return 0;
}

//TASK A1: 
//TASK A2: it shows the number goes infinitely (beacuse of type float) 
//TASK A3: changed to 129 - it repeats the same infinity for each number above the point where it reaches infinity (127, 128, 129) 
//TASK A4: when type double it won't compute infinity beacuse double doesn't compute below 0. values ROUND ERROR