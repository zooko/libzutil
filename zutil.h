/**
 * copyright 2002, 2003 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_zutil_h
#define __INCL_zutil_h

#include "exhaust.h"
#include "minmax.h"
#include "morelimits.h"

#include <limits.h>
#include <stddef.h>

static char const* const zutil_h_cvsid = "$Id: zutil.h,v 1.5 2003/08/09 13:19:53 zooko Exp $";

static int const zutil_vermaj = 0;
static int const zutil_vermin = 9;
static int const zutil_vermicro = 0;
static char const* const zutil_vernum = "0.9.0";

/**
 * This is guaranteed by standard C to be at least large enough to store at 
 * least 8 bits.  It is allowed to be larger.
 */
typedef unsigned char zbyte;

/*
divceil(x, y) is better than (x+(y-1))/y because the latter can overflow in 
the addition.  Also divceil() is probably faster, since GCC 3.0, for example, 
will generate code that does a single division operation and then uses both 
the quotient and the remainder.  Unfortunately the macro version of divceil() 
suffers from "the macro problem" -- if its argument expressions have side 
effects, the side effects happen twice.
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

/**
 * copyright 2002, 2003 Bryce "Zooko" Wilcox-O'Hearn
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software to deal in this software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of this software, and to permit
 * persons to whom this software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of this software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
