/* NUMERICAL COMPUTING - Lab 3 Part C
Patrick Czermak 040389514 */

#include <stdio.h>

int main() {
	float f1 = 1.0;
	float f2 = 0.0;
	int i;
	for (i = 0; i < 8; i++)
		f2 += 1.0 / 8.0;
	printf("0x%08x 0x%08x\n", *(int*)&f1, *(int*)&f2);
	printf("f1 = %10.9f\n", f1);
	printf("f2 = %10.9f\n\n", f2);
	return 0;
}

// INITIAL Output -> 
//                  0x3f800000 0x3f800001
//                  f1 = 1.000000000
//                  f2 = 1.000000119

// Task C.2: replace 10 by 8 in the for loop and 10.0 by 8.0 in the loop body, notice the
//           output. Explain the results to your lab instructor. 
// Output -> 0x3f800000 0x3f800000
//           f1 = 1.000000000
//           f2 = 1.000000000