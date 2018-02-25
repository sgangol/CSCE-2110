all: hash

hash: main.o LinkedList.o HashTable.o
		g++ main.o LinkedList.o HashTable.o -o as1219
		
main.o: main.cpp
		g++ -c main.cpp

LinkedList.o: LinkedList.cpp
		g++ -c LinkedList.cpp

HashTable.o: HashTable.cpp
		g++ -c HashTable.cpp

clean:
		rm -rf *.o as1219