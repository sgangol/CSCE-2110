make: main.o function.o
	g++ -o gradebook main.o function.o

run: 
	./gradebook
	
main.o:	main.cpp func_proto.h
	g++ -c main.cpp

function.o: function.cpp dect_struct.h
	g++ -c function.cpp
	
	