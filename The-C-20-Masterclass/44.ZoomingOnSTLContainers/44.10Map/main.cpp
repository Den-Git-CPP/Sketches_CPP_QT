#include <iostream>
#include <functional>
#include <map>

#include <vector>
#include <cassert>

class IntComparator {
  public:
    bool operator() (int left, int right) const
    {
        return (left < right);
    }
};

bool compare_ints (int left, int right)
{
    return (left < right);
}

class Book {
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);

  public:
    Book () = default;
    Book (int year, std::string title) : m_year (year), m_title (title) {}

    bool operator< (const Book& right_operand) const
    {
        return this->m_year < right_operand.m_year;
    }

  private:
    int m_year;
    std::string m_title;
};

std::ostream& operator<< (std::ostream& out, const Book& operand)
{
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}

template <typename T, typename K>
void print_map (const std::map<T, K>& map)
{

    auto it = map.begin ();

    std::cout << " map of elements : [";
    while (it != map.end ()) {

        std::cout << " [" << it->first << "," << it->second << "]";
        ++it;
    }
    std::cout << " ]  \n";
}

int main ()
{

    // Code1 : Building maps : Notice that things are stored by key by default
    //  regardless of the order you put them in the collection in .

    std::cout << "Creating maps : \n";
    std::map<int, int> numbers{
        {1, 11},
        {0, 12},
        {4, 13},
        {2, 14},
        {3, 15}
    };

    std::cout << " numbers : ";
    print_map (numbers);

    // Map of custom types : Need to implement operator<
    std::map<int, Book> books{
        {2, Book (1734,          "Cooking Food")},
        {0, Book (1930,    "Building Computers")},
        {1, Book (1995, "Farming for Beginners")}
    };
    std::cout << " books : ";
    print_map (books);

    std::cout << "--------------------------------------  \n";

    // Code2 : Element access with regular loops
    // A std::map can be though of as a collection of std::pair's
    std::cout << "\nLooping around printing stuff:\n";
    std::cout << " \nprinting books with regular range based for loop [] syntax (C++17):\n";
    for (const auto& [key, value] : books) {
        std::cout << "  book [ " << key << " ]:" << value << "\n";
    }
    std::cout << "\n Traverse map with C++11 loop syntax :   \n";

    for (const auto& elt : books) {
        std::cout << "  book [" << elt.first << " ] : " << elt.second << "\n";
    }
    std::cout << "\ntraverse map with loop (with explicit types):\n";
    for (const std::pair<int, Book>& elt : books) {
        std::cout << "  book [" << elt.first << " ] : " << elt.second << "\n";
    }
    std::cout << "--------------------------------------\n";

    // Keys can be anything
    std::cout << "\nkeys can be anything : std::string in this case (stored by key):\n";

    std::map<std::string, std::string> address_book;
    address_book ["Daniel Gray"] = "Kigali, KG St 334 #56";
    address_book ["Steve Moris"] = "Huye, SH St 27 #78";
    address_book ["John Snow"]   = "Musanze, NM St 33 #89";
    address_book ["Henry King"]  = "Muhanga, SM St 128 #3";

    for (const auto& [key, value] : address_book) {
        std::cout << " " << key << " lives at address : " << value << "\n";
    }
    std::cout << "--------------------------------------\n";

    // Iterators
    std::cout << "Iterators:\n";
    auto it_access = numbers.begin ();

    std::cout << " numbers (forward iterators) : [";
    while (it_access != numbers.end ()) {
        std::cout << " " << numbers [it_access->first];
        ++it_access;
    }
    std::cout << "]\n";
    std::cout << "modifying elements through iterators : \n";

    // Iterate forward over numbers
    print_map (numbers);

    auto it_modify = numbers.begin ();
    while (it_modify != numbers.end ()) {
        numbers [it_modify->first] = 222; // Modify values in the map
        ++it_modify;
    }
    print_map (numbers);

    // Iterate over books in reverse
    std::cout << "\n(iterators) set of books (reverse) :\n";
    auto it_back_books = books.rbegin ();
    while (it_back_books != books.rend ()) {
        // Will require you to add a default constructor to Book.
        // This is an implementation detail of std::map. If we cut out the line
        // using operator[] the requirement for the default constructor goes away.
        std::cout << " " << it_back_books->first << " - " << books [it_back_books->first] << "\n";
        ++it_back_books;
    }

    // Code4 : Capacity :
    std::cout << "---------------------\n";
    std::cout << std::boolalpha;
    std::cout << "capacity : \n";
    std::cout << "numbers : ";
    print_map (numbers);
    std::cout << " map max_size : " << numbers.max_size () << "\n";
    std::cout << " map is empty : " << numbers.empty () << "\n";
    std::cout << " map size : " << numbers.size () << "\n";
    std::cout << "---------------------\n";

    // Modifiers
    // Clear
    std::cout << "clear :\n";
    std::cout << "numbers:\n";
    print_map (numbers);
    numbers.clear ();

    std::cout << " numbers : ";
    print_map (numbers);
    std::cout << std::boolalpha;
    std::cout << " numbers is empty : " << numbers.empty () << "\n";

    // Insert  : return an std::pair object containing result about the insert operation.
    std::cout << "\ninsert:\n";
    numbers = {
        {0, 11},
        {1, 12},
        {2, 13},
        {3, 14},
        {4, 15}
    };
    print_map (numbers);

    // Insert key 2 : won't insert because std::set doesn't allow duplicate keys.
    // Will just do nothing and won't give an error though.
    numbers.insert ({ 2, 44 });

    //numbers.insert({5,16});//Works

    std::cout << "After insert {2,44} : ";
    // std::cout << "After insert {5,16} : " ;
    print_map (numbers);

    // Can capture the insert result through a returned std::pair object.
    auto result = numbers.insert ({ 6, 17 });

    std::cout << " result.second : " << result.second << "\n";

    if (result.second) {
        std::cout << " Insertion successful\n";
    }
    else {
        std::cout << " Couldn't inser in the set. It's a duplicate!\n";
    }
    print_map (numbers);

    // Emplace
    std::cout << "\nemplace : \n";

    std::cout << " before emplace : ";
    print_map (numbers);

    auto result_emplace = numbers.emplace (std::make_pair (7, 18));

    if (result_emplace.second) {
        std::cout << "Emplace  successful \n";
    }
    else {
        std::cout << " Emplace  FAILED \n";
    }

    std::cout << " after emplace : ";
    print_map (numbers);

    // Erase
    std::cout << "erase : \n";
    print_map (numbers);

    auto it_erase = numbers.find (3); // Find element with key 3
    if (it_erase != numbers.end ()) {
        std::cout << " Found element with key " << it_erase->first << " ! : " << it_erase->second << "\n";
    }
    else {
        std::cout << " Couldn't find element with key 3 !\n";
    }

    // Erase the element with key 3
    if (it_erase != numbers.end ()) numbers.erase (it_erase);

    print_map (numbers);

    // Changing comparators : There are many ways this can be done, but I am
    // going to give you a few variations to get you started.

    std::cout << "\n";
    std::cout << "Changing comparators :   \n";

    //std::map<int,int> numbers2 {{1,11},{0,12},{4,13},{2,14},{3,15}};//Default
    //std::map<int,int,std::less<int>> numbers2 {{1,11},{0,12},{4,13},{2,14},{3,15}};//Built in functor
    // std::map<int,int,std::greater<int>> numbers2 {{1,11},{0,12},{4,13},{2,14},{3,15}};

    // Custom functor
    // std::map<int,int,IntComparator> numbers2 {{1,11},{0,12},{4,13},{2,14},{3,15}};

    // Custom funtion pointer
    /*
    std::map<int,int,bool(*)(int,int)> numbers2(compare_ints);
    numbers2.insert({{1,11},{0,12},{4,13},{2,14},{3,15}});
    */

    // Lambda function
    std::map<int, int, std::function<bool (int, int)>> numbers2 ([] (int left, int right) {
        return left > right;
    });
    numbers2.insert ({
      {1, 11},
      {0, 12},
      {4, 13},
      {2, 14},
      {3, 15}
    });

    std::cout << "numbers2 : [ ";
    for (const auto& [key, value] : numbers2) {
        std::cout << " (" << key << "," << value << ")";
    }
    std::cout << "]  \n";

    // std::map::contains(C++20)
    // Вместо
    // if (auto search = freq_of.find(2); search != freq_of.end()) {
    //     cout << "Found" << endl;
    // }
    // в C++ 20 Можно писать
    if (numbers2.contains (2)) {
        std::cout << "Found!!!\n";
    }

    // std::map::try_emplace(C++17)
    // При вставке в карту у нас есть 2 разные возможности:
    //-Ключ еще не существует. Создайте новую пару ключ-значение.
    //-Ключ уже существует. Возьмите существующий элемент и измените его.
    // C ++ 17, существует этот std::map::try_emplace метод, который создает элементы, только если ключ еще не существует.

    std::vector v{ 3, 4, 5, 8, 7, 3, 5, 2, 4 };
    std::map<uint32_t, uint32_t> freq_of;
    for (const auto& n : v) {
        // if (const auto& [it, inserted] = freq_of.emplace (n, 1); !inserted) {
        //     it->second++; // Exists already
        // }
        if (const auto& [it, inserted] = freq_of.try_emplace (n, 1); !inserted) {
            it->second++;
        }
    }
    assert (freq_of [3] == 2);

    // std::map::insert_or_assign(C ++ 17)
    //  std::map::insert_or_assign является более подходящим и возвращает больше информации, чем std::map::operator[ ]

    { // std::map::insert_or_assign
        std::vector v{ 8, 3, 9, 5, 8 };
        std::map<uint32_t, uint32_t> freq_of;

        for (auto&& n : v) {
            const auto& [it, is_inserted] = freq_of.insert_or_assign (n, 1);

            if (!is_inserted) { // удалить все меньшие элементы, чем текущий, если повторяется
                freq_of.erase (begin (freq_of), it);
            }
        }

        assert ((freq_of
                 == decltype (freq_of){
                   {8, 1},
                   {9, 1},
        }));
    }
    //
    // std::map::insert With Hint(C++11/17)
    {
        std::cout << "\nstd::map::insert With Hint(C++11/17)\n";
        std::map<uint32_t, std::string> m{
            {2, "2a"},
            {3, "3a"}
        };
        auto where (std::end (m));
        for (const auto& n : { 8, 7, 6, 5, 4, 3, 2, 1 }) {
            // Элементы в неинкрементальном порядке
            where = m.insert (where, { n, "" });
        }
        // How it is not done!
        // m.insert(end(m), {0, ""});
        for (const auto& [key, value] : m) {
            std::cout << key << " : " << value << "\n";
        }
    }
    //
    { // std::map::merge(C++17) std::map::merge который переносит элементы оптом
        std::map<uint32_t, std::string> fruits{
            {5, "grapes"},
            {2, "tomoto"}
        };
        std::map<uint32_t, std::string> person{
            { 2, "mickel"},
            {10,  "shree"}
        };
        std::map<uint32_t, std::string> fruits_and_persons;
        fruits_and_persons.merge (fruits);
        assert (fruits.size () == 0);

        fruits_and_persons.merge (person);
        assert (person.size () == 1);
        assert (person.at (2) == "mickel"); // Не будет перезаписывать значение 2, т.е. `mickel`
        assert ((fruits_and_persons
                 == decltype (fruits){
                   { 2, "tomoto"},
                   { 5, "grapes"},
                   {10,  "shree"},
        }));
        // Дублированные элементы не передаются. Они остаются на карте с правой стороны.
    }
    //
    { // std::map::extract(C ++ 17)
      // В отличие от std::map::merge который переносит элементы оптом,  std::map::extract вместе с std::map::insert переносит элемент по частям.
      // Но что является более убедительным применением std::map::extract изменяет ключи.

        std::map<int, std::string> race_scoreboard{
            {1, "Mickel"},
            {2,  "Shree"},
            {3,  "Jenti"}
        };
        using Pair = std::map<int, std::string>::value_type;
        {
            auto Jenti (race_scoreboard.extract (3));
            auto Mickel (race_scoreboard.extract (1));
            std::swap (Jenti.key (), Mickel.key ());

            auto [it, is_inserted, nh] = race_scoreboard.insert (move (Jenti)); // nh = node handle

            assert (*it == Pair (1, "Jenti") && is_inserted == true && nh.empty ());
            race_scoreboard.insert (move (Mickel));
        }
        //
        assert ((race_scoreboard
                 == decltype (race_scoreboard){
                   {1,  "Jenti"},
                   {2,  "Shree"},
                   {3, "Mickel"},
        }));
    }

    return 0;
}
