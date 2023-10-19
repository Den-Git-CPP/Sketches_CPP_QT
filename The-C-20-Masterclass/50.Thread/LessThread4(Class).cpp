#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


class MyClass
{
public:
    void Work(){
    cout<<"==========\tHardWork START\tID-\t"<<this_thread::get_id()<<" ==========";
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    cout<<"==========\tHardWork STOP\tID-\t"<<this_thread::get_id()<<" =========="; 
    }
};

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");

return 0;
};