/**
 * copyright 2004 Bryce "Zooko" Wilcox-O'Hearn
 * mailto:zooko@zooko.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software to deal in this software without restriction (including the
 * rights to use, modify, distribute, sublicense, and/or sell copies) provided
 * that the above copyright notice and this permission notice is included in
 * all copies or substantial portions of this software. THIS SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED.
 */

#ifndef __INCL_zlistimp_h
#define __INCL_zlistimp_h

#define DECLARE_ZLIST(typ, nam) \
typedef struct { \
	size_t len; \
	typ* arr; \
} nam; \
void nam##_resize(nam* l, size_t len); \
void nam##_append(nam* l, typ item); \
void nam##_free(nam* l);

#define DECLARE_ZLIST_CONTAINS_ITEM(typ, nam) \
bool nam##_contains_item(nam l, typ item);

#define DEFINE_ZLIST(typ, nam) \
void nam##_resize(nam* l, size_t len) { \
	l->arr = (typ*)realloc(l->arr, sizeof(typ) * len);	\
	runtime_assert((len == 0) || (l->arr != NULL), "memory exhaustion"); \
	l->len = len; \
} \
 \
void nam##_append(nam*const l, const typ item) { \
	runtime_assert(l != NULL, "You are required to pass a non-NULL pointer."); \
	nam##_resize(l, l->len+1); \
	l->arr[l->len-1] = item; \
} \
 \
void nam##_free(nam*const l) { \
	runtime_assert(l != NULL, "You are required to pass a non-NULL pointer."); \
	if (l->arr != NULL) { free(l->arr); l->arr = NULL; } \
	l->len = 0; \
}

#define DEFINE_ZLIST_CONTAINS_ITEM(typ, nam) \
bool nam##_contains_item(const nam l, const typ item) { \
	size_t i; \
	for (i = 0; i < l.len; i++) { \
		if (l.arr[i] == item) { \
			return true; \
		} \
	} \
	return false; \
}

#endif /* #ifndef __INCL_zlistimp_h */
