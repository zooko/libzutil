#undef NDEBUG

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#define Z_EXHAUST_EXIT

#include "zutil.h"

#include <assert.h>

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
	printf("(char)0: %d\n", (char)0);
	printf("~((char)0): %d\n", ~((char)0));
	printf("(~((char)0))>>1: %d\n", (~((char)0))>>1);
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
	test_GCC_doc_suggestion();
	test_morelimits();
	test_gcc_ifexpr();
/*	test_minmax_flexible_crazybadargs();*/
	test_minmax_strict();
/*	test_minmax_strict_badargs();*/
	/*test_exhausterr();*/
	return 0;
}
