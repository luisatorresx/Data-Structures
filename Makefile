# Build every program into build/<folder-name>
#
#   make                                   build all programs
#   make run P=03-infix-to-postfix-stack   build and run one program
#   make test                              build all and run the tests
#   make clean                             remove build/

CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2

SRCS     := $(wildcard */main.cpp)
PROGRAMS := $(patsubst %/main.cpp,build/%,$(SRCS))

# Accept "P=03-infix-to-postfix-stack/" (tab completion adds the slash)
override P := $(patsubst %/,%,$(P))

.PHONY: all run test clean

all: $(PROGRAMS)

.SECONDEXPANSION:
build/%: %/main.cpp $$(wildcard %/*.h) | build
	$(CXX) $(CXXFLAGS) -o $@ $<

build:
	mkdir -p build

# Runs inside build/run-<folder> with a copy of any data files, so the
# merge sorts never overwrite the original datos.txt
run: $(if $(P),build/$(P))
	$(if $(P),,$(error Usage: make run P=<folder>, for example: make run P=03-infix-to-postfix-stack))
	@rm -rf build/run-$(P) && mkdir -p build/run-$(P)
	@cp $(P)/*.txt build/run-$(P)/ 2>/dev/null || true
	@cd build/run-$(P) && ../$(P)

test: all
	@bash tests/run_tests.sh

clean:
	rm -rf build
