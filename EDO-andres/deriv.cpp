#include "deriv.h"
#include "funcionf.h"

// ODE parameters
const double d = 8.64;
const double m1 = 4.95e2;
const double m2 = 4.95e-2;
const double vs = 0.12;
const double vd = 1.23;
const double w = 0.001;
const double k1 = 2.19e-4;
const double k2 = 6.12e-5;
const double k3 = 0.997148;
const double k4 = 6.79e-2;

void deriv(const std::array<double, 5> & s, std::array<double, 5> & dxdt, double t)
{
	std::array<double, 3> o; // o[0] = hs, o[1] = cs, o[2] = ps
	o[0] = (s[1] - std::sqrt(s[1]*s[1] - k3*s[3]*(2*s[1] - s[3])) ) / k3;
	o[1] = (s[3]-o[0])/2;
	o[2] = (k4*o[0]*o[0])/o[1];

	dxdt[0] = ( (o[2]-s[0])/d ) + (f(t)/m1);
	dxdt[1] = (w*( s[2]-s[1] ) - k1 - m2*( (o[2]-s[0])/d )) / vs;
	dxdt[2] = (k1 - w*( s[2]-s[1] )) / vd;
	dxdt[3] = (w*(s[4]-s[3]) - k2)/vs;
	dxdt[4] = (k2 - w*(s[4]-s[3]))/vd;
}
