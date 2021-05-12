CXX=g++
CXXFLAGS=-g -std=c++17 -fconcepts
GPROFFLAGS=-pg
CACHEGRIND_FLAGS=
CALLGRIND_FLAGS=

all: example.x

%.x: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

gprof: example.cpp
	$(CXX) $(CXXFLAGS) $(GPROFFLAGS) $< -o example-gprof.x
	./example-gprof.x 5000 5000
	gprof ./example-gprof.x > gprof-report.txt

callgrind: example.x example.cpp
	valgrind --tool=callgrind ./$< 5000 5000
	callgrind_annotate $$(ls -t callgrind.out.* | head -n 1) > callgrind-report.txt

cachegrind: example.x example.cpp
	valgrind --tool=cachegrind ./$< 5000 5000
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > cachegrind-report.txt

clean :
	rm -f *.x a.out
