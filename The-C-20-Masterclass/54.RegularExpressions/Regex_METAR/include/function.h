#pragma once
#include <QDebug>
#include <fstream>
#include <filesystem>
#include <vector>
#include <map>
#include <string>
#include <iostream>

enum From_To {
    kt_to_ms,      // км в м/с
    ft_to_m,       // футы в м
    mi_to_m,       // мили в м
    inchHg_to_hPa, // Дюймы ртутного столба в Гектопаскаль
    inchHg_to_mmHg // Дюймы ртутного столба в Миллиметры ртутного столба
};

class Function {
  public:
    Function ();
    ~Function ();
    std::map<std::string, std::string> All_Dictionary;

  protected:
    std::string replace_text (const std::string& _text);
    std::string replace_val_from_to (const From_To& sign_val, const std::string& _text);
    void Load_AMOFSG_Dictionary ();
};