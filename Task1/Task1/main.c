// Arithmetic.cpp : Defines the entry point for the console application.
//

#include "libfix.h"
#include <conio.h>
#include <stdio.h>

void add_test()
{
	//basic
	double n = 3.1415926;
	unsigned int fix_n = DOUBLE2FIX(n);
	printf("%.6f + %.6f = %.6f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_add(fix_n, fix_n)));
	printf("answer: %.6f\n", n + n);
	//overflow test
	unsigned int fix_max = UINT32_MAX;
	printf("n = %.6f\n", FIX2DOUBLE(fix_n));
	printf("fix_max + fix_max = %.6f\n", FIX2DOUBLE(fix_add(fix_max, fix_max)));

}

int main()
{
	add_test();
	return 0;
//	unsigned int fix_max = UINT32_MAX;
//	int fix_smax = UINT32_MAX;
//
//	unsigned int fix_min = 0x000;
//
//	printf("n = %.6f\n", n);
//	printf("n = %.6f\n", FIX2DOUBLE(fix_smax));
//	fix_smax <<= 10;
//	printf("n = %.6f\n", FIX2DOUBLE(fix_smax));
//	printf("fixmax(%u) = %.6f\n", (int)fix_max, FIX2DOUBLE(fix_max));
//	printf("fixmin = %.6f\n", FIX2DOUBLE(fix_min));
//
//	printf("2*pi = %.6f\n", n + n);
//
//	printf("0*pi = %.6f\n", FIX2DOUBLE(fix_sub(fix_n, fix_n)));
//	printf("0*pi = %.6f\n", n - n);
//
//	printf("2*pi = %.6f\n", FIX2DOUBLE(fix_mul(DOUBLE2FIX(2.0), fix_n)));
//	printf("2*pi = %.6f\n", 2 * n);
//
//	double arr[5] = { 10.1, 10.25, 10.5, 110.75, 10.9};
//	int fix_arr[5];
//	double accum = 0;
//	long long fix_accum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		fix_arr[i] = DOUBLE2FIX(arr[i]);
//		accum += arr[i] * arr[i];
//	}
//	printf("accum = %.6f\n", accum);
//	fix_mac(&fix_accum, fix_arr, 5, fix_arr, 5);
//	printf("fix_accum = %.6f\n", FIX2DOUBLE(fix_accum));
//	fix_msub(&fix_accum, fix_arr, 5, fix_arr, 5);
//	printf("fix_accum = %.6f\n", FIX2DOUBLE(fix_accum));
    return 0;
}

