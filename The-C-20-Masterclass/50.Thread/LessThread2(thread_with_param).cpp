#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void HardWork(int a,int b){
 this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
 cout<<"==========\tHardWork START\t==========";
 this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
 cout<<"HardWork Sum \t="<<a+b;
 this_thread::sleep_for(chrono::milliseconds(2000)); // do 1s
 cout<<"==========\tHardWork END\t==========";
}

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 
return 0;
};