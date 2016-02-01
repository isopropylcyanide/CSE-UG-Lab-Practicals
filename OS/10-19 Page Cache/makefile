TARGETS = page_rep

CFLAGS= -Wall -Werror -fpic -std=c++11
Compiler= $(CROSS_TOOL)g++

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.cpp -o $@

clean:
	@rm -f $(TARGETS)
