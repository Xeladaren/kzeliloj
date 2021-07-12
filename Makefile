LIBNAME = libkzeliloj

SRC_DIR     = src
INCLUDE_DIR = include

INSTALL_DIR_LIB ?= /usr/lib/arm-linux-gnueabihf
INSTALL_DIR_INCLUDE ?= /usr/include

CC = arm-linux-gnueabihf-gcc
LD = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar

## CC Options ##
CCFLAGS += -I./$(INCLUDE_DIR)
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -std=c11
CCFLAGS += -fPIC
# DEBUG options
# CCFLAGS += -g -DDEBUG

## LD Options ##
# LDFLAGS += -Wl,-soname=$(LIBNAME).so.$(LIB_VERSION_MAJOR)
# DEBUG options
LDFLAGS += -g -DDEBUG

SRC = $(shell find $(SRC_DIR)/ -type f -name '*.c')
OBJ = $(SRC:.c=.o)

all : $(LIBNAME).so 

$(LIBNAME).a : $(OBJ)
	@echo "	AR $@"
	$(AR) $@ $^

$(LIBNAME).so : $(OBJ)
	@echo "	LD $@"
	$(LD) -shared $^ $(LDFLAGS) -o $@

%.o: %.c
	@echo "	CC $@"
	@$(CC) -c $< $(CCFLAGS) -o $@

.PHONY : doc clear mrproper

doc:
	doxygen Doxyfile

install: all
	install -d      $(INSTALL_DIR_INCLUDE)/kzeliloj
	install -m  644 $(INCLUDE_DIR)/kzeliloj/*.h $(INSTALL_DIR_INCLUDE)/kzeliloj
	install -sm 644 $(LIBNAME).so $(INSTALL_DIR_LIB)

clear :
	rm -rf $(OBJ)

mrproper : clear
	rm -f  $(LIBNAME).so
	rm -rf doc/
