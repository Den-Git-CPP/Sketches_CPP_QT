// https://www.cppstories.com/2020/05/lambdasadvantages.html/

//Example1
#include <algorithm>
#include <functional>
#include <vector>

int main() {
    using std::placeholders::_1;

    const std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const auto val = std::count_if(v.begin(), v.end(),
                               std::bind(std::logical_and<bool>(),
                               std::bind(std::greater<int>(),_1, 2),
                               std::bind(std::less_equal<int>(),_1,6)));
        
    return val;                                        
}

/*У нас не только более короткий синтаксис для объекта anonymous function, но мы могли бы даже сократить один оператор include <functional>).
 into lambda expression:*/

#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const auto val = std::count_if(v.begin(), v.end(), 
                        [](int v) { return v > 2 && v <= 6;});
        
    return val;                                        
}

/*Лямбда-выражения в алгоритмах   */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	
	for_each(v.begin(), v.end(), 
		[](int &elem) {cout << elem << " "; }
        );

	int tok = 5;

	if (any_of(v.begin(), v.end(),
		    [&tok](const int& elem) {return elem == tok; }
	          )
		)
    cout << "Have 5 \n";
	system("pause");
}

/*Лямбда-выражения позволяют легко сохранять состояние   */
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec { 0, 5, 2, 9, 7, 6, 1, 3, 4, 8 };

    size_t compCounter = 0;
    std::sort(vec.begin(), vec.end(), 
                [&compCounter](int a, int b) {
                ++compCounter;
                return a < b;
                }
    );

    std::cout << "number of comparisons: " << compCounter << '\n';

    for (auto& v : vec)
        std::cout << v << ", ";
}

/* Лямбда-выражения допускают несколько перегрузок в одном и том же месте*/

#include <iostream>
#include <string>
#include <variant>

struct PrintVisitor
{
    void operator()(int& i) const {
        std::cout << "int: " << i; }

    void operator()(float& f) const {
        std::cout << "float: " << f;
    }

    void operator()(const std::string& s) const {
        std::cout << "string: " << s;
    }
};


template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

int main() {
    std::variant<int, float, std::string> intFloatString { "Hello" };
    std::visit(overload  {
        [](const int& i) { std::cout << "int: " << i; },
        [](const float& f) { std::cout << "float: " << f; },
        [](const std::string& s) { std::cout << "string: " << s; }
      },
      intFloatString
    );        
}

/*также возможно написать компактную универсальную лямбду, которая работает для всех типов, содержащихся в варианте. Это может поддерживать полиморфизм во время выполнения на основе std::variant/std::visit подхода.*/
#include <variant>

struct Circle { void Draw() const { } };
struct Square { void Draw() const { } };
struct Triangle { void Draw() const { } };

int main() {
    std::variant<Circle, Square, Triangle> shape;
    shape = Triangle{};
    auto callDraw = [](auto& sh) { sh.Draw(); };
    std::visit(callDraw, shape);
}