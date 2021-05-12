#Esto es un comentario
#
#estructura de un makefile
#
#target:dependencias sfd sdf sdfsd sdfs sdf sdf
#	instruccion para crear el target
#usando el ejemplo de la sumas y hacer la gráfica
#para ejecutar solo escribir make,
#también puede ser make -f nombredelmakefile
#sumas.x es lo mismo que a.out
#colocar el ultimo target para que haga todos

#@: es el nombre del target
#^: todas las dependencias
#<: la primera dependencia
#%: todo lo que empiece por ---- se llama igual que el ----.x

#se pueden tener variables
CXX= g++
CXXFLAGS= -O2 -g 

all:fig.pdf

%.x: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
#las instrucciones deben estar separadas por un tab
datos.txt: sumas.x
	./$< > $@

fig.pdf: plot.py datos.txt 
	python3 $<
clean:
	rm -f a.out *.x datos.txt
#como clean no depende de nada no se va a ejecutar a menos que se le diga
# make clean      para ejecutar
