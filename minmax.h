/**
 * copyright 2002, 2003 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license 
 * (BSD-style).
 */
#ifndef __INCL_minmax_h
#define __INCL_minmax_h

/**
 * How to use these macros:
 *
 * You can use the MAX() macro safely.  You can use the MIN() macro safely xxx
XXXXX
 *
 * If you know that at least one of the operands is guaranteed to be less than 
 * or equal to MAX_LLONG then you should use _MIN_LLS_FLEXIBLE.  For example: 
 * if one of the operands is a signed char, unsigned char, short, 
 * unsigned short, int, unsigned int, long, unsigned long, or long long (that 
 * is: signed long long), then you are safe using _MIN_LLS_FLEXIBLE.
 */



/**
 * This macro just does what you expect.  It evaluates to the largest of the 
 * two operands, and the type of the result is a reasonable type for storing 
 * that result, for example it is a signed int if both the operands were 
 * signed ints, it is an unsigned int if either operand was an unsigned int, 
 * it is a double if either operands were a double, etc.
 *
 * You can even use _MAX on pairs of pointers and it will do the correct thing 
 * for pointer comparison in C.  (Note: you may be surprised if you don't know 
 * what the correct thing for pointer comparison in C *is*, exactly.  It isn't 
 * a simple rule of "compare memory addresses numerically".)
 */
#define _MAX(x, y) (((x)>0&&(y)<=0)?(x):(((y)>0&&(x)<=0)?(y):(((x)>(y))?(x):(y))))

/**
 * This MIN macro tries to just do what you would expect, but the result is 
 * cast to type long long, which means that if both of the operands are 
 * unsigned long longs and both are larger than MAX_LLONG (i.e., so big that 
 * they cannot be represented normally in a signed long long), then the answer 
 * will be of the wrong type (signed long long), and could also (depending on 
 * your C implementation) have an incorrect value.  On some C implementations 
 * (e.g. GCC), the answer will actually have the right value and casting it 
 * back to unsigned long long will fix it.
XXX
 */
#define _MIN_LLS(x, y) (((x)<0&&(y)>=0)?((long long)(x)):(((y)<0&&(x)>=0)?((long long)(y)):(((x)<(y))?((long long)(x)):((long long)(y)))))

/**
 * This MIN macro tries to just do what you would expect, but if the winning 
 * operand is a negative signed integer and the other operand is of unsigned 
 * long long type, then the result will be the correct answer (the value of 
 * the winning operand) but it will be cast to type unsigned long long.  This 
 * will work, with GCC, if the context in which you are calling 
 * _MIN_LLU_FLEXIBLE coerces the value back to signed type, for example: 
 * int x = _MIN_LLU_FLEXIBLE(-2, 1ULL);
 * will do what you expect (although it is not required to do by the 
 * standard).  However it will not do what you expect if the context does not 
 * coerce the value to a signed, for example:
 * _MIN_LLU_FLEXIBLE(-2, 1ULL) > 0
 * will evaluate to true!
 */
#define _MIN_LLU(x, y) (((x)<0&&(y)>=0)?(x):(((y)<0&&(x)>=0)?(y):(((x)<(y))?((unsigned long long)(x)):((unsigned long long)(y)))))

/**
 * Min/max macros that are fast but unsafe.  If one of the arguments is 
 * negative and the other is of unsigned type, you'll get the wrong answer.  
 */
#define _MIN_FAST(x, y) ((x)<(y)?(x):(y))
#define _MAX_FAST(x, y) ((x)>(y)?(x):(y))


#endif /* #ifndef __INCL_minmax_h */

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
