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

#ifndef __INCL_exhaust_h
#define __INCL_exhaust_h

static char const* const exhaust_h_cvsid = "$Id: exhaust.h,v 1.4 2004/03/12 16:49:05 zooko Exp $";

static int const exhaust_vermaj = 0;
static int const exhaust_vermin = 9;
static int const exhaust_vermicro = 0;
static char const* const exhaust_vernum = "0.9.0";

void _z_printerr_and_exit(const char*const msg, const char*const filename, unsigned long lineno);

#define ERRNEXIT(msg) _z_printerr_and_exit((msg), __FILE__, __LINE__)

#define EXHAUSTERR(msg) ERRNEXIT("memory exhaustion: " msg " -- exiting")

#define CHECKMALLOCEXIT(x) if ((x) == NULL) EXHAUSTERR(#x)

#define CHECKMALLOC(x) CHECKMALLOCEXIT(x)

#endif /* #ifndef __INCL_exhaust_h */
