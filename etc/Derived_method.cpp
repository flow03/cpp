#include <iostream>
#include <string>

struct Base
{
	Base() : value(0) 
		{std::cout<< "Base() value=" << value << std::endl;}
	Base(int i) : value(i) 
		{std::cout<< "Base(" << i << ')' << " value=" << value << std::endl;} 
	
	virtual void log() const { std::cout << "Base.log() value=" << value << std::endl;}
	
	int value;
};

struct Derived : public Base
{
	Derived() 
		{std::cout<< "Derived() value=" << value << std::endl << std::endl;}
	Derived(int i) : Base(i) 
		{std::cout<< "Derived(" << i << ')' << " value=" << value << std::endl << std::endl;}
	Derived(int a, int b) : Base(a + b)
		{std::cout<< "Derived(" << a << ", " << b << ')' << " value=" << value << std::endl << std::endl;}
	
	virtual void log() const override { std::cout << "Derived.log() value=" << value << std::endl;}
};

int main()
{
	// Base base = Derived();
	Derived derived(15);
	derived = {57, 81};
	derived = (57, 81);
	derived = 31;
	derived = {65};
	derived = (11);
	
	
	// base.log();
	// derived.log();
	
	
	return 0;
}