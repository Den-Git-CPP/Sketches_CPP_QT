std::ranges::iota(range, x) — для переопределения элементов диапазона значениями x++ (P2440).
std::ranges::shift_left(range, n) и 
std::ranges::shift_right(range, n) — для переопределения элементов диапазона значениями из того же диапазона со сдвигом n, по аналогии с std::shift_left/std::shift_right (P2440).
std::views::chunk(range, n) — для группировки элементов в диапазоны из n элементов (P2442).
std::views::slide(range, n) — группировка по n смежных элементов с шагом 1, аналог std::views::adjacent<n> с рантайм-параметром n (P2442).
std::views::chunk_by(range, pred) — разделение на поддиапазоны по предикату pred (P2443).

//Примеры использования новых алгоритмов:
std::vector<char> v;
v.resize(4, 'b');                   // v == {'b', 'b', 'b', 'b'}
std::ranges::iota(v, 'm');          // v == {'m', 'n', 'o', 'p'}
std::ranges::shift_left(v, 1);      // v == {'n', 'o', 'p', 'p'}
v | std::views::chunk(2);           // {['n', 'o'], ['p', 'p']}
v | std::views::slide(2);           // {['n', 'o'], ['o', 'p'], ['p', 'p']}
v | std::views::chunk_by([](auto x, auto y) {
    return x != y;
});                                 // {['n', 'o', 'p'], ['p']}


//std::ranges::to
auto c = std::views::iota('a', 'z') | std::views::common;
std::vector v(c.begin(), c.end());

Теперь эта задача решается в два раза проще:
auto v = std::views::iota('a', 'z') | std::ranges::to<std::vector>();


//В большинство контейнеров стандартной библиотеки добавляются новые методы для работы с диапазонами:
c.insert_range(it, r)   — для вставки диапазона значений r в контейнер c по итератору it.
c.assign_range(r)       — для перезаписи значений контейнера c диапазоном значений r.
c.append_range(r)       — для добавления диапазона значений r в конец контейнера c.
c.prepend_range(r)      — для добавления диапазона значений r в начало контейнера c.

со строками
std::string s{"world"};
std::string_view hello{"Hello "};
std::cout << s.prepend_range(hello).append_range("!!!"); // Hello world!!!


//std::ranges::to не перемещает элементы, даже если контейнер является временной (rvalue) переменной. 
//Поэтому для написания эффективного кода нужно использовать std::views::move (не путайте с std::move)

namespace views = std::views;
using std::ranges::to;

std::vector<std::u8string> strs{u8"Привет", u8"дорогой читатель"};
auto s0 = strs | to<std::deque>(); // Копирование элементов strs
auto s1 = strs | views::move | to<std::deque>(); // Перемещение элементов strs

so.append_range(s1); // Копирование элементов s1
so.append_range(std::move(s1)); // Всё ещё копирование элементов s1
so.append_range(s1 | views::move); // Перемещение элементов s1