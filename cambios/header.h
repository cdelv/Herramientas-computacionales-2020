#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Vector.h"

//Condiciones iniciales
struct CONFIG{

  double box_size = 0;   //Tamaño lateral de la caja en X y Y 
  double box_size_z = 0; //Tamaño lateral de la caja en Z
  double k_wall = 0;  //Constante de dureza de las paredes
  double k_ball = 0;  //Constante de dureza entre pelotas
  double k_trap = 0;  //Constante de dureza de las trampas
  int nt = 0;     //Número de tampas
  double g = 0;   //Aceleración de la gravedad
  double dt = 0;  //Paso de tiempo
  int iterations = 0;
  int resolution = 0;
  double mu_ball=0.2;
  double gamma_ball=0.1;
  
    
};

//Pelotas de ping pong
struct body{
  
  double mass = 0;   //Masa, podria ser unitaria
  double rad = 0;   //Radio, podria ser unitario
  double x=0;      //longitud resorte cundall
  double I=(2*mass*rad*rad)/5; //momento de inercia
  
  vector3D pos;    //Posición
  vector3D vel;   //Velocidad
  vector3D angulo;
  vector3D omega;
  vector3D force; //Fuerza
  vector3D torque;
};

//Trampas de raton
struct trap{

    double rad = 0;  //Radio de la trampa
    int active = 0;  //La trampa esta activa (1) o no (0)
    
    vector3D pos;  //Posición de la trampa

};

//Simplificación de notación
typedef std::vector<int> Vec_i;
typedef std::vector<double> Vec_d;
typedef std::vector<body> Vec_b;
typedef std::vector<trap> Vec_t;

//Funciones principales

void init_data(CONFIG &config, Vec_b &balls, Vec_t &traps);

void start(const CONFIG &config, Vec_b &balls, Vec_b &walls, Vec_t &traps); //Ubica las particulas

void print(int time, const Vec_b &balls, const Vec_t &traps);

void print_start (const CONFIG &config, int time, const Vec_b &balls, const Vec_t &traps);

void compute_force(const CONFIG &config, Vec_b &balls, const Vec_b &walls, const Vec_t &traps);  //Calcula las fuerzas

void time_step(const CONFIG &config, Vec_b &balls, const Vec_b &walls, Vec_t &traps); //Da un paso de tiempo

double energy (int time, const CONFIG &config, const Vec_b &balls);  //Calcula e imprime la energÃ­a del sistema

//Constantes para la integraciÃ³n con PEFRL de orden 4, la organizaciÃ³n de los nÃºmeros es el orden de su uso
const double const1 = 0.1786178958448091; //Xi
const double const3 = -0.06626458266981849; //Ji
const double const4 = -0.2123418310626054;  //Lambda
const double const2 = (1-const4)/2; //(1-Lambda)/2
const double const5 = 1-2*(const3+const1);  //1+2*(Xi+Ji)

