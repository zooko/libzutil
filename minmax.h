/**
 * copyright 2002 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_minmax_h
#define __INCL_minmax_h

/**
 * How to use these macros:
 *
 * There are two kinds of MIN/MAX macros to choose from.
 *
 * The first is the good old standby: `x<y?x:y'.  It is named `MIN_UNSAFE', because if one of the 
 * arguments is unsigned and the other is signed, then you can get a nasty surprise depending on the 
 * size of the types and your CPU architecture, for example `unsigned int i = 3; MIN(i, -1);' 
 * will yield an answer of  `3'.  If you are going to use `MIN_UNSAFE', then be careful that the two 
 * arguments are of the same type.  `MIN_UNSAFE' is a tiny bit faster than the other option: 
 * `MIN_FLEXIBLE'.  (approximately XXXXXX faster).
 *
 * If your compiler is GCC, then you can use a GNU extension to the C language which enables the 
 * compiler to check at compile-time whether the use of `MIN_UNSAFE' will be safe (that is: whether 
 * the two arguments are of the same type).  In that case you should name it `MIN_STRICT' instead of 
 * `MIN_UNSAFE' for documentation purposes, although both names expand to the same macro when using 
 * GCC.
 *
 * The second option is a "flexible" macro that does what you would expect: gives you the least 
 * (i.e. the smallest positive number or the biggest negative number) of the two numeric arguments, 
 * regardless of what their particular type is.  The type of the resulting value is the same as the 
 * type of the "winning" input, so `MIN_FLEXIBLE(0, 3.14159)' yields `0', of type int, and 
 * `MIN_FLEXIBLE(4, 3.14159)' yields `3.14159', of type double.
 *
 * You can even use `MIN_FLEXIBLE' on pairs of pointers and it will do the correct thing for pointer 
 * comparison in C.  (Note: you may be surprised if you don't know what the correct thing for 
 * pointer comparison in C *is*, exactly.  It isn't a simple rule of "compare memory addresses 
 * numerically".)
 *
 *
 * By default `MIN' is defined to be `MIN_FLEXIBLE'.  If you prefer for it to be `MIN_STRICT', 
 * and your compiler is GCC, then you can define Z_STRICT_MINMAX before #include'ing "minmax.h".
 *
 * If your compiler is not GCC, but you prefer the default to be MIN_UNSAFE instead of MIN_FLEXIBLE, 
 * you'll have to alter this header file yourself or just `#define MIN MIN_UNSAFE' after including 
 * this header.
 *
 * If the NDEBUG flag is set, then all uses of `MIN_UNSAFE'  or `MIN_STRICT' get defined to be the 
 * unsafe version.  (It's faster XXXXX, and the unsafe version behaves exactly the same way as the 
 * strict version other than compile-time checking.)  If the NDEBUG flag is unset (i.e., if you are 
 * compiling with debugging checks on) and if your compiler is GCC, then all uses of `MIN_UNSAFE' 
 * and `MIN_STRICT' get defined to be the "strict" version.
 */



#ifdef __GNUC__
/** 
 * Min/max macros that give compiler errors if used on different types of operands, but that rely on 
 * GCC extensions that are not part of ANSI/ISO C89.
 */
#define _MIN_STRICT(x, y) ({const typeof(x) _x = x; const typeof(y) _y = y; &_x==&_y; (_x<_y)?_x:_y;})
#define _MAX_STRICT(x, y) ({const typeof(x) _x = x; const typeof(y) _y = y; &_x==&_y; (_x>_y)?_x:_y;})
#endif /* #ifdef __GNUC__ */

/**
 * Min/max macros that just do what you expect.  (They even work for floats, doubles, and long 
 * doubles!)
 *
 * The type of the value of this macro is the type of the chosen argument expression.  Therefore if 
 * you write `MIN_FLEXIBLE(0, 3.14159)', then the value is an int, but if you write 
 * `MIN_FLEXIBLE(4, 3.14159)' then the value is a float.
 */
#define MIN_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?(x):((y)<0)?(y):((x)<(y))?(x):(y))
#define MAX_FLEXIBLE(x, y) (((x)>0&&(y)<=0)?(x):((y)>0)?(y):((x)>(y))?(x):(y))

/**
 * Min/max macros that are fast but unsafe.
 */
#define _MIN_UNSAFE(x, y) ((x)<(y)?(x):(y))
#define _MAX_UNSAFE(x, y) ((x)>(y)?(x):(y))





#if (!defined NDEBUG) && (defined __GNUC__)
#define _MIN_INFLEX _MIN_STRICT
#define _MAX_INFLEX _MAX_STRICT
#else
#define _MIN_INFLEX _MIN_UNSAFE
#define _MAX_INFLEX _MAX_UNSAFE
#endif /* #if (!defined NDEBUG) && (defined __GNUC__) */

#define MIN_UNSAFE _MIN_INFLEX
#define MAX_UNSAFE _MAX_INFLEX

#ifdef __GNUC__
#define MIN_STRICT _MIN_INFLEX
#define MAX_STRICT _MAX_INFLEX
#endif

#ifdef Z_STRICT_MINMAX
#ifndef __GNUC__
#error "Sorry -- strict min/max checking is not available except with the GCC compiler.  Remove the #define of `Z_STRICT_MINMAX' in order to use flexible min/max"
#endif /* #ifndef __GNUC__ */
#define MIN _MIN_INFLEX
#define MAX _MAX_INFLEX
#else
#define MIN MIN_FLEXIBLE
#define MAX MAX_FLEXIBLE
#endif /* #ifdef Z_STRICT_MINMAX */

#endif /* #ifndef __INCL_minmax_h */

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
