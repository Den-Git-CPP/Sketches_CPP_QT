#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void HardWork(){
for (size_t i = 0; i < 10; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tHardWork\n";
  this_thread::sleep_for(chrono::milliseconds(3000)); // do 3s
  }
}

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 
 thread t1(HardWork);//start thread t1
 
 for (size_t i = 0; i < 10; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tmain\n";
  this_thread::sleep_for(chrono::milliseconds(500));// do 0,5 sec
  }
 
 t1.join();// join end thread t1 
 // t1.detach();

return 0;
};