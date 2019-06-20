// Arithmetic.cpp : Defines the entry point for the console application.
//

#include "libfix.h"
#include <conio.h>
#include <stdio.h>

void add_test()
{
	printf("\n\t==ADD_TEST==\n");
	//basic
	printf("\n basic test\n");
	double n = 0.1415926;
	int fix_n = DOUBLE2FIX(n);
	printf("n = %d => %.9f\n", fix_n, FIX2DOUBLE(fix_n));
	printf("%.9f + %.9f = %.9f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_add(fix_n, fix_n)));
	printf("answer: %.9f\n", n + n);

	// positive overflow test
	printf("\n positive overflow test\n");
	int32_t fix_max = INT32_MAX;
	printf("fix_max = %d => %.9f\n", fix_max, FIX2DOUBLE(fix_max));
	printf("fix_max + fix_max = %.6f\n", FIX2DOUBLE(fix_add(fix_max, fix_max)));


	// negative overflow test
	printf("\n negative overflow test\n");
	int32_t fix_min = INT32_MIN;
	printf("fix_min = %d => %.9f\n", fix_min, FIX2DOUBLE(fix_min));
	printf("fix_min + fix_min = %.6f\n", FIX2DOUBLE(fix_add(fix_min, fix_min)));
}

void sub_test()
{
	printf("\n\t==SUB_TEST==\n");
	//basic
	printf("\n basic test\n");
	double n = 0.1415926;
	int fix_n = DOUBLE2FIX(n);
	printf("n = %d => %.9f\n", fix_n, FIX2DOUBLE(fix_n));
	printf("%.9f + %.9f = %.9f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_sub(fix_n, fix_n)));
	printf("answer: %.9f\n", n + n);

	// positive overflow test
	printf("\n positive overflow test\n");
	int32_t fix_max = INT32_MAX;
	printf("fix_max = %d => %.9f\n", fix_max, FIX2DOUBLE(fix_max));
	printf("-fix_max = %d => %.9f\n", -fix_max, FIX2DOUBLE(-fix_max));
	printf("fix_max - (-fix_max) = %.6f\n", FIX2DOUBLE(fix_sub(fix_max, -fix_max)));


	// negative overflow test
	printf("\n negative overflow test\n");
	int32_t fix_min = INT32_MIN;
	fix_min++;
	printf("fix_min = %d => %.9f\n", fix_min, FIX2DOUBLE(fix_min));
	printf("-fix_min = %d => %.9f\n", -fix_min, FIX2DOUBLE(-fix_min));
	printf("fix_min - (-fix_min) = %.6f\n", FIX2DOUBLE(fix_sub(fix_min, -fix_min)));
}

void mul_test()
{
	printf("\n\t==MUL_TEST==\n");
	//basic
	printf("\n basic test\n");
	double n = 0.1415926;
	int fix_n = DOUBLE2FIX(n);
	printf("n = %d => %.9f\n", fix_n, FIX2DOUBLE(fix_n));
	printf("%.9f x %.9f = %.9f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_mul(fix_n, fix_n)));
	printf("answer: %.9f\n", n * n);

	int32_t fix_max = INT32_MAX;
	printf("fix_max = %d => %.9f\n", fix_max, FIX2DOUBLE(fix_max));
	printf("-fix_max = %d => %.9f\n", -fix_max, FIX2DOUBLE(-fix_max));
	printf("fix_max * (-fix_max) = %.6f\n", FIX2DOUBLE(fix_mul(fix_max, -fix_max)));
}

int main()
{
	add_test();
	sub_test();
	mul_test();
	return 0;
}
