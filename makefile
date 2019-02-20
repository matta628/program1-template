P = program4
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
all: program4
	g++ $(CFLAGS) Planet.o Star.o List.o -o program4

Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o
Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o
List.o: List.cpp List.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o
run: all
	./program4
memcheck:
	valgrind ./program4
clean:
	rm -rf program4
