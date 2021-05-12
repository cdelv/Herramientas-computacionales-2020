#Carlos Andres del Valle
# make compila con sanitizers y ejecuta el programa
#make valrind compila sin sanitizers y corre valgrind
#make sanitizers compila con sanitizers pero no ejecuta el programa
# make clean elimina los ejecutables

CXX=g++
CXXFLAGS=-std=c++17 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full

all : 2.x
	./$<
2.x : 2.cpp
	$(CXX)  $(CXXFLAGS) $(SANITFLAGS) $< -o $@

sanitizers: 2.x

valgrind: 2.cpp
	rm -rf *.x
#se elimina el ejecutable por si fue compilado con sanitizers antes

	$(CXX)  $(CXXFLAGS) $< -o 2.x
	$@ ./2.x $(VALGRINDFLAGS)
	make clean

# se hace make clean para que no haya problemas con los sanitizers después

clean:
	rm -rf *.x a.out *.x.*
