#ifndef __INCL_moreassert_h
#define __INCL_moreassert_h

#include "moreassertimp.h" /* implementation stuff that you needn't see in order to use the library */

/**
 * runtime_assert() gets checked even if NDEBUG is set.
 *
 * A typical use of runtime_assert() is to test input and exit if the input 
 * isn't correct.  You shouldn't use normal assert() for this, because you 
 * ought to test the input even if the program was compiled with the NDEBUG 
 * flag.
 *
 * Use it like this:
 * void runtime_assert(int condition, const char* msg);
 */
#define runtime_assert(expr, msg) _runtime_assert(expr, msg)

#endif /* #ifndef __INCL_moreassert_h */
