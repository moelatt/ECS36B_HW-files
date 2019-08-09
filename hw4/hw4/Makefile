# Moe Ko Latt
# ID: 915866164
CXX = g++
CXXFLAGS=-Wall

all: testFacility testRunway testCode airport testSiteNumber distance

testFacility: testFacility.cpp Facility.cpp gcdistance.cpp
	$(CXX) -o $@ $^

testRunway: testRunway.cpp runway.cpp
	$(CXX) -o $@ $^

testCode: testCode.cpp Facility.cpp gcdistance.cpp
	$(CXX) -o $@ $^

testSiteNumber: testSiteNumber.cpp runway.cpp Facility.cpp gcdistance.cpp
	$(CXX) -o $@ $^

airport: airport.cpp runway.cpp Facility.cpp gcdistance.cpp
	$(CXX) -o $@ $^

distance: distance.cpp runway.cpp Facility.cpp gcdistance.cpp
	$(CXX) -o $@ $^

execs = testFacility testRunway testCode airport testSiteNumber distance

clean:
	rm -f $(execs) *.o
