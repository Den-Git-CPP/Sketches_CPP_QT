#pragma once

#include <vector>
#include <memory>
#include <string>
#include <regex>
#include <sstream> // split
#include "include/forecast.h"
#include "include/function.h"

class Storage_Forecast : public Function {
  public:
    Storage_Forecast ();
    Storage_Forecast (const std::string& _forecast_str);
    void split ();

    void set_convert_Forcast (std::unique_ptr<Forecast>& u_ptr_forcast, const std::string& input_word);

    void insert_Forecast_intro_all_Forecast ();
    std::string forecast_str{};
    std::unique_ptr<Forecast> forecast{ nullptr };
    std::vector<std::unique_ptr<Forecast>> all_Forecast;
};
