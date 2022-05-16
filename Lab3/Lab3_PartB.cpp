/* NUMERICAL COMPUTING - Lab 3_ Part B
Patrick Czermak 040389514*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float x = 88888.0;
    float y = 8.0;
    float y1 = 1.0 / y;
    float z = x / y;
    float z1 = x * y1;

    if (z != z1) {
        cout << z << " != " << z1 << endl;
        printf("%1.20f != %1.20f\n", z, z1);
    }
    else {
        cout << z << " == " << z1 << endl;
        printf("%1.20f == %1.20f\n", z, z1);
    }

    return 0;
}

// Task B.2 :  replace the floats by doubles and notice the output. Explain the results to
//             your lab instructor.
//  FLOAT Output -> 11111 != 11111
//                  11111.00000000000000000000 != 11111.00097656250000000000
// DOUBLE Output -> 11111 == 11111
//                  11111.00000000000000000000 == 11111.00000000000000000000
// 
// because dividing by an odd number will produce a fraction, and the FLOAT will output the actual 
// value and DOUBLE will not recognize places after decimal

// Task B.3 : replace the doubles by floats , 77777.0 by 88888.0 and 7.0 by 8.0, then
//            notice the output.Explain the results to your lab instructor.
// Output -> 11111 == 11111
//           11111.00000000000000000000 == 11111.00000000000000000000
//
// dividing by an even number will not produce a fracion, and the FLOAT will output the actual value here