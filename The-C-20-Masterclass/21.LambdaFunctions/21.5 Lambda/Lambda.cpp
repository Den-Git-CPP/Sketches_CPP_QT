/*Лямбда
В С++11 были добавлены так называемые лямбда-функции. Это обёртки над функциональными объектами классов или лямбда-выражения в C++ — это краткая форма записи анонимных функторов.
Вычисление лямбда-выражения приводит к временному prvalue. Этот временный объект называется объектом-замыканием 
Тип лямбда-выражения (который также является типом объекта-замыкания) является уникальным безымянным non-union типом класса,который называется типом замыкания (closure type).

Возможные варианты синтаксиса лямбда функций:
1.    [ capture ] ( params ) mutable exception attribute -> ret { body }
2.    [ capture ] ( params ) -> ret { body }
3.    [ capture ] ( params ) { body }
4.    [ capture ] { body }

capture - список  внешних захватываемых объектов, могут захватываться как по ссылке, так и копированием.
params - список параметров, передаваемых в лямбда функции, данная часть будет аналогична записи аргументов для обычных функций.
mutable - использование mutable позволяет модифицировать копии объектов, которые были захвачены копированием. 
exception - обеспечивает спецификацию исключения, то есть лямбда функции также как и обычные функции могут выкидывать исключения.
attribute - обеспечивает спецификацию атрибута, таких атрибутов в спецификации C++ определено всего два ([[noreturn]], [[carries_dependency]])
	params - список параметров, передаваемых в лямбда функцию
	ret - возвращаемое значение лямбда функции 

понятие захвата переменных-это означает, что лямбда функция может использовать не только переменные, которые передаются ей в качестве параметров, но и какие-либо объекты, которые были объявлены вне лямда-функции. 
[]  // без захвата переменных из внешней области видимости
[=] // все переменные захватываются по значению
[&] // все переменные захватываются по ссылке
[x, y]  // захват x и y по значению
[&x, &y]    // захват x и y по ссылке
[in, &out]  // захват in по значению, а out — по ссылке
[=, &out1, &out2]   // захват всех переменных по значению, кроме out1 и out2,	
                    // которые захватываются по ссылке
[&, x, &y]  // захват всех переменных по ссылке, кроме x…
*/
{
#include <iostream>

using std::cout;
 int main() {
   int x = 10;
   [x]{ cout << x; }(); 	//Захват Х по значению, выводим значение на экран
   [&x](){ x++; }();        	//Захват Х по ссылке ,изменен x внутри, не забываем запустить лямбда-функцию через ()
   cout << x << '\n'; 
    int xx = 10;  double уy = 5.5;     
    [&](){ xx++, yy = yy + 10; }();        //захват всех значений по ссылке из текущей области видимости
    cout << "xx == " << xx << '\n';        //11
    cout << "yy == " << yy << '\n';  }      //15
}



/*Mutable
По умолчанию operator() типа замыкания является константным, и вы не можете изменять захваченные переменные внутри тела лямбда-выражения.
Если вы хотите изменить это поведение, вам нужно добавить ключевое слово mutable после списка параметров:*/
{
int x = 1, y = 1;
std::cout << x << " " << y << std::endl;
auto foo = [x, y]() mutable { ++x; ++y; };
foo();
std::cout << x << " " << y << std::endl;
}

/*Захват статических переменных*/
#include <iostream>

void bar()
{
    static int static_int = 10;
    std::cout << static_int << std::endl;
    auto foo = [=] () mutable { ++static_int; };
    foo();
    std::cout << static_int << std::endl;
    [] { ++static_int; } ();
    std::cout << static_int << std::endl;
    [static_int] { ++static_int; } ();
}

int main()
{
   bar(); // 10 11 12
}

/*Сохранение констант
Если вы захватываете константную переменную, то константность сохраняется*/
int const x = 10;
auto foo = [x] () mutable { 
    std::cout << std::is_const<decltype(x)>::value << std::endl;
    x = 11;
};
foo();


/*Преобразование в указатель на функцию
Тип замыкания для лямбда-выражения без захвата имеет открытую невиртуальную неявную функцию 
преобразования константы в указатель на функцию, имеющую тот же параметр и возвращаемые типы, 
что и оператор вызова функции типа замыкания. 
Значение, возвращаемое этой функцией преобразования, должно быть адресом функции, которая 
при вызове имеет тот же эффект,что и вызов оператора функции типа сходного с типом замыкания.
Другими словами, вы можете преобразовывать лямбды без захватов в указатель на функцию.*/
{
#include <iostream>
void callWith10(void(* bar)(int)) 
       { bar(10);}
 struct 
{ using f_ptr = void(*)(int);
  void operator()(int s) const { return call(s); }
  operator f_ptr() const { return &call; }
  private:
  static void call(int s) { std::cout << s << std::endl; };
} baz;

int main()
   callWith10(baz);
   callWith10([](int x) { std::cout << x << std::endl; });
}
/*Улучшения в C++14
-Захваты с инициализатором
Мы можем создать новую переменную-член типа замыкания и затем использовать ее внутри лямбда-выражения.*/
{
int main() {
    int x = 10;int y = 11;
    auto foo = [z = x+y]() { std::cout << z << '\n'; };
    foo();
    }
}

/*Перемещение мы можем переместить объект в член типа замыкания:*/
{
#include <memory>
int main()
{
    std::unique_ptr<int> p(new int[10]);
    auto foo = [x=10] () mutable { ++x; };
    auto bar = [ptr=std::move(p)] {};
    auto baz = [p=std::move(p)] {};
   }
}
/* Захват переменной-члена
Инициализатор также можно использовать для захвата переменной-члена. 
Затем мы можем получить копию переменной-члена и не беспокоиться о висячих ссылках.
С++17
*/ 
#include <iostream>

struct Baz {
    auto foo() {
        return [*this] { std::cout << s << std::endl; };
    }

    std::string s;
};

int main() {
   auto f1 = Baz{"ala"}.foo();
   auto f2 = Baz{"ula"}.foo(); 
   f1();
   f2();
}
// для класса
class Baz {
public:
  Baz(){};
  Baz(const std::string &s) : _s{s} {};
  ~Baz(){};
  auto foo() {
    return [*this] { std::cout << _s << std::endl; };
  }

private:
  std::string _s;
};

int main() {
   auto f1 = Baz{"ala"}.foo();
   auto f2 = Baz{"ula"}.foo(); 
   f1();
   f2();
}

/*Обобщенные лямбда-выражения
Начиная с C++14 можно написать:*/

auto foo = [](auto x) { std::cout << x << '\n'; };
foo(10);
foo(10.1234); 
foo("hello world");
//эквивалентно:
struct {
    template<typename T>
    void operator()(T x) const {std::cout << x << '\n';}
} someInstance;



#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main() {
    const std::map<std::string, int> numbers { 
        { "one", 1 }, {"two", 2 }, { "three", 3 }
    };
  
    std::for_each(std::begin(numbers), std::end(numbers), 
    [](const auto& entry) {
        std::cout << entry.first << " = " << entry.second << '\n';
    }
);}



/*Хранение лямбд в контейнере*/
#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::function<std::string(const std::string&)>> vecFilters;
    
    vecFilters.emplace_back(
        [](const std::string& x) {return x + " Amazing";}
        );
    vecFilters.emplace_back(
        [](const std::string& x) { return x + " Modern"; }
        );
    vecFilters.emplace_back(
        [](const std::string& x) { return x + " C++"; }
        );
    vecFilters.emplace_back(
        [](const std::string& x) { return x + " World!";}
        );
    
    const std::string str = "Hello";
    auto temp = str;
    
    for (auto &entryFunc : vecFilters)  
        temp = entryFunc(temp);
        std::cout << temp;
}

/*Возвращение лямбды  начиная с C++14*/

auto CreateLambda(int y) {
    return [&y](int x) { return x + y; };
}

int main() {
    auto lam = CreateLambda(10);
    return lam(32);
}

/*С++17*/
/*constexpr Lambda Expressions*/
template<typename Range, typename Func, typename T>
constexpr T SimpleAccumulate(const Range& range, Func func, T init) {
    for (auto &&elem: range) {
        init += func(elem);
    }
    return init;
}

int main() {
    constexpr std::array arr{ 1, 2, 3 };

    static_assert(SimpleAccumulate(arr, [](int i) { 
            return i * i; 
        }, 0) == 14);
}

