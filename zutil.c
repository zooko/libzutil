/**
 * copyright 2002 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */

#include "zutil.h"

#undef natlong
unsigned long natlong(const void* const vs)
{
	return ((unsigned long)(((zbyte*)vs)[3])) | ((unsigned long)(((zbyte*)vs)[2])) << 8 | ((unsigned long)(((zbyte*)vs)[1])) << 16 | ((unsigned long)(((zbyte*)vs)[0])) << 24;
}

#undef NATLONG
unsigned long NATLONG(const void* const vs)
{
	return ((unsigned long)(((zbyte*)vs)[3])) | ((unsigned long)(((zbyte*)vs)[2])) << 8 | ((unsigned long)(((zbyte*)vs)[1])) << 16 | ((unsigned long)(((zbyte*)vs)[0])) << 24;
}

#undef divceil
unsigned int divceil(unsigned int n, unsigned int d)
{
	return n/d+((n%d)!=0);
}

#undef ldivceil
unsigned long ldivceil(unsigned long n, unsigned long d)
{
	return n/d+((n%d)!=0);
}

#undef DIVCEIL
unsigned int DIVCEIL(unsigned int n, unsigned int d)
{
	return n/d+((n%d)!=0);
}

#undef LDIVCEIL
unsigned long LDIVCEIL(unsigned long n, unsigned long d)
{
	return n/d+((n%d)!=0);
}

#undef add_would_overflow_char
int add_would_overflow_char(char x, char y) {
	return MACRO_ADD_WOULD_OVERFLOW_CHAR(x, y);
}

#undef ADD_WOULD_OVERFLOW_CHAR
int ADD_WOULD_OVERFLOW_CHAR(char x, char y) {
	return MACRO_ADD_WOULD_OVERFLOW_CHAR(x, y);
}

#undef add_would_overflow_uchar
int add_would_overflow_uchar(unsigned char x, unsigned char y) {
	return MACRO_ADD_WOULD_OVERFLOW_UCHAR(x, y);
}

#undef ADD_WOULD_OVERFLOW_UCHAR
int ADD_WOULD_OVERFLOW_UCHAR(unsigned char x, unsigned char y) {
	return MACRO_ADD_WOULD_OVERFLOW_UCHAR(x, y);
}

#undef add_would_overflow_schar
int add_would_overflow_schar(signed char x, signed char y) {
	return MACRO_ADD_WOULD_OVERFLOW_SCHAR(x, y);
}

#undef ADD_WOULD_OVERFLOW_SCHAR
int ADD_WOULD_OVERFLOW_SCHAR(signed char x, signed char y) {
	return MACRO_ADD_WOULD_OVERFLOW_SCHAR(x, y);
}

#undef add_would_overflow_short
int add_would_overflow_short(short x, short y) {
	return MACRO_ADD_WOULD_OVERFLOW_SHORT(x, y);
}

#undef ADD_WOULD_OVERFLOW_USHORT
int ADD_WOULD_OVERFLOW_USHORT(unsigned short x, unsigned short y) {
	return MACRO_ADD_WOULD_OVERFLOW_USHORT(x, y);
}

#undef add_would_overflow_int
int add_would_overflow_int(int x, int y) {
	return MACRO_ADD_WOULD_OVERFLOW_INT(x, y);
}

#undef ADD_WOULD_OVERFLOW_INT
int ADD_WOULD_OVERFLOW_INT(int x, int y) {
	return MACRO_ADD_WOULD_OVERFLOW_INT(x, y);
}

#undef add_would_overflow_uint
int add_would_overflow_uint(unsigned int x, unsigned int y) {
	return MACRO_ADD_WOULD_OVERFLOW_UINT(x, y);
}

#undef ADD_WOULD_OVERFLOW_UINT
int ADD_WOULD_OVERFLOW_UINT(unsigned int x, unsigned int y) {
	return MACRO_ADD_WOULD_OVERFLOW_UINT(x, y);
}

#undef add_would_overflow_long
int add_would_overflow_long(long x, long y) {
	return MACRO_ADD_WOULD_OVERFLOW_LONG(x, y);
}

#undef ADD_WOULD_OVERFLOW_LONG
int ADD_WOULD_OVERFLOW_LONG(long x, long y) {
	return MACRO_ADD_WOULD_OVERFLOW_LONG(x, y);
}

#undef add_would_overflow_ulong
int add_would_overflow_ulong(unsigned long x, unsigned long y) {
	return MACRO_ADD_WOULD_OVERFLOW_ULONG(x, y);
}

#undef ADD_WOULD_OVERFLOW_ULONG
int ADD_WOULD_OVERFLOW_ULONG(unsigned long x, unsigned long y) {
	return MACRO_ADD_WOULD_OVERFLOW_ULONG(x, y);
}

/*
 * The following is not standard C.  If your compiler supports LONG LONG, then please patch this to somehow detect that during preprocessing and send me the patch.
 */
#ifdef __GNUC__
#undef add_would_overflow_longlong
int add_would_overflow_longlong(long long x, long long y) {
	return MACRO_ADD_WOULD_OVERFLOW_LONGLONG(x, y);
}

#undef ADD_WOULD_OVERFLOW_ULONGLONG
int ADD_WOULD_OVERFLOW_ULONGLONG(unsigned long long x, unsigned long long y) {
	return MACRO_ADD_WOULD_OVERFLOW_ULONGLONG(x, y);
}
#endif /* #ifdef __GNUC__ */

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
