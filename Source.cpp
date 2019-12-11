//#define _CRT_SECURE_NO_WARNINGS
//#define PREDICAT

//#define KATA 0 //test, none or all
//#define MAIN
//#define iterator_traits_info
//#define Elf_

//MY LIBS
#ifdef MAIN
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> //system("pause"), SetConsoleTextAttribute
#include <vector>
#include <thread>
#include <chrono>

#include "PREDICAT.h"
#endif

//KATA LIBS
#if (KATA == all) || (KATA == test)
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath> //sqrt, pow
#include <iomanip> //setprecision
//#include <numeric> //accumulate
#include <map>

#include "PREDICAT.h"
#include "SImpleTimer.h"
#endif

/*
//srand(static_cast<unsigned int>(time(NULL)));

struct Base {};

struct D1 : Base {};

struct D2 : Base {};

struct D3 : D1, D2 {};

Base const * D1BaseToD2Base(Base const * base)
{
	
	return (Base const*)((D2 const*)((D3 const*)((D1 const*)base)));
}


struct Unit
{
	
	explicit Unit(size_t id)
		: id_(id)
	{}

	//Unit() : id_(0) {};

	size_t id() const { return id_; }

	virtual ~Unit() {};

private:
	size_t id_;
};

// базовый класс для животных
struct Animal : virtual Unit
{
	// name хранит название животного
	// "bear" для медведя
	// "pig" для свиньи
	Animal(std::string const & name, size_t id) : Unit(id), name_(name) {};

		std::string const& name() const { return name_; }
private:
	std::string name_;
};

// класс для человека
struct Man : virtual Unit { explicit Man(size_t id) : Unit(id) {} };

// класс для медведя
struct Bear : Animal{explicit Bear(size_t id) : Unit(id), Animal("bear", id) {}};

// класс для свиньи
struct Pig : Animal{explicit Pig(size_t id) : Unit(id), Animal("pig", id) {}};

// класс для челмедведосвина
struct ManBearPig : Man, Bear, Pig{ManBearPig(size_t id) : Unit(id), Man(id), Bear(id), Pig(id) {}};

struct Elf : Unit { 
	Elf() :Unit(0) {}
};

struct Dwarf : Unit {
	Dwarf() : Unit(0) {}
};

template<class T>
bool isSameObject(T const * p, T const * q)
{
	return (dynamic_cast<const void*>(p) == dynamic_cast<const void*>(q));
}


template <class T, class RM_type>
bool compare(T const& a, T const& b, RM_type(T::*mptr)() const)
{
	//std::cout << typeid(RM_type).name() << '\n';
	//std::cout << (a.*mptr)() << '\n';
	//std::cout << (b.*mptr)() << '\n';

	return ((a.*mptr)() < (b.*mptr)());
}

void read() {}

template <typename T, typename... Args>
void read(T& value_, Args&... args_) {
	std::cin >> value_;
	read(args_...);
}

void print_values() {}
void print_values(std::ostream & os) {}

template <typename T, typename... Args>
void print_values(std::ostream & os, T value_, Args ...args_)
{
	os << typeid(value_).name() << ": " << value_<<'\n';
	print_values(os, args_...);
}

template< class T1, class T2> struct pair;

// принимает std::tuple произвольного размера
template <int I1, int I2, class T>
auto to_pair(T t) -> decltype(std::make_pair(std::get<I1>(t), std::get<I2>(t)))
{
	return std::make_pair(std::get<I1>(t), std::get<I2>(t));
}


// определение структуры Point уже подключено
 struct Point
{
	constexpr Point(double x, double y)
		: x(x), y(y)
	{}

	double x = 0;
	double y = 0;
};

 constexpr Point operator+(const Point &left, const Point &right){	
	 return (Point(left.x + right.x, left.y + right.y));}

 constexpr Point operator-(const Point &left, const Point &right){
	 return (Point(left.x - right.x, left.y - right.y));}

 constexpr double operator*(const Point &left, const Point &right){ //скалярное произведение
	 return (left.x * right.x) + (left.y * right.y);} 


 template<class F>
 int * find_if(int * p, int * q, F f)
 {
	 for (; p != q; ++p)
		 if (f(*p))
			 return p;
	 return q;
 }

 template <class Func, class... Args>
 auto apply(Func f, Args&&... arg) -> decltype(f(std::forward<Args>(arg)...))
 {
	 return f(std::forward<Args>(arg)...);
 }

auto fun = [](std::string a, std::string const& b) { return a += b; };

auto gen_finder = [](int *a, int *b) {

	 return [&a, &b](int it)//->bool 
	 {

		 for (int* i = a; i != b; ++i) {
			 if (*i == it) return true;
		 }
		 return false;
	 };
 };


template <class It>
size_t max_increasing_len(It p, It q) {
	if (p != q) {
		size_t result = 0; size_t length = 0;
		auto end = q;
		q = p; ++q;
		for (; p != end, q != end; ++p, ++q) {
			//std::cout << *p <<' '<< *q << std::endl;
			if (*p < *q) ++length;
			else length = 0;
			if (result < (length))
				result = length;

		}
		return result + 1;
	}
	else return 0;
}

bool is_isogram(std::string str) {
	//const char * char_str = str.c_str();

	for (int i = 0; i < str.size(); ++i)
		for (int j = 0; j < str.size(); ++j) {
			if (i != j) {
				if (tolower(str[i]) == tolower(str[j])) return false;
			}
		}
	return true;
}

void pic_size(double width, double height) {
	 int new_width = static_cast <int>(height / 160 * 128);
	 if ( new_width <= width) 
		 std::cout << new_width << ' '<< height <<'\n';
	 else 
		 std::cout << width << ' ' << static_cast<int>(width / 128 * 160) << '\n';
 }

 
*/

//KATAs
#if (KATA == all)

//выводит строку с сокращёнными перечислениями, начиная с трёх, идущих подряд
std::string range_extraction(std::vector<int> args) {
	SimpleTimer t;

	if (args.size() == 0) return "";
	if (args.size() == 1) return std::to_string(*args.begin());

	std::string result;

	auto isRange = [&args](size_t &it) -> std::string
	{
		int first = args[it];
		int last = 0;
		unsigned int count = 2;

		for (size_t i = it + 1; i < args.size() - 1; ++i)
		{
			if (args[i + 1] - args[i] == 1)
			{
				last = args[i + 1];
				count++;
				it = i + 1;
			}
			else break;
		}

		if (count >= 3)
			return std::to_string(first) + "-" + std::to_string(last);
		else
			return std::to_string(first);

	};

	for (size_t i = 0; i < args.size(); ++i)
	{
		if ((i < args.size() - 1) &&
			(args[i + 1] - args[i] == 1))
		{
			result += isRange(i);
		}
		else
			result += std::to_string(args[i]);

		if (i < args.size() - 1)
			result += ",";
	}

	return result;
}

//необходимые для следующей КАТЫ typedef-ы
typedef std::vector<long long> vll;
typedef std::vector< std::vector<long long> > vvll;

vvll minor(vvll sub_m, size_t col);

//вычисляет детерминант матрицы любого размера
long long determinant(vvll m) {
	SimpleTimer time;

	if (m.size() == 1) return m[0][0];
	else if (m.size() == 0) return 0;

	long long result = 0;

	for (size_t j = 0; j < m.size(); ++j)
	{
		if (j % 2 == 0)
			result += m[0][j] * determinant(minor(m, j));
		else
			result -= m[0][j] * determinant(minor(m, j));
	}

	return result;
}

vvll minor(vvll sub_m, size_t col) {

	if (col >= sub_m.size() || sub_m.size() <= 1) return sub_m;

	sub_m.erase(sub_m.begin());

	vll::iterator it;

	for (vll &row : sub_m)
	{
		it = row.begin();
		//advance(it, col);
		row.erase(it + col);
	}

	return sub_m;
}

//выводит сумму чисел, которые делятся на заданный k-фактор
class SumOfDivided
{
public:
	static std::string sumOfDivided(std::vector<int> &lst) {
		SimpleTimer t;
		int max = *std::max_element(lst.begin(), lst.end(), [](const int &a, const int &b) {
			return abs(a) < abs(b);
		});

		max = abs(max);

		std::vector<int> primes = countKprimes(1, 2, max);
		//printContainer(primes); std::cout << "\n\n";

		std::vector<std::pair<int, int>> res;

		for (int const &i : primes)
			for (int const &el : lst)
			{
				if (el%i == 0)
				{
					auto ptr = std::find_if(res.begin(), res.end(), [&i](const std::pair<int, int> &p) {
						return p.first == i;
					});
					if (ptr != res.end())
						(*ptr).second += el;
					else res.push_back(std::make_pair(i, el));
				}
			}

		//for (auto &r : res) std::cout << r.first << ' ' << r.second << '\n';

		std::string result;
		for (auto &r : res)
			result += "(" + std::to_string(r.first) + " " + std::to_string(r.second) + ")";

		return result;
	}

	static std::string map_sumOfDivided(std::vector<int> &lst) {
		SimpleTimer t;
		int max = *std::max_element(lst.begin(), lst.end(), [](const int &a, const int &b) {
			return abs(a) < abs(b);
		});

		max = abs(max);

		std::vector<int> primes = countKprimes(1, 2, max);
		//printContainer(primes); std::cout << "\n\n";

		std::map<int, int> res;

		for (int const &i : primes)
			for (int const &el : lst)
			{
				if (el%i == 0)
				{
					auto ptr = res.find(i);

					if (ptr != res.end()) ptr->second += el;
					else res.emplace(i, el);
				}
			}

		//for (auto &r : res) std::cout << r.first << ' ' << r.second << '\n';

		std::string result;
		for (auto &r : res)
			result += "(" + std::to_string(r.first) + " " + std::to_string(r.second) + ")";

		return result;
	}

private:
	//создаёт массив k-простых чисел заданного диапазона
	static std::vector<int> countKprimes(int k, int start, int end) {
		std::vector<int> result;
		for (int i = start; i <= end; ++i)
		{
			if (countPrimeDiv2(i, k) == k) result.emplace_back(i);
		}
		return result;
	}

	static int countPrimeDiv2(int value, int k) {
		if (value < 2) return 0;

		int total = 1;

		for (int i = 2; i * i <= value; ++i)
		{
			if ((value % i) == 0) {
				++total;
				if (total > k) return 0;
				value /= i;
				i = 1;
			}
		}
		return total;
	}
};

//тестовая
class SumOfDivided2
{
public:
	static std::string sumOfDivided(std::vector<long long> &lst) {
		SimpleTimer t;
		long long max = *std::max_element(lst.begin(), lst.end(), [](const long long &a, const long long &b) {
			return abs(a) < abs(b);
		});

		max = abs(max);

		std::vector<long long> primes = countKprimes(1, 2, max);
		//printContainer(primes); std::cout << "\n\n";

		std::vector<std::pair<long long, long long>> res;

		for (long long const &i : primes)
			for (long long const &el : lst)
			{
				if (el%i == 0)
				{
					auto ptr = std::find_if(res.begin(), res.end(), [&i](const std::pair<long long, long long> &p) {
						return p.first == i;
					});
					if (ptr != res.end())
						(*ptr).second += el;
					else res.push_back(std::make_pair(i, el));
				}
			}

		//for (auto &r : res) std::cout << r.first << ' ' << r.second << '\n';

		std::string result;
		for (auto &r : res)
			result += "(" + std::to_string(r.first) + " " + std::to_string(r.second) + ")";

		return result;
	}

private:
	//создаёт массив k-простых чисел заданного диапазона
	static std::vector<long long> countKprimes(int k, long long start, long long end) {
		std::vector<long long> result;
		for (long long i = start; i <= end; ++i)
		{
			if (countPrimeDiv2(i, k) == k) result.emplace_back(i);
		}
		return result;
	}

	static long long countPrimeDiv2(long long value, int k) {
		if (value < 2) return 0;

		long long total = 1;

		for (long long i = 2; i * i <= value; ++i)
		{
			if ((value % i) == 0) {
				++total;
				if (total > k) return 0;
				value /= i;
				i = 1;
			}
		}
		return total;
	}
};

//вычисляет силу, действующую на частицу в матрице (K, N), состоящей из маленьких квадратов (k, n)
class Magnets
{
public:
	//(нет)
	static double doubles(int maxk, int maxn) {
		double S = 0;
		for (double k = 1; k <= maxk; ++k)
			for (double n = 1; n <= maxn; ++n)
				S += 1 / (k * pow(n + 1, 2 * k));

		return S;
	}
};

//класс для работы с простыми числами
class KPrimes
{
public:
	//создаёт массив k-простых чисел заданного диапазона
	static std::vector<long long> countKprimes(int k, long long start, long long end) {
		//SimpleTimer t;
		std::vector<long long> result;
		for (long long i = start; i <= end; ++i)
		{
			if (r_isKprime(i) == k) result.emplace_back(static_cast<long long>(i));
		}
		return result;
	}

	//вычисляет количество возможных сложений (1-простого, 3-простого и 7-простого чисел) для заданного числа
	static int puzzle(int s) {
		//SimpleTimer t;
		std::vector<long long> v1 = KPrimes::countKprimes(1, 0, s);
		std::vector<long long> v3 = KPrimes::countKprimes(3, 0, s);
		std::vector<long long> v7 = KPrimes::countKprimes(7, 0, s);

		long long key = static_cast<long long>(s);

		int result = 0;
		//2x performance optimization
		for (const long long &i7 : v7)
			for (const long long &i3 : v3)
				for (const long long &i1 : v1)
				{
					if ((i7 + i3 + i1) == key) ++result;
				}
		return result;
	}

private:
	//рекурсивно возвращает количество целочисленных делений числа (степень k простого числа)
	static int r_isKprime(long long value)
	{
		if (value < 2) return 0;

		//square root
		long long sq = static_cast<long long>(sqrt(value) + 1);
		int total = 1;

		for (long long i = 2; i < sq; ++i)
		{
			if ((value % i) == 0) {
				total += r_isKprime(value / i);
				break;
			}
		}
		return total;
	}

};

//ещё один класс для работы с простыми числами
class PrimeConsec
{
public:
	//возвращает количество повторений подряд k-простых чисел
	static int consecKprimes(int k, std::vector<long long> &arr)
	{
		//SimpleTimer t;
		int result = 0;
		for (size_t i = 0; i < arr.size() - 1; ++i)
		{
			if (countPrimeDiv2(arr[i], k) == k)
				if (countPrimeDiv2(arr[i + 1], k) == k)
					++result;
		}
		return result;
	}

private:
	//возвращает количество возможных целочисленных делений числа(степень простого числа)
	static int countPrimeDiv(long long value) {
		//SimpleTimer time;
		if (value < 2) return 0;

		int total = 1;

		for (long long i = 2; i * i <= value; ++i)
		{
			if ((value % i) == 0) {
				++total;
				value /= i;
				i = 1;
			}
		}
		return total;
	}

	//super perfomance(но не для всех задач)
	static int countPrimeDiv2(long long value, int k) {
		//SimpleTimer time;
		if (value < 2) return 0;

		int total = 1;

		for (long long i = 2; i * i <= value; ++i)
		{
			if ((value % i) == 0) {
				++total;
				if (total > k) return 0;
				value /= i;
				i = 1;
			}
		}
		return total;
	}

	//не мой
	static int countPrimeDiv1(long long n) {
		//SimpleTimer time;
		int cnt = 0;
		for (long long i = 2; i * i <= n; i++)
		{
			while (n % i == 0)
			{
				cnt++;
				n /= i;
			}
		}
		if (n > 1) cnt++;
		return cnt;
	}

	//пример
	/*vll arr = { 10081, 10071, 10077, 10065, 10060, 10070,
				  10086, 10083, 10078, 10076, 10089, 10085,
				  10063, 10074, 10068, 10073, 10072, 10075 };

	std::cout << PrimeConsec::consecKprimes(2, arr);*/
};

//отсртировать участников по рангам и вывести n-го по счёту
class Rank
{
public:
	static std::string nthRank(const std::string &st, std::vector<int> &we, int n) {
		SimpleTimer t;
		if (st.empty()) return "No participants";
		if (we.size() < size_t(n)) return "Not enough participants";

		typedef std::pair<std::string, int> s_pair;
		std::vector<s_pair> names;

		std::stringstream sstream(st);
		std::string str;

		while (std::getline(sstream, str, ',')) {
			names.push_back(std::make_pair(str, 0));
		}

		for (size_t i = 0; i < names.size(); ++i)
			names[i].second = (countRank(names[i].first) * we[i]);

		std::sort(names.begin(), names.end(), [](const s_pair& a, const s_pair& b) {
			if (a.second != b.second)
				return (a.second > b.second);
			else return (a.first < b.first);
		});

		//for (s_pair &a : names) std::cout << a.second << ' ' << a.first << '\n';

		return names[n - 1].first;
	}

	static int countRank(const std::string &str) {
		int result = 0;
		std::for_each(str.begin(), str.end(), [&result](const char &ch) {
			result += static_cast<unsigned int>(tolower(ch) - 96);
		});

		return result + (int)str.size();
	}
};

//Strings Mix 4 ky
class Mix
{
public:
	Mix() = delete;

	static std::string mix(const std::string &s1, const std::string &s2)
	{
		SimpleTimer time;
		if (s1.empty() && s2.empty()) return "";

		std::vector<std::string> vec1 = Mix::convert(Mix::copy_and_sort(s1), "1");
		std::vector<std::string> vec2 = Mix::convert(Mix::copy_and_sort(s2), "2");

		vec1.insert(vec1.end(), vec2.begin(), vec2.end());
		Mix::unique_and_sort(vec1);
		//printContainer(vec1, '\n');

		std::string result;
		for (std::string str : vec1)
			result += str + "/";
		if (!result.empty()) result.pop_back();

		return result;
	};

private:
	static std::string copy_and_sort(std::string str)
	{
		bool(*pred)(const char&) = [](const char &ch) ->bool {
			return !((ch >= 97) && (ch <= 122));
		};

		str.erase(std::remove_if(str.begin(), str.end(), pred), str.end());

		std::sort(str.begin(), str.end());

		return str;
	}

	static std::vector<std::string> convert(const std::string &str, std::string id) {
		std::vector<std::string> vec;

		for (size_t i = 0; i < str.size();)
			for (size_t j = (i + 1); j <= str.size(); ++j)
			{
				if (str[i] != str[j])
				{
					if ((j - i) > 1)
						vec.push_back(id + ":" + str.substr(i, j - i));
					i = j;
					break;
				}
			}

		return vec;
	}

	static void unique_and_sort(std::vector<std::string> &vec) {

		sort(vec.begin(), vec.end(), [](const std::string &a, const std::string &b) {
			return (a.substr(2, a.size()) > b.substr(2, b.size()));
		});

		auto to_erase = unique(vec.begin(), vec.end(), [](std::string &a, std::string &b) {
			if (a[2] == b[2]) {
				if (a.substr(2, a.size()) == b.substr(2, b.size())) {
					a[0] = '=';
				}
				return true;
			}
			else return false;
		});

		vec.erase(to_erase, vec.end());

		sort(vec.begin(), vec.end(), [](const std::string &a, const std::string &b) {
			if (a.size() == b.size())
			{
				if (a[0] == b[0])
					return (a.substr(2, a.size()) < b.substr(2, b.size()));
				else return a[0] < b[0];
			}
			else return (a.size() > b.size());
		});
	}

};

//класс для вершин
struct PeakData {
	std::vector<int> pos, peaks; //позиция и вершина(пик)
};
//возвращает вершину и её позицию в контейнере
PeakData pick_peaks(std::vector<int> v) {
	PeakData result;

	if (v.size() < 3) return result;

	for (size_t i = 1; i < v.size() - 1; ++i)
	{
		if ((v[i] > v[i - 1]) && (v[i] > v[i + 1]))
		{
			result.pos.push_back((int)i);
			result.peaks.push_back(v[i]);
		}
		else if ((v[i] > v[i - 1]) && (v[i] >= v[i + 1]))
		{
			for (size_t j = i + 1; j < v.size(); ++j)
			{
				if (v[i] > v[j])
				{
					result.pos.push_back((int)i);
					result.peaks.push_back(v[i]);
					break;
				}
				else if (v[i] < v[j]) break;
			}
		}
	}

	return result;
}

//задаёт последвательность Фибоначчи по 3 элементам
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
	//SimpleTimer t;
	std::vector<int> result;
	//const size_t three = 3;

	if (n > signature.size())
	{
		for (const int &i : signature)
			result.push_back(i);

		for (int i = 3; i < n; ++i)
			result.push_back(result[i - 3] + result[i - 2] + result[i - 1]);
	}
	else if (n <= signature.size())
		for (int i = 0; i < n; ++i)
			result.push_back(signature[i]);

	return result;
}

//задаёт последвательность Фибоначчи по n элементам
std::vector<int> xbonacci(std::vector<int> signature, int n)
{
	//SimpleTimer t;
	std::vector<int> result;
	const size_t seed = signature.size();
	int sum = 0;

	if (n > signature.size())
	{
		for (const int &i : signature)
			result.push_back(i);

		for (size_t i = seed; i < n; ++i)
		{
			for (size_t j = result.size() - seed; j < i; ++j)
				sum += result[j];
			result.push_back(sum);
			sum = 0;
		}
	}
	else if (n <= signature.size())
		for (int i = 0; i < n; ++i)
			result.push_back(signature[i]);

	return result;
}
// поиск самого длинного палиндрома
int longest_palindrome(const std::string &s)
{
	SimpleTimer time;

	std::stringstream is{ s };
	std::string sub_str = s;
	std::string token;
	char ch = 0;
	size_t result = 0;

	auto isPalindrome = [](const std::string &str) -> bool {
		return str == std::string(str.rbegin(), str.rend());
		//return equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
	};

	for (size_t i = 0; i < s.size(); ++i) {
		is.clear(); is.str(sub_str);
		while (is.get(ch))
		{
			token += ch;
			if (isPalindrome(token))
				if (token.size() > result)
					result = token.size();
		}
		token = "";
		sub_str.erase(sub_str.begin());
	}
	return static_cast<int>(result);
}

int longest_palindrome2(const std::string &s)
{
	SimpleTimer time;

	std::stringstream is(s);
	std::string sub_str;
	std::string token;
	char ch = 0;
	size_t result = 0;

	auto isPalindrome = [](const std::string &str) -> bool {
		return str == std::string(str.rbegin(), str.rend());
		//return equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
	};

	while (is.get(ch))
	{
		token += ch;
		if (isPalindrome(token))
			if (token.size() > result)
				result = token.size();

		std::getline(is, sub_str);
		if (isPalindrome(sub_str))
			if (sub_str.size() > result)
				result = sub_str.size();

		is.clear(); is.str(sub_str);
	}

	return static_cast<int>(result);
}

//вернуть слово с найвысшим "рейтингом"
std::string highestScoringWord(const std::string &str)
{
	//SimpleTimer time;
	std::string result;
	if (str.empty()) return result;

	unsigned int sum = 0, higest = 0;
	std::string::const_iterator first_it = str.begin(),
		last_it = str.begin(),
		word_begin = str.begin();

	for (size_t it = 0; it <= str.size(); ++it)
	{

		if ((str[it] != ' ') && (str[it] != '\0'))
			sum += static_cast<unsigned int>(tolower(str[it]) - 96);
		else if (higest < sum) {
			higest = sum;
			sum = 0;
			first_it = word_begin;
			if (first_it != str.begin()) ++first_it;
			else if (*first_it == ' ') ++first_it;
			last_it = str.begin();
			advance(last_it, it);
			word_begin = str.begin();
			advance(word_begin, it);
		}
		else {
			word_begin = str.begin();
			advance(word_begin, it);
			sum = 0;
		}

	}

	copy(first_it, last_it, back_inserter(result));

	return result;
}
// не моё решение вернуть слово с найвысшим "рейтингом"
std::string otherhighestScoringWord(const std::string &str)
{
	SimpleTimer time;
	//std::cout << str << std::endl;

	std::istringstream stm(str);
	std::string token, maxString;
	long maxValue = 0;

	auto GetValue = [](const std::string& s)
	{
		long r = 0;
		for (auto c : s)
			r += int(c) - int('a') + 1;

		return r;
	};

	while (std::getline(stm, token, ' '))
	{
		long actValue = GetValue(token);
		if (actValue > maxValue)
		{
			maxValue = actValue;
			maxString = token;
		}
	}

	return maxString;
}

//задача про удаление подряд идущих противоположных направлений NORTH, SOUTH, WEST, EAST
class DirReduction
{
public:
	static std::vector<std::string> dirReduc0(std::vector<std::string> arr)
	{
		//SimpleTimer Timer;
		std::vector<std::string> result_arr;

		for (size_t i = 0; i < arr.size(); ++i)
			for (size_t j = i; j < arr.size(); ++j)
			{
				if (arr[i] == "") break;
				if ((arr[i] == "NORTH") && (arr[j] == "SOUTH")) { arr[i] = ""; arr[j] = ""; break; }
				if ((arr[i] == "SOUTH") && (arr[j] == "NORTH")) { arr[i] = ""; arr[j] = ""; break; }
				if ((arr[i] == "WEST") && (arr[j] == "EAST")) { arr[i] = ""; arr[j] = ""; break; }
				if ((arr[i] == "EAST") && (arr[j] == "WEST")) { arr[i] = ""; arr[j] = ""; break; }
			}

		for (std::string &str : arr)
			if (str != "") result_arr.push_back(str);

		return result_arr;
	}

	static std::vector<std::string> dirReduc(std::vector<std::string> arr)
	{
		//SimpleTimer Timer;
		if (arr.empty()) return arr;
		size_t size;

		auto p = arr.begin();
		auto q = p; ++q;

		do
		{
			size = arr.size();
			for (; q != arr.end(); ++p, ++q)
			{
				if (((*p == "NORTH") && (*q == "SOUTH")) ||
					((*p == "SOUTH") && (*q == "NORTH")) ||
					((*p == "WEST") && (*q == "EAST")) ||
					((*p == "EAST") && (*q == "WEST")))
				{
					arr.erase(p, ++q);
					if (!arr.empty()) {
						p = arr.begin();
						q = p; ++q;
					}
					break;
				}
			}
		} while (size != arr.size() && !arr.empty());

		return arr;
	}
};

int find_even_index(const std::vector<int> &numbers) {

	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < numbers.size(); ++i) {
		if (i)
			for (int j = 0; j < i; ++j) {
				sum1 += numbers[j];
			}
		if (i != numbers.size() - 1)
			for (int sonya = i + 1; sonya < numbers.size(); ++sonya) {
				sum2 += numbers[sonya];
			}
		if (sum1 == sum2) return i;
		sum1 = 0; sum2 = 0;
	}
	return -1;
}

std::string encrypt(std::string text, int n)
{
	if ((text.size() <= 1) || (n <= 0)) return text;
	std::string New_str;
	while (n > 0)
	{
		New_str.clear();
		for (size_t i = 1; i < text.size(); i += 2)
			New_str.push_back(text[i]);
		for (size_t j = 0; j < text.size(); j += 2)
			New_str.push_back(text[j]);
		text = New_str;
		--n;
	}

	return New_str;
}

std::string decrypt(std::string enText, int n)
{
	if ((enText.size() <= 1) || (n <= 0)) return enText;
	std::string decText;
	size_t enSize = enText.size() / 2;

	while (n > 0)
	{
		decText.clear();

		for (size_t i = 0; i < enSize; ++i) {
			decText.push_back(enText[i + enSize]);
			decText.push_back(enText[i]);
		}

		if (enText.size() % 2) decText.push_back(enText[enText.size() - 1]);

		enText = decText;
		--n;
	}

	return decText;
}

size_t duplicateCount(const char* in)
{
	if (strlen(in) == 0) return 0;

	size_t dCount = 0;
	std::list<char> charList;
	for (size_t i = 0; i < strlen(in); ++i)
		charList.push_back(tolower(in[i]));

	size_t last_size = charList.size();

	for (auto i = charList.begin();
		i != charList.end();) {
		for (auto j = i;
			j != charList.end(); ++j) {
			if (j != i)
				if (*i == *j) {
					++dCount;
					charList.remove(*i);
					i = charList.begin();
					//for (char &ch : charList) std::cout << ch;
					//std::cout << std::endl;
					break;
				}
		}
		if (charList.size() == last_size) ++i;
		else last_size = charList.size();
	}

	return dCount;
}
#endif

#ifdef MAIN
class Point
{
public:
	Point() : Point(0,0) {};
	Point(int x_, int y_) : x(x_), y(y_) {};

//private:
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& os, const Point &p) {
	os << p.x << " " << p.y;
	return os;
}

std::istream& operator>>(std::istream& is, Point &p) {
	is >> p.x >> p.y;
	return is;
}

//using namespace std;

int Do(int n) {
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "thread ID " << std::this_thread::get_id() << "\tDo  start" << std::endl;
	//std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "thread ID " << std::this_thread::get_id() << "\tDo  end" << std::endl;
	return n *= n;
}

//операция
template <class Operation>
void display(const int a[], size_t n, Operation operation)
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << operation(a[i]) << ' ';
	}
	std::cout << std::endl;
}
#endif

//#include <time.h>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

#ifdef iterator_traits_info
// алгоритм должен работать с forward итераторами
	// и возвращать итератор, который потом будет передан
	// в метод erase соответствующего контейнера
template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n)
{
	size_t count = 0;
	//auto lambda = [&](decltype(*p) &value) { 
	auto lambda = [&count, &n](typename std::iterator_traits<FwdIt>::reference value) {
		return (count++ == n);
	};
	return std::remove_if(p, q, lambda);
}
#endif

template<class T>
class VectorList
{
private:
	using VectT = std::vector<T>;
	using ListT = std::list<VectT>;

public:
	using value_type = T;

	VectorList() = default;
	VectorList(VectorList const &) = default;
	VectorList(VectorList &&) = default;

	VectorList & operator=(VectorList &&) = default;
	VectorList & operator=(VectorList const &) = default;

	// метод, который будет использоваться для заполнения VectorList
	// гарантирует, что в списке не будет пустых массивов
	template<class It>
	void append(It p, It q) // определена снаружи
	{
		if (p != q)
			data_.push_back(VectT(p, q));
	}

	bool empty() const { return size() == 0; }

	// определите метод size
	size_t size() const
	{
		size_t size = 0;
		for (VectT node : data_)
			size += node.size();
		return size;
	}

	// определите const_iterator
	struct const_iterator //: std::iterator<std::bidirectional_iterator_tag, T, 
		//typename ptrdiff_t, typename const T*, typename const T&>
	{
		using difference_type = typename ptrdiff_t;
		using iterator_category = typename std::bidirectional_iterator_tag;
		using value_type = typename T;
		using pointer = typename const T*;
		using reference = typename const T&;

		const_iterator() = default;
		const_iterator(ListT const &data_,
			typename ListT::const_iterator it_l,
			typename VectT::const_iterator it_v) {
			data = &data_;
			itl = it_l;
			itv = it_v;
		}
		const_iterator(const_iterator const &) = default;
		const_iterator(const_iterator &&) = default;
		const_iterator& operator=(const_iterator const &other) {
			this->data = other.data;
			this->itl = other.itl;
			this->itv = other.itv;

			return *this;
		};

		const_iterator& operator++ ()
		{	// preincrement	
			++itv;
			if (itv == itl->end()) 
			{	
				++itl;
				if (itl != data->end())
					itv = itl->begin();
				else //throw std::out_of_range("Iterator++ out of range!");
				{
					--itl;
					itv = itl->end();
				}
			}
			
			return (*this);
		};

		const_iterator operator++ (int)
		{	// postincrement
			const_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
		};

		const_iterator& operator--() {	
			if (itv == itl->begin())
			{
				if (itl != data->begin())
				{
					--itl;
					itv = --(itl->end());
				}
				else --itv; //throw std::out_of_range("Iterator-- out of range!"); 
			}
			else --itv;

			return (*this);
		};

		const_iterator operator-- (int)
		{
			const_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
		};

		bool operator== (const const_iterator& it) const {
			return ((this->data == it.data) && (this->itl == it.itl) && (this->itv == it.itv));
		};
		bool operator!= (const const_iterator& it) const {
			return !(*this == it);
		};
		const T& operator*() const {
			return *itv;
		};

		pointer operator->() const { return this; };

	private:
		typename ListT::const_iterator itl;
		typename VectT::const_iterator itv;
		ListT const * data;
	};


	// определите методы begin / end
	typename const_iterator begin() const {
		typename std::list<std::vector<T>>::const_iterator it_l = data_.begin();
		typename std::vector<T>::const_iterator it_v = data_.begin()->begin();
		return VectorList::const_iterator(data_, it_l, it_v);
	};
	typename const_iterator end() const {
		return VectorList::const_iterator(data_, --data_.end(), (--data_.end())->end());
	};

	// определите const_reverse_iterator
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	// определите методы rbegin / rend
	const_reverse_iterator rbegin() const { 
		return (const_reverse_iterator(this->end()));
	}
	const_reverse_iterator rend()   const {
		return (const_reverse_iterator(this->begin()));
	}


private:
	ListT data_;
};

#ifdef Elf_
struct Unit {
	virtual ~Unit() {};

	virtual std::string name() { return u; };

	std::string u = "Unit";
};

struct Orc : public Unit {
	std::string name() { return "Orc"; };
};

struct Dwarf : public Unit {
	std::string name() { return "Dwarf"; };
};

struct Elf : public Unit {
//protected:
	std::string name() { return e; };

	std::string e = "Elf";
};


struct Archer {
	//std::string name() { return a; };
	std::string a = "Archer";
};

struct ElfArcher : public Elf, public Archer {
	std::string ea = "ElfArcher";
};
#endif

int main()
{

	/*VectorList<char> vlist;

	std::vector<char> v1;
	v1.push_back('A');
	v1.push_back('B');
	v1.push_back('C');

	std::vector<char> v2;
	v2.push_back('D');
	v2.push_back('E');
	v2.push_back('F');
	v2.push_back('G');
	vlist.append(v1.begin(), v1.end());
	vlist.append(v2.begin(), v2.end());*/

	VectorList<int> vlist;

	std::vector<int> v1 = { 0, 1, 2 };
	std::vector<int> v2 = { 3, 4 };
	std::vector<int> v3 = { 5, 6, 7 };
	std::vector<int> v4 = { 8 };

	vlist.append(v1.begin(), v1.end());
	vlist.append(v2.begin(), v2.end());
	vlist.append(v3.begin(), v3.end());
	vlist.append(v4.begin(), v4.end());

	auto i = vlist.begin();

	/*std::cout << "Size is " << vlist.size() << std::endl;
	std::cout << "begin is " << *i << std::endl;
	std::cout << "std::distance(begin,end) " << (std::distance(vlist.begin(), vlist.end())) << std::endl;
	std::cout << "*(++begin) == 0 ? " << (*++vlist.begin() == 0 ) << std::endl;
	std::cout << "*(++begin) == 1 ? " << (*++vlist.begin() == 1 ) << std::endl;
	std::cout << "*(++begin) != 'C'? " << (*++vlist.begin() != 'C') << std::endl << std::endl;

	std::cout << "Test ++i" << std::endl;
	for (i = vlist.begin(); i != vlist.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test i++" << std::endl;
	for (i = vlist.begin(); i != vlist.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test --i" << std::endl;
	for (i = vlist.end(); i != vlist.begin();)
		std::cout << *--i << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test i--" << std::endl;
	for (i = vlist.end(); i != vlist.begin();) {
		i--;
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
	auto j = vlist.rbegin();
	std::cout << "rbegin is " << *j << std::endl;
	j = --vlist.rend();
	std::cout << "--rend is " << *j << std::endl;

	std::cout << "Test reverse_const_iterator ++" << std::endl;
	for (j = vlist.rbegin(); j != vlist.rend(); ++j)
		std::cout << *j << " ";
	std::cout << std::endl;*/

	auto ptr = &i;

#ifdef Elf_1
	ElfArcher E;

	std::cout << "E.name() " << E.name() << std::endl;

	srand((unsigned int)time(0));
	int seed = rand() % 3;
	
	Unit * U = nullptr;

	switch (seed) {
	case 0: U = new Elf(); break;
	case 1: U = new Orc(); break;
	case 2: U = new Dwarf(); break;
	}
	
	if (dynamic_cast<Orc*>(U)) std::cout << "Orc";
	else if (dynamic_cast<Elf*>(U)) std::cout << "Elf";
	else if (dynamic_cast<Dwarf*>(U)) std::cout << "Dwarf";
	
	std::cout << "\nRAND_MAX " << RAND_MAX;

	delete U;
	
	Unit * UnitPtr = nullptr;
	delete UnitPtr;
#endif

#ifdef iterator_traits_info
	//typedef std::iterator_traits<std::vector<double>::iterator> ItType;
	std::list<int>::iterator it;
	typedef std::iterator_traits<decltype(it)> ItType;
	
	std::cout << typeid(ItType::difference_type).name() << std::endl;
	std::cout << typeid(ItType::value_type).name()<< std::endl;
	std::cout << typeid(ItType::pointer).name() << std::endl;
	std::cout << typeid(ItType::reference).name() << std::endl;
	std::cout << typeid(ItType::iterator_category).name() << std::endl;
	std::cout << "sizeof pointer\t" << sizeof(ItType::pointer) << std::endl;
	std::cout << "sizeof valType\t" << sizeof(ItType::value_type) << std::endl;
#endif

	std::cin.get(); //вместо _getch() и system("pause")
	return 0;
}
