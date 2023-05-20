// Example program
#include <iostream>
#include <string>
#include <type_traits>
#include <memory>

class A {
    public:
     A(){} ;
    virtual ~A(){};
    std::string strA{};
  void print(){std::cout<<strA<<'\n';}
 };

class B {
    public:
     B(){} ;
   virtual  ~B(){} ;
   std::string strB{};
  void print(){std::cout<<strB<<'\n';}
 };

template<class T>
std::shared_ptr<T>GetPtr(){
     if constexpr (std::is_same<T, A>::value){
        auto z=std::make_shared<A>();
        z->strA="Class A";
           return z;
     }else 
     if constexpr (std::is_same<T, B>::value){
        auto z=std::make_shared<B>();
        z->strB="Class B";
           return z;
     }else 
     static_assert(std::is_same<T, A>::value||std::is_same<T, B>::value,"Argument must be Class A or Class B else retrun NULLPTR");
     return nullptr;
     
    }

template<class T, int i=0>
std::shared_ptr<T>GetIntPtr(){
     if constexpr (std::is_same<T, A>::value) {
       auto z=std::make_shared<A>();
        z->strA="Class A";
        if ((i>1)&&(i<10)) z->strA="Class A: A<10";
        if (i>10) z->strA="Class A: A>10";
        return z;
     }else 
     if constexpr (std::is_same<T, B>::value){
        auto z=std::make_shared<B>();
        z->strB="Class B";
           return z;
     }else {
    static_assert(std::is_same<T, A>::value||std::is_same<T, B>::value,"Argument must be Class A or Class B else retrun NULLPTR");
     return nullptr;
     }
    }

int main()
{ 
  auto a_class= GetPtr<A>();
  auto bb_class= GetPtr<B>();
   
  std::cout<<"=======GetPtr======\n";
  a_class->print();
  std::cout<<"=================\n";
  bb_class->print();
    
  std::cout<<"=======GetIntPtr======\n";
  auto a_a_class1= GetIntPtr<A>();
  a_a_class1->print();
  std::cout<<"=================\n";

  auto a_a_class2= GetIntPtr<A,5>();
  a_a_class2->print();
  std::cout<<"=================\n";
  
  auto a_a_class3= GetIntPtr<A,15>();
  a_a_class3->print();
  std::cout<<"=================\n";
   
  auto a_b_class= GetIntPtr<B>();
  a_b_class->print();
  std::cout<<"=================\n";

 return 0;
}
