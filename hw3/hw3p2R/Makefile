# Moe Ko Latt
# ID: 915866164
CXX = g++
CXXFLAGS = - Wall

all: testPoint checkpack testShape

testPoint: testPoint.cpp point.cpp 
	$(CXX) -o $@ $^
checkpack: checkpack.cpp point.cpp domain.cpp shape.cpp
	$(CXX) -o $@ $^
testShape: testShape.cpp shape.cpp point.cpp
	$(CXX) -o $@ $^
clean:
	rm -f testPoint checkpack testShape