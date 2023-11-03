/*Передача в функции
Можно передать span<const T> , чтобы указать постоянные элементы и получить доступ “только для чтения”, 
      передать span<T> ,       чтобы разрешить доступ на чтение / запись.
*/
#include <format>
#include <iostream>
#include <ranges>
#include <vector>
#include <span>

void transform(std::span<char> outbuf) {
    for (auto& elem : outbuf) {
        elem += 1;
    }
}

void output(std::span<const char> outbuf) {
    std::cout << "contents: ";
    for (auto& elem : outbuf) {
        std::cout << elem << ", ";
    }
    std::cout << '\n';
}

int main() {
    std::string str = "Hello World";
    std::span<char> buf_span(str);

    output(str);
    transform(buf_span);
    output(buf_span);
}
