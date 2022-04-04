#Alan Benitez
run: main.o LCSMulti.o LCSPt1.o
	g++ -Wall -o $@ $^
main.o: main.cpp
	g++ -Wall -c main.cpp
LCSMulti.o: LCSMulti.hpp LCSMulti.cpp
	g++ -Wall -c LCSMulti.cpp
LCSPt1.o: LCSPt1.hpp LCSPt1.cpp
	g++ -Wall -c LCSPt1.cpp

