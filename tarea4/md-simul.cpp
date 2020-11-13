#include "md-simul.h"

#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.rad = 0.2;
  body.mass = 0.29698;

  body.Rx = 2.0;
  body.Ry = 2.0;
  body.Rz = 2.0;

  body.Vx = 3.0;
  body.Vy = 5.0;
  body.Vz = 4.0;

  body.Kx = 0.5*body.mass*body.Vx*body.Vx;
  body.Ky = 0.5*body.mass*body.Vy*body.Vy;
  body.Kz = 0.5*body.mass*body.Vz*body.Vz;

  body.Py = -body.mass*G*body.Ry;

}
void compute_force(Particle & body)
{
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;
  // gravitational force
  if(body.Ry == body.rad && body.Vy == 0.0){
    body.Fy == 0.0; //in case the ball starts rolling on the floor
  }
  else {
    body.Fy += body.mass*G;
  }
  // force with ground
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    body.Ey = 0.5*K*delta*delta; //elastic energy y
    body.Fy -= 0.2*body.Vy;
  }
  // force with roof
  delta = body.Ry + body.rad - BOXSIZE;
  if (delta > 0) {
    body.Fy -= K*delta;
    body.Ey = 0.5*K*delta*delta; //elastic energy y
    body.Fy -= 0.2*body.Vy;
  }
  // force with left wall
  delta = body.rad - body.Rx;
  if (delta > 0) {
    body.Fx += K*delta;
    body.Ex = 0.5*K*delta*delta; //elastic energy x
    body.Fx -= 0.2*body.Vx;
  }
  // force with right wall
  delta = body.Rx + body.rad - BOXSIZE;
  if (delta > 0) {
    body.Fx -= K*delta;
    body.Ex = 0.5*K*delta*delta; //elastic energy x
    body.Fx -= 0.2*body.Vx;
  }
  // force with back wall
  delta = body.rad - body.Rz;
  if (delta > 0) {
    body.Fz += K*delta;
    body.Ez = 0.5*K*delta*delta;
    body.Fz -= 0.2*body.Vz;
  }
  // force with front wall
  delta = body.Rz + body.rad - BOXSIZE;
  if (delta > 0) {
    body.Fz -= K*delta;
    body.Ez = 0.5*K*delta*delta;
    body.Fz -= 0.2*body.Vz;
  }
}

void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass);
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}
void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
  //kinetic energy
  body.Kx = 0.5*body.mass*body.Vx*body.Vx;
  body.Ky = 0.5*body.mass*body.Vy*body.Vy;
  body.Kz = 0.5*body.mass*body.Vz*body.Vz;
  //potential energy
  body.Py = -body.mass*G*body.Ry;
}
void print(Particle & body, double time)
{
  std::cout << time << "\t"
            << body.Rx << "\t"
            << body.Ry << "\t"
            << body.Rz << "\t"
            << body.Vx << "\t"
            << body.Vy << "\t"
            << body.Vz << "\t"
            << body.Ex + body.Ey + body.Ez << "\t"
            << body.Kx + body.Ky + body.Kz << "\t"
            << body.Py << "\t"
            << body.Ex + body.Ey + body.Ez + body.Kx + body.Ky + body.Kz + body.Py
            << "\n";
}
