/**
 * copyright 2002-2004 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the simple, permissive free software, open 
 * source license.
 */
#ifndef __INCL_zutilimp_h
#define __INCL_zutilimp_h

#include "morelimits.h"

#ifdef NDEBUG
#define DIVCEIL(n, d) ((n)/(d)+((n)%(d)!=0))
#define LDIVCEIL(n, d) ((unsigned long)((n)/(d)+((n)%(d)!=0)))
#define UINT32_DECODE(bs) ((unsigned long)((bs)[3])) | ((unsigned long)((bs)[2])) << 8 | ((unsigned long)((bs)[1])) << 16 | ((unsigned long)((bs)[0])) << 24;
#endif /* #ifdef NDEBUG */

#define Z_ZERO_VAL(x) ((x)-(x))
#define Z_UNIT_VAL(x) (Z_ZERO_VAL(x) + 1)
#define Z_TYPE_ZERO_VAL(x) ((x)0)
#define Z_TYPE_UNIT_VAL(x) (Z_TYPE_ZERO_VAL(x) + 1)

#define TYPE_FITS_INTO_SIGNED_INT(x) (((Z_TYPE_ZERO_VAL(x) - Z_TYPE_UNIT_VAL(x)) < Z_TYPE_ZERO_VAL(x)) && (sizeof(x) <= sizeof(signed int)))
#define TYPE_PROMOTES_TO_SIGNED_TYPE(x) ((Z_TYPE_ZERO_VAL(x) - Z_TYPE_UNIT_VAL(x)) < Z_TYPE_ZERO_VAL(x))
/* The following macro tests whether all integers of the type of the operand can fit into a signed int, rather than whether this particular operand can fit into a signed int when coerced.   Therefore !OPERAND_FITS_INTO_SIGNED_INT((unsigned int)2) even though OPERAND_FITS_INTO_SIGNED_INT((signed int)2). */
#define OPERAND_FITS_INTO_SIGNED_INT(x) (((Z_ZERO_VAL(x) - Z_UNIT_VAL(x)) < Z_ZERO_VAL(x)) && (sizeof(x) <= sizeof(signed int)))
/* The following macro tests whether all integers of the type of the operand will promote into a signed type, rather than whether this particular operand can fit into a signed int when coerced.   Therefore !OPERAND_PROMOTES_TO_SIGNED_TYPE((unsigned int)2) even though OPERAND_PROMOTES_TO_SIGNED_TYPE((signed int)2). */
#define OPERAND_PROMOTES_TO_SIGNED_TYPE(x) ((Z_ZERO_VAL(x) - Z_UNIT_VAL(x)) < Z_ZERO_VAL(x))

#define ADD_WOULD_OVERFLOW_typ(x, y, typ) ((((x) > 0) && ((y) > 0) && ((Z_MAX(typ) - (x)) < (y))) || (((x) < 0) && ((y) < 0) && ((Z_MIN(typ) - (x)) > (y))))
#define ADD_WOULD_OVERFLOW_Utyp(x, y, typ) (((typ)((x)+(y))) < (x))

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
 * Copyright (c) 2002-2004 Bryce "Zooko" Wilcox-O'Hearn
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software to deal in this software without restriction, including
 * without limitation the rights to use, modify, distribute, sublicense, and/or 
 * sell copies of this software, and to permit persons to whom this software is 
 * furnished to do so, provided that the above copyright notice and this 
 * permission notice is included in all copies or substantial portions of this 
 * software. THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED.
 */
