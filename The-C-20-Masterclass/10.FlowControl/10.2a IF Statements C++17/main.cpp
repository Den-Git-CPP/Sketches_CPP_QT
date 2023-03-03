#include <iostream>
//https://mariusbancila.ro/blog/2021/03/23/initializing-statement-for-if-switch-foreach/

//Before C++17.
//-----------------------
auto val = get_value();
if(val > 0){    
   std::cout << "processing " << val << '\n';
}
else {
   std::cout << "value " << val << " is illegal\n";
}

std::set<int> n{ 1,2,3,5,8 };
auto pos = n.find(3);
if (pos != std::end(n)){
   /* do something */
}

//With init statements in C++17:
//-----------------------
if (auto val = get_value(); val > 0){    
   std::cout << "processing " << val << '\n';
}
else {
   std::cout << "value " << val << " is illegal\n";
}
std::set<int> n{ 1,2,3,5,8 };
if (auto pos = n.find(3); pos != std::end(n)){    
   /* do something */ 
}

/*if(init; condition) statement; 

is equivalent to the following:
{  init;
   if(condition)
      statement;
}
*/
if (auto a = get_value(); a > 0){
std::cout << "processing A " << a << '\n';
}else if(auto b = get_another_value(); b > 0){
std::cout << "processing B " << b << '\n';
}

std::set<int> input= {1,2,3,4};
// первая часть- инициализация, вторая -условие
    if( auto in=input.find(5); it==input.end()){
      std::cout<<5<<"не найдено!\n";
    }else
    {
      std::cout<<5<<"тут!\n";
    }
    
   