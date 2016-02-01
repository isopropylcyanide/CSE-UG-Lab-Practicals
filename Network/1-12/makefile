TARGETS = stringRevClient stringRevServer

CFLAGS= -Wall  -fpic -std=c11 
Compiler= $(CROSS_TOOL)clang

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.c -o $@

clean:
	@rm -f $(TARGETS)
