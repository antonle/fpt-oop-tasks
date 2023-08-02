CC = g++
HEADER = ./header
CFLAGS = -g -fsanitize=address -I$(HEADER)
SRC_FILE = ./src/*.cpp

all: main

main:
	@$(CC) $(CFLAGS) -o main $(SRC_FILE) main.cpp

clean:
	@rm main
