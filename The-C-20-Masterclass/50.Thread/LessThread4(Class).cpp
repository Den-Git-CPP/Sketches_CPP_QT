#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


class MyClass
{
public:
    void Work(){
    cout<<"==========\tMyClass::Work START\tID-\t"<<this_thread::get_id()<<" ==========\n";
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    cout<<"==========\tMyClass::Work STOP\tID-\t"<<this_thread::get_id()<<" ==========\n"; 
    }
    void Work2(int a){
    cout<<"==========\tMyClass::Work2 START\tID-\t"<<this_thread::get_id()<<" ==========\n";
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    cout<<"==========\tID-\t"<<this_thread::get_id()<<"Param a= "<<a<<" ==========\n";
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    cout<<"==========\tMyClass::Work2 STOP\tID-\t"<<this_thread::get_id()<<" ==========\n"; 
    }
    int Work3(int a,int b){
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    cout<<"==========\tMyClass::Work2 START\tID-\t"<<this_thread::get_id()<<" ==========\n";
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    cout<<"==========\tMyClass::Work2 STOP\tID-\t"<<this_thread::get_id()<<" ==========\n"; 
    return a+b;
    }
};

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");

 

return 0;
};