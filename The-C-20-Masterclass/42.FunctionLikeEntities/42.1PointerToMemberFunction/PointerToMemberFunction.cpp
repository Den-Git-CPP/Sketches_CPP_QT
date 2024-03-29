#include <functional>
#include <iostream>
#include <type_traits>

int example(const int a, const int b) { return a * b; }

struct Foo {
  Foo(int num) : num_(num) {}
  void print_add(int i) const { std::cout << num_ + i << '\n'; }
  int num_;
};

void print_num(int i) { std::cout << i << '\n'; }

struct PrintNum {
  void operator()(int i) const { std::cout << i << '\n'; }
};

template <typename F, typename V1, typename V2>
auto foo_invoke(F f, V1 v1, V2 v2) {
  std::invoke(f, v1, v2);
}
class Bar {
public:
  explicit Bar(int v) : m_v{v} {}
  auto bar(int v2) { std::cout << m_v << " " << v2 << std::endl; }

private:
  int m_v;
};

class Console {
public:
  Console(){};
  ~Console(){};

  void set_a(const std::string &a) { a_ = a; }
  void set_b(const std::string &a) { b_ = a; }

private:
  std::string a_{};
  std::string b_{};
};
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

  //  typedef // создаем новый прототип (в данном случае указатель на функцию)
  //          int // возвращаемое значение (такое же как в функциях)
  //              (*func) // имя прототипа (в коде употребляется без звездочки)
  //                     (const int, const int); // список параметров (такое же
  //                     как в функциях)
  typedef int (*func)(const int, const int);
  func test = example;
  std::cout << test(3, 2) << "\n";

  /*НО лучше делать черех std::invoke
   */

  // вызываем бесплатную функцию
  std::invoke(print_num, -9);
  // вызываем лямбду
  std::invoke([]() { print_num(42); });

  // вызываем функцию-член по ссылке
  const Foo foo(314159);
  std::invoke(&Foo::print_add, foo, 1);
  // вызываем функцию-член по указателю
  std::invoke(&Foo::print_add, &foo, 1);

  Bar b{12};
  int v1{12}, v2{23};
  // вызов нестатического метода класса по ссылке
  foo_invoke(&Bar::bar, b, v2);
  // вызов нестатического метода класса по указателю
  foo_invoke(&Bar::bar, &b, v2);

  // вызов (доступ) к элементу данных
  std::cout << "num_: " << std::invoke(&Foo::num_, foo) << '\n';

  // вызываем объект функции
  std::invoke(PrintNum(), 18);
#if defined(__cpp_lib_invoke_r)
  auto add = [](int x, int y) { return x + y; };
  auto ret = std::invoke_r<float>(add, 11, 22);
  static_assert(std::is_same<decltype(ret), float>());
  std::cout << ret << '\n';
  std::invoke_r<void>(print_num, 44);
#endif

// Доступ через лямбду 
Console *c = new Console;
//захватли обект
  auto log = [c](const std::string &fun/* название функции*/  , const std::string &mes/*данные*/) {
    if (fun == "set_a") {std::invoke(&Console::set_a, c, mes); } 
    if (fun == "set_b") {std::invoke(&Console::set_b, c, mes);}
  };
//вектор команд
  std::vector<std::string> v{"set_b", "set_a"};
  for (const auto &elem : v) {
    log(elem, "zzzz");
  }
delete c;

// Доступ через лямбду класс Baz
   auto f1 = Baz{"ala"}.foo();
   auto f2 = Baz{"ula"}.foo(); 
   f1();
   f2();
  return 0;
}
