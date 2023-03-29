#include <iostream>

#include "singleton_n.hpp"

class single
{
public:

	single(const single&) = delete;
	single& operator=(const single&) = delete;
	
	static single& instance()	// небезопасно в многопоточном приложении
	{
		static single s;		// отложенная инициализация
		return s;
	}
	
	void load() {a = 10; b = 15;}
	
	void out() const {std::cout << a << ' ' << b << std::endl;}
	
	const int& get_a() const {return a;}
	
	static int sum(){return instance().internal_sum();} 
	
private:

	int internal_sum() const {return a + b;}
	
	single() = default;
	int a, b;
};

void func_a()
{
	single::instance().out();
}

void func_b()
{
	std::cout << single::sum() << std::endl;
}

void func_c()
{
	const int &a = single::instance().get_a();	// именованная ссылка
	std::cout << a << std::endl;
}


int main()
{
	// single::instance().load();
	
	// func_a();
	// func_b();
	// func_c();
	// singleton_n::a;
	// singleton_n::b;
	// singleton_n::c;
	
	singleton_n::out();
	singleton_n::load();
	singleton_n::out();
	std::cout << singleton_n::sum() << std::endl;
	std::cout << singleton_n::get_a() << std::endl;
	
	return 0;
}












