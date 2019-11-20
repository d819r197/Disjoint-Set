DisjointSet: main.o Executive.o DisjointSet.o Node.o
	g++ -g -std=c++11 main.o Executive.o DisjointSet.o Node.o -o DisjointSet

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp DisjointSet.h
	g++ -std=c++11 -g -c Executive.cpp

DisjointSet.o: DisjointSet.h DisjointSet.cpp  Node.h
	g++ -std=c++11 -g -c DisjointSet.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o DisjointSet
