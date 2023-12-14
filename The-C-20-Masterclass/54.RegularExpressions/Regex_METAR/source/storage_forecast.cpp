
#include "include/storage_forecast.h"

Storage_Forecast::Storage_Forecast () {}

Storage_Forecast::Storage_Forecast (const std::string& _forecast_str) : forecast_str (_forecast_str) // копия прогноза
{
}

void Storage_Forecast::split ()
{
    std::stringstream buf_ss (forecast_str);
    std::string buff_line{}; // токен слово

    // пока поток есть извлекаем по строгкам разбиваем на word item
    while (std::getline (buf_ss, buff_line)) {

        // если поток закончился   ввыодим сообщение
        std::stringstream str_line (buff_line);
        std::string word{}; // токен слово
        char delim{ ' ' };  // разделитель
        while (std::getline (str_line, word, delim)) {
            // установка флага true если начинается прогноз TAF
            (word == "TAF") ? Metar_flag = false : Taf_flag = true;
            // пргонгоз начинается c METAR true
            if (Metar_flag) {
                if (!word.empty ()) {
                    set_convert_Forcast (metar, word); //
                }
            }
            else if (Taf_flag) {
                if (!word.empty ()) {
                    set_convert_Forcast (taf, word); //
                }
            }
            else {
                std::cout << "Dont ForecastObj\n";
            }
        }
    }
}
template <class T>
void Storage_Forecast::set_convert_Forcast (T& s, const std::string& input_word)
{
    // "METAR COR UUWW 301300Z 17005MPS 9000 -SN BKN016 M04/M06 Q1003 R24/520542 TEMPO 1200 SHSN BKN017CB"

    // Группы идентификации
    std::regex Type_regex (R"(METAR|SPECI|COR|NIL|AUTO|TEMPO|BECMG)");
    std::regex Airport_regex (R"([A-Z]{4})");
    std::regex Time_Group_regex (R"(\d{6}Z)");
    std::regex Time_Date_Group_regex (R"(\d{4}\/\d{4})");
    // Приземный ветер dddffGfmfm(MPS|KT)dndndnVdxdxdx
    std::regex Wind_Group_regex (R"((\d{5}|\d{5}G\d{2})(MPS|KT))");
    std::regex Var_Wind_Group_regex (R"((\d{3}V\d{3}))");
    // Видимость
    std::regex Visib_Group_regex (R"(\d{4}|CAVOK)");
    std::regex Visib_Min_Group_regex (R"(\d{4}[A-Z][A-Z])");
    // Дальность видимости на ВПП
    std::regex Visib_RNW_Group_regex (R"(R\d{2}[A-Z]?\/M?\d{4}[UDN]?)");
    // Текущая погода
    std::regex Weather_Group_regex (R"((\+|\-)?[A-Z]{2,8})");
    // Облачность (или вертикальная видимость)
    std::regex Cloud_Group_regex (R"((FEW|SCT|BKN|OVC|NSC|NCD)\d{3}(CB)?)");
    // Температура воздуха и температура точки росы
    std::regex Temperature_Group_regex (R"(M?\d{2}\/M?\d{2})");
    std::regex Pressure_Group_regex (R"(Q\d{4})");

    if (std::regex_match (input_word, Type_regex)) {

        if (input_word == "SPECI") {}
        if (input_word == "COR") {
            s.Type_Cor = std::move (std::make_unique<std::string> (input_word));
        }
        if (input_word == "NIL") {
            s.Type_Nil = std::make_unique<std::string> (input_word);
        }
        if (input_word == "AUTO") {
            s.Type_Auto = std::make_unique<std::string> (input_word);
        }
        if (input_word == "TEMPO") {
            all_Forecast.emplace_back (s);
            //   s.clear ();
        }
        if (input_word == "BECMG") {}
    }
    else if (std::regex_match (input_word, Airport_regex)) {
        if (s.flag_Airport == false) {
            s.Airport      = std::make_unique<std::string> (input_word);
            s.flag_Airport = true;
        }
        else {
            s.Weather_Group = std::make_unique<std::string> (input_word);
        }
    }
    else if (std::regex_match (input_word, Time_Group_regex)) {
        s.Time_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Time_Date_Group_regex)) {
        s.Time_Date_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Wind_Group_regex)) {
        s.Wind_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Var_Wind_Group_regex)) {
        s.Var_Wind_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Visib_Group_regex)) {
        s.Visib_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Visib_Min_Group_regex)) {
        s.Visib_Min_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Visib_RNW_Group_regex)) {
        s.Visib_RNW_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Weather_Group_regex)) {
        s.Weather_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Cloud_Group_regex)) {
        s.Cloud_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Temperature_Group_regex)) {
        s.Temperature_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Pressure_Group_regex)) {
        s.Pressure_Group = std::make_unique<std::string> (input_word);
    }
    else {
        std::cout << "\nRegex is unknown: \t" + input_word;
    }
}
