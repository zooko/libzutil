/**
 * copyright 2002-2004 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software to deal in this software without restriction (including the
 * rights to use, modify, distribute, sublicense, and/or sell copies) provided
 * that the above copyright notice and this permission notice is included in
 * all copies or substantial portions of this software. THIS SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED.
 */

#ifndef __INCL_zutil_h
#define __INCL_zutil_h

#include "exhaust.h"
#include "minmax.h"
#include "morelimits.h"

#include <stddef.h>

static char const* const zutil_h_cvsid = "$Id: zutil.h,v 1.17 2004/03/20 00:28:20 zooko Exp $";

static int const zutil_vermaj = 0;
static int const zutil_vermin = 9;
static int const zutil_vermicro = 14;
static char const* const zutil_vernum = "0.9.14";

#ifndef __cplusplus
typedef int bool;
#define true ((bool)1)
#define false ((bool)0)
#endif

/**
 * This is guaranteed by standard C to be at least large enough to store at 
 * least 8 bits.  It is allowed to be larger.
 */
typedef unsigned char zbyte;

/**
 * Decode a four bytes into an unsigned int.  bs points to a buffer which must 
 * have (at least) four elements; the first four elements of bs contain the 
 * encoding of the unsigned integer in big-endian format.
 */
unsigned long uint32_decode(const zbyte* bs);
unsigned long UINT32_DECODE(const zbyte* bs);

/**
 * Encode an unsigned int into four zbytes in big-endian format.  Aborts (via 
 * runtime_assert()) if the value is too large to encode into 32 bits (that is, 
 * if it is >= 2^32).
 *
 * @param u: the value to encode
 * @param bs: pointer to the first byte of an array of at least four zbytes
 */
void uint32_encode(unsigned int u, zbyte* bs);

/*
Returns ceil(x/y): the smallest integer which is greater than or equal to x/y.

divceil(x, y) is better than (x+(y-1))/y because the latter can overflow in 
the addition.  Also divceil() is usually faster.

Unfortunately the macro version of divceil() suffers from "the macro 
problem" -- if its argument expressions have side effects, the side effects 
happen twice.
*/
unsigned int divceil(unsigned int n, unsigned int d);
unsigned long ldivceil(unsigned long n, unsigned long d);

unsigned int DIVCEIL(unsigned int n, unsigned int d);
unsigned long LDIVCEIL(unsigned long n, unsigned long d);

/*
Returns true iff the value (x+y) cannot be stored in a char.
 */
int add_would_overflow_char(char x, char y);
int ADD_WOULD_OVERFLOW_CHAR(char x, char y);

/*
Returns true iff the value (x+y) cannot be stored in an unsigned char.
 */
int add_would_overflow_uchar(unsigned char x, unsigned char y);
int ADD_WOULD_OVERFLOW_UCHAR(unsigned char x, unsigned char y);

/*
Returns true iff the value (x+y) cannot be stored in a signed char.
 */
int add_would_overflow_schar(signed char x, signed char y);
int ADD_WOULD_OVERFLOW_SCHAR(signed char x, signed char y);

/*
Returns true iff the value (x+y) cannot be stored in a short.
 */
int add_would_overflow_shrt(short x, short y);
int ADD_WOULD_OVERFLOW_SHRT(short x, short y);

/*
Returns true iff the value (x+y) cannot be stored in an unsigned short.
 */
int add_would_overflow_ushrt(unsigned short x, unsigned short y);
int ADD_WOULD_OVERFLOW_USHRT(unsigned short x, unsigned short y);

/*
Returns true iff the value (x+y) cannot be stored in an int.
 */
int add_would_overflow_int(int x, int y);
int ADD_WOULD_OVERFLOW_INT(int x, int y);

/*
Returns true iff the value (x+y) cannot be stored in an unsigned int.
 */
int add_would_overflow_uint(unsigned int x, unsigned int y);
int ADD_WOULD_OVERFLOW_UINT(unsigned int x, unsigned int y);

/*
Returns true iff the value (x+y) cannot be stored in a long.
 */
int add_would_overflow_long(long x, long y);
int ADD_WOULD_OVERFLOW_LONG(long x, long y);

/*
Returns true iff the value (x+y) cannot be stored in an unsigned long.
 */
int add_would_overflow_ulong(unsigned long x, unsigned long y);
int ADD_WOULD_OVERFLOW_ULONG(unsigned long x, unsigned long y);

/*
Returns true iff the value (x+y) cannot be stored in a long long.
 */
int add_would_overflow_llong(long long x, long long y);
int ADD_WOULD_OVERFLOW_LLONG(long long x, long long y);

/*
Returns true iff the value (x+y) cannot be stored in an unsigned long long.
 */
int add_would_overflow_ullong(unsigned long long x, unsigned long long y);
int ADD_WOULD_OVERFLOW_ULLONG(unsigned long long x, unsigned long long y);

#include "zutilimp.h" /* implementation stuff that you needn't see in order to use the library */

#endif /* #ifndef __INCL_zutil_h */
