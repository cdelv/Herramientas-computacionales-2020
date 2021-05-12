all: fig.pdf

fig.pdf: datos.txt script.gp
	gnuplot script.gp

datos.txt: run.sh eigen-Axb.x
	bash run.sh

%.x: %.cpp
	g++ $< -o $@
