#include <QCoreApplication>
//#include <memory.h>
#include <type_traits>
#include<iostream>


class Base1 {
public:
    Base1(){};
   virtual ~Base1(){};
   virtual void Print() const=0;

};

class ClassA1 : public Base1 {
public:
    ClassA1(){};
   ~ClassA1(){};

    void Print() const override{
        qDebug()<< "A1";
    };
 };

class ClassB1 : public Base1 {
public:
    ClassB1(){};
   ~ClassB1(){};

    void Print() const override{
        qDebug()<< "B1";
    };

};

class BaseFactory{
public:
    static std::shared_ptr<Base1> getBase1( const std::string& name)
    {
        if ( name == "A1" ) return std::make_shared<ClassA1>();
        if ( name == "B1" ) return std::make_shared<ClassB1>();
        return nullptr;
    }
};

template <typename T> std::shared_ptr<T> SHRPTR() {

    if constexpr (std::is_same<T, ClassA1>::value) {
        return std::make_shared<ClassA1>();
    }else
    if constexpr (std::is_same<T, ClassB1>::value) {
        return std::make_shared<ClassB1>();
    }else
    return nullptr;
};

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  std::shared_ptr<Base1> b1= BaseFactory::getBase1("A1");
  b1->Print();

  auto A1=SHRPTR<ClassA1>();
  A1->Print();

  return a.exec();
}
