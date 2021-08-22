CC=g++
CFLAGS=-lGL -lSDL2 #-lGLEW
SOURCES=$(wildcard *.cpp)
HSOURCES=$(wildcard *.h)

all: a.out
a.out: $(SOURCES) $(HSOURCES)
	$(CC) -o a.out $(SOURCES) $(CFLAGS)
