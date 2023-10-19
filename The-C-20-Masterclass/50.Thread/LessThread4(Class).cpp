#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


class MyClass
{
public:
    void Work(){
    this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
    cout<<"==========\tHardWork START\t==========";
    this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
    
    this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
    cout<<"==========\tHardWork STOP\t==========";
    }

};

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");

return 0;
};