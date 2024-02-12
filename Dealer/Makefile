output: main.o hand.o
	g++ main.o hand.o -o output

main.o: main.cpp
	g++ -c main.cpp

hand.o: hand.cpp hand.h
	g++ -c hand.cpp

clean:
	rm *.o output