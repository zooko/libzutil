/**
 * copyright 2002 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the free software, open source license (BSD-style).
 */
#ifndef __INCL_exhaust_h
#define __INCL_exhaust_h

static char const* const exhaust_h_cvsid = "$Id: exhaust.h,v 1.1 2002/02/08 17:30:54 zooko Exp $";

static int const exhaust_vermaj = 0;
static int const exhaust_vermin = 1;
static int const exhaust_vermicro = 0;
static char const* const exhaust_vernum = "0.1.0";

void _z_printerr_and_exit(const char*const msg, const char*const filename, unsigned long lineno);

#define ERRNEXIT(msg) _z_printerr_and_exit((msg), __FILE__, __LINE__)

#define EXHAUSTERR(msg) ERRNEXIT("memory exhaustion: " msg " -- exiting")

#define CHECKMALLOCEXIT(x) if ((x) == NULL) EXHAUSTERR(#x)

#ifdef Z_EXHAUST_EXIT
#define CHECKMALLOC(x) CHECKMALLOCEXIT(x)
#else
#define CHECKMALLOC(x) ((void)0)
#endif /* #ifdef Z_EXHAUST_EXIT */

#endif /* #ifndef __INCL_exhaust_h */

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
