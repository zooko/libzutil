#include "delegate.h"
#include "moreassert.h"
#include <stdlib.h>

delegate* make_delegate(void*obj, void (*meth)(void*)) {
	delegate* d = (delegate*)malloc(sizeof(delegate));
	runtime_assert((d != NULL), "memory exhaustion: malloc returned NULL");
	d->obj = obj;
	d->meth = meth;
	return d;
}

void invoke(delegate* f) {
	f->meth(f->obj);
}
