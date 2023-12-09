#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <cassert>
#include <memory>
#include <sstream> // split

struct Smetar {
    bool flag_Airport                              = false;
    std::unique_ptr<std::string> Airport           = nullptr;
    std::unique_ptr<std::string> Type              = nullptr;
    std::unique_ptr<std::string> Type_Cor          = nullptr;
    std::unique_ptr<std::string> Type_Nil          = nullptr;
    std::unique_ptr<std::string> Type_Auto         = nullptr;
    std::unique_ptr<std::string> Time_Group        = nullptr;
    std::unique_ptr<std::string> Time_Date_Group   = nullptr;
    std::unique_ptr<std::string> Wind_Group        = nullptr;
    std::unique_ptr<std::string> Var_Wind_Group    = nullptr;
    std::unique_ptr<std::string> Visib_Group       = nullptr;
    std::unique_ptr<std::string> Visib_Min_Group   = nullptr;
    std::unique_ptr<std::string> Visib_RNW_Group   = nullptr;
    std::unique_ptr<std::string> Weather_Group     = nullptr;
    std::unique_ptr<std::string> Cloud_Group       = nullptr;
    std::unique_ptr<std::string> Temperature_Group = nullptr;
    std::unique_ptr<std::string> Pressure_Group    = nullptr;
    std::unique_ptr<std::string> TEMPO             = nullptr;
    void clear ();
    void print_metar ();
    std::vector<Smetar> all_SMetar{};
};

void Smetar::print_metar ()
{
    if (Type != nullptr) {
        std::cout << "\nType:\t\t" << *Type;
    };
    if (Type_Cor != nullptr) {
        std::cout << "\nType_Cor:\t\t" << *Type_Cor;
    };
    if (Type_Nil != nullptr) {
        std::cout << "\nType_Nil:\t\t" << *Type_Nil;
    };
    if (Type_Auto != nullptr) {
        std::cout << "\nType_Auto:\t\t" << *Type_Auto;
    };
    if (Airport != nullptr) {
        std::cout << "\nAirport:\t\t" << *Airport;
    };
    if (Time_Group != nullptr) {
        std::cout << "\nTime_Group:\t\t" << *Time_Group;
    };
    if (Time_Date_Group != nullptr) {
        std::cout << "\nTime_Date_Group:\t\t" << *Time_Date_Group;
    };
    if (Wind_Group != nullptr) {
        std::cout << "\nWind_Group:\t\t" << *Wind_Group;
    };
    if (Var_Wind_Group != nullptr) {
        std::cout << "\nVar_Wind_Group:\t\t" << *Var_Wind_Group;
    };
    if (Visib_Group != nullptr) {
        std::cout << "\nVisib_Group:\t\t" << *Visib_Group;
    };
    if (Visib_Min_Group != nullptr) {
        std::cout << "\nVisib_Min_Group:\t\t" << *Visib_Min_Group;
    };
    if (Visib_RNW_Group != nullptr) {
        std::cout << "\nVisib_RNW_Group:\t\t" << *Visib_RNW_Group;
    };
    if (Weather_Group != nullptr) {
        std::cout << "\nWeather_Group:\t\t" << *Weather_Group;
    };
    if (Cloud_Group != nullptr) {
        std::cout << "\nCloud_Group:\t\t" << *Cloud_Group;
    };
    if (Temperature_Group != nullptr) {
        std::cout << "\nTemperature_Group :\t\t" << *Temperature_Group;
    };
    if (Pressure_Group != nullptr) {
        std::cout << "\nPressure_Group  :\t\t" << *Pressure_Group;
    };
    if (TEMPO != nullptr) {
        std::cout << "\nTEMPO:\t\t" << *TEMPO;
    };
    std::cout << "\nEND\n";
}

void Smetar::clear ()
{
    Airport           = nullptr;
    Type              = nullptr;
    Type_Cor          = nullptr;
    Type_Nil          = nullptr;
    Type_Auto         = nullptr;
    Time_Group        = nullptr;
    Time_Date_Group   = nullptr;
    Wind_Group        = nullptr;
    Var_Wind_Group    = nullptr;
    Visib_Group       = nullptr;
    Visib_Min_Group   = nullptr;
    Visib_RNW_Group   = nullptr;
    Weather_Group     = nullptr;
    Cloud_Group       = nullptr;
    Temperature_Group = nullptr;
    Pressure_Group    = nullptr;
    TEMPO             = nullptr;
}

void setSmetar (Smetar& s, const std::string& input_word)
{ // "METAR COR UUWW 301300Z 17005MPS 9000 -SN BKN016 M04/M06 Q1003 R24/520542 TEMPO 1200 SHSN BKN017CB"

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
        if (input_word == "METAR") {
            s.Type = std::make_unique<std::string> (input_word);
        }
        if (input_word == "SPECI") {}
        if (input_word == "COR") {
            s.Type_Cor = std::make_unique<std::string> (input_word);
        }
        if (input_word == "NIL") {
            s.Type_Nil = std::make_unique<std::string> (input_word);
        }
        if (input_word == "AUTO") {
            s.Type_Auto = std::make_unique<std::string> (input_word);
        }
        if (input_word == "TEMPO") {
            assert (s.all_SMetar.size () == 0);
            s.print_metar ();
            s.all_SMetar.push_back (std::move (s));
            s.clear ();
            assert (s.all_SMetar.size () == 1);
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
        std::cout << "Regex is unknown: \t" + input_word;
    }
}

void split (const std::string& data_for_split, char delim, Smetar& smetar)
{
    std::stringstream ss (data_for_split);
    std::string item;
    while (std::getline (ss, item, delim)) {
        if (ss.eof ()) {
            std::cout << "END METAR";
        }
        setSmetar (smetar, item); //
    }
}

int main ()
{

    std::string METAR_str{ "METAR COR UUWW 301300Z 17005MPS 9000 -SN BKN016 M04/M06 Q1003 R24/520542 TEMPO 1200 SHSN BKN017CB" };
    Smetar s1;
    split (METAR_str, ' ', s1);

    return 0;
}
