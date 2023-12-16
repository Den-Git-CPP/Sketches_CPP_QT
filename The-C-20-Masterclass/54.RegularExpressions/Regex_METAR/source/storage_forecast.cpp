
#include "include/storage_forecast.h"

#include <qDebug>

Storage_Forecast::Storage_Forecast () {}

Storage_Forecast::Storage_Forecast (const std::string& _forecast_str) : forecast_str (_forecast_str) // копия прогноза
{
    forecast = std::make_unique<Forecast> ();
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
            if (!word.empty ()) {
                set_convert_Forcast (forecast, word); //
            }
        }
        all_Forecast.emplace_back (std::move (forecast));
        forecast = std::make_unique<Forecast> ();
    }
}

void Storage_Forecast::set_convert_Forcast (std::unique_ptr<Forecast>& u_ptr_forcast, const std::string& input_word)
{
    // "METAR COR UUWW 301300Z 17005MPS 9000 -SN BKN016 M04/M06 Q1003 R24/520542 TEMPO 1200 SHSN BKN017CB"

    // Группы идентификации
    std::regex Type_regex (R"(METAR|TAF|SPECI|COR|NIL|AUTO|TEMPO|BECMG|NOSIG)");
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
        if (input_word == "TAF") {}
        if (input_word == "SPECI") {
            u_ptr_forcast->flag_SPECI = true;
        }
        if (input_word == "COR") {
            u_ptr_forcast->flag_COR = true;
        }
        if (input_word == "NIL") {
            u_ptr_forcast->flag_NIL = true;
        }
        if (input_word == "AUTO") {
            u_ptr_forcast->flag_AUTO = true;
        }
        if (input_word == "TEMPO") {
            // TEMPO
            u_ptr_forcast->flag_Airport = true;
            u_ptr_forcast->flag_TEMPO   = true;
        }
        if (input_word == "BECMG") {
            // BECMG
            u_ptr_forcast->flag_Airport = true;
            u_ptr_forcast->flag_BECMG   = true;
        }
        if (input_word == "NOSIG") {
            // NOSIG
            u_ptr_forcast->flag_Airport = true;
            u_ptr_forcast->flag_NOSIG   = true;
        }
    }
    else if (std::regex_match (input_word, Airport_regex)) {
        if (u_ptr_forcast->flag_Airport == false) {
            u_ptr_forcast->Airport      = std::make_unique<std::string> (input_word);
            u_ptr_forcast->flag_Airport = true;
        }
        else {
            u_ptr_forcast->v_Weather_Group.emplace_back (std::move (std::make_unique<std::string> (input_word)));
            // s.Weather_Group = std::make_unique<std::string> (input_word);
        }
    }
    else if (std::regex_match (input_word, Time_Group_regex)) {
        u_ptr_forcast->Time_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Time_Date_Group_regex)) {
        u_ptr_forcast->Time_Date_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Wind_Group_regex)) {
        u_ptr_forcast->Wind_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Var_Wind_Group_regex)) {
        u_ptr_forcast->Var_Wind_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Visib_Group_regex)) {
        u_ptr_forcast->Visib_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Visib_Min_Group_regex)) {
        u_ptr_forcast->Visib_Min_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Visib_RNW_Group_regex)) {
        u_ptr_forcast->Visib_RNW_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Weather_Group_regex)) {
        u_ptr_forcast->v_Weather_Group.emplace_back (std::move (std::make_unique<std::string> (input_word)));
    }
    else if (std::regex_match (input_word, Cloud_Group_regex)) {
        u_ptr_forcast->v_Cloud_Group.emplace_back (std::move (std::make_unique<std::string> (input_word)));
        // s.Cloud_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Temperature_Group_regex)) {
        u_ptr_forcast->Temperature_Group = std::make_unique<std::string> (input_word);
    }
    else if (std::regex_match (input_word, Pressure_Group_regex)) {
        u_ptr_forcast->Pressure_Group = std::make_unique<std::string> (input_word);
    }
    else {
        qDebug () << "\nRegex is unknown: \t" + input_word;
    }
}
