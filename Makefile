CXXFLAGS = -Wall -pedantic -Ofast -lpthread -std=c++17

__START__: sort_test
	./sort_test

sort_test: main.o sort.o array.o
	g++ -o sort_test main.o sort.o array.o

main.o: main.cpp
	g++ -c ${CXXFLAGS} main.cpp

sort.o: sort.cpp sort.hh
	g++ -c ${CXXFLAGS} sort.cpp

array.o: array.cpp array.hh
	g++ -c ${CXXFLAGS} array.cpp

clean:
	rm -f *.o sort_test