#include "delegate.h"
#include "moreassert.h"
#include <stdlib.h>

void* invoke(delegate f, void*data) {
	return f.meth(f.self, data);
}
