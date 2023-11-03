#include <iostream>
#include <span>
#include <vector>
/*
C ++ 20 берет string_view и делает его более универсальным с помощью std::span типа. 
Он служит в качестве упрощенной ссылки без права собственности на непрерывный диапазон объектов. 
Это особенно полезно в функциях, которым необходимо работать с частью массива или вектора, не требуя права собственности на данные.
*/
void print(std::span<const int> sp) {
    for (int i : sp)
        std::cout << i << " ";
    std::cout << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::span sp(arr, 5);
    std::vector nums { 10, 11, 12, 13 };

    print(sp);
    print(nums);
}