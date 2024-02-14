#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <set>

void print (const auto& coll)
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

    return 0;
}
