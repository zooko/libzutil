#include "stdio.h"

#include "zstr.h"

/* An assertion failure message will look like this: */
/* test.c:238: test_minmax_strict: Assertion `1==0' failed. */
int _runtime_assert_fail(char const* filename, int lineno, char const* funcname, char const* expr, char const* msg);

#define _runtime_assert(expr, msg) ((void)((expr) ? 0 : _runtime_assert_fail(__FILE__, __LINE__,  __func__, #expr, msg)))

