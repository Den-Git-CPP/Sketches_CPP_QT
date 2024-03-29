#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void HardWork1(int &a){
this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
 cout<<"==========\tHardWork START\t==========";
 this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
 a=a*2;
 this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
 cout<<"==========\tHardWork STOP\t==========";
}

int HardWork_Sum(int a,int b){
this_thread::sleep_for(chrono::milliseconds(1000)); // do 1s
 cout<<"==========\tHardWork START\tID-\t"<<this_thread::get_id()<<" ==========";
 this_thread::sleep_for(chrono::milliseconds(2000)); // do 2s
 cout<<"==========\tHardWork STOP\tID-\t"<<this_thread::get_id()<<" ==========";
return a+b;
}

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
/*==========================
*/
int Z{5};
thread th_z(HardWork1,std::ref(Z));
for (size_t i = 0; i < 5; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tmain\n";
  this_thread::sleep_for(chrono::milliseconds(500));// do 0,5 sec
  }

th_z.join();
cout<<"==========\tZ="<<Z<<" \t==========";

/*==========================
*/ 
int result1=HardWork_Sum(3,3);
cout<<"Function int HardWork_Sum"<< result1<<"\n";
int result2{0};
thread th_result(
    [&result2](){result2= HardWork_Sum(4,4);}
);

for (size_t i = 0; i < 5; i++)
 {
  cout<<"ID thread - "<<this_thread::get_id()<<"\tmain\n";
  this_thread::sleep_for(chrono::milliseconds(500));// do 0,5 sec
  }
th_result.join();
cout<<"Function int HardWork_Sum over thread"<< result2<<"\n";

return 0;
};