#include "include/forecast.h"

Forecast::Forecast () {}
void Forecast::print ()
{
    std::cout << "Forecast\n";

    if (Airport != nullptr) {
        std::cout << "\nAirport:\t\t" << *Airport;
    };
    if (Time_Group != nullptr) {
        std::cout << "\nTime_Group:\t\t" << *Time_Group;
    };
    if (Time_Date_Group != nullptr) {
        std::cout << "\nTime_Date_Group:\t\t" << *Time_Date_Group;
    };
    if (Wind_Group != nullptr) {
        std::cout << "\nWind_Group:\t\t" << *Wind_Group;
    };
    if (Var_Wind_Group != nullptr) {
        std::cout << "\nVar_Wind_Group:\t\t" << *Var_Wind_Group;
    };
    if (Visib_Group != nullptr) {
        std::cout << "\nVisib_Group:\t\t" << *Visib_Group;
    };
    if (Visib_Min_Group != nullptr) {
        std::cout << "\nVisib_Min_Group:\t\t" << *Visib_Min_Group;
    };
    if (Visib_RNW_Group != nullptr) {

        std::cout << "\nVisib_RNW_Group:\t\t" << *Visib_RNW_Group;
    };
    if (Weather_Group != nullptr) {
        std::cout << "\nWeather_Group:\t\t" << *Weather_Group;
    };
    if (Cloud_Group != nullptr) {
        std::cout << "\nCloud_Group:\t\t" << *Cloud_Group;
    };
    if (Temperature_Group != nullptr) {
        std::cout << "\nTemperature_Group :\t\t" << *Temperature_Group;
    };
    if (Pressure_Group != nullptr) {
        std::cout << "\nPressure_Group  :\t\t" << *Pressure_Group;
    };
    if (TEMPO != nullptr) {
        std::cout << "\nTEMPO:\t\t" << *TEMPO;
    };
    std::cout << "\nEND\n";
}
