all: graph

graph: graph.o LinkedList.o AdjacencyList.o
		g++ graph.o LinkedList.o AdjacencyList.o -o graph
		
graph.o: graph.cpp
		g++ -c graph.cpp

LinkedList.o: LinkedList.cpp
		g++ -c LinkedList.cpp

AdjacencyList.o: AdjacencyList.cpp
		g++ -c AdjacencyList.cpp

clean:
		rm -f *.o graph
