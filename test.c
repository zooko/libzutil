#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#include "zutil.h"

#include <assert.h>

int test_overflow()
{
	assert (add_would_overflow_char(CHAR_MAX - 2, CHAR_MAX - 3));
	assert (add_would_overflow_char(CHAR_MAX, CHAR_MAX));
	assert (add_would_overflow_char((CHAR_MAX/2)+1, (CHAR_MAX/2)+1));
	assert (!add_would_overflow_char(CHAR_MAX/2, CHAR_MAX/2));
	assert (!add_would_overflow_char(CHAR_MAX, 0));
	assert (add_would_overflow_char(CHAR_MAX, 1));
	assert (add_would_overflow_char(1, CHAR_MAX));
	assert (!add_would_overflow_char(CHAR_MAX-1, 1));
	assert (!add_would_overflow_char(CHAR_MAX-2, 2));
	assert (!add_would_overflow_char(0, 0));

	assert (add_would_overflow_shrt(SHRT_MAX - 2, SHRT_MAX - 3));
	assert (add_would_overflow_shrt(SHRT_MAX, SHRT_MAX));
	assert (add_would_overflow_shrt((SHRT_MAX/2)+1, (SHRT_MAX/2)+1));
	assert (!add_would_overflow_shrt(SHRT_MAX/2, SHRT_MAX/2));
	assert (!add_would_overflow_shrt(SHRT_MAX, 0));
	assert (!add_would_overflow_shrt(SHRT_MAX-1, 1));
	assert (!add_would_overflow_shrt(SHRT_MAX-2, 2));
	assert (!add_would_overflow_shrt(0, 0));

	assert (add_would_overflow_shrt(SHRT_MIN, SHRT_MIN));
	assert (add_would_overflow_shrt(SHRT_MIN, -1));
	assert (add_would_overflow_shrt(-1, SHRT_MIN));
	assert (add_would_overflow_shrt((SHRT_MIN/2)-1, (SHRT_MIN/2)-1));
	assert (!add_would_overflow_shrt(SHRT_MIN/2, SHRT_MIN/2));

	assert (add_would_overflow_int(INT_MAX - 2, INT_MAX - 3));
	assert (add_would_overflow_int(INT_MAX, INT_MAX));
	assert (add_would_overflow_int((INT_MAX/2)+1, (INT_MAX/2)+1));
	assert (!add_would_overflow_int(INT_MAX/2, INT_MAX/2));
	assert (!add_would_overflow_int(INT_MAX, 0));
	assert (add_would_overflow_int(INT_MAX, 1));
	assert (add_would_overflow_int(1, INT_MAX));
	assert (!add_would_overflow_int(INT_MAX-1, 1));
	assert (!add_would_overflow_int(INT_MAX-2, 2));
	assert (!add_would_overflow_int(0, 0));

	assert (add_would_overflow_int(INT_MIN, INT_MIN));
	assert (add_would_overflow_int(INT_MIN, -1));
	assert (add_would_overflow_int(-1, INT_MIN));
	assert (add_would_overflow_int((INT_MIN/2)-1, (INT_MIN/2)-1));
	assert (!add_would_overflow_int(INT_MIN/2, INT_MIN/2));

	assert (add_would_overflow_uint(UINT_MAX - 2, UINT_MAX - 3));
	assert (add_would_overflow_uint(UINT_MAX, UINT_MAX));
	assert (add_would_overflow_uint((UINT_MAX/2)+1, (UINT_MAX/2)+1));
	assert (!add_would_overflow_uint(UINT_MAX/2, UINT_MAX/2));
	assert (!add_would_overflow_uint(UINT_MAX, 0));
	assert (add_would_overflow_uint(UINT_MAX, 1));
	assert (add_would_overflow_uint(1, UINT_MAX));
	assert (!add_would_overflow_uint(UINT_MAX-1, 1));
	assert (!add_would_overflow_uint(UINT_MAX-2, 2));
	assert (!add_would_overflow_uint(0, 0));

	assert (add_would_overflow_long(LONG_MAX - 2, LONG_MAX - 3));
	assert (add_would_overflow_long(LONG_MAX, LONG_MAX));
	assert (add_would_overflow_long((LONG_MAX/2)+1, (LONG_MAX/2)+1));
	assert (!add_would_overflow_long(LONG_MAX/2, LONG_MAX/2));
	assert (!add_would_overflow_long(LONG_MAX, 0));
	assert (add_would_overflow_long(LONG_MAX, 1));
	assert (add_would_overflow_long(1, LONG_MAX));
	assert (!add_would_overflow_long(LONG_MAX-1, 1));
	assert (!add_would_overflow_long(LONG_MAX-2, 2));
	assert (!add_would_overflow_long(0, 0));

	assert (add_would_overflow_long(INT_MIN, INT_MIN));
	assert (add_would_overflow_long(INT_MIN, -1));
	assert (add_would_overflow_long(-1, INT_MIN));
	assert (add_would_overflow_long((INT_MIN/2)-1, (INT_MIN/2)-1));
	assert (!add_would_overflow_long(INT_MIN/2, INT_MIN/2));

	assert (add_would_overflow_ulong(ULONG_MAX - 2, ULONG_MAX - 3));
	assert (add_would_overflow_ulong(ULONG_MAX, ULONG_MAX));
	assert (add_would_overflow_ulong((ULONG_MAX/2)+1, (ULONG_MAX/2)+1));
	assert (!add_would_overflow_ulong(ULONG_MAX/2, ULONG_MAX/2));
	assert (!add_would_overflow_ulong(ULONG_MAX, 0));
	assert (add_would_overflow_ulong(ULONG_MAX, 1));
	assert (add_would_overflow_ulong(1, ULONG_MAX));
	assert (!add_would_overflow_ulong(ULONG_MAX-1, 1));
	assert (!add_would_overflow_ulong(ULONG_MAX-2, 2));
	assert (!add_would_overflow_ulong(0, 0));

	return 1;
}

int test_CHAR_FITS_INTO_SIGNED_INT()
{
	assert (TYPE_FITS_INTO_SIGNED_INT(signed char));
	assert (TYPE_FITS_INTO_SIGNED_INT(char));
	assert (TYPE_FITS_INTO_SIGNED_INT(unsigned char));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)CHAR_MAX));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)CHAR_MAX));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)UCHAR_MAX));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)CHAR_MIN));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)CHAR_MIN));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)UCHAR_MIN));
	return 1;
}

int test_CHAR_PROMOTES_TO_SIGNED_TYPE()
{
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(signed char));
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(char));
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(unsigned char));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((char)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned char)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((char)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned char)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((char)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned char)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((char)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned char)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)CHAR_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((char)CHAR_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned char)UCHAR_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)CHAR_MIN));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((char)CHAR_MIN));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned char)UCHAR_MIN));
	return 1;
}

int test_SIGNED_NONLONG_FITS_INTO_SIGNED_INT()
{
	assert (TYPE_FITS_INTO_SIGNED_INT(signed char));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)CHAR_MAX));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)CHAR_MIN));
	assert (TYPE_FITS_INTO_SIGNED_INT(signed short));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)SHRT_MAX));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)SHRT_MIN));
	assert (TYPE_FITS_INTO_SIGNED_INT(signed int));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)INT_MAX));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)INT_MIN));
	return 1;
}

int test_SIGNED_NONLONG_PROMOTES_TO_SIGNED_TYPE()
{
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(signed char));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)CHAR_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed char)CHAR_MIN));
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(signed short));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed short)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed short)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed short)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed short)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed short)SHRT_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed short)SHRT_MIN));
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(signed int));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)INT_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)INT_MIN));
	return 1;
}

int test_UNSIGNED_INT_NOT_FITS_INTO_SIGNED_INT()
{
	assert (!TYPE_FITS_INTO_SIGNED_INT(unsigned int));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)0));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)-1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)2));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)UINT_MAX));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)UINT_MIN));
	return 1;
}

int test_UNSIGNED_INT_NOT_PROMOTES_TO_SIGNED_TYPE()
{
	assert (!TYPE_PROMOTES_TO_SIGNED_TYPE(unsigned int));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)0));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)-1));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)1));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)2));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)UINT_MAX));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)UINT_MIN));
	return 1;
}

int test_UNSIGNED_LONG_NOT_FITS_INTO_SIGNED_INT()
{
	assert (!TYPE_FITS_INTO_SIGNED_INT(unsigned long));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)0));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)-1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)2));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)ULONG_MAX));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)ULONG_MIN));
	return 1;
}

int test_UNSIGNED_LONG_NOT_PROMOTES_TO_SIGNED_TYPE()
{
	assert (!TYPE_PROMOTES_TO_SIGNED_TYPE(unsigned long));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long)0));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long)-1));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long)1));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long)2));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long)ULONG_MAX));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long)ULONG_MIN));
	return 1;
}

int test_UNSIGNED_LONGLONG_NOT_FITS_INTO_SIGNED_INT()
{
	assert (!TYPE_FITS_INTO_SIGNED_INT(unsigned long long));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)0));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)-1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)2));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)ULONG_MAX));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)ULONG_MIN));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)ULLONG_MAX));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long long)ULLONG_MIN));
	return 1;
}

int test_UNSIGNED_LONGLONG_NOT_PROMOTES_TO_SIGNED_TYPE()
{
	assert (!TYPE_PROMOTES_TO_SIGNED_TYPE(unsigned long long));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)0));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)-1));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)1));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)2));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)ULONG_MAX));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)ULONG_MIN));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)ULLONG_MAX));
	assert (!OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned long long)ULLONG_MIN));
	return 1;
}

int test_SIGNED_LONGLONG_NOT_FITS_INTO_SIGNED_INT()
{
	assert (!TYPE_FITS_INTO_SIGNED_INT(long long));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)0));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)-1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)2));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)ULONG_MAX));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)ULONG_MIN));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)ULLONG_MAX));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((long long)ULLONG_MIN));
	return 1;
}

int test_SIGNED_LONGLONG_PROMOTES_TO_SIGNED_TYPE()
{
	assert (TYPE_PROMOTES_TO_SIGNED_TYPE(long long));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)0));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)-1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)1));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)2));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)ULONG_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)ULONG_MIN));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)ULLONG_MAX));
	assert (OPERAND_PROMOTES_TO_SIGNED_TYPE((long long)ULLONG_MIN));
	return 1;
}

int test_FITS_INTO_SIGNED_INT()
{
	if (!test_CHAR_FITS_INTO_SIGNED_INT()) {
		return 0;
	}

	if (!test_SIGNED_NONLONG_FITS_INTO_SIGNED_INT()) {
		return 0;
	}

	if (!test_UNSIGNED_INT_NOT_FITS_INTO_SIGNED_INT()) {
		return 0;
	}

	if (!test_UNSIGNED_LONG_NOT_FITS_INTO_SIGNED_INT()) {
		return 0;
	}
	
	if (!test_UNSIGNED_LONGLONG_NOT_FITS_INTO_SIGNED_INT()) {
		return 0;
	}

	if (!test_SIGNED_LONGLONG_NOT_FITS_INTO_SIGNED_INT()) {
		return 0;
	}

	return 1;
}

int test_PROMOTES_TO_SIGNED_TYPE()
{
	if (!test_CHAR_PROMOTES_TO_SIGNED_TYPE()) {
		return 0;
	}

	if (!test_SIGNED_NONLONG_PROMOTES_TO_SIGNED_TYPE()) {
		return 0;
	}

	if (!test_UNSIGNED_INT_NOT_PROMOTES_TO_SIGNED_TYPE()) {
		return 0;
	}

	if (!test_UNSIGNED_LONG_NOT_PROMOTES_TO_SIGNED_TYPE()) {
		return 0;
	}
	
	if (!test_UNSIGNED_LONGLONG_NOT_PROMOTES_TO_SIGNED_TYPE()) {
		return 0;
	}

	if (!test_SIGNED_LONGLONG_PROMOTES_TO_SIGNED_TYPE()) {
		return 0;
	}

	return 1;
}

/* If this test is commented-in, it will ideally give compile-time errors!
int test_MIN_crazybadargs()
{
	char b[10];
	int z = 1;
	MIN(b, z);
}
*/

int test_minmax_fast()
{
	unsigned int unsignedthree = 3;
	unsigned char unsignedcharthree = 3;
	signed long long signedllthree = 3;
	int negone = -1;
	if (_MIN_UNSAFE(unsignedthree, negone) != negone) {
		/* printf("just as we expected, using _MIN_UNSAFE on one negative operand and one unsigned int operand results in the wrong answer; _MIN_UNSAFE(%uU, %d) != %d\n", unsignedthree, negone, negone); */
	} else {
		printf("???_MIN_UNSAFE() should not have been able to correctly answer this question featuring a negative operand and an unsigned int operand.\n");
	}
	if (_MAX_UNSAFE(unsignedthree, negone) != unsignedthree) {
		/* printf("just as we expected, using _MAX_UNSAFE on one negative operand and one unsigned int operand results in the wrong answer; _MAX_UNSAFE(%uU, %d) != %d\n", unsignedthree, negone, unsignedthree); */
	} else {
		printf("???_MAX_UNSAFE() should not have been able to correctly answer this question featuring a negative operand and an unsigned int operand.\n");
	}
	if (_MIN_UNSAFE(signedllthree, negone) != negone) {
		printf("???_MIN_UNSAFE() should have been able to correctly answer this question featuring a negative operand and a signed long long operand.  _MIN_UNSAFE(%lldLL, %d) != %d\n\n", signedllthree, negone, negone);
	} else {
		/* printf("just as we expected, using _MIN_UNSAFE on one negative operand and one signed long long operand results in the right answer\n"); */
	}
	if (_MIN_UNSAFE(unsignedcharthree, negone) != negone) {
		printf("???_MIN_UNSAFE() should have been able to correctly answer this question featuring a negative operand and an unsigned char operand. _MIN_UNSAFE(%uc, %d) != %d\n\n", unsignedcharthree, negone, negone);
	} else {
		/* printf("just as we expected, using _MIN_UNSAFE on one negative operand and one unsigned char operand results in the right answer\n"); */
	}
	return 0;
}

int _test_MIN_smallerint_biggeruint(int i, unsigned u) {
	if (MIN(i, u) >= u) {
		printf("failed test %d MIN(%d, %uU): %lldLL == %lluULL >= u == %uU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	if (MIN(i, u) > i) {
		printf("failed test %d MIN(%d, %uU): %lldLL == %lluULL > i == %d\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) != i) {
		printf("failed test %d MIN(%d, %uU): %lldLL == %lluULL != i == %d\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	return 0;
}

int _test_MAX_smallerint_biggeruint(int i, unsigned u) {
	if (MAX(i, u) < u) {
		printf("failed test %d MAX(%d, %uU): %lldLL == %lluLLU < u == %uU == %uU\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u, u);
	}
	if (MAX(i, u) != u) {
		printf("failed test %d MAX(%d, %uU): %lldLL == %lluLLU != u == %u\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	return 0;
}

int _test_MIN_smallerlong_biggerulong(long i, unsigned long u) {
	if (MIN(i, u) >= u) {
		printf("failed test %d MIN(%ld, %lu): %lldLL == %lluULL >= u == %lu\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	if (MIN(i, u) > i) {
		printf("failed test %d MIN(%ld, %lu): %lldLL == %lluULL > i == %ld\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) != i) {
		printf("failed test %d MIN(%ld, %lu): %lldLL == %lluULL != i == %ld\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	return 0;
}

int _test_MAX_smallerlong_biggerulong(long i, unsigned long u) {
	if (MAX(i, u) <= i) {
		printf("failed test %d MAX(%ld, %lu): %lldLL == %lluLLU <= i == %ld\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	if (MAX(i, u) < u) {
		printf("failed test %d MAX(%ld, %lu): %lldLL == %lluLLU < u == %luUL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	if (MAX(i, u) != u) {
		printf("failed test %d MAX(%ld, %lu): %lldLL == %lluLLU != u == %luUL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	return 0;
}

int _test_MIN_biggerint_smalleruint(int i, unsigned u) {
	if (MIN(i, u) >= i) {
		printf("failed test %d MIN(%d, %uU): %lldLL == %lluULL >= i == %d\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) > u) {
		printf("failed test %d MIN(%d, %d): %lldLL == %lluULL > u == %uU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	if (MIN(i, u) != u) {
		printf("failed test %d MIN(%d, %d): %lldLL == %lluULL != u == %uU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	return 0;
}

int _test_MAX_biggerint_smalleruint(int i, unsigned u) {
	if (MAX(i, u) <= u) {
		printf("failed test %d MAX(%d, %uU): %lldLL == %lluLLU <= u == %uU\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	if (MAX(i, u) < i) {
		printf("failed test %d MAX(%d, %d): %lldLL == %lluLLU < i == %d\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	if (MAX(i, u) != i) {
		printf("failed test %d MAX(%d, %d): %lldLL == %lluLLU != i == %d\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	return 0;
}

int _test_MIN_biggerulong_smallerint(unsigned long u, int i) {
	if (MIN(u, i) >= u) {
		printf("failed test %d MIN(%luUL, %d): %lldLL == %lluLLU >= u == %luLU\n", __LINE__, u, i, MIN(u, i), MIN(u, i), u);
	}
	if (MIN(u, i) != i) {
		printf("failed test %d MIN(%luUL, %d): %lldLL == %lluLLU != i == %d\n", __LINE__, u, i, MIN(u, i), MIN(u, i), i);
	}
	return 0;
}

int _test_MAX_biggerulong_smallerint(unsigned long u, int i) {
	if (MAX(u, i) <= i) {
		printf("failed test %d MAX(%luUL, %d): %lldLL == %lluLLU <= i == %d\n", __LINE__, u, i, MAX(u, i), MAX(u, i), i);
	}
	if (MAX(u, i) != u) {
		printf("failed test %d MAX(%luUL, %d): %lldLL == %lluLLU != u == %luUL\n", __LINE__, u, i, MAX(u, i), MAX(u, i), u);
	}
	return 0;
}

int _test_MIN_biggerullong_smallerint(unsigned long long u, int i) {
	/*if (MIN(u, i) >= u) {
		printf("failed test %d as expected, MIN(%lluULL, %d): %lldLL == %lluULL >= u == %lluLLU\n", __LINE__, u, i, MIN(u, i), MIN(u, i), u);
	}*/
	if (MIN(u, i) != i) {
		printf("failed test %d MIN(%lluULL, %d): %lldLL == %lluULL != i == %uU\n", __LINE__, u, i, MIN(u, i), MIN(u, i), i);
	}
	return 0;
}

int _test_MAX_biggerullong_smallerint(unsigned long long u, int i) {
	/*if (MAX(u, i) <= i) {
		printf("failed test %d as expected MAX(%lluULL, %d): %lldLL == %lluULL <= i == %d\n", __LINE__, u, i, MAX(u, i), MAX(u, i), i);
	}*/
	if (MAX(u, i) != u) {
		printf("failed test %d MAX(%lluULL, %d): %lldLL == %lluULL != u == %lluULL\n", __LINE__, u, i, MAX(u, i), MAX(u, i), u);
	}
	return 0;
}

int _test_MIN_biggerlong_smallerulong(long i, unsigned long u) {
	if (MIN(i, u) <= -1) {
		printf("failed test %d MIN(%ld, %luLU): %lldLL == %lluULL <= -1 == %d == %uU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), -1, -1);
	}
	if (MIN(i, u) >= i) {
		printf("failed test %d MIN(%ld, %luLU): %lldLL == %lluULL >= i == %ld\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) > u) {
		printf("failed test %d MIN(%ld, %luLU): %lldLL == %lluULL > u == %luLU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	if (MIN(i, u) != u) {
		printf("failed test %d MIN(%ld, %luLU): %lldLL == %lluULL != u == %luLU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	return 0;
}

int _test_MAX_biggerlong_smallerulong(long i, unsigned long u) {
	if (MAX(i, u) <= -1) {
		printf("failed test %d MAX(%ld, %luLU): %lldLL == %lluLLU <= -1 == %d == %u\n", __LINE__, i, u, MAX(i, u), MAX(i, u), -1, -1);
	}
	if (MAX(i, u) <= u) {
		printf("failed test %d MAX(%ld, %luLU): %lldLL == %lluLLU <= u == %luLU\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	if (MAX(i, u) < i) {
		printf("failed test %d MAX(%ld, %ldL): %lldLL == %lluLLU < i == %ldL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	if (MAX(i, u) != i) {
		printf("failed test %d MAX(%ld, %ldL): %lldLL == %lluLLU != i == %ldL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	return 0;
}

int _test_MIN_biggerlong_smallerullong(long i, unsigned long long u) {
	if (MIN(i, u) <= -1) {
		printf("failed test %d MIN(%ld, %lluLLU): %lldLL == %lluULL <= -1 == %d == %u\n", __LINE__, i, u, MIN(i, u), MIN(i, u), -1, -1);
	}
	if (MIN(i, u) >= i) {
		printf("failed test %d MIN(%ld, %lluLLU): %lldLL == %lluULL >= i == %ld\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) > u) {
		printf("failed test %d MIN(%ld, %lluLLU): %lldLL == %lluULL > u == %lluLLU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	if (MIN(i, u) != u) {
		printf("failed test %d MIN(%ld, %lluLLU): %lldLL == %lluULL != u == %lluLLU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	return 0;
}

int _test_MAX_biggerlong_smallerullong(long i, unsigned long long u) {
	/*if (MAX(i, u) <= -1) {
		printf("failed test %d as expected MAX(%ld, %lluLLU): %ldL == %luUL <= -1 == %d == %u\n", __LINE__, i, u, MAX(i, u), MAX(i, u), -1, -1);
	}*/
	if (MAX(i, u) <= u) {
		printf("failed test %d MAX(%ld, %lluLLU): %lldLL == %lluLLU <= u == %lluLLU\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	if (MAX(i, u) < i) {
		printf("failed test %d MAX(%ld, %lluLLU): %lldLL == %lluLLU < i == %ldL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	if (MAX(i, u) != i) {
		printf("failed test %d MAX(%ld, %lluLLU): %lldLL == %lluLLU != i == %ldL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	return 0;
}

int _test_MIN_equalint_equaluint(int i, unsigned u) {
	if (MIN(i, u) != i) {
		printf("failed test %d MIN(%d, %d): %lldLL == %lluULL != i == %d\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) != u) {
		printf("failed test %d MIN(%d, %d): %lldLL == %lluULL != u == %uU\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	return 0;
}

int _test_MAX_equalint_equaluint(int i, unsigned u) {
	if (MAX(i, u) != i) {
		printf("failed test %d MAX(%d, %d): %lldLL == %lluLLU != i == %d\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	if (MAX(i, u) != u) {
		printf("failed test %d MAX(%d, %d): %lldLL == %lluLLU != u == %uU\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	return 0;
}

int _test_MIN_equallong_equalulong(long i, unsigned long u) {
	if (MIN(i, u) != i) {
		printf("failed test %d MIN(%ld, %ld): %lldLL == %lluULL != i == %ldL\n", __LINE__, i, u, MIN(i, u), MIN(i, u), i);
	}
	if (MIN(i, u) != u) {
		printf("failed test %d MIN(%ld, %ld): %lldLL == %lluULL != u == %luUL\n", __LINE__, i, u, MIN(i, u), MIN(i, u), u);
	}
	return 0;
}

int _test_MAX_equallong_equalulong(long i, unsigned long u) {
	if (MAX(i, u) != i) {
		printf("failed test %d MAX(%ld, %ld): %lldLL == %lluLLU != i == %ldL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), i);
	}
	if (MAX(i, u) != u) {
		printf("failed test %d MAX(%ld, %ld): %lldLL == %lluLLU != u == %luUL\n", __LINE__, i, u, MAX(i, u), MAX(i, u), u);
	}
	return 0;
}

int _test_MIN_hugeullong_hugerullong(unsigned long long u1, unsigned long long u2) {
	/*if (MIN(u1, u2) < 0) {
		printf("failed test %d as expected MIN(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2));
	}*/
	if (MIN(u1, u2) >= u2) {
		printf("failed test %d MIN(%lluULL, %lluULL): %lldLL == %lluULL >= u2 == %lluULL\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2), u2);
	}
	if (MIN(u1, u2) > u1) {
		printf("failed test %d MIN(%lluULL, %lluULL): %lldLL == %lluULL > u1 == %lluULL\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2), u1);
	}
	if (MIN(u1, u2) != u1) {
		printf("failed test %d MIN(%lluULL, %lluULL): %lldLL == %lluULL != u1 == %lluULL\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2), u1);
	}
	return 0;
}

int _test_MAX_hugeullong_hugerullong(unsigned long long u1, unsigned long long u2) {
	if (MAX(u1, u2) < 0) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2));
	}
	if (MAX(u1, u2) <= u1) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL <= u1 == %lluULL\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2), u1);
	}
	if (MAX(u1, u2) > u2) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL > u2 == %lluULL\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2), u2);
	}
	if (MAX(u1, u2) != u2) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL != u2 == %lluULL\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2), u2);
	}
	return 0;
}

int _test_MIN_hugerullong_hugeullong(unsigned long long u1, unsigned long long u2) {
	/*if (MIN(u1, u2) < 0) {
		printf("failed test %d as expected MIN(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2));
	}*/
	if (MIN(u1, u2) >= u1) {
		printf("failed test %d MIN(%lluULL, %lluULL): %lldLL == %lluULL >= u1 == %lluULL\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2), u1);
	}
	if (MIN(u1, u2) > u2) {
		printf("failed test %d MIN(%lluULL, %lluULL): %lldLL == %lluULL > u2 == %lluULL\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2), u2);
	}
	if (MIN(u1, u2) != u2) {
		printf("failed test %d MIN(%lluULL, %lluULL): %lldLL == %lluULL != u2 == %lluULL\n", __LINE__, u1, u2, MIN(u1, u2), MIN(u1, u2), u2);
	}
	return 0;
}

int _test_MAX_hugerullong_hugeullong(unsigned long long u1, unsigned long long u2) {
	if (MAX(u1, u2) < 0) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2));
	}
	if (MAX(u1, u2) <= u2) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL <= u2 == %lluULL\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2), u2);
	}
	if (MAX(u1, u2) > u1) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL > u1 == %lluULL\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2), u1);
	}
	if (MAX(u1, u2) != u1) {
		printf("failed test %d MAX(%lluULL, %lluULL): %lldLL == %lluULL != u1 == %lluULL\n", __LINE__, u1, u2, MAX(u1, u2), MAX(u1, u2), u1);
	}
	return 0;
}

int _test_various_MIN_smallerint_biggeruint() {
	_test_MIN_smallerint_biggeruint(-1, 0);
	_test_MIN_smallerint_biggeruint(-1, 1);
	_test_MIN_smallerint_biggeruint(-1, UINT_MAX);

	_test_MIN_smallerint_biggeruint(0, 1);
	_test_MIN_smallerint_biggeruint(0, 2);
	_test_MIN_smallerint_biggeruint(0, UINT_MAX);

	_test_MIN_smallerint_biggeruint(1, 2);
	_test_MIN_smallerint_biggeruint(1, 3);
	_test_MIN_smallerint_biggeruint(1, UINT_MAX);

	_test_MIN_smallerint_biggeruint(INT_MIN, 0);
	_test_MIN_smallerint_biggeruint(INT_MIN, 2);
	_test_MIN_smallerint_biggeruint(INT_MIN, UINT_MAX);
	_test_MIN_smallerint_biggeruint(INT_MIN, UINT_MIN);

	return 0;
}

int _test_various_MAX_smallerint_biggeruint() {
	_test_MAX_smallerint_biggeruint(-1, 0);
	_test_MAX_smallerint_biggeruint(-1, 1);
	_test_MAX_smallerint_biggeruint(-1, UINT_MAX);

	_test_MAX_smallerint_biggeruint(0, 1);
	_test_MAX_smallerint_biggeruint(0, 2);
	_test_MAX_smallerint_biggeruint(0, UINT_MAX);

	_test_MAX_smallerint_biggeruint(1, 2);
	_test_MAX_smallerint_biggeruint(1, 3);
	_test_MAX_smallerint_biggeruint(1, UINT_MAX);

	_test_MAX_smallerint_biggeruint(INT_MIN, 0);
	_test_MAX_smallerint_biggeruint(INT_MIN, 2);
	_test_MAX_smallerint_biggeruint(INT_MIN, UINT_MAX);
	_test_MAX_smallerint_biggeruint(INT_MIN, UINT_MIN);

	return 0;
}

int _test_various_MIN_smallerlong_biggerulong() {
	_test_MIN_smallerlong_biggerulong(-1, 0);
	_test_MIN_smallerlong_biggerulong(-1, 1);
	_test_MIN_smallerlong_biggerulong(-1, UINT_MAX);
	_test_MIN_smallerlong_biggerulong(-1, ULONG_MAX);

	_test_MIN_smallerlong_biggerulong(0, 1);
	_test_MIN_smallerlong_biggerulong(0, 2);
	_test_MIN_smallerlong_biggerulong(0, UINT_MAX);
	_test_MIN_smallerlong_biggerulong(0, ULONG_MAX);

	_test_MIN_smallerlong_biggerulong(1, 2);
	_test_MIN_smallerlong_biggerulong(1, 3);
	_test_MIN_smallerlong_biggerulong(1, UINT_MAX);
	_test_MIN_smallerlong_biggerulong(1, ULONG_MAX);

	_test_MIN_smallerlong_biggerulong(INT_MIN, 0);
	_test_MIN_smallerlong_biggerulong(INT_MIN, 2);
	_test_MIN_smallerlong_biggerulong(INT_MIN, UINT_MAX);
	_test_MIN_smallerlong_biggerulong(INT_MIN, ULONG_MAX);
	_test_MIN_smallerlong_biggerulong(INT_MIN, UINT_MIN);
	_test_MIN_smallerlong_biggerulong(INT_MIN, ULONG_MIN);

	_test_MIN_smallerlong_biggerulong(LONG_MIN, 0);
	_test_MIN_smallerlong_biggerulong(LONG_MIN, 2);
	_test_MIN_smallerlong_biggerulong(LONG_MIN, UINT_MAX);
	_test_MIN_smallerlong_biggerulong(LONG_MIN, ULONG_MAX);
	_test_MIN_smallerlong_biggerulong(LONG_MIN, UINT_MIN);
	_test_MIN_smallerlong_biggerulong(LONG_MIN, ULONG_MIN);

	return 0;
}

int _test_various_MAX_smallerlong_biggerulong() {
	_test_MAX_smallerlong_biggerulong(-1, 0);
	_test_MAX_smallerlong_biggerulong(-1, 1);
	_test_MAX_smallerlong_biggerulong(-1, UINT_MAX);
	_test_MAX_smallerlong_biggerulong(-1, ULONG_MAX);

	_test_MAX_smallerlong_biggerulong(0, 1);
	_test_MAX_smallerlong_biggerulong(0, 2);
	_test_MAX_smallerlong_biggerulong(0, UINT_MAX);
	_test_MAX_smallerlong_biggerulong(0, ULONG_MAX);

	_test_MAX_smallerlong_biggerulong(1, 2);
	_test_MAX_smallerlong_biggerulong(1, 3);
	_test_MAX_smallerlong_biggerulong(1, UINT_MAX);
	_test_MAX_smallerlong_biggerulong(1, ULONG_MAX);

	_test_MAX_smallerlong_biggerulong(INT_MIN, 0);
	_test_MAX_smallerlong_biggerulong(INT_MIN, 2);
	_test_MAX_smallerlong_biggerulong(INT_MIN, UINT_MAX);
	_test_MAX_smallerlong_biggerulong(INT_MIN, ULONG_MAX);
	_test_MAX_smallerlong_biggerulong(INT_MIN, UINT_MIN);
	_test_MAX_smallerlong_biggerulong(INT_MIN, ULONG_MIN);

	_test_MAX_smallerlong_biggerulong(LONG_MIN, 0);
	_test_MAX_smallerlong_biggerulong(LONG_MIN, 2);
	_test_MAX_smallerlong_biggerulong(LONG_MIN, UINT_MAX);
	_test_MAX_smallerlong_biggerulong(LONG_MIN, ULONG_MAX);
	_test_MAX_smallerlong_biggerulong(LONG_MIN, UINT_MIN);
	_test_MAX_smallerlong_biggerulong(LONG_MIN, ULONG_MIN);

	return 0;
}

int _test_various_MIN_biggerint_smalleruint() {
	_test_MIN_biggerint_smalleruint(1, 0);
	_test_MIN_biggerint_smalleruint(2, 0);
	_test_MIN_biggerint_smalleruint(INT_MAX, 0);

	_test_MIN_biggerint_smalleruint(3, 2);

	_test_MIN_biggerint_smalleruint(INT_MAX, INT_MAX-1);
	_test_MIN_biggerint_smalleruint(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MAX_biggerint_smalleruint() {
	_test_MAX_biggerint_smalleruint(1, 0);
	_test_MAX_biggerint_smalleruint(2, 0);
	_test_MAX_biggerint_smalleruint(INT_MAX, 0);

	_test_MAX_biggerint_smalleruint(3, 2);

	_test_MAX_biggerint_smalleruint(INT_MAX, INT_MAX-1);
	_test_MAX_biggerint_smalleruint(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_biggerlong_smallerulong() {
	_test_MIN_biggerlong_smallerulong(1, 0);
	_test_MIN_biggerlong_smallerulong(2, 0);
	_test_MIN_biggerlong_smallerulong(INT_MAX, 0);
	_test_MIN_biggerlong_smallerulong(LONG_MAX, 0);

	_test_MIN_biggerlong_smallerulong(3, 2);

	_test_MIN_biggerlong_smallerulong(LONG_MAX, LONG_MAX-1);
	_test_MIN_biggerlong_smallerulong(LONG_MAX-1, LONG_MAX-2);
	_test_MIN_biggerlong_smallerulong(INT_MAX, INT_MAX-1);
	_test_MIN_biggerlong_smallerulong(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MAX_biggerlong_smallerulong() {
	_test_MAX_biggerlong_smallerulong(1, 0);
	_test_MAX_biggerlong_smallerulong(2, 0);
	_test_MAX_biggerlong_smallerulong(INT_MAX, 0);
	_test_MAX_biggerlong_smallerulong(LONG_MAX, 0);

	_test_MAX_biggerlong_smallerulong(3, 2);

	_test_MAX_biggerlong_smallerulong(LONG_MAX, LONG_MAX-1);
	_test_MAX_biggerlong_smallerulong(LONG_MAX-1, LONG_MAX-2);
	_test_MAX_biggerlong_smallerulong(INT_MAX, INT_MAX-1);
	_test_MAX_biggerlong_smallerulong(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_biggerlong_smallerullong() {
	_test_MIN_biggerlong_smallerullong(1, 0);
	_test_MIN_biggerlong_smallerullong(2, 0);
	_test_MIN_biggerlong_smallerullong(INT_MAX, 0);
	_test_MIN_biggerlong_smallerullong(LONG_MAX, 0);

	_test_MIN_biggerlong_smallerullong(3, 2);

	_test_MIN_biggerlong_smallerullong(LONG_MAX, LONG_MAX-1);
	_test_MIN_biggerlong_smallerullong(LONG_MAX-1, LONG_MAX-2);
	_test_MIN_biggerlong_smallerullong(INT_MAX, INT_MAX-1);
	_test_MIN_biggerlong_smallerullong(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MAX_biggerlong_smallerullong() {
	_test_MAX_biggerlong_smallerullong(1, 0);
	_test_MAX_biggerlong_smallerullong(2, 0);
	_test_MAX_biggerlong_smallerullong(INT_MAX, 0);
	_test_MAX_biggerlong_smallerullong(LONG_MAX, 0);

	_test_MAX_biggerlong_smallerullong(3, 2);

	_test_MAX_biggerlong_smallerullong(LONG_MAX, LONG_MAX-1);
	_test_MAX_biggerlong_smallerullong(LONG_MAX-1, LONG_MAX-2);
	_test_MAX_biggerlong_smallerullong(INT_MAX, INT_MAX-1);
	_test_MAX_biggerlong_smallerullong(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_equalint_equaluint() {
	_test_MIN_equalint_equaluint(0, 0);
	_test_MIN_equalint_equaluint(1, 1);
	_test_MIN_equalint_equaluint(UINT_MIN, UINT_MIN);
	_test_MIN_equalint_equaluint(INT_MAX, INT_MAX);
	return 0;
}

int _test_various_MAX_equalint_equaluint() {
	_test_MAX_equalint_equaluint(0, 0);
	_test_MAX_equalint_equaluint(1, 1);
	_test_MAX_equalint_equaluint(UINT_MIN, UINT_MIN);
	_test_MAX_equalint_equaluint(INT_MAX, INT_MAX);
	return 0;
}

int _test_various_MIN_equallong_equalulong() {
	_test_MIN_equallong_equalulong(0, 0);
	_test_MIN_equallong_equalulong(1, 1);
	_test_MIN_equallong_equalulong(UINT_MIN, UINT_MIN);
	_test_MIN_equallong_equalulong(ULONG_MIN, ULONG_MIN);
	_test_MIN_equallong_equalulong(INT_MAX, INT_MAX);
	_test_MIN_equallong_equalulong(LONG_MAX, LONG_MAX);
	return 0;
}

int _test_various_MAX_equallong_equalulong() {
	_test_MAX_equallong_equalulong(0, 0);
	_test_MAX_equallong_equalulong(1, 1);
	_test_MAX_equallong_equalulong(UINT_MIN, UINT_MIN);
	_test_MAX_equallong_equalulong(ULONG_MIN, ULONG_MIN);
	_test_MAX_equallong_equalulong(INT_MAX, INT_MAX);
	_test_MAX_equallong_equalulong(LONG_MAX, LONG_MAX);
	return 0;
}

int _test_various_MIN_hugeullong_hugerullong() {
	_test_MIN_hugeullong_hugerullong(LLONG_MAX, LLONG_MAX+1LLU);
	_test_MIN_hugeullong_hugerullong(LLONG_MAX+1LLU, LLONG_MAX+2LLU);
	_test_MIN_hugeullong_hugerullong(ULLONG_MAX-1, ULLONG_MAX);

	return 0;
}

int _test_various_MAX_hugeullong_hugerullong() {
	_test_MAX_hugeullong_hugerullong(LLONG_MAX, LLONG_MAX+1LLU);
	_test_MAX_hugeullong_hugerullong(LLONG_MAX+1LLU, LLONG_MAX+2LLU);
	_test_MAX_hugeullong_hugerullong(ULLONG_MAX-1, ULLONG_MAX);

	return 0;
}

int _test_various_MIN_hugerullong_hugeullong() {
	_test_MIN_hugerullong_hugeullong(LLONG_MAX+1LLU, LLONG_MAX);
	_test_MIN_hugerullong_hugeullong(LLONG_MAX+2LLU, LLONG_MAX+1LLU);
	_test_MIN_hugerullong_hugeullong(ULLONG_MAX, ULLONG_MAX-1);

	return 0;
}

int _test_various_MAX_hugerullong_hugeullong() {
	_test_MAX_hugerullong_hugeullong(LLONG_MAX+1LLU, LLONG_MAX);
	_test_MAX_hugerullong_hugeullong(LLONG_MAX+2LLU, LLONG_MAX+1LLU);
	_test_MAX_hugerullong_hugeullong(ULLONG_MAX, ULLONG_MAX-1);

	return 0;
}

int _test_various_MIN_biggerulong_smallerint() {
	_test_MIN_biggerulong_smallerint(0, -1);

	return 0;
}

int _test_various_MIN_biggerullong_smallerint() {
	_test_MIN_biggerullong_smallerint(0, -1);

	return 0;
}

int _test_various_MAX_biggerulong_smallerint() {
	_test_MAX_biggerulong_smallerint(0, -1);

	return 0;
}

int _test_various_MAX_biggerullong_smallerint() {
	_test_MAX_biggerullong_smallerint(0, -1);

	return 0;
}

int test_MIN() {
	_test_various_MIN_smallerint_biggeruint();
	_test_various_MIN_smallerlong_biggerulong();
	_test_various_MIN_biggerint_smalleruint();
	_test_various_MIN_biggerlong_smallerulong();
	_test_various_MIN_biggerlong_smallerullong();
	_test_various_MIN_equalint_equaluint();
	_test_various_MIN_equallong_equalulong();
	_test_various_MIN_hugeullong_hugerullong();
	_test_various_MIN_hugerullong_hugeullong();
	_test_various_MIN_biggerulong_smallerint();
	_test_various_MIN_biggerullong_smallerint();
	return 0;
}

/** This test was designed to exercise each branch of the conditional expressions in _FASTER_MAX_SAFE, hence the name "transparentbox". */
int test_MAX_transparentbox() {
	signed char x = 0;
	signed char y = -1;
	unsigned long z = 0;
	signed char a = 1;
	unsigned long b = 2;
	/* 1, 1, x */
	if (MAX(x, y) != x) {
		printf("failed test %d MAX(%c, %c): %lldLL == %lluLLU != %c\n", __LINE__, x, y, MAX(x, y), MAX(x, y), x);
	}
	/* 1, 1, y */
	if (MAX(y, x) != x) {
		printf("failed test %d MAX(%c, %c): %lldLL == %lluLLU != %c\n", __LINE__, y, x, MAX(y, x), MAX(y, x), x);
	}
	/* 1, 0, 1 */
	if (MAX(y, z) != z) {
		printf("failed test %d MAX(%c, %luLU): %lldLL == %lluLLU != %luLU\n", __LINE__, y, z, MAX(y, z), MAX(y, z), z);
	}
	/* 1, 0, 0, x */
	if (MAX(a, z) != a) {
		printf("failed test %d MAX(%c, %luLU): %lldLL == %lluLLU != %c\n", __LINE__, a, z, MAX(a, z), MAX(a, z), a);
	}
	/* 1, 0, 0, y */
	if (MAX(a, b) != b) {
		printf("failed test %d MAX(%c, %luLU): %lldLL == %lluLLU != %luLU\n", __LINE__, a, b, MAX(a, b), MAX(a, b), b);
	}
	/* 0, 1, 1 */
	if (MAX(z, y) != z) {
		printf("failed test %d MAX(%luLU, %c): %lldLL == %lluLLU != %luLU\n", __LINE__, z, y, MAX(z, y), MAX(z, y), z);
	}
	/* 0, 1, 0, x */
	if (MAX(b, a) != b) {
		printf("failed test %d MAX(%luLU, %c): %lldLL == %lluLLU != %luLU\n", __LINE__, b, a, MAX(b, a), MAX(b, a), b);
	}
	/* 0, 1, 0, y */
	if (MAX(z, a) != a) {
		printf("failed test %d MAX(%luLU, %c): %lldLL == %lluLLU != %c\n", __LINE__, z, a, MAX(z, a), MAX(z, a), a);
	}
	/* 0, 0, x */
	if (MAX(b, z) != b) {
		printf("failed test %d MAX(%luLU, %luLU): %lldLL == %lluLLU != %luLU\n", __LINE__, b, z, MAX(b, z), MAX(b, z), b);
	}
	/* 0, 0, y */
	if (MAX(z, b) != b) {
		printf("failed test %d MAX(%luLU, %luLU): %lldLL == %lluLLU != %luLU\n", __LINE__, z, b, MAX(z, b), MAX(z, b), b);
	}
	return 0;
}

void test_MAX() {
	test_MAX_transparentbox();
	_test_various_MAX_smallerint_biggeruint();
	_test_various_MAX_smallerlong_biggerulong();
	_test_various_MAX_biggerint_smalleruint();
	_test_various_MAX_biggerlong_smallerulong();
	_test_various_MAX_biggerlong_smallerullong();
	_test_various_MAX_equalint_equaluint();
	_test_various_MAX_equallong_equalulong();
	_test_various_MAX_hugeullong_hugerullong();
	_test_various_MAX_hugerullong_hugeullong();
	_test_various_MAX_biggerulong_smallerint();
	_test_various_MAX_biggerullong_smallerint();
}

void test_exhausterr()
{
	CHECKMALLOC((const char*const)malloc(UINT_MAX));
}

int test_morelimits()
{
	assert (TIME_T_MAX > TIME_T_MIN);
	assert (SIZE_T_MAX > SIZE_T_MIN);

	assert (Z_ULLONG_MAX == ULLONG_MAX);
	assert (Z_ULONG_MAX == ULONG_MAX);
	assert (Z_UINT_MAX == UINT_MAX);
	assert (Z_USHRT_MAX == USHRT_MAX);
	assert (Z_UCHAR_MAX == UCHAR_MAX);
	assert (Z_LLONG_MAX == LLONG_MAX);
	assert (Z_LONG_MAX == LONG_MAX);
	assert (Z_INT_MAX == INT_MAX);
	assert (Z_SHRT_MAX == SHRT_MAX);
	assert (Z_CHAR_MAX == CHAR_MAX);
	assert (Z_LLONG_MIN == LLONG_MIN);
	assert (Z_LONG_MIN == LONG_MIN);
	assert (Z_INT_MIN == INT_MIN);
	assert (Z_SHRT_MIN == SHRT_MIN);
	assert (Z_CHAR_MIN == CHAR_MIN);
	assert (Z_SCHAR_MAX == SCHAR_MAX);
	assert (Z_SCHAR_MIN == SCHAR_MIN);
	return 0;
}

void print_morelimits() {
	printf("Z_MAX_UNSIGNED(unsigned char): %40u\n", Z_MAX_UNSIGNED(unsigned char));
	printf("Z_MAX_SIGNED(char):            %40d\n", Z_MAX_SIGNED(char));
	printf("SIZE_T_MAX:                    %40u\n", SIZE_T_MAX);
	printf("SIZE_T_MIN:                    %40u\n", SIZE_T_MIN);
	printf("TIME_T_MAX:                    %40ld\n", TIME_T_MAX);
	printf("TIME_T_MIN:                    %40ld\n", TIME_T_MIN);
	printf("\n");
	printf("UCHAR_MAX:                     %40u\n", UCHAR_MAX);
	printf("Z_UCHAR_MAX:                   %40u\n", Z_UCHAR_MAX);
	printf("\n");
	printf("USHRT_MAX:                     %40u\n", USHRT_MAX);
	printf("Z_USHRT_MAX:                   %40u\n", Z_USHRT_MAX);
	printf("\n");
	printf("UINT_MAX:                      %40u\n", UINT_MAX);
	printf("Z_UINT_MAX:                    %40u\n", Z_UINT_MAX);
	printf("\n");
	printf("ULONG_MAX:                     %40lu\n", ULONG_MAX);
	printf("Z_ULONG_MAX:                   %40lu\n", Z_ULONG_MAX);
	printf("\n");
	printf("ULLONG_MAX:                    %40llu\n", ULLONG_MAX);
	printf("Z_ULLONG_MAX:                  %40llu\n", Z_ULLONG_MAX);
	printf("\n");
	printf("UCHAR_MIN:                     %40u\n", UCHAR_MIN);
	printf("USHRT_MIN:                     %40u\n", USHRT_MIN);
	printf("UINT_MIN:                      %40u\n", UINT_MIN);
	printf("ULONG_MIN:                     %40lu\n", ULONG_MIN);
	printf("ULLONG_MIN:                    %40llu\n", ULLONG_MIN);
	printf("\n");
	printf("CHAR_MAX:                      %40d\n", CHAR_MAX);
	printf("Z_CHAR_MAX:                    %40d\n", Z_CHAR_MAX);
	printf("\n");
	printf("SHRT_MAX:                      %40d\n", SHRT_MAX);
	printf("Z_SHRT_MAX:                    %40d\n", Z_SHRT_MAX);
	printf("\n");
	printf("INT_MAX:                       %40d\n", INT_MAX);
	printf("Z_INT_MAX:                     %40d\n", Z_INT_MAX);
	printf("\n");
	printf("LONG_MAX:                      %40ld\n", LONG_MAX);
	printf("Z_LONG_MAX:                    %40ld\n", Z_LONG_MAX);
	printf("\n");
	printf("LLONG_MAX:                     %40lld\n", LLONG_MAX);
	printf("Z_LLONG_MAX:                   %40lld\n", Z_LLONG_MAX);
	printf("\n");
	printf("CHAR_MIN:                      %40d\n", CHAR_MIN);
	printf("Z_CHAR_MIN:                    %40d\n", Z_CHAR_MIN);
	printf("\n");
	printf("SHRT_MIN:                      %40d\n", SHRT_MIN);
	printf("Z_SHRT_MIN:                    %40d\n", Z_SHRT_MIN);
	printf("\n");
	printf("INT_MIN:                       %40d\n", INT_MIN);
	printf("Z_INT_MIN:                     %40d\n", Z_INT_MIN);
	printf("\n");
	printf("LONG_MIN:                      %40ld\n", LONG_MIN);
	printf("Z_LONG_MIN:                    %40ld\n", Z_LONG_MIN);
	printf("\n");
	printf("LLONG_MIN:                     %40lld\n", LLONG_MIN);
	printf("Z_LLONG_MIN:                   %40lld\n", Z_LLONG_MIN);
}

int test() {
	/*print_morelimits();*/
	test_FITS_INTO_SIGNED_INT();
	test_PROMOTES_TO_SIGNED_TYPE();
	test_overflow();
	test_morelimits();
	/*test_MIN_crazybadargs();*/
	test_MIN();
	test_MAX();
	test_minmax_fast();
	/*test_exhausterr();*/
	return 0;
}

int bench() {
	int i;
	for (i=0; i<20000000;i++) {
		test_MAX();
	}
	return 0;
}

int main(int argv, char**argc) {
	return test();
}

