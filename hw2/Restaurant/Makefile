CXX = g++
CXXFLAGS = -Wall

all: assigntables 

assigntables: Restaurant.cpp Table.cpp assigntables.cpp
	$(CXX) -o $@ $^

clean:
	rm -f assigntables 