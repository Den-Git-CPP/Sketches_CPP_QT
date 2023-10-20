#include <iostream>
#include <thread>
#include <mutex>
 
using namespace std;
 mutex mtx1;
  mutex mtx2;

void Print(char ch){
    
    mtx1.lock(); /// start mutex
    for (int i{0};i<5;++i){
        for (int j {0} ; j < 10; j++){
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout<<"\n";
    }
    cout<<"\n";
    
    mtx1.unlock();/// stop mutex
}

void Print_Lock_Guard(char ch){
    this_thread::sleep_for(chrono::milliseconds(2000)); // hardwork 2s
  {
    lock_guard<mutex> guard(mtx2);/// start mutex2
    for (int i{0};i<5;++i){
        for (int j {0} ; j < 10; j++){
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout<<"\n";
    }
    cout<<"\n";
   }    /// stop mutex2
    
    
    this_thread::sleep_for(chrono::milliseconds(2000)); // hardwork 2s

}


int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 thread th1(Print,'*');
 thread th2(Print,'#');
 thread th3(Print_Lock_Guard,'*');
 thread th4(Print_Lock_Guard,'#');
 
 // Print('*');
 // Print('#');
  th1.join();
  th2.join();
  th3.join();
  th4.join();

system("pause"); 
return 0;
};