hash: main.o LinkedList.o HashTable.o
		g++ main.o LinkedList.o HashTable.o -o hash
		
main.o: main.cpp
		g++ -c main.cpp

LinkedList.o: LinkedList.cpp
		g++ -c LinkedList.cpp

HashTable.o: HashTable.cpp
		g++ -c HashTable.cpp

clean:
		rm -rf *o hash