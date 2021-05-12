//Carlos Andres del Valle
#include <iostream>

void f1(void);
void f2(void);
void f3(void);
void f4(void);

int main()
{
  f1();
  f2();
  f3();
  f4();

  return 0;
}

void f1(void)
{
  //double b = 1; -Werror dice que esta variable no se usa 
  double *z = new double [100] {0.0}; //-Werror dice que no se puede convertir de double a char. se cambió char por double.
    // double a = 2;  -Werror dice que esta variable no se usa
    z[0] = 25; //no existe z[-1]. Detectado en la primera inspección, corregido a Z[0]
    delete [] z;
}

void f2(void)
{
  char *y = new char [10];
  y[9] = 'a'; //no exixste y[10], el arregla va hasta 9, detectado en la primera inspección. esto causa un stack overflow.
  delete [] y; //Valgrind marca un error por no liberar la memoria
}

void f3(void)
{
  int x=0;//-werror para hacer el if pide que x este inicializada
  if(x == 0) //-Werror marca un error porque falta un =, con 2 iguales se compara y con 1 se asigna un nuevo valor a la variable. 
    {
      std::cout << "X is zero: " << x <<"\n";
    }
}

void f4(void)
{
  int x=0; // X no estaba inicializado así que puede imprimir cualquier cosa. -Werror pide que se inicialice 
  std::cout << "x = " << x << "\n";

  int i=0, j=0; //valgrind marca error porque j e i no están inicializadas
  int a[10]{0}; /*b[10] -werror marca error porque b[] no se usa, además valgrind marca error porque a[] no está inicilizada*/ 
  for ( i = 0; i < 10; i++ ) {//valgrind marca error porque el for() se sale del array, elimino el =, detectado con ddd
    j += a[i];
  }
  if ( j == 77 ) //-Werror marca un error porque falta un =, con 2 iguales se compara y con 1 se asigna un nuevo valor a la variable. 
    std::cout<< "hello there\n"; //-Werror marca un problema con los caracteres «, los reemplazo por <<
 
}
