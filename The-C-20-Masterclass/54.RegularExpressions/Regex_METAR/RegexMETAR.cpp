#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <cassert>
#include <sstream> // split
struct Smetar {
    std::string Airport{};
    bool flag_Airport = false;
    std::string TimeGroup{};
    std::string WindGroup{};
    std::string VisibGroup{};
    std::string Wx{};
    void clear ();
    void print_metar ();
    std::vector<Smetar> all_SMetar{};
};

void Smetar::print_metar ()
{
    std::cout << "\nAirport : " << Airport      //

              << "\nTimeGroup : " << TimeGroup  //
              << "\nWindGroup : " << WindGroup  //
              << "\nVisibGroup: " << VisibGroup //
              << "\nWx : " << Wx                //
              << "\n";
}

void Smetar::clear ()
{
    Airport.clear ();
    TimeGroup.clear ();
    WindGroup.clear ();
    VisibGroup.clear ();
}

void setSmetar (Smetar& s, const std::string& input_word)
{
    std::regex Airport_regex (R"(\-[A-Z]{2,})");
    std::regex TimeGroup_regex (R"(\d{6}Z)");
    std::regex WindGroup_regex (R"(\d{5}(MPS|KT))");
    std::regex VisibGroup_regex (R"(\d{4})");
    std::regex TEMPO_regex (R"(TEMPO)");

    if (std::regex_match (input_word, Airport_regex)) {
        if (s.flag_Airport == false) {
            s.Airport = input_word;
            s.flag_Airport=true;
        }
        else {
            s.Wx = input_word;
        }
    };
    if (std::regex_match (input_word, TimeGroup_regex)) {
        s.TimeGroup = input_word;
    };
    if (std::regex_match (input_word, WindGroup_regex)) {
        s.WindGroup = input_word;
    };
    if (std::regex_match (input_word, VisibGroup_regex)) {
        s.VisibGroup = input_word;
    };
   
    if (std::regex_match (input_word, TEMPO_regex)) {
        assert (s.all_SMetar.size () == 0);
        s.print_metar ();
        s.all_SMetar.push_back (s);
        s.clear ();
        assert (s.all_SMetar.size () == 1);
    };
}

void split (const std::string& data_for_split, char delim, Smetar& smetar)
{
    std::stringstream ss (data_for_split);
    std::string item;
    while (std::getline (ss, item, delim)) {
        setSmetar (smetar, item); //
    }
}

int main ()
{
    //*
    std::string METAR_str{ "METAR UUWW 301300Z 17005MPS 9000 -SN BKN016 M04/M06 Q1003 R24/520542 TEMPO 1200 SHSN BKN017CB" };
    // класс METAR

    Smetar s1;
    split (METAR_str, ' ', s1);

    // assert (s.airport == "SHSN");
    // assert (s.TimeGroup == "301300Z");
    // assert (s.WindGroup == "17005MPS");
    // assert (s.VisibGroup == "1200");

    s1.print_metar ();
    return 0;
}
