#include <iostream>
#include <thread>
#include <vector>
 
using namespace std;
 void func(int tid) {
	std::cout << "Launched by thread " << tid << std::endl;
}

int main(int argc, const char** argv)
{
 
 std::vector<std::thread> th;
	int nr_threads = 10;

	//группа потоков
	for (int i = 0; i < nr_threads; ++i) {
		th.push_back(thread(func, i));
	}
	
	//Join все потоки
	for (auto& t : th) {
		t.join();
	}
 
 
 
system("pause"); 
return 0;
};