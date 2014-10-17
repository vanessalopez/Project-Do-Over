CFLAGS=-g -Wall

all: stack

stack: map.h map.cpp
	g++ -o map map-test.cpp $(CFLAGS)

clean:
	rm -f *.o *~ main