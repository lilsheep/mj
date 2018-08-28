CC         = -gcc
GCC        = -g++

TOP = $(shell pwd)
SRCDIR = $(TOP)/src
INCDIR = $(TOP)/headers

SOURCES = \
	$(wildcard $(SRCDIR)/*.cpp )

INCLUDES = \
	-I$(INCDIR)

CFLAGS = \
	-std=c++17 \
	-lm 

mj: $(SOURCES)
	$(GCC) -o $@ $^ $(INCLUDES) $(CFLAGS)
 