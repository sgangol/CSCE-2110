all: sg0440 

.DELETE_ON_ERROR: clean


sg0440: main.o LinkedList.o HashTable.o
		g++ main.o LinkedList.o HashTable.o -o sg0440
		
main.o: main.cpp
		g++ -c main.cpp

LinkedList.o: LinkedList.cpp
		g++ -c LinkedList.cpp

HashTable.o: HashTable.cpp
		g++ -c HashTable.cpp

clean:
		rm -rf *o sg0440