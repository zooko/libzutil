/**
 * copyright 2002-2004 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * See the end of this file for the simple, permissive free software, open 
 * source license.
 */
#include "stdio.h"

void _verbose_abort(char const* filename, int lineno, char const* funcname, char const* msg);
void _verbose_abort2(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2);
void _verbose_abort3(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2, const char* msg3);
void _verbose_abort4(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2, const char* msg3, const char* msg4);
void _verbose_abort5(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2, const char* msg3, const char* msg4, const char* msg5);
void _verbose_abort6(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2, const char* msg3, const char* msg4, const char* msg5, const char* msg6);
void _verbose_abort7(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2, const char* msg3, const char* msg4, const char* msg5, const char* msg6, const char* msg7);
void _verbose_abort8(char const* filename, int lineno, char const* funcname, char const* msg1, const char* msg2, const char* msg3, const char* msg4, const char* msg5, const char* msg6, const char* msg7, const char* msg8);

#define verbose_abort(msg) ((void)(_verbose_abort(__FILE__, __LINE__,  __func__, (msg))))
#define verbose_abort2(msg1, msg2) ((void)(_verbose_abort2(__FILE__, __LINE__,  __func__, (msg1), (msg2))))
#define verbose_abort3(msg1, msg2, msg3) ((void)(_verbose_abort3(__FILE__, __LINE__,  __func__, (msg1), (msg2), (msg3))))
#define verbose_abort4(msg1, msg2, msg3, msg4) ((void)(_verbose_abort4(__FILE__, __LINE__,  __func__, (msg1), (msg2), (msg3), (msg4))))
#define verbose_abort5(msg1, msg2, msg3, msg4, msg5) ((void)(_verbose_abort5(__FILE__, __LINE__,  __func__, (msg1), (msg2), (msg3), (msg4), (msg5))))
#define verbose_abort6(msg1, msg2, msg3, msg4, msg5, msg6) ((void)(_verbose_abort6(__FILE__, __LINE__,  __func__, (msg1), (msg2), (msg3), (msg4), (msg5), (msg6))))
#define verbose_abort7(msg1, msg2, msg3, msg4, msg5, msg6, msg7) ((void)(_verbose_abort7(__FILE__, __LINE__,  __func__, (msg1), (msg2), (msg3), (msg4), (msg5), (msg6), (msg7))))
#define verbose_abort8(msg1, msg2, msg3, msg4, msg5, msg6, msg7, msg8) ((void)(_verbose_abort8(__FILE__, __LINE__,  __func__, (msg1), (msg2), (msg3), (msg4), (msg5), (msg6), (msg7), (msg8))))

#define runtime_assert(expr, msg) ((void)((expr) ? ((void)0) : verbose_abort4("Assertion `", #expr, "' failed.; ", msg)))
#define runtime_assert2(expr, msg1, msg2) ((void)((expr) ? ((void)0) : verbose_abort6("Assertion `", #expr, "' failed.; ", (msg1), "; ", (msg2))))
#define runtime_assert3(expr, msg1, msg2, msg3) ((void)((expr) ? ((void)0) : verbose_abort8("Assertion `", #expr, "' failed.; ", (msg1), "; ", (msg2), "; ", (msg3))))

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
