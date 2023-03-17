#define _CRT_SECURE_NO_WARNINGS // delete error C4996 VS2019
#include <iostream>
#include <cstring>//<string.h>
#include <cctype>//<ctype.h>


using namespace std;
int main()
{
	////////////////////////////////////////////////////////////////= CSTRING= /////////////////////////////////////////////////////////////////////////
	/*=========Copying:==========*/
	//strcpy  strcpy_s
	///char * strcpy ( char * destination, const char * source );
	/*	Копирует строку C, указанную источником, в массив, указанный параметром назначения, включая завершающий нулевой символ(и остановку в этой точке).
		Чтобы избежать переполнения, размер массива, на который указывает пункт назначения, должен быть достаточно длинным, чтобы содержать ту же строку C,
		что и источник(включая завершающий нулевой символ), и не должен перекрываться в памяти с источником.
		*/
	char str01[] = "Sample string";
	char str02[40];
	char str03[40];
	strcpy_s(str02, str01);
	strcpy_s(str03, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str01, str02, str03);
	cout << "\n";

	//strncpy strncpy_s
	///char * strncpy ( char * destination, const char * source, size_t num );
	char str11[] = "To be or not to be";
	char str12[40]; char str13[40];
	strncpy_s(str12, str11, sizeof(str12));
	strncpy_s(str13, str11, 5); str13[5] = '\0';// добавить вручную конец строки
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str11, str12, str13);
	cout << "\n";

	//strxfrm  Функция strxfrm() подобна функции strncpy().
	///size_t strxfrm(char* destination, const char* source, size_t num);
	/*
	Функция strxfrm() используется для копирования до count символов содержимого строки, на которую указывает source, в строку, на которую указывает dest. Аргумент source должен быть указателем на строку, оканчивающуюся нулевым символом. В процессе копирования любые национальные символы преобразуются в формат, характерный для конкретной страны.
	*/


	/*=========Concatenation:==========*/

	//strcat  
	///char * strcat ( char * destination, const char * source );
	/*Добавляет копию исходной строки к целевой строке.Завершающий нулевой символ в пdestination перезаписывается первым символом source, а нулевой символ включается в конец новой строки, образованной объединением обоих в destination.
	  destination и source не должны совпадать.
	*/
	char str20[100];
	char str21[] = "first";
	char str22[] = " second";
	strcpy_s(str20, str21);
	strcat_s(str20, str22);
	printf("str20:%s\n", str20);
	cout << "\n";

	//strncat
	///char * strncat ( char * destination, const char * source, size_t num );
	/*Добавить символы из строки.	Добавляет первое число символов source к destination плюс завершающий нулевой символ.
	*/

	char str30[100];
	char str31[20];
	strcpy_s(str30, "First_CString ");
	strcpy_s(str31, "Second_CString ");
	strncat_s(str30, str31, 6);
	printf("str30:%s\n", str30);
	cout << "\n";


	/*=========Comparison:==========*/
//strcmp
///int strcmp ( const char * str1, const char * str2 );
	/*Aункция начинает сравнивать первый символ каждой строки. Если они равны друг другу, он продолжается со следующими парами, пока символы не различаются или пока не будет достигнут завершающий нулевой символ.
	<0	первый несоответствующий символ имеет меньшее значение в ptr1, чем в ptr2
	0	содержимое обеих строк равно
	>	0первый несоответствующий символ имеет большее значение в ptr1, чем в ptr2
	*/

	char key[] = "apple";
	char buffer[80];
	do
	{
		printf("Insert my fruit/apple/");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (strcmp(buffer, key) != 0);
	printf("Correct answer!%s", buffer + '\0');
	cout << "\n";

	//strncmp
	///int strncmp ( const char * str1, const char * str2, size_t num );
	/* Сравнивает до num символов строки C str1 с символами строки C str2.
	Эта функция начинает сравнение первого символа каждой строки. Если они равны друг другу, он продолжается со следующими парами, пока символы не различаются, пока не будет достигнут завершающий нулевой символ или пока число символов не совпадет в обеих строках, в зависимости от того, что произойдет раньше.
	<0	первый несоответствующий символ имеет меньшее значение в str1, чем в str2
	0	содержимое обеих строк равно
	>0	первый несоответствующий символ имеет большее значение в str1, чем в str2
	*/
	char robot[][5] = { "R2D2" , "C3PO" , "R2A6","R2A7" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 4; n++)
	{
		if (strncmp(robot[n], "R2xx", 2) == 0) { printf("Found %s\n", robot[n]); };

	}
	cout << "\n";


	//strcoll   Функция strcoll() эквивалентна функции strcmp().
	///int strcoll ( const char * str1, const char * str2 );
	/*
	Сравните две строки, используя локаль
	Сравнивает строку C str1 со строкой C str2, обе интерпретируемые соответствующим образом в соответствии с категорией LC_COLLATE текущей выбранной локали C. Эта функция начинает сравнение первого символа каждой строки. Если они равны друг другу, переход к следующей паре продолжается до тех пор, пока символы не различаются или пока не будет достигнут нулевой символ, указывающий на конец строки. Поведение этой функции зависит от категории LC_COLLATE выбранной локали C.

	*/


	/*=========Searching:==========*/
	//strchr
	///const char * strchr ( const char * str, int character );
	///      char * strchr (       char * str, int character );
	/*
	Функция strchr() возвращает указатель на ПЕРВОЕ вхождение символа ch в строку, на которую указывает str. Если символ ch не найден, возвращается NULL.
	*/
	char str40[] = "This is a sample string"; 
	char* p_char;
	printf("Looking for the 's' character in \"%s\"...\n", str40);
	p_char = strchr(str40, 's');
	while (p_char != NULL)
	{
		printf("found at %d\n", p_char - str40 + 1);
		p_char = strchr(p_char + 1, 's');
	}
	cout << "\n";
	//strrchr
	///const char * strrchr ( const char * str, int character );
	//	 	 char* strrchr(char* str, int character);
		/*
		Функция strrchr() возвращает указатель на ПОСЛЕДНЕЕ вхождение младшего байта аргумента ch в строке, на которую указывает str. Если совпадений не обнаружено, возвращается NULL.
		*/
	char str50[] = "This is a sample string";
	char* pch;
	pch = strrchr(str50, 's');
	printf("Last occurence of 's' found at %d \n", pch - str50 + 1);
	cout << "\n";

	//strcspn
	///size_t strcspn ( const char * str1, const char * str2 );	
	/*Функция strcspn() возвращает количество символов в начале строки с указателем str1, среди которых нет ни одного символа, входящего в строку с указателем str2. Другими словами, для строки str1 функция strcspn() возвращает значение индекса первого символа из числа символов, входящих в строку str2.
		*/
	char str60[] = "fcba73";
	char keys[] = "1234567890";
	int i;
	i = strcspn(str60, keys);
	printf("The first number in str is at position %d.\n", i + 1);
	cout << "\n";

	//strspn
	///size_t strspn ( const char * str1, const char * str2 );
	/*Функция strspn() возвращает количество символов в начале строки с указателем str1, в число которых входят только символы, имеющиеся в строке с указателем str2. Другими словами, для строки str1 функция strspn() возвращает значение индекса первого символа из числа символов, не входящих в строку str2.
	*/
	int i1;
	char strtext[] = "129th";
	char cset[] = "1234567890";
	i1 = strspn(strtext, cset);
	printf("The initial number has %d digits.\n", i);
	cout << "\n";

	//strpbrk
	///const char * strpbrk ( const char * str1, const char * str2 );
	///	     char* strpbrk(char* str1, const char* str2);
	/*Функция strpbrk() возвращает указатель на первый символ в строке, на которую указывает str1, совпадающий с каким-нибудь из символов строки, на которую указывает str2. Нулевые символы в конце строк в рассмотрение не включаются. Если совпадений нет, возвращается NULL.

	*/
	char str61[] = "This is a sample string";
	char key61[] = "aeiou";
	char* p_char61;
	printf("Vowels in '%s': ", str61);
	p_char61 = strpbrk(str61, key61);
	while (p_char61 != NULL)
	{
		printf("%c ", *p_char61);
		p_char61 = strpbrk(p_char61 + 1, key61);
	}
	cout << "\n";
	//
	char str62[] = "this is a test";
	char key62[] = " absj";
	char* p_char2;
	p_char2 = strpbrk(str62, key62);
	printf(p_char2);
	cout << "\n";
	//strstr
	///const char * strstr ( const char * str1, const char * str2 );
	///	     char* strstr(char* str1, const char* str2);
	/*Функция strstr() возвращает указатель на первое вхождение в строку, на которую указывает str1, строки, указанной str2 (исключая завершающий нулевой символ). Если совпадений не обна­ружено, возвращается NULL.
	*/
	char str63[] = "This is a simple string";
	char* p_char63;
	p_char63 = strstr(str63, "simple");
	strncpy(p_char63, "sample", 5);
	puts(str63);
	cout << "\n";


	//strtok
	///char * strtok ( char * str, const char * delimiters );
	/* Функция strtok() возвращает указатель на следующую лексему в строке, на которую указывает str1. Символы из строки, на которую указывает str2, используются как ограничители, определяю­щие лексему. Если лексема не найдена, возвращается NULL.

	Во время первого вызова функции strtok() в качестве указателя в самом деле используется str1. При последующих вызовах в качестве первого аргумента используется NULL. Таким образом вся строка может быть разбита на лексемы.

	Важно понимать, что функция strtok() модифицирует строку, на которую указывает str1. Каж­дый раз, когда найдена лексема, на месте, где был найден ограничитель, помещается нулевой символ. Таким образом strtok() продвигается вдоль строки.

	При каждом вызове strtok() можно варьировать набор ограничителей
	*/
	char str64[] = "- This, a sample string.";
	char* pch64;
	printf("Splitting string \"%s\" into tokens:\n", str64);
	pch64 = strtok(str64, " ,.-");
	while (pch64 != NULL)
	{
		printf("%s\n", pch64);
		pch64 = strtok(NULL, " ,.-");
	}
	cout << "\n";
	/*=========Other:==========*/
//strerror
///char * strerror ( int errnum );
/*
Функция strerror() возвращает указатель на сообщение об ошибке, связанное с номером ошибки.
*/
	FILE* pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error opening file unexist.ent: %s\n", strerror(errno));
	cout << "\n";
	//_strerror
	///char *_strerror(const char *str)
	/*Функция _strerror() позволяет выводить на экран собственное сообщение об ошибке, за которым через двоеточие следует последнее сообщение об ошибке, выданное программой. Функция возвращает указатель на всю строку.
	*/
	FILE* pFile1;
	pFile1 = fopen("unexist.ent", "r");
	if (pFile1 == NULL)
		//printf(_strerror("Error in opening."));
		cout << "\n";

	//strlen
	///size_t strlen ( const char * str );
	/*
	Функция strlen() возвращает длину строки, оканчивающейся нулевым символом, на которую указывает str. При определении длины строки нулевой символ не учитывается.
	*/
	char s_char[10];
	strcpy(s_char, "hello");
	printf("%d", strlen(s_char));
	cout << "\n";

	//_strset
		/*Функция strset() не определена стандартом ANSI С.
		Функция strset() присваивает всем символам строки, на которую указывает str, значение ch. Функция возвращает str.
		*/
	char str_set[] = "***";
	printf("%s", _strset(str_set, 'z'));
	cout << "\n";
	//strnset
	///char *strnset(char *str, int ch, size_t count)
	/*Функция strnset() присваивает первым count символам строки, на которую указывает source, значения ch. Функция возвращает str.
	*/
	char strn_set[80];
	strcpy(strn_set, "123456789101112");
	printf("%s", _strnset(strn_set, '*', 10));
	char xx[20] = "z";
	printf("%s", xx);

	cout << "\n";

	////////////////////////////////////////////////////////////////= CCTYPE= /////////////////////////////////////////////////////////////////////////

	//=============Character classification functions========//
	//isalnum()
	///int isalnum(int ch);
	/*Макрос isalnum() возвращает ненулевое значение, если его аргумент является либо буквой ал­фавита (верхнего или нижнего регистра), либо цифрой. Если символ не является буквенно-циф­ровым, возвращается 0.
	*/

	int cci = 0;
	char strcc[] = "c3po...";
	while (isalnum(strcc[cci])) cci++;
	printf("The first %d characters are alphanumeric.\n", cci);


	//isalpha()
	///int isalpha ( int ch );
	/*Макрос isalpha() возвращает ненулевое значение, если его аргумент является буквой алфавита (верхнего или нижнего регистра). В противном случае возвращается 0.  	ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz	*/

	int iz1 = 0;
	cout << "\nIn  string \"C++\"";
	char str_isalph[] = "C++";
	while (str_isalph[iz1])
	{
		if (isalpha(str_isalph[iz1])) printf("character %c is alphabetic\n", str_isalph[iz1]);
		else printf("character %c is not alphabetic\n", str_isalph[iz1]);
		iz1++;
	}
	cout << "\n";

	//isblank
	///int isblank ( int ch );
	/*проверяет  tab ('\t') или space (' ') 	*/
	char c_isblk;
	int i_isblk = 0;
	char str_isblk[] = "Example sentence to test isblank\n";
	while (str_isblk[i_isblk])
	{
		c_isblk = str_isblk[i_isblk];
		if (isblank(c_isblk)) c_isblk = '\n';
		putchar(c_isblk);
		i_isblk++;
	}

	//iscntrl
	///int iscntrl ( int ch );
	/*Макрос isctrl() возвращает ненулевое значение, если значение ch находится в пределах от 0 до 0x1F или равно 0x7F (DEL), в противном случае возвращается 0. 
	NUL, (other control codes) 
	tab ('\t') 
	(white-space control codes: '\f','\v','\n','\r')
	(other control codes)
	*/
	int i_cntrl = 0;
	char str_cntrl[] = "first line \n second line \n";
	while (!iscntrl(str_cntrl[i_cntrl]))
	{
		putchar(str_cntrl[i_cntrl]);
		i_cntrl++;
	}
	cout << "\n";

	//isdigit
	///int isdigit ( int ch );
	/*Макрос isdigit() возвращает ненулевое значение, если аргумент ch является цифрой от 0 до 9, в противном случае возвращается 0. 
	0123456789
	*/
	char str_isdig[] = "1776ad";
	int year_isdig;
	if (isdigit(str_isdig[0]))
	{
		year_isdig = atoi(str_isdig);
		printf("The year that followed %d was %d.\n", year_isdig, year_isdig + 1);
	}

	//isgraph
	///int isgraph ( int ch );
	/*Макрос isgrapn() возвращает ненулевое значение, если аргумент ch является печатным симво­лом, отличным от пробела; в противном случае возвращается 0. Значения печатных символов находятся в пределах от 0x21 до 0х7Е.
	!"#$%&'()*+,-./:;<=>?@ [\]^_`{|}~
	0123456789
	ABCDEFGHIJKLMNOPQRSTUVWXYZ
	abcdefghijklmnopqrstuvwxyz
	*/
	
	int i_graph = 0;
	char ch_graph;
	while (i_graph <3)
	{
		ch_graph = getchar();
		if (isgraph(ch_graph))
		{
			printf("%c is a printing character\n", ch_graph);
		}
		i_graph++;
	}
	
	cout << "\n";

	//islower
	//int islower(int ch)
	/*Макрос islower() возвращает ненулевое значение, если аргумент ch является буквой нижнего регистра (от «а» до «z»); в противном случае возвращается 0.
	abcdefghijklmnopqrstuvwxyz
	*/
	int i_lower = 0;
	char str_lower[] = "Test String.\n";
	char c_lower;

	while (str_lower[i_lower])
	{
		c_lower = str_lower[i_lower];
		if (islower(c_lower)) c_lower = toupper(c_lower);
		putchar(c_lower);
		i_lower++;
	}
	cout << "\n";


	//isprint
	///int isprint ( int ch );
	/*Макрос isprint() возвращает ненулевое значение, если аргумент ch является печатным символом, включая пробел; в противном случае возвращается 0. Значения печатных символов находятся в пределах от 0x20 до 0х7Е.
	!"#$%&'()*+,-./:;<=>?@ [\]^_`{|}~
	0123456789
	ABCDEFGHIJKLMNOPQRSTUVWXYZ
	abcdefghijklmnopqrstuvwxyz
	*/
	int i_print = 0;
	char str_print[] = "first line \n second line \n";
	while (isprint(str_print[i_print]))
	{
		putchar(str_print[i_print]);
		i_print++;
	}
	cout << "\n";
	
	//ispunct
	///int ispunct ( int ch );
	/*Макрос ispunct() возвращает ненулевое значение, если аргумент ch является знаком пунктуации или пробелом; в противном случае возвращается 0.
	!"#$%&'()*+,-./:;<=>?@ [\]^_`{|}~
	*/

	int i_punct = 0; int cx_punct = 0;
	char str_punct[] = "Hello, welcome!";
	while (str_punct[i_punct])
	{
		if (ispunct(str_punct[i_punct])) cx_punct++;
		i_punct++;
	}
	printf("Sentence contains %d punctuation characters.\n", cx_punct);
	cout << "\n";

	//isspace
	///int isspace ( int ch );
	/*
	Макрос isspace() возвращает ненулевое значение, если аргумент ch является символом пробела, возврата каретки, горизонтальной табуляции, вертикальной табуляции, перевода формата или новой строки; в противном случае возвращается 0.
	' '		(0x20)	space (SPC)
	'\t'	(0x09)	horizontal tab (TAB)
	'\n'	(0x0a)	newline (LF)
	'\v'	(0x0b)	vertical tab (VT)
	'\f'	(0x0c)	feed (FF)
	'\r'	(0x0d)	carriage return (CR)
	
	*/
	char c_space; 	int i_space = 0;
	char str_space[] = "Example sentence to test isspace\n";
	while (str_space[i_space])
	{
		c_space = str_space[i_space];
		if (isspace(c_space)) c_space = '\n';
		putchar(c_space);
		i_space++;
	}
	cout << "\n";


	//isupper
	///int isupper ( int ch );
	/*Макрос isupper() возвращает ненулевое значение, если аргумент ch является буквой верхнего регистра (от «А» до «Z»); в противном случае возвращается 0.
	ABCDEFGHIJKLMNOPQRSTUVWXYZ
	*/

	int i_upper = 0;
	char str_upper[] = "Test String.\n";
	char c_upper;
	while (str_upper[i_upper])
	{
		c_upper = str_upper[i];
		if (isupper(c_upper)) c_upper = tolower(c_upper);
		putchar(c_upper);
		i_upper++;
	}
	cout << "\n";

	//isxdigit
	///int isxdigit ( int ch );
	/*Макрос isxdigit() возвращает ненулевое значение, если аргумент ch является шестнадцатиричной цифрой, в противном случае возвращается 0. Шестнадцатеричные цифры могут принадлежать одному из следующих отрезков: от «А» до «F», от «а» до «f» и от «0» до «9».
	Hexadecimal digits are any of: 0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F
	*/
	char str_xdig[] = "ffff";
	long int number;
	if (isxdigit(str_xdig[0]))
	{
		number = strtol(str_xdig, NULL, 16);
		printf("The hexadecimal number %lx is %ld.\n", number, number);
	}
	cout << "\n";
	///===========Character conversion functions============///
	//tolower
	///int tolower ( int ch );
	/*Функция tolower() возвращает соответствующий нижнему регистру эквивалент символа ch, если ch — это буква верхнего регистра. В противном случае ch возвращается неизмененным. 
	*/
	int i_low = 0;
	char str_low[] = "Test String.\n";
	char c_low;
	while (str_low[i_low])
	{
		c_low = str_low[i_low];
		putchar(tolower(c_low));
		i_low++;
	}
	cout << "\n";

	//toupper
	///int toupper ( int ch );
	/*Функция toupper() возвращает соответствующий верхнему регистру эквивалент символа ch, если ch — это буква. В противном случае ch возвращается неизмененным. 
	*/
	int i_up = 0;
	char str_up[] = "Test String.\n";
	char c_up;
	while (str_up[i_up])
	{
		c_up = str_up[i_up];
		putchar(toupper(c_up));
		i_up++;
	}
	cout << "\n";

	cout << "\n"; system("pause");
}




