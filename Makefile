#++ Compiler
CXX := g++
#
#
# Flags
#
#   Compiler
CXXFLAGS +=-c -std=c++11 -fprofile-arcs -ftest-coverage
#
#   Linker
LDFLAGS += -g --coverage
#
#   Library
LIBFLAGS :=
#
#   Include
INCLUDEFLAGS :=
#
#
# Program name
EXE := calc
#
#
# Directories
#
#   Headers
HEADERDIR := ./headers
#
#   Sources
SRCDIR := ./source
#
#   Objects
OBJDIR := obj
#
#   Binary
BINDIR := bin
#
#
################################################################################

HEADERS := $(wildcard $(HEADERDIR)/*.h)
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(subst $(SRCDIR)/,$(OBJDIR)/,$(SRCS:.cpp=.o))

CXXFLAGS += $(INCLUDEFLAGS) -I$(HEADERDIR)
LDFLAGS += $(LIBFLAGS)

.PHONY: all clean distclean

all: $(BINDIR)/$(EXE)

$(BINDIR)/$(EXE): $(OBJS)
	mkdir -p $(BINDIR)
	$(CXX) $(LDFLAGS) $? -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(EXE)

distclean: clean
