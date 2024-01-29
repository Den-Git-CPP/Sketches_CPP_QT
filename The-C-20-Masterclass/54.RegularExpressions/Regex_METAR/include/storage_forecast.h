#pragma once

#include <vector>
#include <memory>
#include <string>
#include <regex>

#include "./include/forecast.h"
#include "./include/function.h"

class Storage_Forecast : public Function {
  public:
    explicit Storage_Forecast ();
    ~Storage_Forecast ();
    void split (const std::string& in_forecast_str);
    void convert_word_to_Forcast (std::unique_ptr<Forecast>& u_ptr_forcast, const std::string& in_forecast_str);

    std::string RawTAF{};
    std::string RawMETAR{};
    std::vector<std::unique_ptr<Forecast>> all_Forecast{};
};
