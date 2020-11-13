
#include<iostream>
#include<vector>
#include<cmath>


//------------------------ Declarar constantes globales------------

 int const Nx=8, Ny=8;      //divisiones del latice
 int const Lx=200, Ly=200; //la longitud de los lados del latice

//-----------------------------Declarar clases----------------------

class Particle;

//-----------------------------Implementar clases--------------------

class Particle{
  
private:
  
  int position[2]={0,0}; int cel=0; double lx=Lx/Nx, ly=Ly/Ny;
  
public:
  
  void start(int x0, int y0);
  void Move(int p, int q);
  int Getx(void){return position[0];};       
  int Gety(void){return position[1];};
  int Getcel(void);
};

void Particle::start(int x0,int y0){
  position[0]=x0; position[1]=y0;}

void Particle::Move(int p, int q){
  position[q] += p;
  
  if(position[0]==0)
    position[0]+=1;
  if(position[0]==Lx)
    position[0]-=1;
  if(position[1]==0)
    position[1]+=1;
  if(position[1]==Ly)
    position[1]-=1;  
}

int Particle::Getcel(void){
  int X=0, Y=0;
  X=position[0]/lx;
  Y=position[1]/ly;
  cel=X+Y*Ny;
  return cel;}

//----------------------declaracion de funciones----------------------

void start(int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel, std::vector<double> &Probability);
double entropy(int tmax, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel, std::vector<double> &Probability);

//-----------------------funcion principal--------------------------

int main(void)
{
 srand(0);
//-----------------------declaracion de constantes-----------------
 
 int tmax=1000000;     //tiempo maximo de la simulacion
 int N=40000;       //numero de particulas
 int M=Nx*Ny;     //numero de celdas del latice
 double S=0;     //entropia
    
//-----------------------declaracion de vectores--------------  

 std::vector <Particle> Particles (N);
 std::vector <int> Cel (M,0);
 std::vector <double> Probability (M,0);

  start(N,M, Particles, Cel, Probability); //inicializa los vectors
  
  S=entropy(tmax, N, M, Particles, Cel, Probability); //calcula la entropia y permite graficarla
  
  return 0;
}
//-----------------------Funcion start----------------------

void start(int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel, std::vector<double> &Probability)
{
  double T=std::sqrt(N), P=0;
  double dx=25/(T+1), dy=25/(T+1);//.start(dx*(ix+200), dy*(iy+200)
  int k=0;
  
  for(int ix=0; ix<T; ix++){
    for(int iy=0; iy<T-1; iy++){
      Particles[ix*T+iy].start(iy-T/2,ix-T/2);
    }
  }
  
  
  for(int ii=0; ii<N; ii++)
    {
      k=Particles[ii].Getcel();
      Cel[k]+=1;
    }
  for(int j=0; j<m; j++)
    {
      P=Cel[j];
      double val=P/N;
      Probability[j]=val;
    }
  
  
}
  //----------------------funcion entropy-------------------------------
  
  double entropy(int tmax, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel, std::vector<double> &Probability)
{
  int i=0,p=0,q=0, k=0;                     //numeros aleatorios
  double S=0, sum=0, T=0, P=0;             //m numero de celdas, N numero de particulas
  
  for(int t=0; t<=tmax; t++)
    {
      q = rand() % 2;           //genera un numero 0 o 1
      p = -1 +(rand() % 2)*2;  //genera un numero -1 o 1
      i=(rand() % N);         //numero aleatorio entre 0 y N-1
      
      k=Particles[i].Getcel();
      Cel[k]-=1;
      P=Cel[k];
      Probability[k]=P/N;
      Particles[i].Move(p,q);
      k=Particles[i].Getcel();
      Cel[k]+=1;
      P=Cel[k];
      Probability[k]=P/N;
    
      for(int ii=0; ii<m; ii++)
	{
	  T=Probability[ii];
	  if(T!=0)
	    sum+=(-T*std::log(T));    //mirar el tamaño de P
	}
      S=sum;
      sum=0;
      std::cout << t <<"\t"<< S <<std::endl;     
    }
  return S;
}
  
