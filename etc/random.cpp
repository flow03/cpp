#include <iostream>  
#include <random>  
#include <ctime>  
#include <functional>
 
int main() 
{ 
	// генератор случайных чисел
    std::mt19937 gen(time(0)); 
	std::mt19937_64 gen_64(time(0));
    // gen.seed(time(0)); 

	// распределение, определяющее границы для ГСЧ
	std::uniform_int_distribution<> uid(0, 100);
	// std::uniform_int_distribution<int> uid1(uid.param().a(), 50);
	// std::uniform_int_distribution<int> uid2(uid1.param().b(), uid.param().b()); 
	
    // std::cout	<< "uid1 min: " << uid1.min() << " max: " << uid1.max() << std::endl 
				// << "uid2 min: " << uid2.min() << " max: " << uid2.max() << std::endl; 
	// uid1.max() = 20; 
	// uid1.param().b() = 20;
	
	// for(int i = 0; i < 3; ++i)
		// std::cout << "uid1(gen) " << uid1(gen) << " uid2(gen) " << uid2(gen) << std::endl; 
              
	// std::cin >> uid0; 
    // std::cout << uid0; 
	
	// Генератор ИСТИННО случайных чисел
	std::random_device dev;
	// std::cout << "dev() " << dev() << std::endl;
	// std::cout << "min() " << dev.min() << std::endl;
	// std::cout << "max() " << dev.max() << std::endl;
	// std::cout << "entropy() " << dev.entropy() << std::endl << std::endl;
	
	std::uniform_real_distribution<> urd(0, 4);
	std::cout << "urd min: " << urd.min() << " max: " << urd.max() << std::endl; 	
	// for(int i = 0; i < 5; ++i)
		std::cout << "urd(dev) " << urd(dev) << std::endl; 
	
	std::mt19937 gen_rd(std::random_device().operator()());
	std::mt19937 gen2 { std::random_device()() }; 
	
	auto roll = std::bind(urd, gen_rd); 
	auto roll2 = std::bind(uid, gen);
	
    std::cout << "urd gen_rd " << roll() << std::endl; 
	std::cout << "uid gen " << roll2() << std::endl; 
	// std::cout << typeid(roll).name() << std::endl; 
	
	std::cin.get();
	return 0;
} 