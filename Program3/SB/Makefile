all: SB0576

SB0576: main.o ListData.o Adjacent.o
		g++ main.o ListData.o Adjacent.o -o SB0576
		
main.o: main.cpp
		g++ -c main.cpp

ListData.o: ListData.cpp
		g++ -c ListData.cpp

Adjacent.o: Adjacent.cpp
		g++ -c Adjacent.cpp

clean:
		rm -f *.o SB0576
