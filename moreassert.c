#include "moreassert.h"

#include <stdlib.h>

int _runtime_assert_fail(char const*const filename, const int lineno, char const*const funcname, char const*const expr, char const*const msg) {
	fprintf(stderr, "%s\n\n%s: %d: %s: Assertion `%s' failed.  Exiting.", msg, filename, lineno, funcname, expr);
	exit(EXIT_FAILURE);
	return 1;
}
