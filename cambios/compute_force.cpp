#include "header.h"

void compute_force (const CONFIG &config, Vec_b &balls, const Vec_b &walls, const Vec_t &traps){
    //Calcula las fuerzas del sistema

  //variables

  Vector3D normal,tangente,dr,Vc,Vn,Vt,FHertz,Fnp,Ftp,Ftpmax,V1, V2,Fn,Ftotal,torque1,torque2;

  double norm_dr, S, norm_Vt, err=1e-8,masar;

  int N = balls.size();

  for (auto& b: balls){
    b.force.cargue(0,0,-b.mass*config.g); //Resetar las fuerzas con solo PESO
    b.torque.cargue(0,0,0);              //Resetar el torque
  }
  
  //fuerza con otras pelotas
  for (int ii = 0; ii < N; ii++){
    for (int jj = ii+1; jj < N; jj++) {
      
      dr = balls[ii].pos-balls[jj].pos;
      norm_dr = norma(dr);
      normal=dr*(1/norm_dr);
      V2=balls[ii].vel+(balls[ii].omega^(dr*(-1/2)));
      V1=balls[jj].vel+(balls[jj].omega^(dr*(1/2)));
      Vc=V2-V1;
      Vn=(Vc*normal)*normal;
      Vt=Vc-Vn;
      norm_Vt=norma(Vt);
      tangente=Vt*(1/norm_Vt);	
      S = balls[ii].rad + balls[jj].rad - norm_dr;
      masar=(balls[ii].mass*balls[jj].mass)/(balls[ii].mass+balls[jj].mass);
      if(S > err){
	ball[ii].x+=Vt*config.dt; ball[jj].x+=Vt*config.dt;}
      else{
	ball[ii].x=ball[jj].x=0;}
      if (S > err){
	FHertz=config.k_ball*std::pow(S,1.5)*normal; //fuerza de Hertz
	Fnp=-config.gamma_ball*masar*std::sqrt(S)*Vc;    //fuerza normal plastica
	Ftp=-K*x*tangente;                         //fuerza tangente plastica
	Fn=FHertz+Fnp;
	Ftpmax=-config.mu_ball*norma(Fn)*tangente;
	if(norma(Ftp)<norma(Ftpmax)){
	  Ftotal=Fn+Ftp;
	  torque1=(Ftp^(dr*(1/2)));
	  torque2=(Ftp^(dr*(-1/2)));
	}                             
	else{
	  Ftotal=Fn+Ftpmax;
	  torque1=(Ftp^R1);
	  torque2=(Ftp^R2);
	}
	
	balls[ii].force += Ftotal;
	balls[jj].force -= Ftotal;
	balls[ii].torque += torque1;
	balls[jj].torque += torque2;
      }
    }
    
      //fuerza con las paredes
      
      //FUERZA TRAMPAS

      //calculo de los vectores direccion
      
      //calculo de las perturbaciones
      
      //calculo de las fuerza

      //Fuerza total
      
      //TORQUE
      
}
