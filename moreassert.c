#include "moreassert.h"

#include <stdio.h>
#include <stdlib.h>

void _verbose_abort(char const*const filename, const int lineno, char const*const funcname, char const* msg) {
	if (msg == NULL) { msg = ""; }
	fprintf(stderr, "%s: %d: %s: %s", filename, lineno, funcname, msg);
	exit(EXIT_FAILURE);
}

void _verbose_abort2(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s", filename, lineno, funcname, msg1, msg2);
	exit(EXIT_FAILURE);
}

void _verbose_abort3(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2, char const* msg3) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	if (msg3 == NULL) { msg3 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s%s", filename, lineno, funcname, msg1, msg2, msg3);
	exit(EXIT_FAILURE);
}

void _verbose_abort4(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2, char const* msg3, char const* msg4) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	if (msg3 == NULL) { msg3 = ""; }
	if (msg4 == NULL) { msg4 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s%s%s", filename, lineno, funcname, msg1, msg2, msg3, msg4);
	exit(EXIT_FAILURE);
}

void _verbose_abort5(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2, char const* msg3, char const* msg4, char const* msg5) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	if (msg3 == NULL) { msg3 = ""; }
	if (msg4 == NULL) { msg4 = ""; }
	if (msg5 == NULL) { msg5 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s%s%s%s", filename, lineno, funcname, msg1, msg2, msg3, msg4, msg5);
	exit(EXIT_FAILURE);
}

void _verbose_abort6(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2, char const* msg3, char const* msg4, char const* msg5, char const* msg6) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	if (msg3 == NULL) { msg3 = ""; }
	if (msg4 == NULL) { msg4 = ""; }
	if (msg5 == NULL) { msg5 = ""; }
	if (msg6 == NULL) { msg6 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s%s%s%s%s", filename, lineno, funcname, msg1, msg2, msg3, msg4, msg5, msg6);
	exit(EXIT_FAILURE);
}

void _verbose_abort7(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2, char const* msg3, char const* msg4, char const* msg5, char const* msg6, char const* msg7) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	if (msg3 == NULL) { msg3 = ""; }
	if (msg4 == NULL) { msg4 = ""; }
	if (msg5 == NULL) { msg5 = ""; }
	if (msg6 == NULL) { msg6 = ""; }
	if (msg7 == NULL) { msg7 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s%s%s%s%s%s", filename, lineno, funcname, msg1, msg2, msg3, msg4, msg5, msg6, msg7);
	exit(EXIT_FAILURE);
}

void _verbose_abort8(char const*const filename, const int lineno, char const*const funcname, char const* msg1, char const* msg2, char const* msg3, char const* msg4, char const* msg5, char const* msg6, char const* msg7, char const* msg8) {
	if (msg1 == NULL) { msg1 = ""; }
	if (msg2 == NULL) { msg2 = ""; }
	if (msg3 == NULL) { msg3 = ""; }
	if (msg4 == NULL) { msg4 = ""; }
	if (msg5 == NULL) { msg5 = ""; }
	if (msg6 == NULL) { msg6 = ""; }
	if (msg7 == NULL) { msg7 = ""; }
	if (msg8 == NULL) { msg8 = ""; }
	fprintf(stderr, "%s: %d: %s: %s%s%s%s%s%s%s%s", filename, lineno, funcname, msg1, msg2, msg3, msg4, msg5, msg6, msg7, msg8);
	exit(EXIT_FAILURE);
}
