#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "include/forecastobj.h"

class Metar : public ForecastObj {
  public:
    Metar ();
    bool flag_Airport                              = false;
    std::unique_ptr<std::string> Airport           = nullptr;
    std::unique_ptr<std::string> Type_Cor          = nullptr;
    std::unique_ptr<std::string> Type_Nil          = nullptr;
    std::unique_ptr<std::string> Type_Auto         = nullptr;
    std::unique_ptr<std::string> Time_Group        = nullptr;
    std::unique_ptr<std::string> Time_Date_Group   = nullptr;
    std::unique_ptr<std::string> Wind_Group        = nullptr;
    std::unique_ptr<std::string> Var_Wind_Group    = nullptr;
    std::unique_ptr<std::string> Visib_Group       = nullptr;
    std::unique_ptr<std::string> Visib_Min_Group   = nullptr;
    std::unique_ptr<std::string> Visib_RNW_Group   = nullptr;
    std::unique_ptr<std::string> Weather_Group     = nullptr;
    std::unique_ptr<std::string> Cloud_Group       = nullptr;
    std::unique_ptr<std::string> Temperature_Group = nullptr;
    std::unique_ptr<std::string> Pressure_Group    = nullptr;
    std::unique_ptr<std::string> TEMPO             = nullptr;
    void clear ();
    void print_metar ();
};
