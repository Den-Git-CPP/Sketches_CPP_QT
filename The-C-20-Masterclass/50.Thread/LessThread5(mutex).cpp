#include <iostream>
#include <thread>
#include <mutex>
 
using namespace std;
 mutex mtx1;
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

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 thread th1(Print,'*');
 thread th2(Print,'#');
 
 //Print('*');
 // Print('#');
  th1.join();
  th2.join();
  
system("pause"); 
return 0;
};