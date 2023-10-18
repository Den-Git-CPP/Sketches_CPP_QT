#include <iostream>
#include <thread>
#include <chrono>

 
using namespace std;
 
int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 cout<<"Start main\n";
 cout<<this_thread::get_id()<<"\tmain\n";
 cout<<"End main\n";
   
return 0;
};