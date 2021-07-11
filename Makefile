LIBNAME = libkzeliloj

LIB_VERSION_MAJOR = 1
LIB_VERSION_MINOR = 0

SRC_DIR     = src
INCLUDE_DIR = include
OBJ_DIR     = obj

INSTALL_DIR_LIB ?= /usr/lib/x86_64-linux-gnu
INSTALL_DIR_INCLUDE ?= /usr/include

CC ?= gcc
LC ?= gcc

## CC Options ##
CCFLAGS += -I./$(INCLUDE_DIR)
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -std=c11
CCFLAGS += -fPIC
# DEBUG options
# CCFLAGS += -g -DDEBUG

LIBFILE = $(LIBNAME).so.$(LIB_VERSION_MAJOR).$(LIB_VERSION_MINOR)

## LD Options ##
LDFLAGS += -Wl,-soname,$(LIBNAME).so.$(LIB_VERSION_MAJOR)
# DEBUG options
# LDFLAGS += -g -DDEBUG

SRC = $(shell find $(SRC_DIR)/ -type f -name '*.c')
OBJ = $(SRC:.c=.o)

all : $(LIBFILE)

$(LIBFILE) : $(OBJ)
	@echo "	LD $@"
	@$(LC) -shared $(LDFLAGS) $^ -o $@
	@ln -sf $(LIBFILE) $(LIBNAME).so.$(LIB_VERSION_MAJOR)
	@ln -sf $(LIBFILE) $(LIBNAME).so

%.o: %.c
	@echo "	CC $@"
	@$(CC) $(CCFLAGS) -c $< -o $@

.PHONY : doc clear mrproper

doc:
	doxygen Doxyfile

install: all
	# create the include folder.
	install -d $(INSTALL_DIR_INCLUDE)/kzeliloj
	# move the include and lib files
	install -m 644 $(INCLUDE_DIR)/kzeliloj/*.h $(INSTALL_DIR_INCLUDE)/kzeliloj
	install -m 644 $(LIBFILE) $(INSTALL_DIR_LIB)
	# create the symbolic link of libs.
	ln -sf $(LIBFILE) $(INSTALL_DIR_LIB)/$(LIBNAME).so
	ln -sf $(LIBFILE) $(INSTALL_DIR_LIB)/$(LIBNAME).so.$(LIB_VERSION_MAJOR)

clear :
	rm -rf $(OBJ)

mrproper : clear
	rm -f $(LIBNAME).so*
	rm -rf doc/
