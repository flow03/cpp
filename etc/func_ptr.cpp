#include <iostream>


int func(){return 10;}

int main()
{
	auto out_pos = [](const int pos)
	{
		std::cout << "out_pos  \t" << pos << std::endl;
	};
	
	void (*out_pos_2)(const int) = [](const int pos)
	{
		std::cout << "out_pos_2\t" << pos << std::endl;
	};
	
	void (*out_p)(const int) = out_pos;
	//виклик out_pos через неявне розіменування указателя out_p
	out_p(15);
	//присвоєння указателю out_p адресу функції out_pos_2
	out_p = out_pos_2;
	//виклик out_pos_2 через явне розіменування указателя out_p
	(*out_p)(99);
	
	// оголошення і ініціалізація константного указателя c_out_p на функцию out_pos
	void (*const c_out_p)(const int) = out_pos;
	// c_out_p = out_pos_2;	// assignment of read-only variable error
	
	std::cout << func << std::endl;
	std::cout << reinterpret_cast<void*>(func);
	
	return 0;
}