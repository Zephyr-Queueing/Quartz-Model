CC=g++
CFLAGS=-std=c++11 -I=./ext

all: clean install test

test: test.o Message.o
	$(CC) $(CFLAGS) -o test test.o Message.o

test.o: test.cpp Message.h
	$(CC) $(CFLAGS) -o test.o -c test.cpp

Message.o: Message.h Message.cpp
	$(CC) $(CFLAGS) -o Message.o -c Message.cpp

install:
	rmdir -rf ext; \
	mkdir ext; \
	wget -P ext https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp \

clean:
	rm -rf *.o test ext
