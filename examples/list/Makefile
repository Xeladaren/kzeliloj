EXEC=list-example

CC=gcc
LD=gcc

CCFLAGS += --std=c11
CCFLAGS += -I../../include
CCFLAGS += -lkzeliloj
CCFLAGS += -g

# LDFLAGS += -L../../
LDFLAGS += -lkzeliloj
LDFLAGS += -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(LD) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)
