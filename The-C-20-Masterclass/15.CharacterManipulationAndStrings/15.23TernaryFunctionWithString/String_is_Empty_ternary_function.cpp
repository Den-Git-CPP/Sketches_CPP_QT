#include <iostream>
#include <string>

using namespace std;

string str(string i, string a, string b)
{
	return ((!i.empty()) ? i : "(=I is empty=),")
		+ ((!a.empty()) ? a : "(=A is empty=),")
		+ ((!b.empty()) ? b : "(=B is empty=),");
}

int main()

{	
	string g=str("1", "Hello", "World");

	cout << g << "\n";
	system("pause");
}

