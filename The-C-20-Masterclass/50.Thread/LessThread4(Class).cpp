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

MyClass m;
/*==========MyClass::Work()=========
*/
thread th_work_a(
    [&](){
        m.Work();
    }
);
/*or*/
thread th_work_b(&MyClass::Work,m);
/*========== MyClass::Work2()=========
*/
thread th_work2_a(
    [&](){
        m.Work2(4);
    }
);
/*or*/
thread th_work2_b(&MyClass::Work2,m,5);

/*========== MyClass::Work3()=========
*/
int result_work3{0};
thread th_work3(
    [&](){
        result_work3=m.Work3(5,5);
    }
);


 for (size_t i = 0; i < 5; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tmain\n";
  this_thread::sleep_for(chrono::milliseconds(500));// do 0,5 sec
  }

th_work_a.join();
th_work_b.join();

th_work2_a.join();
th_work2_b.join();

th_work3.join();
 cout<<"result_work3-\t"<<result_work3<<"\n";
 
return 0;
};