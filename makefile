CC=g++

CFLAGS= -Wall

DEPS = state.cpp graph.cpp vehicle.cpp

MAIN = vrp

all: compile

compile:
	$(CC) $(CFLAGS) -o $(MAIN) vrp.cpp $(DEPS)

clean:
	rm $(MAIN)