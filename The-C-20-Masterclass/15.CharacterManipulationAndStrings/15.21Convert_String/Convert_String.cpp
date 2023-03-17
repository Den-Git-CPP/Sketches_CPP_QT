#define _CRT_SECURE_NO_WARNINGS // delete error C4996 VS2019

#include <iostream>
#include <string>


using namespace std;


int main()
{	//
	//Везде:Если idx не является нулевым указателем, функция также устанавливает значение idx на позицию первого символа в строке после числа.
	//

	///////////////////////////////////////////////////
	/////////////////////////////Convert from strings
	///////////////////////////////////////////////////
	//stoi()
	//Преобразовать строку в целое число
	//В случае успеха функция возвращает преобразованное целое число как значение типа int .
	//Анализирует str, интерпретируя его содержимое как целое число указанной base , которое возвращается как значение типа int .

	//int stoi(const string & str, size_t * idx = 0, int base = 10);
	//int stoi(const wstring & str, size_t * idx = 0, int base = 10);

	std::string str_dec = "2001, A Space Odyssey";
	std::string str_hex = "40c3";
	std::string str_bin = "-10010110001";
	std::string str_auto = "0x7f";

	std::string::size_type sz;   // alias of size_t

	int i_dec = std::stoi(str_dec, &sz);
	int i_hex = std::stoi(str_hex, nullptr, 16);
	int i_bin = std::stoi(str_bin, nullptr, 2);
	int i_auto = std::stoi(str_auto, nullptr, 0);

	std::cout << str_dec << ": " << i_dec <<" and [" << str_dec.substr(sz) << "]\n";
	std::cout << str_hex << ": " << i_hex << '\n';
	std::cout << str_bin << ": " << i_bin << '\n';
	std::cout << str_auto << ": " << i_auto << '\n';

	std::cout << endl;

	//stol()
	//Преобразовать строку в long int
	//Разбирает str, интерпретируя его содержимое как целое число указанной base , которое возвращается как значение типа long int .

	//В случае успеха функция возвращает преобразованное целое число как значение типа long int .
	//long stol(const string & str, size_t * idx = 0, int base = 10);
	//long stol(const wstring & str, size_t * idx = 0, int base = 10);

	std::string str_dec_li = "1987520";
	std::string str_hex_li = "2f04e009";
	std::string str_bin_li = "-11101001100100111010";
	std::string str_auto_li = "0x7fffff";

	std::string::size_type sz_li;   // alias of size_t

	long li_dec = std::stol(str_dec_li, &sz_li);
	long li_hex = std::stol(str_hex_li, nullptr, 16);
	long li_bin = std::stol(str_bin_li, nullptr, 2);
	long li_auto = std::stol(str_auto_li, nullptr, 0);

	std::cout << str_dec_li << ": " << li_dec << '\n';
	std::cout << str_hex_li << ": " << li_hex << '\n';
	std::cout << str_bin_li << ": " << li_bin << '\n';
	std::cout << str_auto_li << ": " << li_auto << '\n';
	std::cout << endl;


	//stoul()
	//Преобразовать строку в беззнаковое целое
	//Разбирает str, интерпретируя его содержимое как целое число указанной base , которое возвращается как длинное значение без знака .
	//В случае успеха функция возвращает преобразованное целое число в виде длинного значения без знака .
	
	//unsigned long stoul (const string&  str, size_t* idx = 0, int base = 10);
	//unsigned long stoul(const wstring & str, size_t * idx = 0, int base = 10);
	std::string str_ul;
	std::cout << "Enter an unsigned number: ";
	std::getline(std::cin, str_ul);
	unsigned long ul = std::stoul(str_ul, nullptr, 0);
	std::cout << "You entered: " << ul << '\n';
	std::cout << endl;

	//stoll()
	//Преобразовать строку в long long
	//Разбирает str, интерпретируя его содержимое как целое число указанной base , которое возвращается как значение типа long long .
	//В случае успеха функция возвращает преобразованное целое число как значение типа long long .
	
	//long long stoll (const string&  str, size_t* idx = 0, int base = 10);
	//long long stoll(const wstring & str, size_t * idx = 0, int base = 10);
	std::string str_ll = "8246821 0xffff 020";
	std::string::size_type sz_ll = 0;   // alias of size_t

	while (!str_ll.empty()) {
		long long ll = std::stoll(str_ll, &sz_ll, 0);
		std::cout << str_ll.substr(0, sz_ll) << " interpreted as " << ll << '\n';
		str_ll = str_ll.substr(sz_ll);
	}
	std::cout << endl;

	//stoull()
	//Преобразовать строку в unsigned long long
	//Разбирает str, интерпретируя ее содержимое как целое число указанной base , которое возвращается как значение типа unsigned long long .
	//В случае успеха функция возвращает преобразованное целое число как значение типа unsigned long long 
	//unsigned long long stoull(const string & str, size_t * idx = 0, int base = 10);
	//unsigned long long stoull(const wstring & str, size_t * idx = 0, int base = 10);

	std::string str_ull = "8246821 0xffff 020 -1";
	std::string::size_type sz_ull = 0;   // alias of size_t

	while (!str_ull.empty()) {
		unsigned long long ull = std::stoull(str_ull, &sz_ull, 0);
		std::cout << str_ull.substr(0, sz_ull) << " interpreted as " << ull << '\n';
		str_ull = str_ull.substr(sz_ull);
	}
	std::cout << endl;


	//stof()
	//Преобразовать строку в число с плавающей запятой'
	//Разбирает str, интерпретируя его содержимое как число с плавающей запятой, которое возвращается как значение типа float .
	//В случае успеха функция возвращает преобразованное число с плавающей запятой как значение типа float .
	//float stof (const string&  str, size_t* idx = 0);
	//float stof(const wstring & str, size_t * idx = 0);
	//
	std::string orbits("686.97 365.24");
	std::string::size_type sz_f=0;     // alias of size_t
	
	float mars = std::stof(orbits, &sz_f);
	float earth = std::stof(orbits.substr(sz_f));
	
	std::cout << "One martian year takes " << (mars / earth) << " Earth years.\n";
	
	std::cout << endl;
	
	//stod()
	//Разбирает str, интерпретируя его содержимое как число с плавающей запятой, которое возвращается как значение типа double .
	//В случае успеха функция возвращает преобразованное число с плавающей запятой как значение типа double .
	//double stod (const string&  str, size_t* idx = 0);
	//double stod(const wstring& str, size_t* idx = 0);
	
	std::string orbits_d("365.24 29.53");
	std::string::size_type sz_d;     // alias of size_t

	double earth_d = std::stod(orbits_d, &sz_d);
	double moon_d = std::stod(orbits_d.substr(sz_d));
	std::cout << "The moon completes " << (earth_d / moon_d) << " orbits per Earth year.\n";
	std::cout << endl;


	//stold()
	//Разбирает str, интерпретируя его содержимое как число с плавающей запятой, которое возвращается как значение типа long  double .
	//В случае успеха функция возвращает преобразованное число с плавающей запятой как значение типа long double .
	//long double stold(const string& str, size_t* idx = 0);
	//long double stold(const wstring& str, size_t* idx = 0);
	std::string orbits_ld("90613.305 365.24");
	std::string::size_type sz_ld;     // alias of size_t

	long double pluto_ld = std::stod(orbits_ld, &sz_ld);
	long double earth_ld = std::stod(orbits_ld.substr(sz_ld));
	std::cout << "Pluto takes " << (pluto_ld / earth_ld) << " years to complete an orbit.\n";
	std::cout << endl;

	///////////////////////////////////////////////////
	/////////////////////////////Convert to strings
	///////////////////////////////////////////////////

	//string to_string(int val);
	//string to_string(long val);
	//string to_string(long long val);
	//string to_string(unsigned val);
	//string to_string(unsigned long val);
	//string to_string(unsigned long long val);
	//string to_string(float val);
	//string to_string(double val);
	//string to_string(long double val);
	//Возвращает строку с представлением val.
	//В случае успеха функция возвращает представление val в виде последовательности символов.
	// формат printf()
	
	//type of val		printf equivalent		description
	
	//int					"%d"					Decimal - base representation of val.
	//										The representations of negative values are preceded with a minus sign(-).
	//long					"%ld"
	//long long				"%lld"
	//unsigned				"%u"					//Decimal - base representation of val.
	//unsigned long			"%lu"
	//unsigned long long	"%llu"
	//float					"%f"	
	//double				"%f"
	//long double			"%Lf"
	//Записывается столько цифр, сколько необходимо для представления целой части, за которыми следуют десятичный знак и шесть десятичных цифр.
	//inf(или бесконечность) используется для представления бесконечности.
	//nan(за которым следует необязательная последовательность символов) для представления NaN(Not - a - Number).
	//Представлениям отрицательных значений предшествует знак минус(-).
	
	
	std::string pi = "pi is " + std::to_string(3.1415926);
	std::string perfect = std::to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";
	std::cout << pi << '\n';
	std::cout << perfect << '\n';
	cout << endl;

	//to_wstring()
	//wstring to_wstring(int val);
	//wstring to_wstring(long val);
	//wstring to_wstring(long long val);
	//wstring to_wstring(unsigned val);
	//wstring to_wstring(unsigned long val);
	//wstring to_wstring(unsigned long long val);
	//wstring to_wstring(float val);
	//wstring to_wstring(double val);
	//wstring to_wstring(long double val);

	// формат printf()

	//type of val		printf equivalent		description

	//int					"%d"					Decimal - base representation of val.
	//										The representations of negative values are preceded with a minus sign(-).
	//long					L"%ld"
	//long long				L"%lld"
	//unsigned				L"%u"					//Decimal - base representation of val.
	//unsigned long			L"%lu"
	//unsigned long long	L"%llu"
	//float					L"%f"	
	//double				L"%f"
	//long double			L"%Lf"
	//Записывается столько цифр, сколько необходимо для представления целой части, за которыми следуют десятичный знак и шесть десятичных цифр.
	//inf(или бесконечность) используется для представления бесконечности.
	//nan(за которым следует необязательная последовательность символов) для представления NaN(Not - a - Number).
	//Представлениям отрицательных значений предшествует знак минус(-).

	std::wstring wpi = L"pi is " + std::to_wstring(3.1415926);
	std::wstring wperfect = std::to_wstring(1 + 2 + 4 + 7 + 14) + L" is a perfect number";
	std::wcout << wpi << L'\n';
	std::wcout << wperfect << L'\n';
	cout << endl;




cout << endl;
cout << endl;
system("pause");
}

