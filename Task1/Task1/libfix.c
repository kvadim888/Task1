#include "libfix.h"
#include <stdint.h>
#include <stdio.h>

int32_t fix_add(int32_t a, int32_t b)
{
	uint32_t tmp_a = a;
	uint32_t tmp_b = b;
	uint32_t sum = tmp_a + tmp_b;
	if (!((tmp_a ^ tmp_b) >> 32) && ((tmp_a ^ sum) >> 32))
	{
		printf("sum overflow \n");
		return (a >= 0) ? INT32_MAX : INT32_MIN;
	}
	return (int32_t)sum;
}

int32_t fix_sub(int32_t a, int32_t b)
{
	uint32_t tmp_a = a;
	uint32_t tmp_b = b;
	uint32_t sub = tmp_a - tmp_b;

	if (((tmp_a ^ tmp_b) >> 32) && ((tmp_a ^ sub) >> 32))
	{
		printf("sub overflow \n");
		return (a >= 0) ? INT32_MAX : INT32_MIN;
	}
	return (int32_t)sub;
}

int32_t fix_mul(int32_t a, int32_t b)
{
	int64_t tmp_a = a;
	int64_t tmp_b = b;

	int64_t	mul = (tmp_a * tmp_b) >> 31;

	return (int32_t)mul;
}

int32_t	fix_mac(int64_t *accum, int32_t *a, size_t len_a, int32_t *b, size_t len_b)
{
	size_t common = (len_a < len_b) ? len_a : len_b;

	for (size_t i = 0; i < common; i++)
	{
		*accum += ((int64_t)a[i] * (int64_t)b[i]) >> 16;
	}
	return 0;
}

int32_t	fix_msub(int64_t *accum, int32_t *a, size_t len_a, int32_t *b, size_t len_b)
{
	size_t common = (len_a < len_b) ? len_a : len_b;

	for (size_t i = 0; i < common; i++)
	{
		*accum -= ((int64_t)a[i] * (int64_t)b[i]) >> 16;
	}
	return 0;
}

int32_t	fix_leftshift(int32_t num, int8_t shift)
{
	return (num << shift);
}

int32_t	fix_rightshift(int32_t num, int8_t shift)
{
	return (num >> shift);
}

