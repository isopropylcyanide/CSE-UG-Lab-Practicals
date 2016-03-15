TARGETS = ellipse

CFLAGS= -Wall -fpic -std=c++14 -lgraph
Compiler= $(CROSS_TOOL)clang++

all:clean $(TARGETS)

$(TARGETS):
	@$(Compiler) $(CFLAGS) $@.cpp -o $@

clean:
	@rm -f $(TARGETS)
