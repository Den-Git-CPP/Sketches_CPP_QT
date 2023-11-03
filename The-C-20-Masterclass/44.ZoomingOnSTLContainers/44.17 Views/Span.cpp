//Defined in header <span>

/*
template<
    class T,
    std::size_t Extent = std::dynamic_extent
> class span;
*/

//Для создания этого объекта  есть два основных варианта: 
//Когда вы знаете размер во время компиляции-> статический экстент :
int arr1[] = {1, 2, 3, 4, 5};
std::span<int, 5> arr_span1 {arr1};

//std::span<int, 2> arr_span2 {arr}; // error size doesn't match

// Когда вы знаете размер только во время выполнения-> динамический
int arr2[] = {1, 2, 3, 4, 5};
std::vector v2 { 1, 2, 3, 4, 5};
std::span<int> arr_span2 {arr2}; // dynamic extent
std::span<int> vec_span2 {v2};   // also!


/*Размер span
что когда размер статичен, то тип меньше, поскольку нет необходимости сохранять 
размер последовательности*/
int arr3[] = {1, 2, 3, 4, 5};
std::vector<int> vec = {1, 2, 3, 4, 5};
std::span<int, 5> arr_span3 {arr3};
std::span<int> other_span3 {arr3};
std::span<int> vec_span3{vec3};

std::cout << std::format("sizeof arr_span: {}\n", sizeof(arr_span3));
std::cout << std::format("sizeof other_span: {}\n", sizeof(other_span3));
std::cout << std::format("sizeof vec_span: {}\n", sizeof(vec_span3));

/*
1.Конструктор по умолчанию
*/
std::span<int> empty_span; 
//.data() дает nullptr
//.size() дает 0

/*
2. span на основе начального итератора и размера.
*/
std::vector<int> vec = {1, 2, 3};
std::span<int> from_iterator_and_size(vec.begin(), /*count*/2); // 1, 2
std::span<int> from_iterator_and_size2(vec.begin(), /*count*/3); // 1, 2, 3

/*3.span из двух итераторов , указанного двумя итераторами.
*/
std::span<int> from_two_iterators(vec.begin(), vec.end());

/*
4.Из массива в стиле C
*/
int arr[] = {1, 2, 3};
std::span<int> from_array(arr);
std::span from_array2(arr);

/*
5.Из массива std::array 
*/
std::array<int, 3> std_arr = {1, 2, 3};
std::span<int, 3> from_std_array(std_arr);
// CTAD:
std::span from_std_array2(std_arr);

const std::array<int, 3> const_std_arr = {1, 2, 3};
std::span<const int> from_const_std_array(const_std_arr);

/*
6.Из массива std::vector
*/
std::vector vec {1, 2, 3, 4, 5};
std::span<int> from_range(vec); // covers entire vec

/*
7.из другого Span
*/
std::span<int> int_span(vec);
std::span<const int> const_span = int_span; // conversion



