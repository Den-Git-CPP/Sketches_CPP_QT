#include <iostream>
#include <thread>
#include <chrono>

 
using namespace std;
 
int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 for (size_t i = 0; i < 10; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tmain\n";
  this_thread::sleep_for(chrono::milliseconds(3000));
  }
  
return 0;
};