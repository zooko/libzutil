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
