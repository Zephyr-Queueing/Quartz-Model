CC=g++
CFLAGS=

test: test.o Message.o
	$(CC) $(CFLAGS) -o test test.o Message.o

test.o: test.cpp Message.h
	$(CC) $(CFLAGS) -o test.o -c test.cpp

Message.o: Message.h Message.cpp
	$(CC) $(CFLAGS) -o Message.o -c Message.cpp

clean:
	rm -rf *.o test
