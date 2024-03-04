#include <iostream>
#include <optional>

std::optional<int> divide(int num1, int num2) {
    if (num2 != 0) {
        return num1/num2;
    }
    return std::nullopt; //Указывает на отсутствие типобезопасного значения.
}

int main() {
    auto result = divide(10, 2);                                // Чтобы сделать вывод в std::optional<int>, используемый для экономии времени
    if (result.has_value()) {                                   // has_value проверяет, возвращается ли значение типа
        std::cout << "Result: " << result.value() << std::endl; // value возвращает значение, поскольку аргументы функции верны
    } else {
        std::cout << "Division by zero" << std::endl;
    }

    return 0;
}