NAME=zutil

LIBPREFIX=lib
LIBSUFFIX=.a

RANLIB=ranlib
AR=ar

# CC=gcc-3.3
# CPPFLAGS=-UNDEBUG -std=c99
CPPFLAGS=-DNDEBUG
CFLAGS=-Wall -O2
# LDFLAGS += -g

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
ifneq (,$(TESTSRCS:%.c=%.d))
-include $(TESTSRCS:%.c=%.d)
endif
endif


%.d: %.c
	@echo remaking $@
	@set -e; $(CC) $(CPPFLAGS) $(CFLAGS) -MM $< \
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
