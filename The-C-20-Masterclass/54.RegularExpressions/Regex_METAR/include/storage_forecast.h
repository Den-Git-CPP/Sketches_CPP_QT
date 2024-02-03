#pragma once

#include <vector>
#include <memory>
#include <string>
#include <regex>

#include "forecast.h"
#include "function.h"

class Storage_Forecast : public Function {
  public:
    explicit Storage_Forecast ();
    ~Storage_Forecast ();
    void split_str (const std::string& in_forecast_str);
    void split_vord (std::unique_ptr<Forecast>& u_ptr_forcast, std::string& buff_line);
    void convert_word_to_Forcast (std::unique_ptr<Forecast>& u_ptr_forcast, const std::string& in_forecast_str);

    std::string RawTAF{ "" };
    std::string RawMETAR{ "" };
    int TempoInMetar{ 0 };
    std::vector<std::unique_ptr<Forecast>> all_Forecast{};
};
