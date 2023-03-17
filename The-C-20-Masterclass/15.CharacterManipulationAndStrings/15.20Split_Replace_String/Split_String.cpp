#include <iostream>
#include <string>
using namespace std;

//Извлечение слов и вывод их в обратном порядке

int main (int argc, char** argv)
{
   const string delims(" \t,.;");
   string line;

   // for every line read successfully
   while (getline(cin,line)) {
       string::size_type begIdx, endIdx;

       // search beginning of the first word
       begIdx = line.find_first_not_of(delims);

       // while beginning of a word found
       while (begIdx != string::npos) {
           // search end of the actual word
           endIdx = line.find_first_of (delims, begIdx);
           if (endIdx == string::npos) {
               // end of word is end of line
               endIdx = line.length();
           }

           // print characters in reverse order
           for (int i=endIdx-1; i>=static_cast<int>(begIdx); --i) {
               cout << line[i];
           }
           cout << ' ';

           // search beginning of the next word
           begIdx = line.find_first_not_of (delims, endIdx);
       }
       cout << endl;
   }
}



//================================
void strLineSplit(const string& str, const string& delim)
{
	size_t prev = 0, pos = 0;
	int strLength = 0;
	strLength = str.length();
	while (pos < strLength && pos != string::npos)
	{
		pos = str.find(delim, prev);
		string token = str.substr(prev, pos - prev);
		prev = pos + 1;
		cout << token << "\n";
	}
}

string str = "11.1 22.24 3.736";
strLineSplit(str, " ");


//==============================

std::string::size_type n1 = 0;
std::string::size_type n2 = 0;
string str = "11.1 22.24 3.736";
while (n2 != std::string::npos)
{
	n2 = str.find(' ');
	cout << str.substr(n1, n2) << endl;
	str = str.substr(n2 + 1);

}

//=============================
