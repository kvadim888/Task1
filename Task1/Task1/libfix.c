#include "libfix.h"
#include <stdint.h>
#include <stdio.h>

int32_t fix_add(int32_t a, int32_t b)
{
	uint32_t tmp_a = a;
	uint32_t tmp_b = b;

	uint32_t sum = a + b;

	printf("(tmp_a & (uint32_t)(1 << 32) = %d\n", (tmp_a & (uint32_t)(1 << 32)));
	printf("(tmp_b & (uint32_t)(1 << 32) = %d\n", (tmp_b & (uint32_t)(1 << 32)));
	printf("sum & (uint32_t)(1 << 32) = %d\n", sum & (uint32_t)(1 << 32));
	if ((tmp_a & (uint32_t)(1 << 32) == tmp_b & (uint32_t)(1 << 32)) && (tmp_a & (uint32_t)(1 << 32) != sum & (uint32_t)(1 << 32)))
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

	uint32_t sub = a - b;

	if (((tmp_a & (uint32_t)(1 << 32)) != tmp_b & (uint32_t)(1 << 32)) && (tmp_a & (uint32_t)(1 << 32) != sub & (uint32_t)(1 << 32)))
	{
		printf("sub overflow \n");
		return (a >= 0) ? INT32_MAX : INT32_MIN;
	}
	return (int32_t)sub;
}

int32_t fix_mul(int32_t a, int32_t b)
{
	uint32_t tmp_a = a;
	uint32_t tmp_b = b;

	int64_t	mul = ((int64_t)a * (int64_t)b) >> 16;
	if (((tmp_a ^ tmp_b) & (uint32_t)(1 << 32)) != ((uint32_t)(mul) & (uint32_t)(1 << 32)))
	{
		printf("mul overflow \n");
		return ((uint32_t)mul & (uint32_t)(1 << 32)) ? INT32_MAX : INT32_MIN;
	}
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

