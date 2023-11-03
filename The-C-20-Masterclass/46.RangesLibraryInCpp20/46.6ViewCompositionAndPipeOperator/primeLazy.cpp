// primesLazy.cpp

#include <iostream>
#include <ranges>


bool isPrime(int i) {
    for (int j=2; j*j <= i; ++j){
        if (i % j == 0) return false;
    }
    return true;
}

int main() {
                                        
    std::cout << '\n';
                                         
    auto odd = [](int i){ return i % 2 == 1; };

    for (int i: std::views::iota(1'000'000) | std::views::filter(odd)       //в бесконечном потоке на 1'000'000 фильтр пропускает нечетные элементы
                                            | std::views::filter(isPrime)   // фильтр пропускает простые числа
                                            | std::views::take(10)) {       //поток данных, останавливаtncz после десяти чисел
        std::cout << i << " ";  
    }

    std::cout << '\n';
// out 1000033 1000037 1000039 1000081 1000099 1000117 1000121 1000133 1000151
}