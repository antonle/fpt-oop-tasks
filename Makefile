CC = g++
HEADER = ./header
SRC_PATH = ./src
CFLAGS = -g -fsanitize=address -I$(HEADER)
SRC_FILE = Employee.cpp Engineer.cpp Management.cpp Staff.cpp Worker.cpp
SRC = $(wildcard $(SRC_PATH)/*.cpp)

all: main

main:
	$(CC) $(CFLAGS) -o main $(SRC) main.cpp
