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
	int fix_zero = DOUBLE2FIX(0);
	printf("n = %d => %.9f\n", fix_n, FIX2DOUBLE(fix_n));
	printf("%.9f + %.9f = %.9f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_add(fix_n, fix_n)));
	printf("%.9f - %.9f = %.9f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_add(fix_n, -fix_n)));
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
	int fix_zero = DOUBLE2FIX(0);

	printf("n = %d => %.9f\n", fix_n, FIX2DOUBLE(fix_n));
	printf("%.9f - %.9f = %.9f\n", FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_sub(fix_n, fix_n)));
	printf("%.9f - %.9f = %.9f\n", FIX2DOUBLE(fix_zero), FIX2DOUBLE(fix_n), FIX2DOUBLE(fix_sub(fix_zero, fix_n)));
	printf("answer: %.9f\n", n - n);

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
	printf("fix_max * fix_max = %.6f\n", FIX2DOUBLE(fix_mul(fix_max, fix_max)));
	printf("fix_max * (-fix_max) = %.6f\n", FIX2DOUBLE(fix_mul(fix_max, -fix_max)));
	printf("-fix_max * (-fix_max) = %.6f\n", FIX2DOUBLE(fix_mul(-fix_max, -fix_max)));
}

void mac_test()
{
	printf("\n\t==MAC_TEST==\n");
	
	double arr1[5] = { 0.123345, 0.2345235, 0.234234, 0.456456, 0.123756 };
	int32_t fix_arr1[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr1[i] = DOUBLE2FIX(arr1[i]);
		printf("arr1[%d] = %.9f => %.9f\n", i, arr1[i], FIX2DOUBLE(fix_arr1[i]));
	}

	double arr2[5] = { 0.345, 0.45235, 0.2334, 0.6456, 0.1256 };
	int32_t fix_arr2[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr2[i] = DOUBLE2FIX(arr2[i]);
		printf("arr2[%d] = %.9f => %.9f\n", i, arr2[i], FIX2DOUBLE(fix_arr2[i]));
	}

	double acc = 0;
	int32_t fix_acc = 0;

	for (int i = 0; i < 5; i++)
	{
		acc += arr1[i] * arr2[i];
		fix_acc = fix_mac(fix_acc, fix_arr1[i], fix_arr2[i]);
		printf("acc = %.9f\n", acc);
		printf("fix_acc = %.9f\n", FIX2DOUBLE(fix_acc));
	}
	printf("acc = %.9f\n", acc);
	printf("fix_acc = %.9f\n", FIX2DOUBLE(fix_acc));
}

void msub_test()
{
	printf("\n\t==MSUB_TEST==\n");
	
	double arr1[5] = { 0.123345, 0.2345235, 0.234234, 0.456456, 0.123756 };
	int32_t fix_arr1[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr1[i] = DOUBLE2FIX(arr1[i]);
		printf("arr1[%d] = %.9f => %.9f\n", i, arr1[i], FIX2DOUBLE(fix_arr1[i]));
	}

	double arr2[5] = { 0.345, 0.45235, 0.2334, 0.6456, 0.1256 };
	int32_t fix_arr2[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr2[i] = DOUBLE2FIX(arr2[i]);
		printf("arr2[%d] = %.9f => %.9f\n", i, arr2[i], FIX2DOUBLE(fix_arr2[i]));
	}

	double acc = 0.0;
	int32_t fix_acc = DOUBLE2FIX(acc);

	for (int i = 0; i < 5; i++)
	{
		acc -= arr1[i] * arr2[i];
		fix_acc = fix_msub(fix_acc, fix_arr1[i], fix_arr2[i]);
		printf("acc = %.9f\n", acc);
		printf("fix_acc = %.9f\n", FIX2DOUBLE(fix_acc));
	}
	printf("acc = %.9f\n", acc);
	printf("fix_acc = %.9f\n", FIX2DOUBLE(fix_acc));
}

int main()
{
	add_test();
	sub_test();
	mul_test();
	mac_test();
	msub_test();
	return 0;
}
