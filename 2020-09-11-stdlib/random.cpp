//generador de números aleatorios

#include <iostream>
#include <random>


int main(void)
{
    const int Nmax=10000;
  const int Nbins=20;
  const double min=0.0;
  const double max=1.0;
  const int seed =0;
  const double dxhisto=(max-min)/Nbins;

  double histo[Nbins] = {0.0};
  
  std::mt19937 gen(seed); //declarando el generador
  std::uniform_real_distribution <double> dis(min,max);
//tipo de distribucion, datos que genra e intervalo de generación
//cada vez que es llamado genera un numero diferente
  

  for(int i=0; i<Nmax; i++){
    double r = dis(gen);
    int bin = int((r-min)/dxhisto);
    histo[bin] +=1;
  }

    for(int i=0; i<Nbins; i++){

      std::cout << min + i*dxhisto  << "\t" << histo[i] << "\n";
  }
 

  return 0;
}
