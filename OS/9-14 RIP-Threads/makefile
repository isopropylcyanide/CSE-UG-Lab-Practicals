TARGETS = rip-th

CFLAGS= -Wall -Werror -fpic -std=c99 -pthread -lncurses
Compiler= $(CROSS_TOOL)gcc

all:clean $(TARGETS)

$(TARGETS):
	$(Compiler) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)
