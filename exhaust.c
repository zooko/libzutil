/**
 * copyright 2002-2004 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the simple, permissive free software, open 
 * source license.
 */
#include "exhaust.h"

#include <stdio.h>
#include <stdlib.h>

void _z_printerr_and_exit(const char*const msg, const char*const filename, unsigned long lineno)
{
	fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, msg);
	fflush(stderr);
	exit(EXIT_FAILURE);
}

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
