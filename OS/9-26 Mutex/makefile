TARGETS = mutex

CFLAGS= -Wall -Werror -fpic -std=c11 -pthread
Compiler= $(CROSS_TOOL)gcc

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.c -o $@

clean:
	@rm -f $(TARGETS)
