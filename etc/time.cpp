#include <iostream>
#include <ctime>
// #include <stdio.h>	// printf


// time_t		time type, long long int in same realization
// struct tm	time structure, contains nine members of type int
// clock_t		clock type

// CLOCKS_PER_SEC	clock ticks per second macro

// time			get current time

// localtime	convert time_t to struct tm as local time
// gmtime		convert time_t to struct tm as UTC time
// mktime		convert struct tm to time_t
// asctime		convert struct tm to char*
// ctime		convert time_t directly to char*
// strftime		format struct tm as string

// difftime		return difference between two time_t
// clock		returns the processor time consumed by the program


// asctime(localtime(&seconds)) equivalent to ctime(&seconds)
	
// Всемирное координиированное время (UTC) используется в качестве точки отсчёта времени в других часовых поясах. Не переводится ни зимой, ни летом
// В 1972 году UTC пришло на замену GMT - среднему времени по Гринвичу (Greenwich Mean Time)
// UTC также является стандартом для протокола сетевого времени (NTP), авиации, МКС, и много где ещё

int main()
{
	// setlocale(LC_ALL, "RUS");
	
	time_t seconds;
	time(&seconds); //seconds = time(0);
	clock_t clocker = clock();
	clock_t clocker_2;
	struct tm * utc_time; 
	struct tm * diff_tm;
	time_t end_time;
	time_t diff_time;
	time_t minus_time;
	char buffer[30];
	
	auto end_symbol = [](const time_t *diff){
		if (*diff == 1) std::cout << "a\n";
		else if (*diff < 5) std::cout << "ы\n";
		else std::cout << std::endl;
	};
	
	utc_time = gmtime(&seconds);
	std::cout << "UTC time\n" << asctime(utc_time) << std::endl;
	int hours = (seconds/3600); // hours
	std::cout << hours/24 << " дней и " << hours%24 << " часов прошло с 1 января 1970 года\n\n";
	
	std::cout << "Текущее время\n" << ctime(&seconds) << std::endl;
	std::cout << "Какой-то ввод ";
	std::cin.get();
	
	end_time = time(0);
	diff_time = difftime(end_time, seconds);
	minus_time = end_time - seconds;
	clocker_2 = clock();
	std::cout << "\nВремя после\n" << ctime(&end_time) << std::endl;
	std::cout << "Разница оператор минус\t" << minus_time << " секунд"; end_symbol(&minus_time);
	std::cout << "Разница difftime\t" << diff_time << " секунд"; end_symbol(&diff_time);
	
	std::cout << "Счётчик 1: " << clocker << std::endl;
	std::cout << "Счётчик 2: " << clocker_2 << std::endl;
	clocker = clocker_2 - clocker;
	std::cout << "clock_t " << clocker << " тиков или " << (double)clocker/CLOCKS_PER_SEC << " секунд" << std::endl;
	
	// если использовать localtime, к времени будет прибавлена разница UTC с текущим часовым поясом
	diff_tm = gmtime(&diff_time);
	strftime(buffer, 30, "strftime %H:%M:%S", diff_tm);
	std::cout << buffer << std::endl;
	std::cout << "diff_tm structure " << diff_tm->tm_hour << ':' << diff_tm->tm_min << ':' << diff_tm->tm_sec << std::endl;
	
	// fflush(stdin);
	// std::cin.get();
	
	return 0;
}