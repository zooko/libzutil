/**
 * copyright 2002, 2003 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_zutilimp_h
#define __INCL_zutilimp_h

#ifdef NDEBUG
#define DIVCEIL(n, d) ((n)/(d)+((n)%(d)!=0))
#define LDIVCEIL(n, d) ((unsigned long)((n)/(d)+((n)%(d)!=0)))
#endif /* #ifdef NDEBUG */

#define Z_ZERO_VAL(x) ((x)-(x))
#define Z_UNIT_VAL(x) (Z_ZERO_VAL(x) + 1)
#define Z_TYPE_ZERO_VAL(x) ((x)0)
#define Z_TYPE_UNIT_VAL(x) (Z_TYPE_ZERO_VAL(x) + 1)
#define OPERAND_FITS_INTO_SIGNED_INT(x) ((Z_ZERO_VAL(x) - Z_UNIT_VAL(x)) < Z_ZERO_VAL(x))
#define TYPE_FITS_INTO_SIGNED_INT(x) ((Z_TYPE_ZERO_VAL(x) - Z_TYPE_UNIT_VAL(x)) < Z_TYPE_ZERO_VAL(x))

#define OPERAND_IS_SIGNED(x) ((-((x)==0?((x)+1):((x)/(x))))<0)

#define ADD_WOULD_OVERFLOW_typ(x, y, typ) ((((x) > 0) && ((y) > 0) && ((Z_MAX(typ) - (x)) < (y))) || (((x) < 0) && ((y) < 0) && ((Z_MIN(typ) - (x)) > (y))))
#define ADD_WOULD_OVERFLOW_Utyp(x, y, typ) (((typ)((x)+(y)))<(x))

#define MACRO_ADD_WOULD_OVERFLOW_CHAR(x, y) ADD_WOULD_OVERFLOW_typ(x, y, char)
#define MACRO_ADD_WOULD_OVERFLOW_SHRT(x, y) ADD_WOULD_OVERFLOW_typ(x, y, short)
#define MACRO_ADD_WOULD_OVERFLOW_INT(x, y) ADD_WOULD_OVERFLOW_typ(x, y, int)
#define MACRO_ADD_WOULD_OVERFLOW_LONG(x, y) ADD_WOULD_OVERFLOW_typ(x, y, long)
#define MACRO_ADD_WOULD_OVERFLOW_LLONG(x, y) ADD_WOULD_OVERFLOW_typ(x, y, long long)

#define MACRO_ADD_WOULD_OVERFLOW_UCHAR(x, y) ADD_WOULD_OVERFLOW_Utyp(x, y, unsigned char)
#define MACRO_ADD_WOULD_OVERFLOW_USHRT(x, y) ADD_WOULD_OVERFLOW_Utyp(x, y, unsigned short)
#define MACRO_ADD_WOULD_OVERFLOW_UINT(x, y) ADD_WOULD_OVERFLOW_Utyp(x, y, unsigned int)
#define MACRO_ADD_WOULD_OVERFLOW_ULONG(x, y) ADD_WOULD_OVERFLOW_Utyp(x, y, unsigned long)
#define MACRO_ADD_WOULD_OVERFLOW_ULLONG(x, y) ADD_WOULD_OVERFLOW_Utyp(x, y, unsigned long long)

#define MACRO_ADD_WOULD_OVERFLOW_SCHAR(x, y) ADD_WOULD_OVERFLOW_typ(x, y, signed char)


#ifdef NDEBUG
#define ADD_WOULD_OVERFLOW_CHAR(x, y) MACRO_ADD_WOULD_OVERFLOW_CHAR(x, y)
#define ADD_WOULD_OVERFLOW_SHRT(x, y) MACRO_ADD_WOULD_OVERFLOW_SHRT(x, y)
#define ADD_WOULD_OVERFLOW_INT(x, y) MACRO_ADD_WOULD_OVERFLOW_INT(x, y)
#define ADD_WOULD_OVERFLOW_LONG(x, y) MACRO_ADD_WOULD_OVERFLOW_LONG(x, y)
#define ADD_WOULD_OVERFLOW_LLONG(x, y) MACRO_ADD_WOULD_OVERFLOW_LLONG(x, y) 

#define ADD_WOULD_OVERFLOW_UCHAR(x, y) MACRO_ADD_WOULD_OVERFLOW_UCHAR(x, y)
#define ADD_WOULD_OVERFLOW_USHRT(x, y) MACRO_ADD_WOULD_OVERFLOW_USHRT(x, y)
#define ADD_WOULD_OVERFLOW_UINT(x, y) MACRO_ADD_WOULD_OVERFLOW_UINT(x, y)
#define ADD_WOULD_OVERFLOW_ULONG(x, y) MACRO_ADD_WOULD_OVERFLOW_ULONG(x, y)
#define ADD_WOULD_OVERFLOW_ULLONG(x, y) MACRO_ADD_WOULD_OVERFLOW_ULLONG(x, y) 

#define ADD_WOULD_OVERFLOW_SCHAR(x, y) MACRO_ADD_WOULD_OVERFLOW_SCHAR(x, y)
#endif /* #ifdef NDEBUG */


#endif /* #ifndef __INCL_zutilimp_h */

/**
 * copyright (c) 2002, 2003 Bryce "Zooko" Wilcox-O'Hearn
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
