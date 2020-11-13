all: main-md.x

CXX=g++
OBJECTS=main-md.o md-simul.o
CXXFLAGS=-O2 -g -std=c++14

main-md.x: $(OBJECTS) particle.h
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *.x *.txt
