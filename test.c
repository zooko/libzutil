#undef NDEBUG

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

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

int test_OPERAND_IS_SIGNED()
{
	/*printf("OPERAND_IS_SIGNED(0U): %d\n", OPERAND_IS_SIGNED(0U));*/
	assert (!OPERAND_IS_SIGNED(0U));
	/*printf("OPERAND_IS_SIGNED(1U): %d\n", OPERAND_IS_SIGNED(1U));*/
	assert (!OPERAND_IS_SIGNED(1U));
	/*printf("OPERAND_IS_SIGNED(2U): %d\n", OPERAND_IS_SIGNED(2U));*/
	assert (!OPERAND_IS_SIGNED(2U));
	/*printf("OPERAND_IS_SIGNED(-1U): %d\n", OPERAND_IS_SIGNED(-1U));*/
	assert (!OPERAND_IS_SIGNED(-1U));
	/*printf("OPERAND_IS_SIGNED(-2U): %d\n", OPERAND_IS_SIGNED(-2U));*/
	assert (!OPERAND_IS_SIGNED(-2U));
	/*printf("OPERAND_IS_SIGNED((unsigned int)0): %d\n", OPERAND_IS_SIGNED((unsigned int)0));*/
	assert (!OPERAND_IS_SIGNED((unsigned int)0));
	/*printf("OPERAND_IS_SIGNED((unsigned int)1): %d\n", OPERAND_IS_SIGNED((unsigned int)1));*/
	assert (!OPERAND_IS_SIGNED((unsigned int)1));
	/*printf("OPERAND_IS_SIGNED((unsigned int)2): %d\n", OPERAND_IS_SIGNED((unsigned int)2));*/
	assert (!OPERAND_IS_SIGNED((unsigned int)2));
	/*printf("OPERAND_IS_SIGNED((unsigned int)-1): %d\n", OPERAND_IS_SIGNED((unsigned int)-1));*/
	assert (!OPERAND_IS_SIGNED((unsigned int)-1));
	/*printf("OPERAND_IS_SIGNED((unsigned int)-2): %d\n", OPERAND_IS_SIGNED((unsigned int)-2));*/
	assert (!OPERAND_IS_SIGNED((unsigned int)-2));

	/*printf("OPERAND_IS_SIGNED(0): %d\n", OPERAND_IS_SIGNED(0));*/
	assert (OPERAND_IS_SIGNED(0));
	/*printf("OPERAND_IS_SIGNED(1): %d\n", OPERAND_IS_SIGNED(1));*/
	assert (OPERAND_IS_SIGNED(1));
	/*printf("OPERAND_IS_SIGNED(2): %d\n", OPERAND_IS_SIGNED(2));*/
	assert (OPERAND_IS_SIGNED(2));
	/*printf("OPERAND_IS_SIGNED(-1): %d\n", OPERAND_IS_SIGNED(-1));*/
	assert (OPERAND_IS_SIGNED(-1));
	/*printf("OPERAND_IS_SIGNED(-2): %d\n", OPERAND_IS_SIGNED(-2));*/
	assert (OPERAND_IS_SIGNED(-2));
	/*printf("OPERAND_IS_SIGNED((signed int)0): %d\n", OPERAND_IS_SIGNED((signed int)0));*/
	assert (OPERAND_IS_SIGNED((signed int)0));
	/*printf("OPERAND_IS_SIGNED((signed int)1): %d\n", OPERAND_IS_SIGNED((signed int)1));*/
	assert (OPERAND_IS_SIGNED((signed int)1));
	/*printf("OPERAND_IS_SIGNED((signed int)2): %d\n", OPERAND_IS_SIGNED((signed int)2));*/
	assert (OPERAND_IS_SIGNED((signed int)2));
	/*printf("OPERAND_IS_SIGNED((signed int)-1): %d\n", OPERAND_IS_SIGNED((signed int)-1));*/
	assert (OPERAND_IS_SIGNED((signed int)-1));
	/*printf("OPERAND_IS_SIGNED((signed int)-2): %d\n", OPERAND_IS_SIGNED((signed int)-2));*/
	assert (OPERAND_IS_SIGNED((signed int)-2));
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

	return 1;
}

/* If this test is commented-in, it will ideally give compile-time errors!
int test_minmax_flexible_crazybadargs()
{
	char b[10];
	int z = 1;
	_MIN_LLS(b, z);
}
*/

int test_minmax_fast()
{
	unsigned int unsignedthree = 3;
	int negone = -1;
	if (_MIN_FAST(unsignedthree, negone) != -1) {
		printf("failed test _MIN_FAST(%uU, %d) != %d\n", unsignedthree, negone, -1);
		return -1;
	}
	return 0;
}

int test_gcc_ifexpr()
{
	int i;
	unsigned int u;
	const typeof(1>0?i:u) _res = 1>0?i:u;
	const typeof(u) _u = u;
	/* Now by ANSI C rules, the expression `1>0?i:u' must have typed unsigned int! */
	if (&_res==&_u) {
		/* That `==' is just to elicit a compiler error if they are of different types... */
		return 2;
	}
	return 0;
}

int _test_MIN_LLS_smallerint_biggeruint(int i, unsigned u) {
	if (_MIN_LLS(i, u) >= u) {
		printf("failed test _MIN_LLS(%d, %uU): %lldLL == %lluULL >= u == %uU\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	if (_MIN_LLS(i, u) > i) {
		printf("failed test _MIN_LLS(%d, %uU): %lldLL == %lluULL > i == %d\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	if (_MIN_LLS(i, u) != i) {
		printf("failed test _MIN_LLS(%d, %uU): %lldLL == %lluULL != i == %d\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_smallerlong_biggerulong(long i, unsigned long u) {
	if (_MIN_LLS(i, u) >= u) {
		printf("failed test _MIN_LLS(%ld, %lu): %lldLL == %lluULL >= u == %lu\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	if (_MIN_LLS(i, u) > i) {
		printf("failed test _MIN_LLS(%ld, %lu): %lldLL == %lluULL > i == %ld\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	if (_MIN_LLS(i, u) != i) {
		printf("failed test _MIN_LLS(%ld, %lu): %lldLL == %lluULL != i == %ld\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_biggerint_smalleruint(int i, unsigned u) {
	if (_MIN_LLS(i, u) >= i) {
		printf("failed test _MIN_LLS(%d, %uU): %lldLL == %lluULL >= i == %d\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	if (_MIN_LLS(i, u) > u) {
		printf("failed test _MIN_LLS(%d, %d): %lldLL == %lluULL > u == %uU\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	if (_MIN_LLS(i, u) != u) {
		printf("failed test _MIN_LLS(%d, %d): %lldLL == %lluULL != u == %uU\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_biggerullong_smallerint(unsigned long long u, int i) {
	if (_MIN_LLS(u, i) != i) {
		printf("failed test _MIN_LLS(%lluULL, %d): %lldLL == %lluULL != i == %uU\n", u, i, _MIN_LLS(u, i), _MIN_LLS(u, i), i);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_biggerlong_smallerulong(long i, unsigned long u) {
	if (_MIN_LLS(i, u) >= i) {
		printf("failed test _MIN_LLS(%ld, %lu): %lldLL == %lluULL >= i == %ld\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	if (_MIN_LLS(i, u) > u) {
		printf("failed test _MIN_LLS(%ld, %ld): %lldLL == %lluULL > u == %lu\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	if (_MIN_LLS(i, u) != u) {
		printf("failed test _MIN_LLS(%ld, %ld): %lldLL == %lluULL != u == %lu\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_equalint_equaluint(int i, unsigned u) {
	if (_MIN_LLS(i, u) != i) {
		printf("failed test _MIN_LLS(%d, %d): %lldLL == %lluULL != i == %d\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	if (_MIN_LLS(i, u) != u) {
		printf("failed test _MIN_LLS(%d, %d): %lldLL == %lluULL != u == %uU\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_equallong_equalulong(long i, unsigned long u) {
	if (_MIN_LLS(i, u) != i) {
		printf("failed test _MIN_LLS(%ld, %ld): %lldLL == %lluULL != i == %ld\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), i);
		return -1;
	}
	if (_MIN_LLS(i, u) != u) {
		printf("failed test _MIN_LLS(%ld, %ld): %lldLL == %lluULL != u == %lu\n", i, u, _MIN_LLS(i, u), _MIN_LLS(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_hugeullong_hugerullong(unsigned long long u1, unsigned long long u2) {
	if (_MIN_LLS(u1, u2) < 0) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2));
		return -1;
	}
	if (_MIN_LLS(u1, u2) >= u2) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL >= u2 == %lluULL\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2), u2);
		return -1;
	}
	if (_MIN_LLS(u1, u2) > u1) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL > u1 == %lluULL\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2), u1);
		return -1;
	}
	if (_MIN_LLS(u1, u2) != u1) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL != u1 == %lluULL\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2), u1);
		return -1;
	}
	return 0;
}

int _test_MIN_LLS_hugerullong_hugeullong(unsigned long long u1, unsigned long long u2) {
	if (_MIN_LLS(u1, u2) < 0) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2));
		return -1;
	}
	if (_MIN_LLS(u1, u2) >= u1) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL >= u1 == %lluULL\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2), u1);
		return -1;
	}
	if (_MIN_LLS(u1, u2) > u2) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL > u2 == %lluULL\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2), u2);
		return -1;
	}
	if (_MIN_LLS(u1, u2) != u2) {
		printf("failed test _MIN_LLS(%lluULL, %lluULL): %lldLL == %lluULL != u2 == %lluULL\n", u1, u2, _MIN_LLS(u1, u2), _MIN_LLS(u1, u2), u2);
		return -1;
	}
	return 0;
}

int _test_various_MIN_LLS_smallerint_biggeruint() {
	_test_MIN_LLS_smallerint_biggeruint(-1, 0);
	_test_MIN_LLS_smallerint_biggeruint(-1, 1);
	_test_MIN_LLS_smallerint_biggeruint(-1, UINT_MAX);

	_test_MIN_LLS_smallerint_biggeruint(0, 1);
	_test_MIN_LLS_smallerint_biggeruint(0, 2);
	_test_MIN_LLS_smallerint_biggeruint(0, UINT_MAX);

	_test_MIN_LLS_smallerint_biggeruint(1, 2);
	_test_MIN_LLS_smallerint_biggeruint(1, 3);
	_test_MIN_LLS_smallerint_biggeruint(1, UINT_MAX);

	_test_MIN_LLS_smallerint_biggeruint(INT_MIN, 0);
	_test_MIN_LLS_smallerint_biggeruint(INT_MIN, 2);
	_test_MIN_LLS_smallerint_biggeruint(INT_MIN, UINT_MAX);
	_test_MIN_LLS_smallerint_biggeruint(INT_MIN, UINT_MIN);

	return 0;
}

int _test_various_MIN_LLS_smallerlong_biggerulong() {
	_test_MIN_LLS_smallerlong_biggerulong(-1, 0);
	_test_MIN_LLS_smallerlong_biggerulong(-1, 1);
	_test_MIN_LLS_smallerlong_biggerulong(-1, UINT_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(-1, ULONG_MAX);

	_test_MIN_LLS_smallerlong_biggerulong(0, 1);
	_test_MIN_LLS_smallerlong_biggerulong(0, 2);
	_test_MIN_LLS_smallerlong_biggerulong(0, UINT_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(0, ULONG_MAX);

	_test_MIN_LLS_smallerlong_biggerulong(1, 2);
	_test_MIN_LLS_smallerlong_biggerulong(1, 3);
	_test_MIN_LLS_smallerlong_biggerulong(1, UINT_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(1, ULONG_MAX);

	_test_MIN_LLS_smallerlong_biggerulong(INT_MIN, 0);
	_test_MIN_LLS_smallerlong_biggerulong(INT_MIN, 2);
	_test_MIN_LLS_smallerlong_biggerulong(INT_MIN, UINT_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(INT_MIN, ULONG_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(INT_MIN, UINT_MIN);
	_test_MIN_LLS_smallerlong_biggerulong(INT_MIN, ULONG_MIN);

	_test_MIN_LLS_smallerlong_biggerulong(LONG_MIN, 0);
	_test_MIN_LLS_smallerlong_biggerulong(LONG_MIN, 2);
	_test_MIN_LLS_smallerlong_biggerulong(LONG_MIN, UINT_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(LONG_MIN, ULONG_MAX);
	_test_MIN_LLS_smallerlong_biggerulong(LONG_MIN, UINT_MIN);
	_test_MIN_LLS_smallerlong_biggerulong(LONG_MIN, ULONG_MIN);

	return 0;
}

int _test_various_MIN_LLS_biggerint_smalleruint() {
	_test_MIN_LLS_biggerint_smalleruint(1, 0);
	_test_MIN_LLS_biggerint_smalleruint(2, 0);
	_test_MIN_LLS_biggerint_smalleruint(INT_MAX, 0);

	_test_MIN_LLS_biggerint_smalleruint(3, 2);

	_test_MIN_LLS_biggerint_smalleruint(INT_MAX, INT_MAX-1);
	_test_MIN_LLS_biggerint_smalleruint(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_LLS_biggerlong_smallerulong() {
	_test_MIN_LLS_biggerlong_smallerulong(1, 0);
	_test_MIN_LLS_biggerlong_smallerulong(2, 0);
	_test_MIN_LLS_biggerlong_smallerulong(INT_MAX, 0);
	_test_MIN_LLS_biggerlong_smallerulong(LONG_MAX, 0);

	_test_MIN_LLS_biggerlong_smallerulong(3, 2);

	_test_MIN_LLS_biggerlong_smallerulong(LONG_MAX, LONG_MAX-1);
	_test_MIN_LLS_biggerlong_smallerulong(LONG_MAX-1, LONG_MAX-2);
	_test_MIN_LLS_biggerlong_smallerulong(INT_MAX, INT_MAX-1);
	_test_MIN_LLS_biggerlong_smallerulong(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_LLS_equalint_equaluint() {
	_test_MIN_LLS_equalint_equaluint(0, 0);
	_test_MIN_LLS_equalint_equaluint(1, 1);
	_test_MIN_LLS_equalint_equaluint(UINT_MIN, UINT_MIN);
	_test_MIN_LLS_equalint_equaluint(INT_MAX, INT_MAX);
	return 0;
}

int _test_various_MIN_LLS_equallong_equalulong() {
	_test_MIN_LLS_equallong_equalulong(0, 0);
	_test_MIN_LLS_equallong_equalulong(1, 1);
	_test_MIN_LLS_equallong_equalulong(UINT_MIN, UINT_MIN);
	_test_MIN_LLS_equallong_equalulong(ULONG_MIN, ULONG_MIN);
	_test_MIN_LLS_equallong_equalulong(INT_MAX, INT_MAX);
	_test_MIN_LLS_equallong_equalulong(LONG_MAX, LONG_MAX);
	return 0;
}

int _test_various_MIN_LLS_hugeullong_hugerullong() {
	_test_MIN_LLS_hugeullong_hugerullong(LLONG_MAX, LLONG_MAX+1LLU);
	_test_MIN_LLS_hugeullong_hugerullong(LLONG_MAX+1LLU, LLONG_MAX+2LLU);
	_test_MIN_LLS_hugeullong_hugerullong(ULLONG_MAX-1, ULLONG_MAX);

	return 0;
}

int _test_various_MIN_LLS_hugerullong_hugeullong() {
	_test_MIN_LLS_hugerullong_hugeullong(LLONG_MAX+1LLU, LLONG_MAX);
	_test_MIN_LLS_hugerullong_hugeullong(LLONG_MAX+2LLU, LLONG_MAX+1LLU);
	_test_MIN_LLS_hugerullong_hugeullong(ULLONG_MAX, ULLONG_MAX-1);

	return 0;
}

int _test_various_MIN_LLS_biggerullong_smallerint() {
	_test_MIN_LLS_biggerullong_smallerint(0, -1);

	return 0;
}

int test_MIN_LLS() {
	_test_various_MIN_LLS_smallerint_biggeruint();
	_test_various_MIN_LLS_smallerlong_biggerulong();
	_test_various_MIN_LLS_biggerint_smalleruint();
	_test_various_MIN_LLS_biggerlong_smallerulong();
	_test_various_MIN_LLS_equalint_equaluint();
	_test_various_MIN_LLS_equallong_equalulong();
	//	_test_various_MIN_LLS_hugeullong_hugerullong();
	//	_test_various_MIN_LLS_hugerullong_hugeullong();
	_test_various_MIN_LLS_biggerullong_smallerint();
	return 0;
}

int _test_MIN_LLU_smallerint_biggeruint(int i, unsigned u) {
	if (_MIN_LLU(i, u) >= u) {
		printf("failed test _MIN_LLU(%d, %uU): %lldLL == %lluULL >= u == %uU\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	if (_MIN_LLU(i, u) > i) {
		printf("failed test _MIN_LLU(%d, %uU): %lldLL == %lluULL > i == %d\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	if (_MIN_LLU(i, u) != i) {
		printf("failed test _MIN_LLU(%d, %uU): %lldLL == %lluULL != i == %d\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_smallerlong_biggerulong(long i, unsigned long u) {
	if (_MIN_LLU(i, u) >= u) {
		printf("failed test _MIN_LLU(%ld, %lu): %lldLL == %lluULL >= u == %lu\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	if (_MIN_LLU(i, u) > i) {
		printf("failed test _MIN_LLU(%ld, %lu): %lldLL == %lluULL > i == %ld\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	if (_MIN_LLU(i, u) != i) {
		printf("failed test _MIN_LLU(%ld, %lu): %lldLL == %lluULL != i == %ld\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_biggerint_smalleruint(int i, unsigned u) {
	if (_MIN_LLU(i, u) >= i) {
		printf("failed test _MIN_LLU(%d, %uU): %lldLL == %lluULL >= i == %d\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	if (_MIN_LLU(i, u) > u) {
		printf("failed test _MIN_LLU(%d, %d): %lldLL == %lluULL > u == %uU\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	if (_MIN_LLU(i, u) != u) {
		printf("failed test _MIN_LLU(%d, %d): %lldLL == %lluULL != u == %uU\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_biggerullong_smallerint(unsigned long long u, int i) {
	if (_MIN_LLU(u, i) != i) {
		printf("failed test _MIN_LLU(%lluULL, %d): %lldLL == %lluULL != i == %d\n", u, i, _MIN_LLU(u, i), _MIN_LLU(u, i), i);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_biggerlong_smallerulong(long i, unsigned long u) {
	if (_MIN_LLU(i, u) >= i) {
		printf("failed test _MIN_LLU(%ld, %lu): %lldLL == %lluULL >= i == %ld\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	if (_MIN_LLU(i, u) > u) {
		printf("failed test _MIN_LLU(%ld, %ld): %lldLL == %lluULL > u == %lu\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	if (_MIN_LLU(i, u) != u) {
		printf("failed test _MIN_LLU(%ld, %ld): %lldLL == %lluULL != u == %lu\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_equalint_equaluint(int i, unsigned u) {
	if (_MIN_LLU(i, u) != i) {
		printf("failed test _MIN_LLU(%d, %d): %lldLL == %lluULL != i == %d\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	if (_MIN_LLU(i, u) != u) {
		printf("failed test _MIN_LLU(%d, %d): %lldLL == %lluULL != u == %uU\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_equallong_equalulong(long i, unsigned long u) {
	if (_MIN_LLU(i, u) != i) {
		printf("failed test _MIN_LLU(%ld, %ld): %lldLL == %lluULL != i == %ld\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), i);
		return -1;
	}
	if (_MIN_LLU(i, u) != u) {
		printf("failed test _MIN_LLU(%ld, %ld): %lldLL == %lluULL != u == %lu\n", i, u, _MIN_LLU(i, u), _MIN_LLU(i, u), u);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_hugeullong_hugerullong(unsigned long long u1, unsigned long long u2) {
	if (_MIN_LLU(u1, u2) < 0) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2));
		return -1;
	}
	if (_MIN_LLU(u1, u2) >= u2) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL >= u2 == %lluULL\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2), u2);
		return -1;
	}
	if (_MIN_LLU(u1, u2) > u1) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL > u1 == %lluULL\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2), u1);
		return -1;
	}
	if (_MIN_LLU(u1, u2) != u1) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL != u1 == %lluULL\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2), u1);
		return -1;
	}
	return 0;
}

int _test_MIN_LLU_hugerullong_hugeullong(unsigned long long u1, unsigned long long u2) {
	if (_MIN_LLU(u1, u2) < 0) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL < 0\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2));
		return -1;
	}
	if (_MIN_LLU(u1, u2) >= u1) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL >= u1 == %lluULL\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2), u1);
		return -1;
	}
	if (_MIN_LLU(u1, u2) > u2) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL > u2 == %lluULL\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2), u2);
		return -1;
	}
	if (_MIN_LLU(u1, u2) != u2) {
		printf("failed test _MIN_LLU(%lluULL, %lluULL): %lldLL == %lluULL != u2 == %lluULL\n", u1, u2, _MIN_LLU(u1, u2), _MIN_LLU(u1, u2), u2);
		return -1;
	}
	return 0;
}

int _test_various_MIN_LLU_smallerint_biggeruint() {
	_test_MIN_LLU_smallerint_biggeruint(-1, 0);
	_test_MIN_LLU_smallerint_biggeruint(-1, 1);
	_test_MIN_LLU_smallerint_biggeruint(-1, UINT_MAX);

	_test_MIN_LLU_smallerint_biggeruint(0, 1);
	_test_MIN_LLU_smallerint_biggeruint(0, 2);
	_test_MIN_LLU_smallerint_biggeruint(0, UINT_MAX);

	_test_MIN_LLU_smallerint_biggeruint(1, 2);
	_test_MIN_LLU_smallerint_biggeruint(1, 3);
	_test_MIN_LLU_smallerint_biggeruint(1, UINT_MAX);

	_test_MIN_LLU_smallerint_biggeruint(INT_MIN, 0);
	_test_MIN_LLU_smallerint_biggeruint(INT_MIN, 2);
	_test_MIN_LLU_smallerint_biggeruint(INT_MIN, UINT_MAX);
	_test_MIN_LLU_smallerint_biggeruint(INT_MIN, UINT_MIN);

	return 0;
}

int _test_various_MIN_LLU_smallerlong_biggerulong() {
	_test_MIN_LLU_smallerlong_biggerulong(-1, 0);
	_test_MIN_LLU_smallerlong_biggerulong(-1, 1);
	_test_MIN_LLU_smallerlong_biggerulong(-1, UINT_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(-1, ULONG_MAX);

	_test_MIN_LLU_smallerlong_biggerulong(0, 1);
	_test_MIN_LLU_smallerlong_biggerulong(0, 2);
	_test_MIN_LLU_smallerlong_biggerulong(0, UINT_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(0, ULONG_MAX);

	_test_MIN_LLU_smallerlong_biggerulong(1, 2);
	_test_MIN_LLU_smallerlong_biggerulong(1, 3);
	_test_MIN_LLU_smallerlong_biggerulong(1, UINT_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(1, ULONG_MAX);

	_test_MIN_LLU_smallerlong_biggerulong(INT_MIN, 0);
	_test_MIN_LLU_smallerlong_biggerulong(INT_MIN, 2);
	_test_MIN_LLU_smallerlong_biggerulong(INT_MIN, UINT_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(INT_MIN, ULONG_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(INT_MIN, UINT_MIN);
	_test_MIN_LLU_smallerlong_biggerulong(INT_MIN, ULONG_MIN);

	_test_MIN_LLU_smallerlong_biggerulong(LONG_MIN, 0);
	_test_MIN_LLU_smallerlong_biggerulong(LONG_MIN, 2);
	_test_MIN_LLU_smallerlong_biggerulong(LONG_MIN, UINT_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(LONG_MIN, ULONG_MAX);
	_test_MIN_LLU_smallerlong_biggerulong(LONG_MIN, UINT_MIN);
	_test_MIN_LLU_smallerlong_biggerulong(LONG_MIN, ULONG_MIN);

	return 0;
}

int _test_various_MIN_LLU_biggerint_smalleruint() {
	_test_MIN_LLU_biggerint_smalleruint(1, 0);
	_test_MIN_LLU_biggerint_smalleruint(2, 0);
	_test_MIN_LLU_biggerint_smalleruint(INT_MAX, 0);

	_test_MIN_LLU_biggerint_smalleruint(3, 2);

	_test_MIN_LLU_biggerint_smalleruint(INT_MAX, INT_MAX-1);
	_test_MIN_LLU_biggerint_smalleruint(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_LLU_biggerlong_smallerulong() {
	_test_MIN_LLU_biggerlong_smallerulong(1, 0);
	_test_MIN_LLU_biggerlong_smallerulong(2, 0);
	_test_MIN_LLU_biggerlong_smallerulong(INT_MAX, 0);
	_test_MIN_LLU_biggerlong_smallerulong(LONG_MAX, 0);

	_test_MIN_LLU_biggerlong_smallerulong(3, 2);

	_test_MIN_LLU_biggerlong_smallerulong(LONG_MAX, LONG_MAX-1);
	_test_MIN_LLU_biggerlong_smallerulong(LONG_MAX-1, LONG_MAX-2);
	_test_MIN_LLU_biggerlong_smallerulong(INT_MAX, INT_MAX-1);
	_test_MIN_LLU_biggerlong_smallerulong(INT_MAX-1, INT_MAX-2);

	return 0;
}

int _test_various_MIN_LLU_equalint_equaluint() {
	_test_MIN_LLU_equalint_equaluint(0, 0);
	_test_MIN_LLU_equalint_equaluint(1, 1);
	_test_MIN_LLU_equalint_equaluint(UINT_MIN, UINT_MIN);
	_test_MIN_LLU_equalint_equaluint(INT_MAX, INT_MAX);
	return 0;
}

int _test_various_MIN_LLU_equallong_equalulong() {
	_test_MIN_LLU_equallong_equalulong(0, 0);
	_test_MIN_LLU_equallong_equalulong(1, 1);
	_test_MIN_LLU_equallong_equalulong(UINT_MIN, UINT_MIN);
	_test_MIN_LLU_equallong_equalulong(ULONG_MIN, ULONG_MIN);
	_test_MIN_LLU_equallong_equalulong(INT_MAX, INT_MAX);
	_test_MIN_LLU_equallong_equalulong(LONG_MAX, LONG_MAX);
	return 0;
}

int _test_various_MIN_LLU_hugeullong_hugerullong() {
	_test_MIN_LLU_hugeullong_hugerullong(LLONG_MAX, LLONG_MAX+1LLU);
	_test_MIN_LLU_hugeullong_hugerullong(LLONG_MAX+1LLU, LLONG_MAX+2LLU);
	_test_MIN_LLU_hugeullong_hugerullong(ULLONG_MAX-1, ULLONG_MAX);

	return 0;
}

int _test_various_MIN_LLU_hugerullong_hugeullong() {
	_test_MIN_LLU_hugerullong_hugeullong(LLONG_MAX+1LLU, LLONG_MAX);
	_test_MIN_LLU_hugerullong_hugeullong(LLONG_MAX+2LLU, LLONG_MAX+1LLU);
	_test_MIN_LLU_hugerullong_hugeullong(ULLONG_MAX, ULLONG_MAX-1);

	return 0;
}

int _test_various_MIN_LLU_biggerullong_smallerint() {
	_test_MIN_LLU_biggerullong_smallerint(0, -1);

	return 0;
}

int test_MIN_LLU() {
	_test_various_MIN_LLU_smallerint_biggeruint();
	_test_various_MIN_LLU_smallerlong_biggerulong();
	_test_various_MIN_LLU_biggerint_smalleruint();
	_test_various_MIN_LLU_biggerlong_smallerulong();
	_test_various_MIN_LLU_equalint_equaluint();
	_test_various_MIN_LLU_equallong_equalulong();
	_test_various_MIN_LLU_hugeullong_hugerullong();
	_test_various_MIN_LLU_hugerullong_hugeullong();
	_test_various_MIN_LLU_biggerullong_smallerint();
	return 0;
}

int test_exhausterr()
{
	CHECKMALLOC((const char*const)malloc(UINT_MAX));
	return -1;
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

int main(int argv, char**argc)
{
	/*print_morelimits();*/
	test_OPERAND_IS_SIGNED();
	test_FITS_INTO_SIGNED_INT();
	test_overflow();
	test_morelimits();
	test_gcc_ifexpr();
	/*test_minmax_flexible_crazybadargs();*/
	test_MIN_LLS();
	test_MIN_LLU();
	test_minmax_fast();
	test_gcc_ifexpr();
	/*test_exhausterr();*/
	return 0;
}
