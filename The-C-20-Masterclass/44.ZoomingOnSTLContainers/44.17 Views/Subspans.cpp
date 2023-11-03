//Subspans   
#include <span>
#include <iostream>

void printSpan(std::span<const int> sp) {
    for (auto&& elem : sp)
        std::cout << elem << ' ';
    std::cout << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    std::span<int> sp(arr, 6);

    // subspan(start, count):
    std::span<int> sub = sp.subspan(2, /*count*/2);
    printSpan(sub);

    // fist(count):
    std::span<int> subFirst3 = sp.first(3);
    printSpan(subFirst3);

    // last(count):
    std::span<int> subLast4 = sp.last(4);
    printSpan(subLast4);
}