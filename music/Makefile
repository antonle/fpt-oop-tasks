CC = g++
CFLAGS = -g -fsanitize=address
INC = -I./header/controller -I./header/view -I./header/model -I/usr/include -I./header
LIB_DIR = /usr/local/lib
LIB = -ltag -lz -lSDL2 -lSDL2_mixer
SRC = ./src/controller/*.cpp ./src/view/*.cpp ./src/model/*.cpp

all: main

main:
	$(CC) $(CFLAGS) $(INC) -o main $(SRC) main.cpp $(LIB)
