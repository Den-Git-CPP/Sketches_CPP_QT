#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void HardWork(int a,int b){
 this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
 cout<<"==========\tHardWork START\t==========";
 this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
 cout<<"HardWork Sum \t="<<a+b<<"\n";
 this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
 cout<<"==========\tHardWork STOP\t==========";
}

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");


 thread th1(HardWork,2,5);

 for (size_t i = 0; i < 10; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tmain\n";
  this_thread::sleep_for(chrono::milliseconds(500));// do 0,5 sec
  }
 th1.join();
return 0;
};