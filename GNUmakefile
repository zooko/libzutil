NAME=zutil

LIBPREFIX=lib
LIBSUFFIX=.a

RANLIB=ranlib
AR=ar

CFLAGS_FOR_LIBRARY=-Wall -O2
CFLAGS_FOR_TEST=-Wall -O0 -UNDEBUG
# I would like to set these pedantic flags when compiling the library but not when compiling the test, but that would require writing my own .c -> .o rule...  So I just comment these lines in and out when compiling.  --Zooko 2002-09-03
# CFLAGS=$(CFLAGS_FOR_LIBRARY)
CFLAGS=$(CFLAGS_FOR_TEST)

# SRCS=$(wildcard *.c)
SRCS=zutil.c exhaust.c
TESTSRCS=test.c
OBJS=$(SRCS:%.c=%.o)
TESTOBJS=$(TESTSRCS:%.c=%.o)
TEST=test
LIB=$(LIBPREFIX)$(NAME)$(LIBSUFFIX)

all: $(LIB) $(TEST)

# .d auto-dependency files
ifneq ($(findstring clean,$(MAKECMDGOALS)),clean)
ifneq (,$(SRCS:%.c=%.d))
-include $(SRCS:%.c=%.d)
endif
endif


%.d: %.c
	@echo remaking $@
	@set -e; $(CC) -MM $(CFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
	[ -s $@ ] || rm -f $@

$(LIB): $(OBJS)
	$(AR) -r $@ $+
	$(RANLIB) $@

$(TEST): $(TESTOBJS) $(LIB)
	$(CC) $(LDFLAGS) $+ -o $@

clean:
	-rm $(LIB) $(OBJS) $(TEST) $(TESTOBJS) *.d 2>/dev/null

.PHONY: clean all
