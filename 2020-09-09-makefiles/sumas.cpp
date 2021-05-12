#include <iostream>
#include<cmath>

double sumaup(int Max);
double sumadown(int Max);

int main(void)
{
  int Max=100;
  double up= 0;
  double down= 0;

  for (int ii=1; ii<=Max; ii++){
    up= sumaup(ii);
    down= sumadown(ii);
    
    std::cout << ii <<"\t"<< std::fabs(1-down/up) << std::endl;
  }
  return 0;
}

double sumaup(int Max)
{
  double suma = 0.0;
  
  for(int ii=1; ii<=Max ; ii++ ){
    suma+=1.0/ii;
  }
  return suma;
}
double sumadown(int Max)
{
  double suma = 0.0;
  
  for(int ii=Max; ii>=1 ; --ii){
    suma+=1.0/ii;
  }
  return suma;  
}
