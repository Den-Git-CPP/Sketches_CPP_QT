#include "include/function.h"

Function::Function ()
{
    if (All_Dictionary.empty ()) {
        Function::Load_AMOFSG_Dictionary ();
    }
}
Function::~Function () {}
std::string Function::replace_val_from_to (const From_To& sign_val, const std::string& _text)
{
    std::string val{};
    switch (sign_val) {
        case From_To::kt_to_ms:                // км в м/с
                                               //       val = std::string::number (static_cast<int> (round (0.5 * _text.toDouble ())));
            break;
        case From_To::ft_to_m:                 //
                                               //     val = std::string::number (static_cast<int> (0.3 * _text.toDouble ()));
            break;
        case From_To::mi_to_m:                 //
                                               //    val = std::string::number (static_cast<int> (1000 * round (1.609344 * _text.toDouble ())));
            break;
        case From_To::inchHg_to_hPa:           //
                                               //   val = std::string::number (static_cast<int> (round (33.8638 * _text.toDouble ())));
            break;
        case From_To::inchHg_to_mmHg:          //
                                               //     val = std::string::number (static_cast<int> (round (25.4 * _text.toDouble ())));
            break;
        case From_To::Time_Group:              //
            return _text.substr (0, 2) + " "   // День месяца
                   + _text.substr (2, 2) + ":" // Часы
                   + _text.substr (4, 2)       // Минуты
                   + " UTC";

        case From_To::Time_Date_Group:
            return "c " + _text.substr (2, 2)         // Число месяца
                   + " " + _text.substr (0, 2)        // Часы
                   + " UTC по " + _text.substr (7, 2) // Число месяца
                   + " " + _text.substr (5, 2)        // Часы
                   + " UTC";
        case From_To::Wind_Group: {
            std::string Wind_Group = "Ветер: " + _text.substr (0, 3) + "° ";
            size_t found_G         = _text.find ('G');
            if (found_G != std::string::npos) {
                Wind_Group.append ("Порывы: " + std::to_string (std::stoi (_text.substr (6, 2))) + " м/с");
            }
            else {
                Wind_Group.append (std::to_string (std::stoi (_text.substr (3, 2))) + " м/с");
            };
            return Wind_Group;
        }
        case From_To::Var_Wind_Group:
            return "Ветер переменный: " + std::to_string (std::stoi (_text.substr (0, 3))) // от направления ветра в градусах
                   + "°-" + std::to_string (std::stoi (_text.substr (4, 3))) + "°"; // до направления ветра в градусах

        case From_To::Visib_Group: {
            if (_text == "CAVOK") {
                return "Видимость более 10 км, нет облаков ниже 1500 м, нет явлений погоды и облачности";
            };
            if (_text == "9999") {
                return "Видимость: 10км.";
            }
            else {
                return "Видимость: " + _text + " м.";
            }
        }
        case From_To::Visib_Min_Group:
            //
            {
                std::string Visib_Min_Group = "Минимальная видимость: " + _text.substr (0, 4);
                if (_text.size () == 5) {
                    if (_text.at (4) == 'N') {
                        Visib_Min_Group.append (" на север.");
                    }
                    if (_text.at (4) == 'W') {
                        Visib_Min_Group.append (" на запад.");
                    }
                    if (_text.at (4) == 'S') {
                        Visib_Min_Group.append (" на юг.");
                    }
                    if (_text.at (4) == 'E') {
                        Visib_Min_Group.append (" на восток.");
                    }
                }
                else if (_text.size () == 6) {
                    if (_text.find ("NW") < _text.size ()) {
                        Visib_Min_Group.append (" на северо-запад.");
                    };
                    if (_text.find ("NE") < _text.size ()) {
                        Visib_Min_Group.append (" на северо-восток.");
                    };
                    if (_text.find ("SW") < _text.size ()) {
                        Visib_Min_Group.append (" на юго-запад.");
                    };
                    if (_text.find ("SE") < _text.size ()) {
                        Visib_Min_Group.append (" на юго-восток.");
                    }
                }
                else {
                    Visib_Min_Group = "Минимальная видимость не пасшифрована.";
                };

                return Visib_Min_Group;
            }

        case From_To::Visib_RNW_Group:
            //
            return "1";

        case From_To::v_Cloud_Group: {
            std::string v_Cloud_Group = replace_text (_text.substr (0, 3))                      // тип облачности
                                        + " на "                                                //
                                        + std::to_string (std::stoi (_text.substr (3, 3)) * 30) // на высоте
                                        + " м.";
            if (_text.find ("CB")) {
                // есди есть призна СВ то обчаность куечво-дождевая
                v_Cloud_Group.append ("(кучево-дождевая)");
            };
            return v_Cloud_Group;
        }
        case From_To::Temperature_Group:
            //
            return "1";
        case From_To::Pressure_Group:
            //
            return "1";

        default:
            val = "Not Converting";
    }
    return val;
}
std::string Function::replace_text (const std::string& _wx_string)
{
    return All_Dictionary [_wx_string];
}
void Function::Load_AMOFSG_Dictionary ()
{
    std::vector<std::string> v_file_path{
        "resource/AMOFSG_Dictionary.txt",      // словарь с явлениями погоды
        "resource/AirportName_Dictionary.txt", // словарь с названиями аэропортов
        "resource/Dictionary.txt"              // словарь с остальными термиинами
    };

    for (const auto& elem : v_file_path) {
        auto currentDir      = std::filesystem::current_path ();
        auto dictionary_path = currentDir / elem;
        dictionary_path.make_preferred ();

        std::ifstream infile;
        infile.open (dictionary_path);
        if (!infile) {
            std::cout << "Can't open file Dictionary: " << dictionary_path << "\n";
            exit (EXIT_FAILURE);
        }
        std::string item1{}, item2{};
        while (infile) {
            std::getline (infile, item1, '/'), getline (infile, item2);
            if (item1 != "") {
                All_Dictionary [item1] = item2;
            }
        }
        infile.close ();
    }
}
