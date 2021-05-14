
# Proyecto Final Herramientas Computacionales
---
## Integrantes:
Andrés Vargas

Carlos del Valle

Felipe Gómez

Julián Jiménez

# Repositorio:
---
https://github.com/fegomezl/P_F_HC.git

## Uso:

#### make:
El comando make se encarga de compilar todos los archivos (.CPP) necesarios
para la simulacion en archivos objeto en el directorio objects, luego los
compila para crear el ejecutable main.x Todos los archivos se compilan usando
mpic++ y las banderas especificadas, en este caso -std=c++17 -O3 -g.

#### make mpi:
Este comando elimina los resultados que existan en data/system_parameters y data/visual. Revisa que exista main.x y corre la simulacion con mpirun para el
numero de procesadores especificado en init_data.txt. Corre el script de bash
print_system.sh.

#### make scaling:
Revisa que exista main.x, elimina los resultados de los directorios
data/system_parameters, data/sacaling y data/visual. Luego corre el script de
bash scaling.sh

#### make test:
Revisa que exista el ejecutable test.x y lo ejecuta usando mpirun y el numero de
procesadores especificado en init_data.txt

#### make system_graps:
Ejecuta los scripts de genuplot plot_system_state.gp, plot_start.gp y muestra
los resultados energy.pdf, activation_partial.pdf, activation_total.pdf y
start.pdf usando xpdf.

#### make scaling_graphs:
Ejecuta el script de gnuplot plot_scaling.gp y muestra los resultados
speed_up.pdf y parallel_efficiency.pdf usando xpdf.

#### make distribution:
Elimina los resultados que haya en data/distribution. Ejecuta el script de
gnuplot plot_distribution.gp y usa convert para convertir la salida (imagenes
.png) en distribution.gif

#### make animaiton:
Elimina los resultados que haya en data/animation, corre el script de gnuplot
plot_animation.gp y convierte la salida (imagenes .png) en animation.gif

#### make send:
**Importante:** Este target se usa si se corre la simulacion en una maquina
virtual y se encarga de enviar los archivos de data/visual (archivos.csv) a la
carpeta compartida entre la maquina virtual y el sistema host. Para usarlo
correctamente hay que cambiar el directorio "/media/sf_Data_machine" de los
comandos por la dirección de la carpeta compartida respectiva.

#### make clean:
Elimina los archivos .csv que haya en data/visual y data/system_parameters, los
archivos. png en data/distribution y data/atctivation y los archivos .x

#### make oclean:
elimina los archivos objeto (.o) en la carpeta objects


## Parametros de funcionamiento:

Para correr la simulacion se debe tener cuidado con ciertas condiciones
iniciales que permiten que el sistema funcione correctamente. Por fuera de estos
rangos, pueden encontrarse problemas de ejecución y problemas con los resultados
de la simulacion, por ejemplo, overflow en la energia.
El parametro **dt**
optimo es del orden de 10^-3. Los parametros **k_wall** y **k_ball** no deberian
exceder 10000. El sistema se ha probado para un **nt** de hasta 10000 pelotas,
mas alla de eso no se garantiza un funcionamiento correcto. Si **box_size_z**
es demasiado pequeño, puede que las particulas se salgan de la caja y el
programa falle.


## Funciones:

#### class vector3D:
Define la clase vector3D proveida por el profesor Jose Daniel Muñoz que se
comporta como un vector en 3 dimensiones, tiene 3 componentes y define las
operaciones igualdad, suma, resta, producto con escalar, division por escalar, producto
punto, producto vectorial y norma.

#### struct CONFIG:
Contiene todas las variables generales del sistema, entre las que estan: el
numero de trampas, los tamaños de la caja, los radios de trampas y particulas,
el numero de procesos, las constantes de dureza, de friccion, de choque plastico
de las particulas, entre otras.

#### struct body:
Define una particula a traves de su masa, su radio, su momento de inercia, y los
vectores 3D que definen su posicon,fuerza, velocidad, angulo, velocidad angular
y torque.

#### struct trap:
Define una trampa a traves de al fuerza que imprime, su radio de activacion, su
estado (activa o inactiva), las variables send_up y send_down que determinan si
se comparte con un procesador adyacente y su vector 3D de posicion.

#### struct domain:
Define una seccion de la caja de acuerdo a su coluna inicial y final de trampas,
el numero de pelotas y trampas que estan en su dominio, las variables que
comunican cuantas trampas se van a mandar y a recibir en un momento dado de las
secciones adyacentes, el vector de elementos **struct trap** traps donde se guardan
las trampas que estan en el dominio, el vector de elementos **struct body**
balls donde se guardan las pelotas que esten en el dominio 

#### init_data:
La funcion se encasrga de leer las condiciones iniciales del archivo
init_data.txt y asignarlas en sus correspondientes variables en el struct
config. Tambien se encarga de revisar que la caja no sea demasiado pequeña, que
la pelota inicial no este fuera de la caja y que el area de las trampas no
supere el area del suelo.

#### start:
Se encarga de inicializar correctamente trampas y particulas en sus respectivas
posiciones, así como establecer el limite maximo y minimo de cada seccion.

#### ghost:
Es una funcion propia de la paralelizacion que se encarga de realizar las
comunicaciones entres secciones distintas, enviando particulas al procesador
correspondiente cuando pasan de dominio y compartiendo la informacion de
particulas y trampas cerca de las fronteras de cada seccion para hacer el calculo
completo de la fuerza.

#### compute_force:
Es la funcion encargada de calcular todas las fuerzas y torques del sistema  de
acuerdo al algoritmo de integracion
PEFRL 4. Calcula fuerzas y torques entre particulas, con las trampas y las
paredes. Para esto usa las 3 subfunciones **force wall**, **force_ball** y **force_trap**.

#### time_step:
Ejecuta un paso de tiempo. En este se usa **ghost** para comunicar a las
secciones, se verifica si hay trampas activadas, se ejecuta el movimiento de las
particulas usando **compute_force** de acuerdo al algoritmo PEFRL 4 Y **ghost**.
Finalmente, quita las trampas que hayan sido activadas.

#### print:
Se encarga de imprimir el estado del sistema en un momento dado. Envia la
energia total, la activacion parcial y total al archivo data_system-(time).csv
donde (time) corresponde al momento en el que este el sistema. Envia los datos
de activacion parcial y total por celdas al archivo data_activation-(time).csv.
Envia las posiciones y el radio de las pelotas al archivo dta_balls-(time).csv.
Envia las posiciones de las trampas a data_traps-(time).csv.

#### catch_mpi_test_main:
Usa #define CATCH_CONFIG_RUNNER para poder definir el main que usara catch2 para
correr los test, es necesario para que catch2 funcione con MPI.

#### test y test2:
Contiene los tests. Se revisa que el numero de particulas sea
constatne, que las particulas no escapen de la caja, que la energia sea positiva
y no tenga overflow y que el primer, que ultimo proceso hagan correctamente los
envios y que en un rebote, una particula no supere su altura inicial.

## Scripts:

#### print_system.sh:
Se encarga de recopilar todos los datos de la forma data_system-(numero).csv y
componerlos en el archivo system_state.txt. Ademas envia los datos de los lados
de la caja a box.txt para podre graficarla.

#### plot_start.gp:
Se encarga de graficar el estado inicial del sistema en gnuplot, mostrando las
posiciones de las particulas dentro de la caja.

#### plot _system_state.gp:
Se encarga de hacer 3 graficas. La energia total del sistema contra el tiempo,
el porcentaje de activaciones instantaneo contra el tiempo y el porcentaje de
activaciones acumuladas contra el tiempo.

#### plot_distribution.gp:
Imprime la distribucion acumulada de activaciones en una celda de la caja. Esto
lo hace para todos los tiempos de la simulacion y los envia a archivos .png para
despues poder hacer un archivo .gif.

#### plot_animation.gp:
Se encarga de imprimir las posiciones de las trampas y pelotas para todos los
tiempos del sistema y mandarlos a archivos .png para despues hacer una animacion
del movimiento.

#### scaling.sh:
Se encarga de correr la simulacion para distintos tamaños del sistema (numero de
particulas) y en cada
uno para multiples procesos cada uno 10 repeticiones. Con los datos del tiempo
de procesamiento para un tamaño del sistema se extraen datos sobre el scaling
del programa asi como la eficiencia paralela con sus respectivas desviaciones que se imprimen en metrics-(nt).txt
donde (nt) corresponde al tamaño del sistema.

#### plot_scaling.gp:
Se encarga de graficar los diferentes datos extraidos del script scaling.sh para
analizar la eficiencia paralela del programa.

#### plot_exp.gp:
Se encarga de graficar los datos experimentales hallados sobre el sistema, que
se usaron para definir ciertas condiciones.

#### plot_analysis.gp:
Grafica la tasa de aumento y la tasa de decremento de la energia para analizar
su punto de interseccion.

#### fit.gp y fit_limit.gp:
Se encarga de hacer las graficas de energia, activacion total y activacion
acumulada con los respectivos fit de las funciones gamma y exponencial para su
respectivo analisis.
