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

/*
    //https://www.wpc.ncep.noaa.gov/html/dewrh.shtml
    //https://www.wikihow.com/Calculate-Humidity

    // 1.Convert the air temperature and dew-point temperature to Celsius.
    // For example, if the temperature is 100°F, you would first subtract 32 from 100, which would give you 68.
    // Then, you would multiply 68 by 5/9, which would give you the temperature of 37.778°C.
    // С=(5/9)*(F-32)

    // 2.Calculate the saturated vapor pressure with a formula.
    // Es = 6.11*10((7.5*T_air)/(237.3+T_air))
    // Es-     standard vapor pressure and ( T )
    // T_air-  air temperature

    // 3.Find the actual vapor pressure with the same formula.
    // E = 6.11*10((7.5*T_dev)/(237.3+T_dev))
    // E-  actual vapor pressure
    // T_dev- dew point

    // 4.Calculate the relative humidity
    // RH=(E/Es)*100
    // RH- relative humidity,
    // E-  actual vapor pressure
    // Es-     standard vapor pressure and ( T )
    //-------------------
    
    var a=tonum(form.inputbox1.value);//Air Temperature
    var b=tonum(form.inputbox2.value);//Dew Point

    if (form.inputbox1.value == "") { 
      alert("Enter a Temperature value")
    }
    else if (form.inputbox2.value == "") { 
      alert("Enter a Dew Point value") 
    } else if (a < b) { 
        alert("Dew Point cannot be greater than temperature")
    }
    else 
    {
       var a=tonum(form.inputbox1.value);//Air Temperature
       var b=tonum(form.inputbox2.value);//Dew Point
       var a_c = (5.0/9.0)*(a-32.0);
       var b_c = (5.0/9.0)*(b-32.0);
       var c=6.11*Math.pow(10,((7.5*a_c/(237.7+a_c))));//saturation vapor pressure
       var d=6.11*Math.pow(10,((7.5*b_c/(237.7+b_c))));//actual vapor pressure
       var e=(d/c)*100;//relative humidity 
}

*/