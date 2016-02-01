TARGETS = file_alloc

CFLAGS= -Wall -Werror -fpic -std=c++0x
Compiler= $(CROSS_TOOL)g++

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.cpp -o $@

clean:
	@rm -f $(TARGETS)
