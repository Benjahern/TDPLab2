all: Read.o ListAdy.o testRead

Read.o: Read.cpp Read.h
	g++ -c Read.cpp

ListAdy.o: ListAdy.cpp ListAdy.h
	g++ -c ListAdy.cpp

testRead: Read.o ListAdy.o testRead.cpp
	g++ testRead.cpp Read.o ListAdy.o -o testRead

clean:
	rm -f *.o testRead