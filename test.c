#undef NDEBUG

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#define Z_EXHAUST_EXIT

#include "zutil.h"

#include <assert.h>

int test_overflow()
{
	assert (add_would_overflow_char(MAX_CHAR - 2, MAX_CHAR - 3));
	assert (add_would_overflow_char(MAX_CHAR, MAX_CHAR));
	assert (add_would_overflow_char((MAX_CHAR/2)+1, (MAX_CHAR/2)+1));
	assert (!add_would_overflow_char(MAX_CHAR/2, MAX_CHAR/2));
	assert (!add_would_overflow_char(MAX_CHAR, 0));
	assert (add_would_overflow_char(MAX_CHAR, 1));
	assert (add_would_overflow_char(1, MAX_CHAR));
	assert (!add_would_overflow_char(MAX_CHAR-1, 1));
	assert (!add_would_overflow_char(MAX_CHAR-2, 2));
	assert (!add_would_overflow_char(0, 0));

	assert (add_would_overflow_short(MAX_SHORT - 2, MAX_SHORT - 3));
	assert (add_would_overflow_short(MAX_SHORT, MAX_SHORT));
	assert (add_would_overflow_short((MAX_SHORT/2)+1, (MAX_SHORT/2)+1));
	assert (!add_would_overflow_short(MAX_SHORT/2, MAX_SHORT/2));
	assert (!add_would_overflow_short(MAX_SHORT, 0));
	assert (!add_would_overflow_short(MAX_SHORT-1, 1));
	assert (!add_would_overflow_short(MAX_SHORT-2, 2));
	assert (!add_would_overflow_short(0, 0));

	assert (add_would_overflow_short(MIN_SHORT, MIN_SHORT));
	assert (add_would_overflow_short(MIN_SHORT, -1));
	assert (add_would_overflow_short(-1, MIN_SHORT));
	assert (add_would_overflow_short((MIN_SHORT/2)-1, (MIN_SHORT/2)-1));
	assert (!add_would_overflow_short(MIN_SHORT/2, MIN_SHORT/2));

	assert (add_would_overflow_int(MAX_INT - 2, MAX_INT - 3));
	assert (add_would_overflow_int(MAX_INT, MAX_INT));
	assert (add_would_overflow_int((MAX_INT/2)+1, (MAX_INT/2)+1));
	assert (!add_would_overflow_int(MAX_INT/2, MAX_INT/2));
	assert (!add_would_overflow_int(MAX_INT, 0));
	assert (add_would_overflow_int(MAX_INT, 1));
	assert (add_would_overflow_int(1, MAX_INT));
	assert (!add_would_overflow_int(MAX_INT-1, 1));
	assert (!add_would_overflow_int(MAX_INT-2, 2));
	assert (!add_would_overflow_int(0, 0));

	assert (add_would_overflow_int(MIN_INT, MIN_INT));
	assert (add_would_overflow_int(MIN_INT, -1));
	assert (add_would_overflow_int(-1, MIN_INT));
	assert (add_would_overflow_int((MIN_INT/2)-1, (MIN_INT/2)-1));
	assert (!add_would_overflow_int(MIN_INT/2, MIN_INT/2));

	assert (add_would_overflow_uint(MAX_UINT - 2, MAX_UINT - 3));
	assert (add_would_overflow_uint(MAX_UINT, MAX_UINT));
	assert (add_would_overflow_uint((MAX_UINT/2)+1, (MAX_UINT/2)+1));
	assert (!add_would_overflow_uint(MAX_UINT/2, MAX_UINT/2));
	assert (!add_would_overflow_uint(MAX_UINT, 0));
	assert (add_would_overflow_uint(MAX_UINT, 1));
	assert (add_would_overflow_uint(1, MAX_UINT));
	assert (!add_would_overflow_uint(MAX_UINT-1, 1));
	assert (!add_would_overflow_uint(MAX_UINT-2, 2));
	assert (!add_would_overflow_uint(0, 0));

	assert (add_would_overflow_long(MAX_LONG - 2, MAX_LONG - 3));
	assert (add_would_overflow_long(MAX_LONG, MAX_LONG));
	assert (add_would_overflow_long((MAX_LONG/2)+1, (MAX_LONG/2)+1));
	assert (!add_would_overflow_long(MAX_LONG/2, MAX_LONG/2));
	assert (!add_would_overflow_long(MAX_LONG, 0));
	assert (add_would_overflow_long(MAX_LONG, 1));
	assert (add_would_overflow_long(1, MAX_LONG));
	assert (!add_would_overflow_long(MAX_LONG-1, 1));
	assert (!add_would_overflow_long(MAX_LONG-2, 2));
	assert (!add_would_overflow_long(0, 0));

	assert (add_would_overflow_long(MIN_INT, MIN_INT));
	assert (add_would_overflow_long(MIN_INT, -1));
	assert (add_would_overflow_long(-1, MIN_INT));
	assert (add_would_overflow_long((MIN_INT/2)-1, (MIN_INT/2)-1));
	assert (!add_would_overflow_long(MIN_INT/2, MIN_INT/2));

	assert (add_would_overflow_ulong(MAX_ULONG - 2, MAX_ULONG - 3));
	assert (add_would_overflow_ulong(MAX_ULONG, MAX_ULONG));
	assert (add_would_overflow_ulong((MAX_ULONG/2)+1, (MAX_ULONG/2)+1));
	assert (!add_would_overflow_ulong(MAX_ULONG/2, MAX_ULONG/2));
	assert (!add_would_overflow_ulong(MAX_ULONG, 0));
	assert (add_would_overflow_ulong(MAX_ULONG, 1));
	assert (add_would_overflow_ulong(1, MAX_ULONG));
	assert (!add_would_overflow_ulong(MAX_ULONG-1, 1));
	assert (!add_would_overflow_ulong(MAX_ULONG-2, 2));
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
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)MAX_CHAR));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)MAX_CHAR));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)MAX_UCHAR));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)MIN_CHAR));
	assert (OPERAND_FITS_INTO_SIGNED_INT((char)MIN_CHAR));
	assert (OPERAND_FITS_INTO_SIGNED_INT((unsigned char)MIN_UCHAR));
	return 1;
}

int test_SIGNED_NONLONG_FITS_INTO_SIGNED_INT()
{
	assert (TYPE_FITS_INTO_SIGNED_INT(signed char));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)MAX_CHAR));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed char)MIN_CHAR));
	assert (TYPE_FITS_INTO_SIGNED_INT(signed short));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)MAX_SHORT));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed short)MIN_SHORT));
	assert (TYPE_FITS_INTO_SIGNED_INT(signed int));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)0));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)2));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)-1));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)MAX_INT));
	assert (OPERAND_FITS_INTO_SIGNED_INT((signed int)MIN_INT));
	return 1;
}

int test_UNSIGNED_INT_NOT_FITS_INTO_SIGNED_INT()
{
	assert (!TYPE_FITS_INTO_SIGNED_INT(unsigned int));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)0));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)-1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)2));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)MAX_UINT));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned int)MIN_UINT));
	return 1;
}

int test_UNSIGNED_LONG_NOT_FITS_INTO_SIGNED_INT()
{
	assert (!TYPE_FITS_INTO_SIGNED_INT(unsigned long));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)0));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)-1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)1));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)2));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)MAX_ULONG));
	assert (!OPERAND_FITS_INTO_SIGNED_INT((unsigned long)MIN_ULONG));
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

int test_GCC_doc_suggestion()
{
#define max(a,b) \
       ({typedef _ta = (a), _tb = (b);  \
         _ta _a = (a); _tb _b = (b);     \
         _a > _b ? _a : _b; })

	if (max(-1, 2UL) > 0) {
		printf("That's a strange definition of \"safe\".\n");
		return -1;
	}
	return 0;
}

/*
int test_minmax_flexible_crazybadargs()
{
	char b[10];
	int z = 1;
	MIN_FLEXIBLE(b, z);
}
*/

/*
int test_min_strict_diff_unsigned_types_should_be_ok_but_isnt()
{
	int i;
	short int u = 3;
	i = MIN_STRICT(2, u);
	if (i != 2) {
		printf("failed test MIN_STRICT(2, 3) != 2: %d\n", i);
		return -1;
	}
	return 0;
}
*/

/*
int test_minmax_strict_badargs()
{
	int i;
	unsigned int u = 3;
	i = MIN_STRICT(2, u);
	if (i != 2) {
		printf("failed test MIN_STRICT(2, 3) != 2: %d\n", i);
		return -1;
	}
	return 0;
}
*/

int test_minmax_strict()
{
	int x = 2;
	int y = 3;
	int res = MIN_STRICT(x, y);
	unsigned int z;
	unsigned int b;
	int a;
	if (res != 2) {
		printf("failed test MIN(%d, %d) != %d\n", x, y, 2);
		return -1;
	}
	res = MIN_STRICT(y, x);
	if (res != 2) {
		printf("failed test MIN(%d, %d) != %d\n", y, x, 2);
		return -1;
	}
	z = 4;
	b = 5;
	res = MIN_STRICT(z, b);
	if (res != 4) {
		printf("failed test MIN(%d, %d) != %d\n", z, b, 4);
		return -1;
	}
	res = MIN_STRICT(b, z);
	if (res != 4) {
		printf("failed test MIN(%d, %d) != %d\n", b, z, 4);
		return -1;
	}
	a = -1;
	res = MIN_STRICT(x, a);
	if (res != -1) {
		printf("failed test MIN(%d, %d) != %d\n", x, a, -1);
		return -1;
	}
	res = MIN_STRICT(a, x);
	if (res != -1) {
		printf("failed test MIN(%d, %d) != %d\n", a, x, -1);
		return -1;
	}
	return 0;
}

/*
int test_minmax_unsafe()
{
	int a;
	unsigned int b;
	a = 3;
	b = -1;
	if (MIN(a, b) != -1) {
		printf("failed test MIN(%d, %d) != %d\n", a, b, -1);
		return -1;
	}
	return 0;
}
*/

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

/*
int test_minmax_flexible()
{
	int a, res, x;
	unsigned int u;
	long double q, ldres;

	a = -2;
	u = 3;

	if (MIN(a, u) > -1) {
		printf("failed test MIN(%d, %d): %d == %u > -1\n", a, u, MIN(a, u), MIN(a, u));
		return -1;
	}
	if (MIN(a, u) < -3) {
		printf("failed test MIN(%d, %d): %d == %u < -3\n", a, u, MIN(a, u), MIN(a, u));
		return -1;
	}
	if (MIN(a, u) != -2) {
		printf("failed test MIN(%d, %d) == %d == %u != %d\n", a, u, MIN(a, u), MIN(a, u), -2);
		return -1;
	}
	if (MIN(a, u) > a) {
		printf("failed test MIN(%d, %d) == %d == %u > %d == %u\n", a, u, MIN(a, u), MIN(a, u), a, a);
		return -1;
	}
	if (MIN(a, u) > u) {
		printf("failed test MIN(%d, %d) == %d == %u > %d == %u\n", a, u, MIN(a, u), MIN(a, u), u, u);
		return -1;
	}
	if (MIN(a, u) > 0) {
		printf("failed test MIN(%d, %d) == %d == %u > 0\n", a, u, MIN(a, u), MIN(a, u));
		return -1;
	}

	a = 4;
	u = 3;
	res = MIN(a, u);
	if (res != 3) {
		printf("failed test MIN(%d, %d) != %d\n", a, u, 3);
		return -1;
	}

	q = 3.14159;

	ldres = MIN(u, q);
	if ((int)ldres != 3) {
		printf("failed test MIN(%d, %Lf) != %d\n", u, q, 3);
		return -1;
	}

	res = MIN(u, q);
	if (res != 3) {
		printf("failed test MIN(%d, %Lf) != %d\n", u, q, 3);
		return -1;
	}

	x = 99;
	res = MIN(x, q);
	if (res != 3) {
		printf("failed test MIN(%d, %Lf) != %d\n", x, q, 3);
		return -1;
	}

	ldres = MIN(a, q);
	if (ldres != 3.14159) {
		printf("failed test MIN(%d, %Lf): %Lf != %f\n", a, q, ldres, 3.14159);
		return -1;
	}
	return 0;
}
*/

int test_exhausterr()
{
	CHECKMALLOC((const char*const)malloc(UINT_MAX));
	return -1;
}

int test_morelimits()
{
	printf("MAX_UNSIGNED(unsigned char): %u\n", Z_MAX_UNSIGNED(unsigned char));
	printf("MAX_SIGNED(char): %d\n", Z_MAX_SIGNED(char));

	printf("MAX_UCHAR: %u\n", MAX_UCHAR);
	printf("UCHAR_MAX: %u\n", UCHAR_MAX);
	printf("MAX_USHORT: %u\n", MAX_USHORT);
	printf("USHRT_MAX: %u\n", USHRT_MAX);
	printf("MAX_UINT: %u\n", MAX_UINT);
	printf("UINT_MAX: %u\n", UINT_MAX);
	printf("MAX_ULONG: %lu\n", MAX_ULONG);
	printf("ULONG_MAX: %lu\n", ULONG_MAX);
	printf("MAX_SIZE_T: %u\n", MAX_SIZE_T);

	printf("MAX_TIME_T: %ld\n", MAX_TIME_T);
	printf("\n");
	printf("MIN_UCHAR: %u\n", MIN_UCHAR);
	printf("MIN_USHORT: %u\n", MIN_USHORT);
	printf("MIN_UINT: %u\n", MIN_UINT);
	printf("MIN_ULONG: %lu\n", MIN_ULONG);
	printf("MIN_SIZE_T: %u\n", MIN_SIZE_T);
	printf("MIN_TIME_T: %ld\n", MIN_TIME_T);
	printf("\n");
	printf("MAX_CHAR: %d\n", MAX_CHAR);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("MAX_SHORT: %d\n", MAX_SHORT);
	printf("SHRT_MAX: %d\n", SHRT_MAX);
	printf("MAX_INT: %d\n", MAX_INT);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("MAX_LONG: %ld\n", MAX_LONG);
	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("\n");
	printf("MIN_CHAR: %d\n", MIN_CHAR);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("MIN_SHORT: %d\n", MIN_SHORT);
	printf("SHRT_MIN: %d\n", SHRT_MIN);
	printf("MIN_INT: %d\n", MIN_INT);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("MIN_LONG: %ld\n", MIN_LONG);
	printf("LONG_MIN: %ld\n", LONG_MIN);

#ifdef __GNUC__
	printf("\n");
	printf("MAX_LONGLONG: %lld\n", MAX_LONGLONG);
	printf("MIN_LONGLONG: %lld\n", MIN_LONGLONG);
	printf("MAX_ULONGLONG: %llu\n", MAX_ULONGLONG);
	printf("MIN_ULONGLONG: %llu\n", MIN_ULONGLONG);
#endif /* #ifdef __GNUC__ */

	assert (MAX_TIME_T > MIN_TIME_T);

	return 0;
}

int main(int argv, char**argc)
{
	test_FITS_INTO_SIGNED_INT();
	test_overflow();
	test_GCC_doc_suggestion();
	test_morelimits();
	test_gcc_ifexpr();
/*	test_minmax_flexible_crazybadargs();*/
	test_minmax_strict();
/*	test_minmax_strict_badargs();*/
	/*test_exhausterr();*/
	return 0;
}
