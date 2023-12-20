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
        case From_To::kt_to_ms:       // км в м/с
                                      //       val = std::string::number (static_cast<int> (round (0.5 * _text.toDouble ())));
            break;
        case From_To::ft_to_m:        //
                                      //     val = std::string::number (static_cast<int> (0.3 * _text.toDouble ()));
            break;
        case From_To::mi_to_m:        //
                                      //    val = std::string::number (static_cast<int> (1000 * round (1.609344 * _text.toDouble ())));
            break;
        case From_To::inchHg_to_hPa:  //
                                      //   val = std::string::number (static_cast<int> (round (33.8638 * _text.toDouble ())));
            break;
        case From_To::inchHg_to_mmHg: //
                                      //     val = std::string::number (static_cast<int> (round (25.4 * _text.toDouble ())));
            break;
        default:
            val = "Not Converting";
    }
    return val;
}
std::string Function::replace_text (const std::string& _wx_string)
{
    // QMapIterator<QString, QString> it_map (All_Dictionary);

    return "";
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
