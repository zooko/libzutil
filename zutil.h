/**
 * copyright 2002 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_zutil_h
#define __INCL_zutil_h

/* define LITTLE_ENDIAN if your machine stores integers with the most significant byte in the rightmost (highest-addressed) byte of the word */
/* #define LITTLE_ENDIAN */

#include "exhaust.h"
#include "minmax.h"
#include "morelimits.h"

#include <stddef.h>

static char const* const zutil_h_cvsid = "$Id: zutil.h,v 1.2 2002/02/09 13:50:39 zooko Exp $";

static int const zutil_vermaj = 0;
static int const zutil_vermin = 2;
static int const zutil_vermicro = 0;
static char const* const zutil_vernum = "0.2.0";

typedef unsigned char zbyte;

/**
 * Reads the data from the first four bytes of `bs' and creates an unsigned long, according to big-
 * endian encoding of an unsigned 32-bit integer.  Note that this works even if your unsigned longs 
 * are bigger than 32 bits.
 */
unsigned long natlong(const void*const vs);
unsigned long NATLONG(const void*const vs);
#ifdef NDEBUG
#ifdef LITTLE_ENDIAN
unsigned long natlong(const void*const vs);
#define NATLONG(vs) (((unsigned long)(((zbyte*)(vs))[3])) | ((unsigned long)(((zbyte*)(vs))[2])) << 8 | ((unsigned long)(((zbyte*)(vs))[1])) << 16 | ((unsigned long)(((zbyte*)(vs))[0])) << 24)
#else /* #ifdef LITTLE_ENDIAN */
#define natlong(vs) (*((const unsigned long*const)(vs)))
#define NATLONG(vs) (*((const unsigned long*const)(vs)))
#endif /* #ifdef LITTLE_ENDIAN */
#endif /* #ifdef NDEBUG */

/*
`divceil(x, y)' is better than `(x+(y-1))/y' because the latter can overflow in the addition.   
Also `divceil()' is probably faster, since GCC 3, for example, will generate code that does a single
division operation and then uses both the quotient and the remainder.  Unfortunately the macro 
version of `divceil()' suffers from the problem that if its argument expressions have side effects, 
the side effects happen twice.
*/
unsigned int divceil(unsigned int n, unsigned int d);
unsigned long ldivceil(unsigned long n, unsigned long d);

unsigned int DIVCEIL(unsigned int n, unsigned int d);
unsigned long LDIVCEIL(unsigned long n, unsigned long d);
#ifdef NDEBUG
#define DIVCEIL(n, d) ((n)/(d)+((n)%(d)!=0))
#define LDIVCEIL(n, d) ((unsigned long)((n)/(d)+((n)%(d)!=0)))
#endif /* #ifdef NDEBUG */

#endif /* #ifndef __INCL_zutil_h */

/**
 * Copyright (c) 2002 Bryce "Zooko" Wilcox-O'Hearn
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
