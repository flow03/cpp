#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream> //std::stringstream и std::ostringstream
#include <iterator> // дл€ использовани€ ostream_iterator

#include "Array.h"

template <class T, class U>
void copy_n(T * doubles, U * ints, size_t count) {
	for (size_t i = 0; i < count; ++i)
		doubles[i] = T(ints[i]);
};

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };


template <typename T, typename Comp>
T minimum(const Array<T> & Array, Comp less) {
	T min = Array[0];
	for (size_t i = 0; i < Array.size(); ++i)
		if (less(Array[i], min)) min = Array[i];

	return min;
};

template <class T>
void flatten(const T& Array, std::ostream& os) {
	//for (size_t i = 0; i < Array.size(); ++i)
	os << Array << ' ';
};

template <class T>
void flatten(const Array<T>& Array, std::ostream& os) {
	for (size_t i = 0; i < Array.size(); ++i) //2
		flatten(Array[i], os);
};

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
	ValueHolder(const T &value) :data_(value) { //std::cout << this << " constructor\n";
	};

	//ValueHolder(const ValueHolder &other) {
	//std::cout << this << " copy constructor\n";
	//data_ = other.data_;};

	~ValueHolder() { //std::cout << this << " destructor\n";
	};

	virtual ValueHolder* clone() const {
		return new ValueHolder<T>(*this);
	};

	T data_;
};

class Any
{
public:
	Any() : anydata_(0) { //std::cout << this << " constructor Any empty\n"; 
	};

	template<class Type>
	Any(const Type & data) : anydata_(new ValueHolder<Type>(data)) { //std::cout << this << " constructor Any\n";
	};

	~Any() {
		//std::cout << this << " destructor Any";
		if (anydata_) { //std::cout << " normal\n"; 
			delete anydata_;
		}
		//else std::cout << " empty\n";
	};


	Any(const Any & other) {
		if (other.anydata_)
			anydata_ = other.anydata_->clone();
	};

	//template <class Type>
	Any& operator=(const Any & other) {
		if (anydata_ != other.anydata_)
		{
			if (anydata_) delete anydata_;

			if (other.anydata_)
				anydata_ = other.anydata_->clone();
			else anydata_ = 0;

			return *this;
		}
	};

	template <class T>
	Any& operator=(const T & other) {

		if (anydata_) delete anydata_;

		if (other)
			anydata_ = new ValueHolder<T>(other);
		else anydata_ = 0;

		return *this;
	};


	template <class Type>
	Type * cast() const {
		if (anydata_)
		{
			ValueHolder<Type> * f = dynamic_cast<ValueHolder<Type>*>(anydata_);

			if (f) return &f->data_;
			else return 0;
		}
		else return 0;

	};

private:
	ICloneable * anydata_;
};


template <class T1, class T2>
struct SameType {
	SameType() { std::cout << "\ndifferent types\n"; };

	static const bool value = false;
};

template <class T>
struct SameType <T, T> {
	SameType() { std::cout << "\nsame types\n"; };

	static const bool value = true;
};

template <>
struct SameType <int, int> {
	SameType() { std::cout << "\nint int\n"; };

	static const bool value = 1;
};


template <typename TypeZ, size_t size>
size_t array_size(TypeZ(&ar)[size]) { return size; };

//---------------------------------------------------
//---------------------------------------------------

std::string std::to_string(int i);

template<typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

template<>
std::string toString<int>(const int& i) {
	std::stringstream ss;
	ss << i;
	std::string str;
	ss >> str;
	return str;
};

//int std::stoi(const std::string& str, size_t *pos = 0, int base = 10);

//template< template<typename, typename> class Container>

template <typename ValueType,
	template <class T, class Allocator = std::allocator<T> > class Container>
Container<std::string> toStrings(Container<ValueType> const& ar) {
	std::cout << "toStrings template called\n";

	Container<std::string> result(ar.size());
	for (size_t i = 0; i != ar.size(); ++i)
		result.get(i) = std::to_string(ar.get(i));

	return result;
};

template <class ValueType>
std::vector<std::string> toStrings(std::vector<ValueType> const& ar) {
	std::cout << "toStrings vector template called\n";
	std::vector<std::string> result(ar.size());
	for (size_t i = 0; i != ar.size(); ++i)
		result.at(i) = toString(ar.at(i));
	return result;
};

template <class ValueType>
std::list<std::string> toStrings(std::list<ValueType> const& ar) {
	std::cout << "toStrings list template called\n";

	std::list< std::string > result;

	std::list< int >::const_iterator it_int = ar.begin();

	for (size_t i = 0; i != ar.size(); ++i)
	{
		result.push_back(std::to_string(*it_int));
		it_int++;
	}

	return result;
};


template <class Container>
bool contains(Container const& Cont, typename Container::value_type const& value)
{
	for (size_t i = 0; i < Cont.size(); ++i)
		if (value == Cont[i]) return true;
	return false;
};

// исключени€
/*
	std::string str1 = "9857";
	try {
		std::cout << std::endl<< stoi(str1) << std::endl;
		//throw 1;
	}
	catch (std::exception& e) {
		std::cout << "a standard exception was caught, with message '" << e.what() << "'\n";
	}
	catch (std::invalid_argument) {
		std::cout << "\ninvalid_argument\n";
		//return 0;
	}
	catch (std::out_of_range) {
		std::cout << "\nout_of_range\n";
		//return 0;
	}
	catch (...) {
		std::cout << "\netc\n";
		//return 0;
	}
	*/

struct String {
	String(const char *s = "")
	{
		size = strlen(s);
		str = new char[size + 1];
		strcpy_s(str, size + 1, s);
	}

	String(size_t n, char c) :size(n)
	{
		str = new char[size + 1];
		for (size_t i = 0; i != size; ++i)
		{
			str[i] = c;
		}
		str[size] = '\0';
	}

	/* и деструктор */
	~String(){delete[] str;}

	void append(String &other)
	{
		size_t NewSize = (this->size) + other.size;
		char* NewStr = new char[NewSize + 1];
		//копирование элементов первого массива
		for (size_t i = 0; i != this->size; ++i)
		{
			NewStr[i] = this->str[i];
		}
		//дописывание вконец элементов второго массива
		for (size_t i = (this->size), i0 = 0; i != NewSize; ++i)
		{
			NewStr[i] = other.str[i0];
			++i0;
		}
		NewStr[NewSize] = '\0';

		delete[] this->str;
		this->str = NewStr;
		this->size = NewSize;
	}

	explicit operator char const *() const { return const_cast<char const*>(str); };

private:
	size_t size;
	char *str;
};