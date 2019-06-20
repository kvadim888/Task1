#ifndef LIBFIX_H
#define LIBFIX_H

#include <stdint.h>

#define PRECISION		31 

#define FLOAT2FIX(num) (num * (float)((1 << PRECISION)-1))
#define FIX2FLOAT(num) ((float)num / ((1 << PRECISION)-1))

#define DOUBLE2FIX(num) (num * (double)((1 << PRECISION)-1))
#define FIX2DOUBLE(num) ((double)num / ((1 << PRECISION)-1))

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"

#define BYTE_TO_BINARY(byte)  \
					(byte & 0x80 ? '1' : '0'), \
					(byte & 0x40 ? '1' : '0'), \
					(byte & 0x20 ? '1' : '0'), \
					(byte & 0x10 ? '1' : '0'), \
					(byte & 0x08 ? '1' : '0'), \
					(byte & 0x04 ? '1' : '0'), \
					(byte & 0x02 ? '1' : '0'), \
					(byte & 0x01 ? '1' : '0') 

#define INT_TO_BINARY(num)

int32_t fix_add(int32_t a, int32_t b);

int32_t fix_sub(int32_t a, int32_t b);
int32_t	fix_mul(int32_t a, int32_t b);

int32_t	fix_mac(int64_t *accum, int32_t *a, size_t len_a, int32_t *b, size_t len_b);
int32_t	fix_msub(int64_t *accum, int32_t *a, size_t len_a, int32_t *b, size_t len_b);

int32_t	fix_leftshift(int32_t num, int8_t shift);
int32_t	fix_rightshift(int32_t num, int8_t shift);

#endif	//LIBFIX_H
