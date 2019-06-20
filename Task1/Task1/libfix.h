#ifndef LIBFIX_H
#define LIBFIX_H

#include <stdint.h>

#define	Q16_16 int32_t
#define	Q32_32 int64_t

#define PRECISION		16 

#define FLOAT2FIX(num) (num * (float)(1 << PRECISION))
#define FIX2FLOAT(num) ((float)num / (1 << PRECISION))

#define DOUBLE2FIX(num) (num * (double)(1 << PRECISION))
#define FIX2DOUBLE(num) ((double)num / (1 << PRECISION))

int32_t fix_add(int32_t a, int32_t b);

int32_t fix_sub(int32_t a, int32_t b);
int32_t	fix_mul(int32_t a, int32_t b);

int32_t	fix_mac(int64_t *accum, int32_t *a, size_t len_a, int32_t *b, size_t len_b);
int32_t	fix_msub(int64_t *accum, int32_t *a, size_t len_a, int32_t *b, size_t len_b);

int32_t	fix_leftshift(int32_t num, int8_t shift);
int32_t	fix_rightshift(int32_t num, int8_t shift);

#endif	//LIBFIX_H
