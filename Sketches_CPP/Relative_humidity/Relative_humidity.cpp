// Example program
#include <iostream>
#include <string>
#include <cmath>

float E(float T)
{  
  return 6.1121 * exp((17.5043 * T) / (241.2 + T));
}

float HR(float Tc, float Tv)
{
  float Ec = E(Tc);
  float Ev = E(Tv);
  float e1 = Ev - 0.7945 * (Tc - Tv);
  float HR = 100.0 * (e1 / Ec);
  return HR;
}

int main()
{
int Tc = 30; //температура сухого термометра
int Tv = 27; //температура влажного термометра
float Hum=HR(Tc, Tv);//78.3934
std::cout<<"Relative humidity: "<<Hum;  
}