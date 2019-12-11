#pragma once

	//   конструктор по умолчанию
	template <class T, class A>
	Array<T,A>::Array() :data_(0), size_(0) { //std::cout << this << " constructor empty\n";
	};

	//   деструктор
	template <class T, class A>
	Array<T, A>::~Array() {
		//std::cout << this << " destructor";
		if (data_)
		{
			//std::cout << " norm\n";
			//delete[](char*)data_;
			for (size_t i = 0; i < size_; ++i) {
				data_[i].~T();

			}
			operator delete[]((char*)data_);
		}
		//else std::cout << " empty\n";
	};

	//   конструктор копирования
	template <class T, class A>
	Array<T, A>::Array(const Array & other) {
		//std::cout << this << " copy operator\n";

		size_ = other.size_;
		data_ = (T*)new char[size_ * sizeof(T)];
		//T * Pdata = data_;

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(*(other.data_ + i));
	};

	template <class T, class A>
	Array<T, A>::Array(const std::vector<T> & other) {
		//std::cout << this << " vector to Array copy operator\n";

		size_ = other.size();
		data_ = (T*)new char[size_ * sizeof(T)];

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(other[i]);
	};

	//	 оператор присваивания
	//Array& operator=(const Array & other);
	template <class T, class A>
	Array<T, A>& Array<T, A>::operator=(const Array<T,A> & other)
	{

		if (data_ != other.data_)
		{
			//std::cout << this << " operator=";

			if (data_)
			{
				//std::cout << " full\n";

				for (size_t i = 0; i < size_; ++i) {
					data_[i].~T();
				}
				operator delete[]((char*)data_);
			}
			//else std::cout << " empty\n";

			size_ = other.size_;
			if (other.data_)
			{
				data_ = (T*)new char[size_ * sizeof(T)];

				//T * Pdata = data_;
				for (size_t i = 0; i < size_; ++i)
					new (data_ + i) T(*(other.data_ + i));
			}
			else {
				data_ = 0; //std::cout << this << " Empty data_\n";
			}
		}
		//else std::cout << this << " operator= poshel";

		return *this;
	};
	//      ↑ в типе возвращаемого значения ОБЯЗАТЕЛЬНО указываются параметры шаблона

	//	 меняется местами с другим обьектом
	template <class T, class A>
	void Array<T, A>::swap(Array &other) {
		T * data_temp = data_;
		data_ = other.data_;
		other.data_ = data_temp;

		size_t size_temp = size_;
		size_ = other.size_;
		other.size_ = size_temp;
	};

	//   возвращает размер массива (количество элементов).
	template <class T, class A>
	size_t Array<T, A>::size() const { return size_; };
	//T * data() const { return data_; };

	//   две версии оператора доступа по индексу
	template <class T, class A>
	T& Array<T,A>::operator[](size_t i) { //std::cout << this << " operator[]\n"; 
		if ((i < size_) && (i >= 0)) return data_[i]; else return data_[0];
	};
	template <class T, class A>
	const T& Array<T, A>::operator[](size_t i) const { //std::cout << this << " operator[] const\n";  
		if ((i < size_) && (i >= 0)) return data_[i]; else return data_[0];
	};

	template <class T, class A>
	T& Array<T, A>::get(size_t i) { return data_[i]; };
	template <class T, class A>
	const T& Array<T, A>::get(size_t i) const { return data_[i]; };

	//T& at(size_t i) { return data_[i]; };
	//const T& at(size_t i) const { return data_[i]; };

	template <class T, class A>
	T* Array<T, A>::begin() { return &data_[0]; }
	template <class T, class A>
	T* Array<T, A>::end() { return &data_[size_]; }


template <>
class Array<bool> {
public:
	static unsigned int const INTBITS = 8 * sizeof(unsigned int); //32
	explicit Array(size_t size)
		: size_(size),
		data_(new unsigned int[size_ / INTBITS + 1]) // 1000/32 + 1 = 32
	{
		//std::cout << this << " bool constructor\n"; 
	};

	bool operator[](size_t i) {

		return data_[i / INTBITS] & ((unsigned int)1 << (i % INTBITS));
		//в каком int искать бит     //какой по счёту бит
	};

private:
	size_t size_;
	unsigned int * data_;
};

// класс Array не разбитый на объявление и определение
/*
#include <list>

template <typename T, class Allocator = std::allocator<T>>
class Array
{
public:
	typedef T value_type;
	//   конструктор класса
	explicit Array(size_t size, const T& value = T())
		: size_(size) {
		//std::cout << this << " constructor\n";

		data_ = (T*)new char[size_ * sizeof(T)];
		//T * Pdata = data_;

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(value);
	};

	//   конструктор по умолчанию
	Array() :data_(0), size_(0) { //std::cout << this << " constructor empty\n";
	};

	//   деструктор
	~Array() {
		//std::cout << this << " destructor";
		if (data_)
		{
			//std::cout << " norm\n";
			//delete[](char*)data_;
			for (size_t i = 0; i < size_; ++i) {
				data_[i].~T();

			}
			operator delete[]((char*)data_);
		}
		//else std::cout << " empty\n";
	};

	//   конструктор копирования
	Array(const Array & other) {
		//std::cout << this << " copy operator\n";

		size_ = other.size_;
		data_ = (T*)new char[size_ * sizeof(T)];
		//T * Pdata = data_;

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(*(other.data_ + i));
	};

	Array(const std::vector<T> & other) {
		//std::cout << this << " vector to Array copy operator\n";

		size_ = other.size();
		data_ = (T*)new char[size_ * sizeof(T)];

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(other[i]);
	};

	//	 оператор присваивания
	Array& operator=(const Array & other)
	{

		if (data_ != other.data_)
		{
			//std::cout << this << " operator=";

			if (data_)
			{
				//std::cout << " full\n";

				for (size_t i = 0; i < size_; ++i) {
					data_[i].~T();
				}
				operator delete[]((char*)data_);
			}
			//else std::cout << " empty\n";

			size_ = other.size_;
			if (other.data_)
			{
				data_ = (T*)new char[size_ * sizeof(T)];

				//T * Pdata = data_;
				for (size_t i = 0; i < size_; ++i)
					new (data_ + i) T(*(other.data_ + i));
			}
			else {
				data_ = 0; //std::cout << this << " Empty data_\n";
			}
		}
		//else std::cout << this << " operator= poshel";

		return *this;
	};

	void swap(Array &other) {
		T * data_temp = data_;
		data_ = other.data_;
		other.data_ = data_temp;

		size_t size_temp = size_;
		size_ = other.size_;
		other.size_ = size_temp;
	};
	//   возвращает размер массива (количество элементов).
	size_t size() const { return size_; };
	//T * data() const { return data_; };


	//   две версии оператора доступа по индексу
	T& operator[](size_t i) { //std::cout << this << " operator[]\n";
		if ((i < size_) && (i >= 0)) return data_[i]; else return data_[0];
	};
	const T& operator[](size_t i) const { //std::cout << this << " operator[] const\n";
		if ((i < size_) && (i >= 0)) return data_[i]; else return data_[0];
	};

	T& get(size_t i) { return data_[i]; };
	const T& get(size_t i) const { return data_[i]; };

	T& at(size_t i) { return data_[i]; };
	const T& at(size_t i) const { return data_[i]; };

	T* begin() { return &data_[0]; }
	T* end() { return &data_[size_]; }

private:
	size_t size_;
	T * data_;

};

template <>
class Array<bool> {
public:
	static unsigned int const INTBITS = 8 * sizeof(unsigned int); //32
	explicit Array(size_t size)
		: size_(size),
		data_(new unsigned int[size_ / INTBITS + 1]) // 1000/32 + 1 = 32
	{
		//std::cout << this << " bool constructor\n";
	};

	bool operator[](size_t i) {

		return data_[i / INTBITS] & ((unsigned int)1 << (i % INTBITS));
		//в каком int искать бит     //какой по счёту бит
	};

private:
	size_t size_;
	unsigned int * data_;
};
*/
