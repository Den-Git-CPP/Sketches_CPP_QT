#pragma once

#include <vector>
#include <memory>
#include <string>
#include <regex>
#include <sstream> // split
#include "include/metar.h"
#include "include/taf.h"

class Storage_Forecast {
  public:
    Storage_Forecast ();
    Storage_Forecast (const std::string& _forecast_str);
    void split ();

    template <class T>
    void set_convert_Forcast (T& s, const std::string& input_word);
    Metar metar;
    Taf taf;

    bool Metar_flag{ true };
    bool Taf_flag{ false };

    std::string forecast_str{};

    std::vector<ForecastObj> all_Forecast;
};
