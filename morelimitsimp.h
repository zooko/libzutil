/**
 * copyright 2002, 2003 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_morelimitsimp_h
#define __INCL_morelimitsimp_h

#define Z_MAX_UNSIGNED(typ) ((typ)(~((typ)0)))
#define Z_MIN_UNSIGNED(typ) ((typ)0)

/* The following Z_MAX_SIGNED and Z_MIN_SIGNED macros will work on any C 
   implementation where the maximum value of a signed type (called typ) is 
   equal to 2^(sizeof(typ)*CHAR_BIT) - 1, and the minimum value of a signed 
   type is equal to the -1*(maximum value+1). */
#define Z_SIGNED_HIGH_BIT(typ) ((typ)((typ)1 << ((sizeof(typ)*CHAR_BIT)-2)))
#define Z_SIGNED_LOW_BITS(typ) ((typ)(Z_SIGNED_HIGH_BIT(typ)-1))
#define Z_MAX_SIGNED(typ) ((typ)(Z_SIGNED_HIGH_BIT(typ) + Z_SIGNED_LOW_BITS(typ)))
#define Z_MIN_SIGNED(typ) ((typ)((-Z_MAX_SIGNED(typ))-1))

#define Z_MAX(typ) ((Z_MAX_SIGNED(typ) > Z_MAX_UNSIGNED(typ))?Z_MAX_SIGNED(typ):Z_MAX_UNSIGNED(typ))
#define Z_MIN(typ) ((Z_MIN_SIGNED(typ) < Z_MIN_UNSIGNED(typ))?Z_MIN_SIGNED(typ):Z_MIN_UNSIGNED(typ))

#define Z_UNSIGNED_HIGH_BIT_BITS(b) (1 << ((b)-1))
#define Z_UNSIGNED_LOW_BITS_BITS(b) (Z_UNSIGNED_HIGH_BIT_BITS(b)-1)
#define Z_MAX_UNSIGNED_BITS(b) (Z_UNSIGNED_HIGH_BIT_BITS(b) | Z_UNSIGNED_LOW_BIT_BITS(b))

#endif /* #ifndef __INCL_morelimitsimp_h */

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
