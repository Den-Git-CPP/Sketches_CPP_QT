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

  return 0;
}
