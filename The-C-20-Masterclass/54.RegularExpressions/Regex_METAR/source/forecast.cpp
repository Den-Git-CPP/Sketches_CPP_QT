#include "include/forecast.h"

#include <iostream>
#include <tuple>
#include <functional>

Forecast::Forecast () {}

std::string Forecast::getForecast () const
{
    std::string AllDataForecast{};

    if (flag_TAF) {
        AllDataForecast.append ("ПРОГНОЗ: ");
    }

    //    AllDataForecast.append ("ФАКТИЧЕСКАЯ: ");

    // if (flag_SPECI) {
    //     AllDataForecast.append ("****");
    // };
    // if (flag_COR) {
    //     AllDataForecast.append ("****");
    // };
    // if (flag_NIL) {
    //     AllDataForecast.append ("****");
    // };
    // if (flag_AUTO) {
    //     AllDataForecast.append ("****");
    // };
    if (flag_TEMPO) {
        AllDataForecast.append ("ВРЕМЕНАМИ: ");
    };
    if (flag_BECMG) {
        AllDataForecast.append ("ПОСТЕПЕННО ");
    };

    if (Airport) {
        AllDataForecast.append (*Airport).append ("\n");
    };

    if (Time_Date_Group) {
        AllDataForecast.append (*Time_Date_Group).append ("\n");
    };

    if (Wind_Group) {
        AllDataForecast.append (*Wind_Group).append ("\n");
    };

    if (Var_Wind_Group) {
        AllDataForecast.append (*Var_Wind_Group).append ("\n");
    };
    if (Visib_Group) {
        AllDataForecast.append (*Visib_Group).append ("\n");
    };

    // if (Time_Group) {
    //     AllDataForecast.append (*Time_Group).append ("\n");
    //     ;
    // };

    if (Visib_Min_Group) {
        AllDataForecast.append (*Visib_Min_Group).append ("\n");
    };
    if (Visib_RNW_Group) {
        AllDataForecast.append (*Visib_RNW_Group).append ("\n");
    };
    for (const auto& elem : v_Cloud_Group) {
        AllDataForecast.append (*elem).append ("\n");
    }

    for (const auto& elem : v_Weather_Group) {
        AllDataForecast.append (*elem).append ("\n");
    }

    if (Weather_Group) {
        AllDataForecast.append (*Weather_Group).append ("\n");
    };
    if (Temperature_Group) {
        AllDataForecast.append (*Temperature_Group).append ("\n");
    };
    if (Pressure_Group) {
        AllDataForecast.append (*Pressure_Group).append ("\n");
    };
    // std::vector<std::unique_ptr<std::string>> v_Cloud_Group{};
    // std::vector<std::unique_ptr<std::string>> v_Weather_Group{};
    if (flag_NOSIG) {
        AllDataForecast.append ("Без существенных изменений.\n");
    };
    return AllDataForecast + "\n";
}
