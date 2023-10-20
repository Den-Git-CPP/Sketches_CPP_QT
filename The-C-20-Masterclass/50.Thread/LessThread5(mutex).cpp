#include <iostream>
#include <thread>
#include <mutex>
 
using namespace std;
 
void Print(char ch){
    for (int i{0};i<5;++i){
        for (int j {0} ; j < 10; j++){
            cout<<ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main(int argc, const char** argv)
{
 setlocale(LC_ALL,"ru");
 Print('*');
 Print('#');
 
system("pause"); 
return 0;
};