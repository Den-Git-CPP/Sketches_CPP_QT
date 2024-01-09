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
    explicit Storage_Forecast ();
    void split (std::string&& in_forecast_str);
    void convert_word_to_Forcast (std::unique_ptr<Forecast>& u_ptr_forcast, std::string&& input_word);
    std::vector<std::unique_ptr<Forecast>> all_Forecast;
};
