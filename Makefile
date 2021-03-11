LIBNAME = libkzeliloj

SRCDIR = src
LIBDIR = include
OBJDIR = obj

CC = gcc
LC = gcc

## CC Options ##
CCFLAGS += -I$(LIBDIR)
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -std=c11
CCFLAGS += -fPIC

## LD Options ##
LDFLAGS += -fPIC
LDFLAGS += -shared

SRC=$(shell find $(SRCDIR)/ -type f -name '*.c')
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all : $(LIBNAME).so.1.0.0 $(LIBNAME).so.1 $(LIBNAME).so

$(LIBNAME).so : $(LIBNAME).so.1.0.0
	ln -s $< $@

$(LIBNAME).so.1 : $(LIBNAME).so.1.0.0
	ln -s $< $@

$(LIBNAME).so.1.0.0 : $(OBJ)
	$(LC) $(OBJ) $(LDFLAGS) -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p `dirname $@`
	@mkdir -p $(LIBDIR)

	$(CC) -c $(CCFLAGS) $< -o $@

example:
	@make -C examples/ all

clear :
	rm -rf $(OBJDIR)/

mrproper : clear
	rm -f $(LIBNAME).so*
