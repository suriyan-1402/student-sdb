CC = gcc
BIN = student-sdb
SOURCES = new-input.c read-new-input.c save-file.c read-file.c append.c remove.c main.c
OBJECTS = $(SOURCES:.c=.o)

default: $(BIN)

$(BIN): common.h $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm $(BIN) $(OBJECTS)

help:
	@echo "Please run make $(BIN) or just make"

.PHONY: help clean default
