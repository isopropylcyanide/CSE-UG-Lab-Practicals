TARGETS = steganography

CFLAGS= -Wall -fpic -std=c11 -lm
Compiler= $(CROSS_TOOL)clang

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.c -o $@

clean:
	@rm -f $(TARGETS)
