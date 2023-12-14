#pragma once
#include <vector>
#include <memory>
#include <string>

#include "include/metar.h"
#include "include/taf.h"

class Storage_Forecast {
  public:
    Storage_Forecast ();
    Storage_Forecast (const std::string& _forecast_str);
    void split ();

    template <class T>
    void set_convert_Forcast (std::unique_ptr<T>& s, const std::string& input_word);
    std::unique_ptr<Metar> metar;
    std::unique_ptr<Taf> taf;

    bool Metar_flag{ false };
    bool Taf_flag{ false };

    std::string forecast_str{};

    std::vector<std::unique_ptr<ForecastObj>> all_Forecast;
};
