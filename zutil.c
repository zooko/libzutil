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

#include "zutil.h"

#include "moreassert.h"
#include "morelimits.h"

#undef uint32_decode
unsigned long uint32_decode(const zbyte* const bs)
{
	return ((unsigned long)(bs[3])) | ((unsigned long)(bs[2])) << 8 | ((unsigned long)(bs[1])) << 16 | ((unsigned long)(bs[0])) << 24;
}

#undef UINT32_DECODE
unsigned long UINT32_DECODE(const zbyte* const bs)
{
	return ((unsigned long)(bs[3])) | ((unsigned long)(bs[2])) << 8 | ((unsigned long)(bs[1])) << 16 | ((unsigned long)(bs[0])) << 24;
}

#undef uint32_encode
void uint32_encode(unsigned int u, zbyte* const bs)
{
	runtime_assert(u <= Z_UINT32_MAX, "Cannot encode a number this into 32 bits.");
	bs[3] = u % Z_UINT8_MAX;
	u /= Z_UINT8_MAX;
	bs[2] = u % Z_UINT8_MAX;
	u /= Z_UINT8_MAX;
	bs[1] = u % Z_UINT8_MAX;
	u /= Z_UINT8_MAX;
	bs[0] = u;
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

#undef add_would_overflow_shrt
int add_would_overflow_shrt(short x, short y) {
	return MACRO_ADD_WOULD_OVERFLOW_SHRT(x, y);
}

#undef ADD_WOULD_OVERFLOW_USHRT
int ADD_WOULD_OVERFLOW_USHRT(unsigned short x, unsigned short y) {
	return MACRO_ADD_WOULD_OVERFLOW_USHRT(x, y);
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

#undef add_would_overflow_longlong
int add_would_overflow_longlong(long long x, long long y) {
	return MACRO_ADD_WOULD_OVERFLOW_LLONG(x, y);
}

#undef ADD_WOULD_OVERFLOW_ULLONG
int ADD_WOULD_OVERFLOW_ULLONG(unsigned long long x, unsigned long long y) {
	return MACRO_ADD_WOULD_OVERFLOW_ULLONG(x, y);
}
