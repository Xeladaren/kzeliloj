LIBNAME = libkzeliloj

SRCDIR = src
LIBDIR = include
OBJDIR = obj

INSTALL_DIR = /usr/lib

CC = gcc
LC = gcc

## CC Options ##
CCFLAGS += -I./$(LIBDIR)
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -std=c11
CCFLAGS += -fPIC
CCFLAGS += -g

## LD Options ##
LDFLAGS += -shared
LDFLAGS += -Wl,-soname,$(LIBNAME).so.1
LDFLAGS += -g

SRC=$(shell find $(SRCDIR)/ -type f -name '*.c')
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all : $(LIBNAME).so.1.0 $(LIBNAME).so.1 $(LIBNAME).so

$(LIBNAME).so : $(LIBNAME).so.1.0
	ln -s $< $@

$(LIBNAME).so.1 : $(LIBNAME).so.1.0
	ln -s $< $@

$(LIBNAME).so.1.0 : $(OBJ)
	$(LC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p `dirname $@`
	@mkdir -p $(LIBDIR)

	$(CC) $(CCFLAGS) -c $< -o $@

install: all
	install $(LIBNAME).so     $(INSTALL_DIR)
	install $(LIBNAME).so.1   $(INSTALL_DIR)
	install $(LIBNAME).so.1.0 $(INSTALL_DIR)

example:
	@make -C examples/ all

clear :
	rm -rf $(OBJDIR)/
	@make -C examples/ clean

mrproper : clear
	rm -f $(LIBNAME).so*
	@make -C examples/ mrproper
