//https://mariusbancila.ro/blog/2021/03/23/initializing-statement-for-if-switch-foreach/


std::vector<int> get_values() { return { 1,2,3,5,8 }; }

/*The following is a range-based for loop prior to C++20:*/
auto const& values = get_values();
for (auto const& v : values){
std::cout << v << '\n';
}

//In C++20, we can rewrite this to the following form:
for (auto const& values = get_values(); auto const& v : values){
std::cout << v << '\n';
}
   
//This form with init statement can be handy when you iterate over a range but you also need the index of the elements of the range.
for (size_t index = 1; auto const& v : get_values())
{
std::cout << "value " << index++ << ": " << v << '\n';
}
   
