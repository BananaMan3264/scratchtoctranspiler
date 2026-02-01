CC = gcc
CFLAGS = -c
LIBS = -lm -ljson-c -lSDL2
LDFLAGS = 
EXE = build/program

O = -o 
OE = -o 

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/obj/%.o, $(SRC))

.PHONY:
	clean build run windows

all: $(EXE)

# Somebody kill me
windows:
	make CC="cl" CFLAGS="/c" O="/Fo" OE="/Fe" LDFLAGS="" LIBS="json-c.lib SDL2.lib"

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) $(OE)$(EXE)

build/obj/%.o: src/%.c
	$(CC) $(CFLAGS) $< $(O)$@

clean:
	rm -rf build/*
	mkdir build/obj