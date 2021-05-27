LIBNAME = libkzeliloj

SRCDIR = src
LIBDIR = include
OBJDIR = obj

INSTALL_DIR ?= /usr

CC ?= gcc
LC ?= gcc

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

.PHONY : doc clear mrproper

doc:
	doxygen Doxyfile

install: all
	install -d $(INSTALL_DIR)/lib
	install -d $(INSTALL_DIR)/include/kzeliloj
	install -m 644 $(LIBDIR)/kzeliloj/*.h $(INSTALL_DIR)/include/kzeliloj
	install -m 644 $(LIBNAME).so.1.0      $(INSTALL_DIR)/lib
	ln -sf  $(LIBNAME).so.1.0 $(INSTALL_DIR)/lib/$(LIBNAME).so
	ln -sf  $(LIBNAME).so.1.0 $(INSTALL_DIR)/lib/$(LIBNAME).so.1

example:
	@make -C examples/ all

clear :
	rm -rf $(OBJDIR)/
	@make -C examples/ clean

mrproper : clear
	rm -f $(LIBNAME).so*
	@make -C examples/ mrproper
