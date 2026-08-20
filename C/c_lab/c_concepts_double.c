#include <stdio.h>
#include <float.h>

/*DBL_MAX        largest finite double
DBL_DIG          decimal digits of precision
DBL_MANT_DIG     bits of precision in the significand*/

int main(void)
{
    printf("%g\n", DBL_MAX);
    printf("%d\n", DBL_DIG);
    printf("%d\n", DBL_MANT_DIG);

    return 0;
}

/*This code snippet is a simple C program that prints out the maximum finite value of a double, 
the number of decimal digits of precision, and the number of bits of precision in the significand for the double data type. It uses the constants defined in the float.h header file.*/

/*DBL_MAX
DBL_MIN
DBL_DIG
DBL_MANT_DIG
DBL_MAX_10_EXP*/