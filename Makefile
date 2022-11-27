CC=g++
CFLAGS=-std=c++11 -I=./ext
EDIR=ext
BDIR=bin
ODIR=obj
SDIR=src
TDIR=test
LDIR=lib

all: clean mount install $(BDIR)/test package

$(BDIR)/test: $(ODIR)/test.o $(ODIR)/Message.o
	$(CC) $(CFLAGS) -o $(BDIR)/test $(ODIR)/test.o $(ODIR)/Message.o

$(ODIR)/test.o: $(TDIR)/test.cpp $(SDIR)/Message.h
	$(CC) $(CFLAGS) -o $(ODIR)/test.o -c $(TDIR)/test.cpp

$(ODIR)/Message.o: $(SDIR)/Message.h $(SDIR)/Message.cpp
	$(CC) $(CFLAGS) -o $(ODIR)/Message.o -c $(SDIR)/Message.cpp

package:
	ar -rcs $(LDIR)/message.a $(ODIR)/Message.o

install:
	wget -P $(EDIR) https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp

mount:
	mkdir $(EDIR) $(BDIR) $(ODIR) $(LDIR)

clean:
	rm -rf $(EDIR) $(BDIR) $(ODIR) $(LDIR)
