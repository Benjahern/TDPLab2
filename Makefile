all: Read.o testRead

Read.o: Read.cpp Read.h
	g++ -c Read.cpp

testRead: Read.o testRead.cpp
	g++ testRead.cpp Read.o -o testRead

clean:
	rm -f *.o testRead