TARGET    := $(patsubst %-gcc,%,$(GCCEXE))
CC         = $(TARGET)-gcc
GCC        = $(TARGET)-g++

TOP = $(shell pwd)
SRCDIR = $(TOP)/src
INCDIR = $(TOP)/headers

MAIN = \
	$(TOP)/main.cpp

SOURCES = \
	$(wildcard $(SRCDIR)/*.cpp )

INCLUDES = \
	-I$(INCDIR)

CFLAGS = \
	-std=c++17 \
	-lm \
	-fpermissive

mj: $(SOURCES)
	$(GCC) -o $@ $^ $(MAIN) $(INCLUDES) $(CFLAGS)
 