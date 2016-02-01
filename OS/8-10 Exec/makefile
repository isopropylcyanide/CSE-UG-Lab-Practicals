TARGETS = count mncount

CFLAGS= -Wall -Werror -fpic -std=c11
Compiler= $(CROSS_TOOL)gcc

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.c -o $@

clean:
	@rm -f $(TARGETS)
