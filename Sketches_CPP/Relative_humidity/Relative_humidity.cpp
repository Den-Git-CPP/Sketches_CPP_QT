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

/*
для отррицательных теператур подходит больше
float HR1(float Tc, float Tv)
{
    float HR1= ( (6.1121 * exp((18.678-Tv/234.5)*Tv/(257.14 + Tv))) / 
               (6.1121 * exp((18.678-Tc/234.5)*Tc/(257.14 + Tc)))
              )*100;
  
  return HR1;
}
*/