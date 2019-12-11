#pragma once
//#define PREDICAT

#include <iostream>
#include <string>
#include <fstream>

//PREDICAT LIBS
#ifdef PREDICAT
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric> //accumulate


#include "SImpleTimer.h" //time.h
#endif


//выводит контейнер на экран
template <typename ValueType,
	template <class T, class Allocator = std::allocator<T> > class Container>
void printContainer(const Container<ValueType> &v, bool is_separator = true, char separator = ' ') {
	for (const ValueType &el : v)
	{
		if (is_separator)
			std::cout << el << separator;
		else std::cout << el;
	}
	//std::cout << '\n';
}
//специализация для массива
template <typename ValueType>
void printContainer(const ValueType &v, bool is_separator = true, char separator = ' ') {
	for (auto i = std::begin(v); i != std::end(v); ++i)
	{
		if (is_separator)
			std::cout << *i << separator;
		else std::cout << *i;
	}
	//std::cout << '\n';
}
//делегирование для вызова от 2-х параметров
template <typename ValueType>
void printContainer(const ValueType &v, char separator = ' ') {
	printContainer(v, true, separator);
}
//выводит ячейки памяти контейнера на экран
template <typename ValueType,
	template <class T, class Allocator = std::allocator<T> > class Container>
void memoryContainer(Container<ValueType> &v) {
	const ValueType * ptr;

	std::cout << "Container size\t  " << sizeof(ValueType) * v.size() << '\n';
	std::cout << "Element size\t  " << sizeof(ValueType) << "\n\n";
	//std::cout << "capacity\t" << v.capacity() << '\n';
	//std::cout << "val * capacity\t" << sizeof(ValueType) * v.capacity() << '\n';

	for (const ValueType &value : v) {
		ptr = &value;

		for (int i = sizeof(value) - 1; i >= 0; --i)
		{
			std::cout << reinterpret_cast<const int *>(reinterpret_cast<const char*>(ptr) - i) << "  "
				<< *(reinterpret_cast<const ValueType *>(reinterpret_cast<const char*>(ptr) - i)) << std::endl;

			//(ValueType *)((char*)ptr + i)
			//reinterpret_cast<ValueType *>(reinterpret_cast<char*>(ptr) + i)
		}
	}
}

//учебный класс классов в WoW
class Class
{
public:
	Class() = delete;

	explicit Class(std::string _spec, std::string _name, int _lvl)
		: spec(_spec), name(_name)
	{
		if (_lvl < 0) level = abs(_lvl);
		else if (_lvl > 120) level = 120;
		else level = _lvl;
	};
	~Class() {};

	std::string getSpec() const { return spec; }
	std::string getName() const { return name; }
	int getLevel() const { return level; }

	void file_append(std::string path) {
		std::fstream f;
		f.open(path, std::fstream::out | std::fstream::app);

		if (f.is_open())
			f << *this << '\n';

		f.close();
	}

	template <template <class T, class Allocator = std::allocator<T>> class Container>
	static void file_read_eof(std::string path, Container<Class> &v) {
		std::fstream f;
		f.open(path, std::fstream::in);
		if (f.is_open())
		{
			Class msg;
			while (true)
			{
				f >> msg;
				if (f.eof()) break;
				v.push_back(msg);
			}
		}

		f.close();
	}

private:
	std::string spec;
	std::string name;
	int level;

	friend std::ostream& operator<<(std::ostream& os, const Class &cl);
	friend std::istream& operator>>(std::istream& is, Class &cl);
};

//сравнение по всем полям
bool operator==(const Class &left, const Class &right) {
	return (
		left.getSpec() == right.getSpec() &&
		left.getName() == right.getName() &&
		left.getLevel() == right.getLevel()
		);
};
//сравнение только по уровню
bool operator<(const Class &left, const Class &right) {
	return (
		left.getLevel() < right.getLevel()
		/*&&
		left.getName() < right.getName() &&
		left.getSpec() < right.getSpec()*/
		);
};

std::ostream& operator<<(std::ostream& os, const Class &cl) {
	if (cl.getLevel() < 100)
		os << cl.level << "  " << cl.spec << " " << cl.name;
	else os << cl.level << " " << cl.spec << " " << cl.name;
	return os;
}

std::istream& operator>>(std::istream& is, Class &cl) {

	is >> cl.level >> cl.spec >> cl.name;

	return is;
}


#ifdef PREDICAT

std::vector<Class> vlc = {
	Class("Druid", "Balance", 15),
	Class("Death Knight", "Frost", 55),
	Class("Death Knight", "Anholy", 90),
	Class("Paladin", "Holy", 100),
	Class("Priest", "Shadow", 79),
	Class("Death Knight", "Blood", 120),
	Class("Shaman", "Elemental", 50),
	Class("Mage", "Fire", 82),
	Class("Warrior", "Furi", 84),
	Class("Rogue", "Assasination", 120),
	Class("Warrior", "Arms", 11),
	Class("Druid", "Feral", 11),
	Class("Warrior", "Protection", 60),

};

std::vector<Class> c1 = {
	Class("Druid", "Balance", 15),
	Class("Death Knight", "Frost", 55),
	Class("Death Knight", "Frost", 55),
	Class("Warrior", "Furi", 90),
	Class("Warrior", "Furi", 90),
	Class("Warrior", "Furi", 90),
};
std::vector<Class> c2 = {
	Class("Druid", "Balance", 15),
	Class("Death Knight", "Frost", 55),
	Class("Warrior", "Furi", 90),
};

////бинарный предикат
//bool(*predicat)(const Class&, const Class&) = [](const Class& class_a, const Class& class_b)->bool {
//	return class_a.getLevel() < class_b.getLevel();
//};
////сортировка
//sort(vlc.begin(), vlc.end(), predicat);
////удаление(смещение вконец) с условием(унарный предикат)
//vlc.erase(remove_if(vlc.begin(), vlc.end(), [](const Class &cl) {return cl.getName() == "Warrior";})
//	,vlc.end());
////поиск минимального и максимального элементов
//auto minmax = minmax_element(vlc.begin(), vlc.end());
//std::cout << *minmax.first << '\n' << *minmax.second << "\n\n";
//printContainer(vlc, '\n');
////сравнение двух контейнеров
//std::cout << equal(std::begin(c1), std::end(c1), std::begin(c2), std::end(c2));
////удаление идущих подряд повторяющихся элементов контейнера
//auto to_unique = std::unique(c1.begin(), c1.end());
//c1.erase(to_unique, c1.end());
//printContainer(c1, '\n');

std::vector<int> iv = { 1, -9, -9, 1, 1, 4, 4, 3, 4, 1 };
std::list<int> unique_iv;

std::vector<int> v1 = { 3, 2, 8, 3, 0, 9, 6 };
std::vector<int> v2 = { 3, 2, 1, 3, 5, 9, 6 };

int m[] = { 0, 1, 2, 3, 4, 5, 6 };
int m2[] = { 3, 2, 8, 4, 2, 9, 6 };

////удаление элементов контейнера с помощью метода erase и алгоритма с предикатом remove_if
////iv.erase(remove_if(iv.begin(), iv.end(), [](const int &i) {return i == 1; }), iv.end());
////произведение(перемножение) всех нечётных(odd) элементов
//auto result = accumulate(iv.begin(), iv.end(), 1, [](const int &result, const int &element) {
//	if (element % 2 != 0)
//	return result * element;
//	else return result;
//});
////запись всех элементов контейнера в строку с разделителями
//std::string str = accumulate(next(iv.begin()), iv.end(), std::to_string(*iv.begin()),
//	[](const std::string &result, const int &element) {
//
//	return result + ' ' + std::to_string(element);
//	}
//);
////запись всех элементов массива в строку с разделителями
//std::string result = std::accumulate(std::begin(m), std::end(m), std::to_string(*std::begin(m)),
//	[](std::string result, int el) {
//	return result + " | " + std::to_string(el);
//});
////printContainer(m);
//std::cout << result;
////добавление элементов в вектор с помощью алгоритма for_each
////перегрузка для массива std::for_each (определена в пространстве имён std)
//std::for_each(std::begin(m),  std::end(m),  [&v1](const int &el) {v1.push_back(el); });
//std::for_each(std::begin(m2), std::end(m2), [&v2](const int &el) {v2.push_back(el); });
//auto comparator = [](const int &a, const int &b) { return a == b; };
//std::vector<std::pair<int, int>> pairs;
////тестовый предикат, записывающий пары нессответсвующих значений в контейнер pair
//auto multi_comparator = [&pairs](const int &a, const int &b) {
//	if (a != b)
//		pairs.push_back(std::pair<int, int>(a, b));
//		
//	return true;
//};
////сравнение двух контейнеров с возвращением пары итераторов на первое несоответствующее значение
////или на конец контейнера
//auto mis = mismatch(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2), multi_comparator);
//if (!pairs.empty())
//	for (auto &p : pairs) std::cout << p.first << ' ' << p.second << std::endl;
//else std::cout << "массивы идентичны";
////копирование неповторяющихся подряд элементов контейнера
//auto to_unique = std::unique_copy(std::begin(iv), std::end(iv), std::back_inserter(unique_iv));
//printContainer(unique_iv);
//srand(time(0));
////перемешивание элементов массива
//std::random_shuffle(std::begin(m), std::end(m));


#endif