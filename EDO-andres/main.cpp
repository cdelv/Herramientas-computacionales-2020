#include <iostream>
#include <array>
#include <cmath>
#include "print.h"
#include "deriv.h"

#include <boost/numeric/odeint.hpp>

typedef std::array<double, 5> state;

// Method parameters
const double dt = 1;
const double t0 = 1000;
const double tf = 5000;

int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);

  double t = t0;

  // s[0]=p, s[1]=ss, s[2]=sd, s[3]=as, s[4]=ad
  state s {1.00, 2.01, 2.23, 2.20, 2.26};

  //timestep
  boost::numeric::odeint::integrate(deriv, s, t0, tf, dt, print);

  return 0;
}
