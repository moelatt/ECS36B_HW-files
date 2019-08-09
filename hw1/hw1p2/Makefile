# Moe Ko Latt
# ID: 915866164
CXX = g++
CXXFLAGS = -Wall
all: useFraction calculator

useFraction: Fraction.cpp useFraction.cpp
	$(CXX) -o $@ $^
calculator: Fraction.cpp calculator.cpp
	$(CXX) -o $@ $^
clean:
	rm -f useFraction calculator