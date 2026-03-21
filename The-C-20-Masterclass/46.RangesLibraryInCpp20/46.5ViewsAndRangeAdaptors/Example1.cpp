#include <vector>
#include <iostream>
#include <ranges>
#include <map>

/*
Представление (View) — это легковесный диапазон, который не владеет данными. 
Его семантика копирования и перемещения должна быть очень быстрой (константное время). 
Представления создаются путем применения преобразований к другим диапазонам, но сами эти преобразования вычисляются “лениво”-
обрабатываются только когда мы начинаем их итерировать. Такой подход позволяет избежать выделения дополнительной памяти и лишних вычислений.

Адаптер диапазона (Range Adaptor) представляет собой объект, который принимает на вход один или несколько диапазонов (или другие параметры) 
и возвращает новое представление. Адаптеры можно объединять в конвейеры (pipelines) с помощью оператора | (pipe), что делает код невероятно читаемым.
*/

int main()
{
std::vector <float> temperatures{28, 25, -8, -3, 15, 21, -1};

auto minus = [](int i){ return i <= 0; };
auto toFahrenheit = [](int i) { return (i*(9/5)) + 32; };

for (int t : temperatures   |std::views::filter(minus)
                            |std::views::transform(toFahrenheit)
    )
                            
std::cout << t << ' ';  // 82.4 77 59 69.8

// https://habr.com/ru/companies/otus/articles/1001540/

/*
Контейнеры C++ 
-Последовательные контейнеры (Sequence Containers) хранят элементы в линейной последовательности, при этом порядок элементов определяется позицией добавления. 
-Ассоциативные контейнеры (Associative Containers) автоматически сортируют элементы по ключу. При этом, они обеспечивают достаточно быстрый поиск (O(log n)). 
-Неупорядоченные ассоциативные контейнеры (Unordered Associative Containers) хранят элементы в хеш-таблицах. Обеспечивают поиск в среднем за O(1). 
-Адаптеры контейнеров (Container Adapters) предоставляют ограниченный интерфейс поверх других контейнеров.
*/

/*Допустим, у нас есть вектор чисел, и нам нужно получить квадраты только четных чисел. Классический подход требует промежуточного вектора:*/
//std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//std::vector<int> intermediate, output;

//std::copy_if(input.begin(), input.end(), std::back_inserter(intermediate),
//             [](int i) { return i % 2 == 0; });
//std::transform(intermediate.begin(), intermediate.end(), std::back_inserter(output),
//               [](int i) { return i * i; });

 std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result_view = input
                     | std::views::filter([](int n) { return n % 2 == 0; }) //фильтрация на предмет четности
                     | std::views::transform([](int n) { return n * n; });  //выполняет необходимые вычисления.

    for (int val : result_view) {
        std::cout << val << ' '; // Вывод: 0 4 16 36 64 100
    }
    std::cout << '\n';

/*Следующая задача: Взять числа от 1 до бесконечности, выбрать нечетные, возвести их в квадрат, взять первые 5 и вывести в обратном порядке.*/
 auto result_5 = std::views::iota(1)                                    // Бесконечная последовательность 1, 2, 3, ...
                | std::views::filter([](int n) { return n % 2 == 1; })  // Оставляем нечетные
                | std::views::transform([](int n) { return n * n; })    // Возводим в квадрат
                | std::views::take(5)                                   // Берем первые 5: 1, 9, 25, 49, 81
                | std::views::reverse;                                  // Разворачиваем: 81, 49, 25, 9, 1

    for (int val : result_5) {
        std::cout << val << ' '; // Вывод: 81 49 25 9 1
    }
   
/*Работа с парами "ключ-значение"
*/
    std::cout << '\n';

std::map<std::string, int> ages = {
    {"Alice", 30}, 
    {"Bob", 25}, 
    {"Charlie", 35}
};

    // Получить все ключи (имена)
    auto names = ages | std::views::keys;
    for (const auto& name : names) {
        std::cout << name << ' '; // Вывод: Alice Bob Charlie (порядок может отличаться)
    }

    std::cout << '\n';

    // Получить все значения (возраст) и отфильтровать их
    auto adult_ages = ages | std::views::values 
                           | std::views::filter([](int age) { return age >= 30; });

    for (int age : adult_ages) {
        std::cout << age << ' '; // Вывод: 30 35
    }
    std::cout << '\n';

/*Конструирование контейнеров из диапазонов  C++ версии 23 
*/

 std::vector<int> input_23 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result_view_23 = input_23
                     | std::views::filter([](int n) { return n % 2 == 0; })
                     | std::views::transform([](int n) { return n * n; });

    // C++23: Прямое конструирование вектора из диапазона

    std::vector<int> output_23(std::from_range, result_view_23);
    for (int val : output_23) {
        std::cout << val << ' '; // Вывод: 0 4 16 36 64 100
    }

    std::cout << '\n';



return 0;
}