/**
 * copyright 2002 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_morelimits_h
#define __INCL_morelimits_h

#include <stddef.h>

#include "zutil.h"

static char const* const morelimits_h_cvsid = "$Id: morelimits.h,v 1.1 2002/02/08 17:30:54 zooko Exp $";

static int const morelimits_vermaj = 0;
static int const morelimits_vermin = 1;
static int const morelimits_vermicro = 0;
static char const* const morelimits_vernum = "0.1.0";

#define Z_MAX_UNSIGNED(typ) ((typ)(~(typ)0))
#define Z_MIN_UNSIGNED(typ) ((typ)0)

/* This doesn't work on a "long long" of course. */
#define Z_MAX_SIGNED(typ) ((~((typ)0UL))>>1)
#define Z_MIN_SIGNED(typ) ((typ)(-(Z_MAX_SIGNED(typ)-1)))

#define Z_MAX(typ) ((typ)(MAX_FLEXIBLE(Z_MAX_UNSIGNED(typ), Z_MAX_SIGNED(typ))))
#define Z_MIN(typ) ((typ)(MIN_FLEXIBLE(Z_MIN_UNSIGNED(typ), Z_MIN_SIGNED(typ))))

/*
 * The following are not defined in the standard C library's "limits.h", but they should be!
 */
#define MAX_SIZE_T Z_MAX(size_t)
#define MIN_SIZE_T Z_MIN(size_t)

#define MAX_TIME_T Z_MAX(time_t)
#define MIN_TIME_T Z_MIN(time_t)

/*
 * The following are not defined in the standard C library's "limits.h", presumably because you could just write "0" instead.
 */
#define MIN_ULONG Z_MIN(unsigned long)
#define MIN_UINT Z_MIN(unsigned int)
#define MIN_USHORT Z_MIN(unsigned short)
#define MIN_UCHAR Z_MIN(unsigned char)

/*
 * All of the following are defined in the standard C library's "limits.h" header, under different names.  They are included here just because I can.  Maybe someday you'll be on a machine with an incorrect or incomplete "limits.h" and you'll thank me.
 */
#define MAX_ULONG Z_MAX(unsigned long)
#define MAX_UINT Z_MAX(unsigned int)
#define MAX_USHORT Z_MAX(unsigned short)
#define MAX_UCHAR Z_MAX(unsigned char)

#define MAX_LONG Z_MAX(long)
#define MAX_INT Z_MAX(int)
#define MAX_SHORT Z_MAX(short)
#define MAX_CHAR Z_MAX(char)

#define MIN_LONG Z_MIN(long)
#define MIN_INT Z_MIN(int)
#define MIN_SHORT Z_MIN(short)
#define MIN_CHAR Z_MIN(char)

#endif /* #ifndef __INCL_morelimits_h */

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
