#include "funcionf.h"

double f(double t)
{
	std::array<double, 3> ci {2.0, 10.5, 2.7};
	std::array<double, 3> ti {1988.0, 2100.0, 2265.0};
	std::array<double, 3> si {21.0, 96.0, 57.0};

	double sum = 0;

	for (int i = 0; i < ci.size(); i++){
		sum += ci[i] * std::exp( -((t-ti[i])*(t-ti[i])) / (si[i]*si[i]) );
	}

	return sum;
}
