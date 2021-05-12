#include "print.h"


void print(const std::array<double, 5> & s, const double t)
{
  std::cout << t << "\t"
              << s[0] << "\t"
              << s[1] << "\t"
              << s[2] << "\t"
              << s[3] << "\t"
              << s[4] << std::endl;
}
