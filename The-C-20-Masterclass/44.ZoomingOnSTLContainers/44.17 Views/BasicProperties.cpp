#include <format>
#include <iostream>
#include <ranges>
#include <vector>
#include <span>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::array sarr {1, 2, 3, 4, 5};
    std::span<int, 5> arr_span {arr};
    std::span<int> sarr_span {arr};
    std::span<int> vec_span{vec};

    auto span_info = [](std::string_view str, auto sp) {
        std::cout << std::format("{}\n sizeof {}\n extent {}\n size in bytes: {}\n", 
                             str, sizeof(sp), sp.extent == std::dynamic_extent ? "dynamic" : "static", 
                             sp.size_bytes());
    };
    span_info("arr_span", arr_span);
    span_info("sarr_span", sarr_span);
    span_info("vec_span", vec_span);
}
/*
arr_span
 sizeof 8
 extent static
 size in bytes: 20
sarr_span
 sizeof 16
 extent dynamic
 size in bytes: 20
vec_span
 sizeof 16
 extent dynamic
 size in bytes: 20
*/
