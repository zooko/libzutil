/**
 * copyright 2002 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_minmax_h
#define __INCL_minmax_h

#error "This stuff is untested and incompletely documented.  Use at your own risk.  I gotta hack on Mnet for CodeCon right now.  --Zooko 2002-02-10"
/**
 * How to use these macros:
 *
XXXXX
 */



/**
 * This MAX macro just does what you expect.  It evaluates to the largest of the two operands, and 
 * the type of the result is a reasonable type for storing that result, for example it is a signed 
 * int if both the operands were signed ints, it is an unsigned int if either operand was an 
 * unsigned int, it is a double if either operands were a double, etc. XXXXX
 */
#define _MAX_FLEXIBLE(x, y) (((x)>0&&(y)<=0)?(x):(((y)>0&&(x)<=0)?(y):(((x)>(y))?(x):(y))))

/**
 * This MIN macro tries to just do what you would expect, but the result is cast to type `long', 
 * which means that if both of the operands are unsigned longs and both are larger than MAX_LONG 
 * (i.e., so big that they cannot be represented normally in a signed long), then the answer will be 
 * of the wrong type, and could also (depending on your C implementation) be screwed up in some 
 * other way.
 */
#define _MIN_S_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?((long)x):(((y)<0&&(x)>=0)?((long)y):(((x)<(y))?((long)x):((long)y))))

/**
 * This MIN macro tries to just do what you would expect, but if the winning operand is a negative 
 * signed integer and the other operand is of `unsigned int' or `unsigned long' type, then the 
 * result will be the correct answer (the value of the winning operand) but it will be cast to type 
 * `unsigned long'.  This will work, on most C implementations, if the context in which you are 
 * calling `_MIN_U_FLEXIBLE' coerces the value back to signed type, for example: 
 * `int x = _MIN_U_FLEXIBLE(-2, 1UL);' will do what you expect on most C implementations (although 
 * it is not required to do by the standard).  However it will not do what you expect if the context
 * does not coerce the value to a signed, for example `_MIN_U_FLEXIBLE(-2, 1UL) > 0' will evaluate 
 * to true.
 *
 * If you know that at least one of the operands is guaranteed to be less than or equal to MAX_LONG 
 * then you should use MIN_S_FLEXIBLE.  For example: if one of the operands is a signed char, 
 * unsigned char, short, unsigned short, int, or long (that is: signed int or signed long), then you
 * are safe using MIN_S_FLEXIBLE.
 */
#define _MIN_U_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?(x):(((y)<0&&(x)>=0)?(y):(((x)<(y))?(x):(y))))

/**
 * This macro uses `_MIN_S_FLEXIBLE', but checks to see if the result would be of the wrong type, and 
 * if so causes a divide-by-zero error so that you can locate and debug the problem (by changing it 
 * from `_MIN_S_DEBUG' to `_MIN_U_DEBUG').
 */
#define _MIN_S_DEBUG(x, y) (((x)>MAX_LONG&&(y)>MAX_LONG)?(1/0):_MIN_S_FLEXIBLE(x, y))

/**
 * This macro uses MIN_U_FLEXIBLE, but checks to see if the result would be of the wrong type, and 
 * if so causes a divide-by-zero error so that you can locate and debug the problem (by changing it 
 * from `_MIN_U_DEBUG' to `MIN_S_DEBUG').
 */
#define _MIN_U_DEBUG(x, y) (((x)<0||(y)<0)?(1/0):_MIN_U_FLEXIBLE(x, y))

/**
 * Min/max macros that are fast but unsafe.
 */
#define _MIN_UNSAFE(x, y) ((x)<(y)?(x):(y))
#define _MAX_UNSAFE(x, y) ((x)>(y)?(x):(y))

#ifdef __GNUC__
/**
 * This MIN macro tries to just do what you would expect, but the result is cast to type `long long', 
 * which means that if both of the operands are unsigned long longs and both are larger than 
 * MAX_LONGLONG (i.e., so big that they cannot be represented normally in a signed long long), then 
 * the answer will be of the wrong type, and could also (depending on your C implementation) be 
 * screwed up in some other way.
 */
#define _MIN_LLS_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?((long long)x):(((y)<0&&(x)>=0)?((long long)y):(((x)<(y))?((long long)x):((long long)y))))

/**
 * This MIN macro tries to just do what you would expect, but if the winning operand is a negative 
 * signed integer and the other operand is of `unsigned long long' type, then the result will be the
 * correct answer (the value of the winning operand) but it will be cast to type `unsigned long 
 * long'.  This will work, with GCC, if the context in which you are calling `_MIN_LLU_FLEXIBLE' 
 * coerces the value back to signed type, for example: `int x = _MIN_LLU_FLEXIBLE(-2, 1ULL);' will 
 * do what you expect (although it is not required to do by the standard).  However it will not do 
 * what you expect if the context does not coerce the value to a signed, for example 
 * `_MIN_LLU_FLEXIBLE(-2, 1ULL) > 0' will evaluate to true.
 *
 * If you know that at least one of the operands is guaranteed to be less than or equal to 
 * MAX_LONGLONG then you should use `_MIN_LLS_FLEXIBLE'.  For example: if one of the operands is a 
 * signed char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, or 
 * long long (that is: signed long long), then you are safe using `_MIN_LLS_FLEXIBLE'.
 */
#define _MIN_LLU_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?((unsigned long long)x):(((y)<0&&(x)>=0)?((unsigned long long)y):(((x)<(y))?((unsigned long long)x):((unsigned long long)y))))

/** 
 * Min/max macros that give compiler errors if used on different types of operands, but that rely on 
 * GCC extensions that are not part of ANSI/ISO C89.
 */
#define _MIN_STRICT(x, y) ({const typeof(x) _x = x; const typeof(y) _y = y; &_x==&_y; (_x<_y)?_x:_y;})
#define _MAX_STRICT(x, y) ({const typeof(x) _x = x; const typeof(y) _y = y; &_x==&_y; (_x>_y)?_x:_y;})

#endif /* #ifdef __GNUC__ */





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
 * This MAX macro just does what you expect.  It evaluates to the largest of the two operands, and 
 * the type of the result is a reasonable type for storing that result, for example it is a signed 
 * int if the winning operand was a signed int, it is an unsigned int if the winning operand was an 
 * unsigned int, it is a double if the winning operand were a double, etc. XXX
 *
 * You can even use `MAX_FLEXIBLE' on pairs of pointers and it will do the correct thing for pointer
 * comparison in C.  (Note: you may be surprised if you don't know what the correct thing for 
 * pointer comparison in C *is*, exactly.  It isn't a simple rule of "compare memory addresses 
 * numerically".)
 */
#define _MAX_FLEXIBLE(x, y) (((x)>0&&(y)<=0)?(x):(((y)>0&&(x)<=0)?(y):(((x)>(y))?(x):(y))))

/**
 * This MIN macro tries to just do what you would expect, but the result is cast to type `long', 
 * which means that if both of the operands are unsigned longs and both are larger than MAX_LONG 
 * (i.e., so big that they cannot be represented normally in a signed long), then the answer will be 
 * of the wrong type, and could also (depending on your C implementation) be screwed up in some 
 * other way.
 */
#define _MIN_S_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?((long)x):(((y)<0&&(x)>=0)?((long)y):(((x)<(y))?((long)x):((long)y))))

#ifdef __GNUC__
/**
 * This MIN macro tries to just do what you would expect, but the result is cast to type `long long', 
 * which means that if both of the operands are unsigned long longs and both are larger than 
 * MAX_LONGLONG (i.e., so big that they cannot be represented normally in a signed long long), then 
 * the answer will be of the wrong type, and could also (depending on your C implementation) be 
 * screwed up in some other way.
 */
#define _MIN_LLS_FLEXIBLE(x, y) ((long long)(((x)<0&&(y)>=0)?(x):(((y)<0&&(x)>=0)?(y):(((x)<(y))?(x):(y)))))
#endif /* #ifdef __GNUC__ */

/**
 * This MIN macro tries to just do what you would expect, but if the winning operand is a negative 
 * signed integer and the other operand is of `unsigned int' or `unsigned long' type, then the 
 * result will be the correct answer (the value of the winning operand) but it will be cast to type 
 * `unsigned long'.  This will work, on most C implementations, if the context in which you are 
 * calling `_MIN_U_FLEXIBLE' coerces the value back to signed type, for example: 
 * `int x = _MIN_U_FLEXIBLE(-2, 1UL)' will do what you expect on most C implementations (although it
 * is not required to do by the standard).  However it will not do what you expect if the context 
 * does not coerce the value to a signed, for example `_MIN_U_FLEXIBLE(-2, 1UL) > 0' will evaluate 
 * to true.
 *
 * If you know that at least one of the operands is guaranteed to be less than or equal to MAX_LONG 
 * then you should use `_MIN_S_FLEXIBLE'.  For example: if one of the operands is a signed char, 
 * unsigned char, short, unsigned short, int, or long (that is: signed int or signed long), then you
 * are safe using `_MIN_S_FLEXIBLE'.
 */
#define _MIN_U_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?(x):(((y)<0&&(x)>=0)?(y):(((x)<(y))?(x):(y))))

/**
 * This MIN macro tries to just do what you would expect, but if the winning operand is a negative 
 * signed integer and the other operand is of `unsigned long long' type, then the result will be the 
 * correct answer (the value of the winning operand) but it will be cast to type `unsigned long 
 * long'.  This will work, on GCC, if the context in which you are calling `_MIN_LLU_FLEXIBLE' 
 * coerces the value back to signed type, for example: `int x = _MIN_LLU_FLEXIBLE(-2, 1ULL)' will do
 * what you expect on GCC.  However it will not do what you expect if the context does not coerce 
 * the value to a signed, for example `_MIN_LLU_FLEXIBLE(-2, 1ULL) > 0' will evaluate to true.
 *
 * If you know that at least one of the operands is guaranteed to be less than or equal to 
 * MAX_LONGLONG then you should use `_MIN_LLS_FLEXIBLE'.  For example: if one of the operands is a 
 * signed char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, or 
 * long long (that is: signed long long), then you are safe using `_MIN_LLS_FLEXIBLE'.
 */
#define _MIN_LLU_FLEXIBLE(x, y) (((x)<0&&(y)>=0)?(x):(((y)<0&&(x)>=0)?(y):(((x)<(y))?(x):(y))))

/**
 * This macro uses MIN_S_FLEXIBLE, but checks to see if the result would be of the wrong type, and 
 * if so causes a divide-by-zero error so that you can locate and debug the problem (by changing it 
 * to `MIN_U_DEBUG').
 */
#define _MIN_S_DEBUG(x, y) (((x)>MAX_LONG&&(y)>MAX_LONG)?(1/0):MIN_S_FLEXIBLE(x, y))

/**
 * This macro uses MIN_U_FLEXIBLE, but checks to see if the result would be of the wrong type, and 
 * if so causes a divide-by-zero error so that you can locate and debug the problem (by changing it 
 * to `MIN_S_DEBUG').
 */
#define _MIN_U_DEBUG(x, y) (((x)<0||(y)<0)?(1/0):MIN_U_FLEXIBLE(x, y))

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
