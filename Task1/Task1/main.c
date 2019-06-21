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
	int fix_n = float_to_fix(n);
	int fix_zero = float_to_fix(0);
	printf("n = %d => %.9f\n", fix_n, fix_to_float(fix_n));
	printf("%.9f + %.9f = %.9f\n", fix_to_float(fix_n), fix_to_float(fix_n), fix_to_float(fix_add(fix_n, fix_n)));
	printf("%.9f - %.9f = %.9f\n", fix_to_float(fix_n), fix_to_float(fix_n), fix_to_float(fix_add(fix_n, -fix_n)));
	printf("answer: %.9f\n", n + n);

	// positive overflow test
	printf("\n positive overflow test\n");
	int32_t fix_max = INT32_MAX;
	printf("fix_max = %d => %.9f\n", fix_max, fix_to_float(fix_max));
	printf("fix_max + fix_max = %.6f\n", fix_to_float(fix_add(fix_max, fix_max)));
	printf("-fix_max + fix_max = %.6f\n", fix_to_float(fix_add(-fix_max, fix_max)));


	// negative overflow test
	printf("\n negative overflow test\n");
	int32_t fix_min = INT32_MIN;
	printf("fix_min = %d => %.9f\n", fix_min, fix_to_float(fix_min));
	printf("fix_min + fix_min = %.6f\n", fix_to_float(fix_add(fix_min, fix_min)));
	printf("fix_min + fix_max = %.6f\n", fix_to_float(fix_add(fix_min, fix_max)));
}

void sub_test()
{
	printf("\n\t==SUB_TEST==\n");
	//basic
	printf("\n basic test\n");
	double n = 0.1415926;
	int fix_n = float_to_fix(n);
	int fix_zero = float_to_fix(0);

	printf("n = %d => %.9f\n", fix_n, fix_to_float(fix_n));
	printf("%.9f - %.9f = %.9f\n", fix_to_float(fix_n), fix_to_float(fix_n), fix_to_float(fix_sub(fix_n, fix_n)));
	printf("%.9f - %.9f = %.9f\n", fix_to_float(fix_zero), fix_to_float(fix_n), fix_to_float(fix_sub(fix_zero, fix_n)));
	printf("answer: %.9f\n", n - n);

	// positive overflow test
	printf("\n positive overflow test\n");
	int32_t fix_max = INT32_MAX;
	printf("fix_max = %d => %.9f\n", fix_max, fix_to_float(fix_max));
	printf("-fix_max = %d => %.9f\n", -fix_max, fix_to_float(-fix_max));
	printf("fix_max - (-fix_max) = %.6f\n", fix_to_float(fix_sub(fix_max, -fix_max)));
	printf("fix_max - fix_max = %.6f\n", fix_to_float(fix_sub(fix_max, fix_max)));


	// negative overflow test
	printf("\n negative overflow test\n");
	int32_t fix_min = INT32_MIN;
	fix_min++;
	printf("fix_min = %d => %.9f\n", fix_min, fix_to_float(fix_min));
	printf("-fix_min = %d => %.9f\n", -fix_min, fix_to_float(-fix_min));
	printf("fix_min - (-fix_min) = %.6f\n", fix_to_float(fix_sub(fix_min, -fix_min)));
}

void mul_test()
{
	printf("\n\t==MUL_TEST==\n");
	//basic
	printf("\n basic test\n");
	double n = 0.1415926;
	int fix_n = float_to_fix(n);
	printf("n = %d => %.9f\n", fix_n, fix_to_float(fix_n));
	printf("%.9f x %.9f = %.9f\n", fix_to_float(fix_n), fix_to_float(fix_n), fix_to_float(fix_mul(fix_n, fix_n)));
	printf("answer: %.9f\n", n * n);

	int32_t fix_max = INT32_MAX;
	printf("fix_max = %d => %.9f\n", fix_max, fix_to_float(fix_max));
	printf("-fix_max = %d => %.9f\n", -fix_max, fix_to_float(-fix_max));
	printf("fix_max * fix_max = %.6f\n", fix_to_float(fix_mul(fix_max, fix_max)));
	printf("fix_max * (-fix_max) = %.6f\n", fix_to_float(fix_mul(fix_max, -fix_max)));
	printf("-fix_max * (-fix_max) = %.6f\n", fix_to_float(fix_mul(-fix_max, -fix_max)));
}

void mac_test()
{
	printf("\n\t==MAC_TEST==\n");
	
	double arr1[5] = { 0.123345, 0.2345235, 0.234234, 0.456456, 0.123756 };
	int32_t fix_arr1[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr1[i] = float_to_fix(arr1[i]);
		printf("arr1[%d] = %.9f => %.9f\n", i, arr1[i], fix_to_float(fix_arr1[i]));
	}

	double arr2[5] = { 0.345, 0.45235, 0.2334, 0.6456, 0.1256 };
	int32_t fix_arr2[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr2[i] = float_to_fix(arr2[i]);
		printf("arr2[%d] = %.9f => %.9f\n", i, arr2[i], fix_to_float(fix_arr2[i]));
	}

	double acc = 0;
	int32_t fix_acc = 0;

	for (int i = 0; i < 5; i++)
	{
		acc += arr1[i] * arr2[i];
		fix_acc = fix_mac(fix_acc, fix_arr1[i], fix_arr2[i]);
		printf("acc = %.9f\n", acc);
		printf("fix_acc = %.9f\n", fix_to_float(fix_acc));
	}
	printf("acc = %.9f\n", acc);
	printf("fix_acc = %.9f\n", fix_to_float(fix_acc));
}

void msub_test()
{
	printf("\n\t==MSUB_TEST==\n");
	
	double arr1[5] = { 0.123345, 0.2345235, 0.234234, 0.456456, 0.123756 };
	int32_t fix_arr1[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr1[i] = float_to_fix(arr1[i]);
		printf("arr1[%d] = %.9f => %.9f\n", i, arr1[i], fix_to_float(fix_arr1[i]));
	}

	double arr2[5] = { 0.345, 0.45235, 0.2334, 0.6456, 0.1256 };
	int32_t fix_arr2[5];
	for (int i = 0; i < 5; i++)
	{
		fix_arr2[i] = float_to_fix(arr2[i]);
		printf("arr2[%d] = %.9f => %.9f\n", i, arr2[i], fix_to_float(fix_arr2[i]));
	}

	double acc = 0.0;
	int32_t fix_acc = float_to_fix(acc);

	for (int i = 0; i < 5; i++)
	{
		acc -= arr1[i] * arr2[i];
		fix_acc = fix_msub(fix_acc, fix_arr1[i], fix_arr2[i]);
		printf("acc = %.9f\n", acc);
		printf("fix_acc = %.9f\n", fix_to_float(fix_acc));
	}
	printf("acc = %.9f\n", acc);
	printf("fix_acc = %.9f\n", fix_to_float(fix_acc));
}

void	lshift_test()
{
	int32_t fix_max = float_to_fix(0.00000001);
	printf("\nfix_max = %d => %.9f\n", fix_max, fix_to_float(fix_max));

	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_leftshift(fix_max, 1), fix_to_float(fix_leftshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_leftshift(fix_max, 2), fix_to_float(fix_leftshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_leftshift(fix_max, 3), fix_to_float(fix_leftshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_leftshift(fix_max, 4), fix_to_float(fix_leftshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_leftshift(fix_max, 5), fix_to_float(fix_leftshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_leftshift(fix_max, 6), fix_to_float(fix_leftshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_leftshift(fix_max, 7), fix_to_float(fix_leftshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_leftshift(fix_max, 8), fix_to_float(fix_leftshift(fix_max, 8)));

	fix_max = fix_leftshift(fix_max, 8);

	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_leftshift(fix_max, 1), fix_to_float(fix_leftshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_leftshift(fix_max, 2), fix_to_float(fix_leftshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_leftshift(fix_max, 3), fix_to_float(fix_leftshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_leftshift(fix_max, 4), fix_to_float(fix_leftshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_leftshift(fix_max, 5), fix_to_float(fix_leftshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_leftshift(fix_max, 6), fix_to_float(fix_leftshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_leftshift(fix_max, 7), fix_to_float(fix_leftshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_leftshift(fix_max, 8), fix_to_float(fix_leftshift(fix_max, 8)));
	
	fix_max = fix_leftshift(fix_max, 8);

	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_leftshift(fix_max, 1), fix_to_float(fix_leftshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_leftshift(fix_max, 2), fix_to_float(fix_leftshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_leftshift(fix_max, 3), fix_to_float(fix_leftshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_leftshift(fix_max, 4), fix_to_float(fix_leftshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_leftshift(fix_max, 5), fix_to_float(fix_leftshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_leftshift(fix_max, 6), fix_to_float(fix_leftshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_leftshift(fix_max, 7), fix_to_float(fix_leftshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_leftshift(fix_max, 8), fix_to_float(fix_leftshift(fix_max, 8)));

	fix_max = fix_leftshift(fix_max, 8);

	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_leftshift(fix_max, 1), fix_to_float(fix_leftshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_leftshift(fix_max, 2), fix_to_float(fix_leftshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_leftshift(fix_max, 3), fix_to_float(fix_leftshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_leftshift(fix_max, 4), fix_to_float(fix_leftshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_leftshift(fix_max, 5), fix_to_float(fix_leftshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_leftshift(fix_max, 6), fix_to_float(fix_leftshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_leftshift(fix_max, 7), fix_to_float(fix_leftshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_leftshift(fix_max, 8), fix_to_float(fix_leftshift(fix_max, 8)));

	fix_max = fix_leftshift(fix_max, 8);

	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_leftshift(fix_max, 1), fix_to_float(fix_leftshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_leftshift(fix_max, 2), fix_to_float(fix_leftshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_leftshift(fix_max, 3), fix_to_float(fix_leftshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_leftshift(fix_max, 4), fix_to_float(fix_leftshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_leftshift(fix_max, 5), fix_to_float(fix_leftshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_leftshift(fix_max, 6), fix_to_float(fix_leftshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_leftshift(fix_max, 7), fix_to_float(fix_leftshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) <%d< %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_leftshift(fix_max, 8), fix_to_float(fix_leftshift(fix_max, 8)));

	int32_t fix_min = float_to_fix(-0.00000001);
	printf("\nfix_min = %d => %.9f\n", fix_min, fix_to_float(fix_min));

	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_leftshift(fix_min, 1), fix_to_float(fix_leftshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_leftshift(fix_min, 2), fix_to_float(fix_leftshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_leftshift(fix_min, 3), fix_to_float(fix_leftshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_leftshift(fix_min, 4), fix_to_float(fix_leftshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_leftshift(fix_min, 5), fix_to_float(fix_leftshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_leftshift(fix_min, 6), fix_to_float(fix_leftshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_leftshift(fix_min, 7), fix_to_float(fix_leftshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_leftshift(fix_min, 8), fix_to_float(fix_leftshift(fix_min, 8)));

	fix_min = fix_leftshift(fix_min, 8);

	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_leftshift(fix_min, 1), fix_to_float(fix_leftshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_leftshift(fix_min, 2), fix_to_float(fix_leftshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_leftshift(fix_min, 3), fix_to_float(fix_leftshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_leftshift(fix_min, 4), fix_to_float(fix_leftshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_leftshift(fix_min, 5), fix_to_float(fix_leftshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_leftshift(fix_min, 6), fix_to_float(fix_leftshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_leftshift(fix_min, 7), fix_to_float(fix_leftshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_leftshift(fix_min, 8), fix_to_float(fix_leftshift(fix_min, 8)));

	fix_min = fix_leftshift(fix_min, 8);

	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_leftshift(fix_min, 1), fix_to_float(fix_leftshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_leftshift(fix_min, 2), fix_to_float(fix_leftshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_leftshift(fix_min, 3), fix_to_float(fix_leftshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_leftshift(fix_min, 4), fix_to_float(fix_leftshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_leftshift(fix_min, 5), fix_to_float(fix_leftshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_leftshift(fix_min, 6), fix_to_float(fix_leftshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_leftshift(fix_min, 7), fix_to_float(fix_leftshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_leftshift(fix_min, 8), fix_to_float(fix_leftshift(fix_min, 8)));

	fix_min = fix_leftshift(fix_min, 8);

	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_leftshift(fix_min, 1), fix_to_float(fix_leftshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_leftshift(fix_min, 2), fix_to_float(fix_leftshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_leftshift(fix_min, 3), fix_to_float(fix_leftshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_leftshift(fix_min, 4), fix_to_float(fix_leftshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_leftshift(fix_min, 5), fix_to_float(fix_leftshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_leftshift(fix_min, 6), fix_to_float(fix_leftshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_leftshift(fix_min, 7), fix_to_float(fix_leftshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_leftshift(fix_min, 8), fix_to_float(fix_leftshift(fix_min, 8)));

	fix_min = fix_leftshift(fix_min, 8);

	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_leftshift(fix_min, 1), fix_to_float(fix_leftshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_leftshift(fix_min, 2), fix_to_float(fix_leftshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_leftshift(fix_min, 3), fix_to_float(fix_leftshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_leftshift(fix_min, 4), fix_to_float(fix_leftshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_leftshift(fix_min, 5), fix_to_float(fix_leftshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_leftshift(fix_min, 6), fix_to_float(fix_leftshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_leftshift(fix_min, 7), fix_to_float(fix_leftshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) <%d< %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_leftshift(fix_min, 8), fix_to_float(fix_leftshift(fix_min, 8)));
}

void	rshift_test()
{
	int32_t fix_max = float_to_fix(1.0);
	printf("\nfix_max = %d => %.9f\n", fix_max, fix_to_float(fix_max));

	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_rightshift(fix_max, 1), fix_to_float(fix_rightshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_rightshift(fix_max, 2), fix_to_float(fix_rightshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_rightshift(fix_max, 3), fix_to_float(fix_rightshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_rightshift(fix_max, 4), fix_to_float(fix_rightshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_rightshift(fix_max, 5), fix_to_float(fix_rightshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_rightshift(fix_max, 6), fix_to_float(fix_rightshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_rightshift(fix_max, 7), fix_to_float(fix_rightshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_rightshift(fix_max, 8), fix_to_float(fix_rightshift(fix_max, 8)));

	fix_max = fix_rightshift(fix_max, 8);

	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_rightshift(fix_max, 1), fix_to_float(fix_rightshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_rightshift(fix_max, 2), fix_to_float(fix_rightshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_rightshift(fix_max, 3), fix_to_float(fix_rightshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_rightshift(fix_max, 4), fix_to_float(fix_rightshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_rightshift(fix_max, 5), fix_to_float(fix_rightshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_rightshift(fix_max, 6), fix_to_float(fix_rightshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_rightshift(fix_max, 7), fix_to_float(fix_rightshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_rightshift(fix_max, 8), fix_to_float(fix_rightshift(fix_max, 8)));

	fix_max = fix_rightshift(fix_max, 8);
	
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_rightshift(fix_max, 1), fix_to_float(fix_rightshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_rightshift(fix_max, 2), fix_to_float(fix_rightshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_rightshift(fix_max, 3), fix_to_float(fix_rightshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_rightshift(fix_max, 4), fix_to_float(fix_rightshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_rightshift(fix_max, 5), fix_to_float(fix_rightshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_rightshift(fix_max, 6), fix_to_float(fix_rightshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_rightshift(fix_max, 7), fix_to_float(fix_rightshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_rightshift(fix_max, 8), fix_to_float(fix_rightshift(fix_max, 8)));

	fix_max = fix_rightshift(fix_max, 8);

	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_rightshift(fix_max, 1), fix_to_float(fix_rightshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_rightshift(fix_max, 2), fix_to_float(fix_rightshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_rightshift(fix_max, 3), fix_to_float(fix_rightshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_rightshift(fix_max, 4), fix_to_float(fix_rightshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_rightshift(fix_max, 5), fix_to_float(fix_rightshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_rightshift(fix_max, 6), fix_to_float(fix_rightshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_rightshift(fix_max, 7), fix_to_float(fix_rightshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_rightshift(fix_max, 8), fix_to_float(fix_rightshift(fix_max, 8)));

	fix_max = fix_rightshift(fix_max, 8);

	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 1, fix_rightshift(fix_max, 1), fix_to_float(fix_rightshift(fix_max, 1)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 2, fix_rightshift(fix_max, 2), fix_to_float(fix_rightshift(fix_max, 2)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 3, fix_rightshift(fix_max, 3), fix_to_float(fix_rightshift(fix_max, 3)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 4, fix_rightshift(fix_max, 4), fix_to_float(fix_rightshift(fix_max, 4)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 5, fix_rightshift(fix_max, 5), fix_to_float(fix_rightshift(fix_max, 5)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 6, fix_rightshift(fix_max, 6), fix_to_float(fix_rightshift(fix_max, 6)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 7, fix_rightshift(fix_max, 7), fix_to_float(fix_rightshift(fix_max, 7)));
	printf("fix_max = %d (%.9f) >%d> %d (%.9f)\n", fix_max, fix_to_float(fix_max), 8, fix_rightshift(fix_max, 8), fix_to_float(fix_rightshift(fix_max, 8)));

	int32_t fix_min = float_to_fix(-1.0);
	printf("\nfix_min = %d => %.9f\n", fix_min, fix_to_float(fix_min));

	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_rightshift(fix_min, 1), fix_to_float(fix_rightshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_rightshift(fix_min, 2), fix_to_float(fix_rightshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_rightshift(fix_min, 3), fix_to_float(fix_rightshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_rightshift(fix_min, 4), fix_to_float(fix_rightshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_rightshift(fix_min, 5), fix_to_float(fix_rightshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_rightshift(fix_min, 6), fix_to_float(fix_rightshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_rightshift(fix_min, 7), fix_to_float(fix_rightshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_rightshift(fix_min, 8), fix_to_float(fix_rightshift(fix_min, 8)));

	fix_min = fix_rightshift(fix_min, 8);

	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_rightshift(fix_min, 1), fix_to_float(fix_rightshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_rightshift(fix_min, 2), fix_to_float(fix_rightshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_rightshift(fix_min, 3), fix_to_float(fix_rightshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_rightshift(fix_min, 4), fix_to_float(fix_rightshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_rightshift(fix_min, 5), fix_to_float(fix_rightshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_rightshift(fix_min, 6), fix_to_float(fix_rightshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_rightshift(fix_min, 7), fix_to_float(fix_rightshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_rightshift(fix_min, 8), fix_to_float(fix_rightshift(fix_min, 8)));

	fix_min = fix_rightshift(fix_min, 8);

	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_rightshift(fix_min, 1), fix_to_float(fix_rightshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_rightshift(fix_min, 2), fix_to_float(fix_rightshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_rightshift(fix_min, 3), fix_to_float(fix_rightshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_rightshift(fix_min, 4), fix_to_float(fix_rightshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_rightshift(fix_min, 5), fix_to_float(fix_rightshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_rightshift(fix_min, 6), fix_to_float(fix_rightshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_rightshift(fix_min, 7), fix_to_float(fix_rightshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_rightshift(fix_min, 8), fix_to_float(fix_rightshift(fix_min, 8)));

	fix_min = fix_rightshift(fix_min, 8);

	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_rightshift(fix_min, 1), fix_to_float(fix_rightshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_rightshift(fix_min, 2), fix_to_float(fix_rightshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_rightshift(fix_min, 3), fix_to_float(fix_rightshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_rightshift(fix_min, 4), fix_to_float(fix_rightshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_rightshift(fix_min, 5), fix_to_float(fix_rightshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_rightshift(fix_min, 6), fix_to_float(fix_rightshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_rightshift(fix_min, 7), fix_to_float(fix_rightshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_rightshift(fix_min, 8), fix_to_float(fix_rightshift(fix_min, 8)));

	fix_min = fix_rightshift(fix_min, 8);

	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 1, fix_rightshift(fix_min, 1), fix_to_float(fix_rightshift(fix_min, 1)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 2, fix_rightshift(fix_min, 2), fix_to_float(fix_rightshift(fix_min, 2)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 3, fix_rightshift(fix_min, 3), fix_to_float(fix_rightshift(fix_min, 3)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 4, fix_rightshift(fix_min, 4), fix_to_float(fix_rightshift(fix_min, 4)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 5, fix_rightshift(fix_min, 5), fix_to_float(fix_rightshift(fix_min, 5)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 6, fix_rightshift(fix_min, 6), fix_to_float(fix_rightshift(fix_min, 6)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 7, fix_rightshift(fix_min, 7), fix_to_float(fix_rightshift(fix_min, 7)));
	printf("fix_min = %d (%.9f) >%d> %d (%.9f)\n", fix_min, fix_to_float(fix_min), 8, fix_rightshift(fix_min, 8), fix_to_float(fix_rightshift(fix_min, 8)));

}

int main()
{
	add_test();
	sub_test();
	mul_test();
	mac_test();
	msub_test();
	lshift_test();
	rshift_test();
	return 0;
}
