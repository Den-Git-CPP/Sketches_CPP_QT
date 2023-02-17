#include <iostream>
#include <cmath> // для round
//ГГ.гггггг° / DD.dddddd°
//to
//ГГ°MM'СС.с" / DD°MM'SS.s"
using namespace std;

int main(int argc, char* argv[])
{
double Long{55.7522},Lat{37.660777};
int Degree_Long= abs(Long);
int Degree_Lat=abs(Lat);
std::cout <<"Degree_Long:  "<<Degree_Long<<"\n"
          <<"Degree_Lat:  "<<Degree_Lat<<"\n";

int Minutes_Long= (Long-static_cast<int>(abs(Long)))*60;
int Minutes_Lat= (Lat-static_cast<int>(abs(Lat)))*60;
std::cout <<"Minutes_Long:  "<<Minutes_Long<<"\n"
          <<"Minutes_Lat:  "<<Minutes_Lat<<"\n";

double  Seconds_Long= ((Long-Degree_Long)*60- static_cast<int>(abs((Long-Degree_Long))*60))*60;
double  Seconds_Lat=  ((Lat-Degree_Lat)*60- static_cast<int>(abs((Lat-Degree_Lat)*60)))*60;
std::cout <<"Seconds_Long:  "<<Seconds_Long<<"\n"
          <<"Seconds_Lat:  "<<Seconds_Lat<<"\n";

double  Seconds_Long_dbl= round(Seconds_Long*100)/100;//Округление до второго знака
double  Seconds_Lat_dbl=  round(Seconds_Lat*100)/100; //Округление до второго знака
std::cout <<"Seconds_Long:  "<<Seconds_Long_dbl<<"\n"
          <<"Seconds_Lat:  "<<Seconds_Lat_dbl<<"\n";


  return 0;
}