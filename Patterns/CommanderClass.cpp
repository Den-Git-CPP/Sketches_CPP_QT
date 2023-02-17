
#include <iostream>
#include <vector>
#include <string>
class ClassA
{
public:
	ClassA();
	~ClassA();
	std::string Name{};
};

ClassA::ClassA(){}
ClassA::~ClassA(){}

class ClassC
{
public:
	ClassC();
	~ClassC();
	void add_vev();
	void print();
	std::string Name{};
	std::vector<std::string> Vec_c{};
};

ClassC::ClassC() {}

ClassC::~ClassC(){}

void ClassC::add_vev(){
	Vec_c.push_back(Name);
}
void ClassC::print(){
	for (auto elem : Vec_c){
		std::cout << elem << "\n";
	}
}
class ClassB
{
public:
	ClassB();
	~ClassB();
	void add_vev();
	void add_ClassC();
	void print();
	ClassC* c = nullptr;
	std::string Name{};
	std::vector<std::string> Vec_b{};
	std::vector<ClassC> Vec_ClassC{};
};

ClassB::ClassB(){
	c = new ClassC;
}

ClassB::~ClassB(){
	delete c;
}

void ClassB::add_vev(){
	Vec_b.push_back(Name);
}

void ClassB::add_ClassC(){
	Vec_ClassC.push_back(*c);
}

void ClassB::print(){
	for (auto elem: Vec_b){
		std::cout << elem << "\n";
	}
}

class All
{
public:
	All();
	~All();

	ClassA* A = nullptr;
	ClassB* B = nullptr;
};

All::All()
{
A= new ClassA;
B = new ClassB;
}

All::~All()
{
	delete A;
	delete B;
}

class Commander
{
public:
	Commander();

	~Commander();
	std::string NameA = "NameAAA";
	std::string NameB = "NameBBB";
	void command(All *all);
};

Commander::Commander(){}

Commander::~Commander(){}

void Commander::command(All *all)
{
	all->A->Name = NameA;
    all->B->Name = NameB;
	all->B->add_vev();
	all->B->Name = "BBB1";
	all->B->add_vev();
	all->B->Name = "BBB2";
	all->B->add_vev();
	all->B->print();
	all->B->c->Name = "CCC1";
	all->B->c->add_vev();
	all->B->c->Name = "CCC2";
	all->B->c->add_vev();
	all->B->add_ClassC();
	std::cout << "======";
	all->B->c->Name = "CCC3";
	all->B->c->add_vev();
	all->B->add_ClassC();
	
	std::cout << "======";
}

int main()
{
	All* all1 = nullptr ;
	all1 = new All;
	Commander com1;
	com1.command(all1);
	return 0;
}

