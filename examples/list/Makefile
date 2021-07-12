EXEC=list-example

CC = arm-linux-gnueabihf-gcc
LD = arm-linux-gnueabihf-gcc

CCFLAGS += --std=c11
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -g

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
