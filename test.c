#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#define Z_EXHAUST_EXIT

#include "zutil.h"

#undef NDEBUG

int test_minmax_picky()
{
	int x = 2;
	int y = 3;
	int res = MIN(x, y);
	if (res != 2) {
		printf("failed test MIN(%d, %d) != %d\n", x, y, 2);
		return -1;
	}
	res = MIN(y, x);
	if (res != 2) {
		printf("failed test MIN(%d, %d) != %d\n", y, x, 2);
		return -1;
	}
	unsigned int z = 4;
	unsigned int b = 5;
	res = MIN(z, b);
	if (res != 4) {
		printf("failed test MIN(%d, %d) != %d\n", z, b, 4);
		return -1;
	}
	res = MIN(b, z);
	if (res != 4) {
		printf("failed test MIN(%d, %d) != %d\n", b, z, 4);
		return -1;
	}
	int a = -1;
	res = MIN(x, a);
	if (res != -1) {
		printf("failed test MIN(%d, %d) != %d\n", x, a, -1);
		return -1;
	}
	res = MIN(a, x);
	if (res != -1) {
		printf("failed test MIN(%d, %d) != %d\n", a, x, -1);
		return -1;
	}
	return 0;
}

int test_minmax_lenient()
{
	if (test_minmax_picky()) {
		return -1;
	}

	int a = -2;
	unsigned int z = 3;
	int res;
	
	res = MIN(a, z);
	if (res != -2) {
		printf("failed test MIN(%d, %d) != %d\n", a, z, -2);
		return -1;
	}

	long double q = 3.14159;
	long double ldres;

	ldres = MIN(z, q);
	if ((int)ldres != 3) {
		printf("failed test MIN(%d, %Lf) != %d\n", z, q, 3);
		return -1;
	}

	res = MIN(z, q);
	if (res != 3) {
		printf("failed test MIN(%d, %Lf) != %d\n", z, q, 3);
		return -1;
	}

	int x = 99;
	res = MIN(x, q);
	if (res != 3) {
		printf("failed test MIN(%d, %Lf) != %d\n", x, q, 3);
		return -1;
	}

	ldres = MIN(a, q);
	if (ldres != -2) {
		printf("failed test MIN(%d, %Lf): %Lf != %d\n", a, q, ldres, -2);
		return -1;
	}
	return 0;
}


int test_natlong()
{
	const zbyte buf[4] = { 0, 0, 0, 3 };
	unsigned long x = natlong(buf);
	unsigned long y = NATLONG(buf);
	printf("%u, %lu, %lu\n", buf[3], x, natlong(buf));
	assert (x == y);
	assert (x == 3);
	return 0;
}

int test_exhausterr()
{
	CHECKMALLOC((const char*const)malloc(UINT_MAX));
	return -1;
}

#if 0
int test_morelimits()
{
	printf("(char)0: %d\n", (char)0);
	printf("MAX_UNSIGNED(char): %d\n", Z_MAX_UNSIGNED(char));
	printf("MAX_SIGNED(char): %d\n", Z_MAX_UNSIGNED(char));

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

	assert (MAX_TIME_T > MIN_TIME_T);

	return 0;
}
#endif

int main(int argv, char**argc)
{
	test_minmax_lenient();
	/*test_natlong();*/
	/*test_morelimits();*/
	/*test_exhausterr();*/
	return 0;
}
