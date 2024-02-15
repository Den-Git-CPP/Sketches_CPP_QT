#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
void print (const auto& coll)
{
    for (const auto& elem : coll) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

void print2 (auto&& coll)
{
    for (const auto& elem : coll) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
int main ()
{

    std::vector<int> coll1{ 0, 15, 47, 11, 42, 2 };
    std::set<int> coll2{ 0, 15, 47, 11, 42, 2 };

    print (coll1);                       // 0, 15, 47, 11, 42, 2
    print (coll2);                       // 0, 15, 47, 11, 42,
    print (std::views::take (coll1, 3)); // 0 15 47 // print first 3 elem
    print (std::views::take (coll2, 3)); // 0 2 11  // print first 3 elem

    print (coll1 | std::views::take (3));         // 0 15 47 // print first 3 elem
    print (coll2 | std::views::take (3));         // 0 2 11  // print first 3 elem
    print (coll2 | std::views::take (3)           // взяли 3
           | std::views::transform ([] (auto v) { // прибавили в конце "s" // 0s 2s 11s
                 return std::to_string (v) + 's';
             }));

    std::map<std::string, int> composers{
        {       "Bach", 1965},
        {     "Mozart", 1756},
        {  "Beethoven", 1770},
        {"Tchaikovsky", 1840},
        {     "Chopin", 1810},
        {    "Vivaldi", 1675}
    };

    namespace vws = std::views;
    for (const auto& elem : composers
                              | vws::filter ([] (const auto& e) // since 1700
                                {
                                    return e.second >= 1700;
                                })
                              | vws::take (3) // first 3
                              | vws::keys     // only names
    ) {
        std::cout << "-" << elem << "\n"; //-Bach
                                          //-Beethoven
                                          // -Chopin
    }

    auto v = std::views::iota (1) // generate 1,2,3..
             | std::views::filter ([] (auto val) {
                   return val % 3 == 0;
               })
             | std::views::drop (3) // skip 3
             | std::views::take (3) // take next 3
             | std::views::transform ([] (auto val) {
                   return std::to_string (val) + 's';
               });
    for (const auto& elem : v) {          //-12s
        std::cout << "-" << elem << "\n"; //-15s
    }                                     //-18s

    // Processing Containers and Views
    std::vector<int> vec{ 0, 15, 47, 11, 42, 2 };
    std::list<int> lst{ 0, 15, 47, 11, 42, 2 };
    print (vec);
    print (lst);

    print (vec | std::views::take (3));
    print (lst | std::views::take (3));
    print (vec | std::views::drop (3));
    // print (lst | std::views::drop (3)); // Compile-time Error
    print (std::ranges::subrange{ lst | std::views::drop (3) }); // OK

    auto less20 = [] (auto val) {
        return val < 20;
    };
    print2 (vec | std::views::filter (less20)); // OK
    print2 (lst | std::views::filter (less20)); // OK

    std::vector<int> vec_1{ 0, 15, 47, 11, 42, 2 };
    print (vec_1); // 0 15 47 11 42 2
    auto isEven = [] (auto&& i) {
        return i % 2 == 0;
    };
    auto vec_1_Even = vec_1 | std::views::filter (isEven);
    for (int& i : vec_1_Even) {
        i += 2;
    }
    print (vec_1); // 2 15 47 11 44 4

    // Modifications Considered Harmful with Caching
    std::vector<int> vec_2{ 1, 2, 3, 4 };
    vec_2.reserve (9);

    std::list<int> lst_2{ 1, 2, 3, 4 };

    auto vVec = vec_2 | std::views::drop (2);
    auto vLst = lst_2 | std::views::drop (2);

    vec_2.insert (vec_2.begin (), 0);
    lst_2.insert (lst_2.begin (), 0);
    print (vVec);                          // 2 3 4
    print (std::ranges::subrange{ vLst }); // 2 3 4

    vec_2.insert (vec_2.begin (), { -2, -1 });
    lst_2.insert (lst_2.begin (), { -2, -1 });
    print (vVec);                          // 0 1 2 3 4
    print (std::ranges::subrange{ vLst }); // 2 3 4

    auto vVecB = vVec;
    auto vLstB = vLst;
    print (vVecB);                          // 0 1 2 3 4
    print (std::ranges::subrange{ vLstB }); // 0 1 2 3 4

    return 0;
}
