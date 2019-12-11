#pragma once
#include <list>

template <class T, class Allocator = std::allocator<T>>
class Array
{
public:
	//   ����������� ������
	//	 ������ � ����������� �� ��������� �� ����� ���� ���������� ��� ������
	explicit Array(size_t size, const T& value = T())
		: size_(size) {
		//std::cout << this << " constructor\n"; 

		data_ = (T*)new char[size_ * sizeof(T)];
		//T * Pdata = data_;

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(value);
	};

	//   ����������� �� ���������
	Array();

	//   ����������
	~Array();

	//   ����������� �����������
	Array(const Array & other);
	Array(const std::vector<T> & other);

	//	 �������� ������������
	Array& operator=(const Array & other);

	//	 ������������ �����������
	Array(Array && s) {
		swap(s);
		s.data_ = nullptr; 
		s.size_ = 0;
	}

	//	 ������������ �������� ������������
	Array & operator=(Array && s) {
		
		swap(s);

		return *this;
	}

	void swap(Array &other);
	//   ���������� ������ ������� (���������� ���������).
	size_t size() const;
	//T * data() const { return data_; };

	//   ��� ������ ��������� ������� �� �������
	T& operator[](size_t i);
	const T& operator[](size_t i) const;

	T& get(size_t i);
	const T& get(size_t i) const;

	//T& at(size_t i);
	//const T& at(size_t i) const;

	T* begin();
	T* end();

private:
	size_t size_;
	T * data_;
};


//---------------------Sonya--------------------------
/*
template <class T>
class Sonya {
public:
	Sonya(T v);
	Sonya() :vafelka(0) {};
	T & operator [](size_t i);
	~Sonya();
private:
	T vafelka;
};

template <class T>
Sonya<T>::Sonya(T v) : vafelka (v) {}

template <class T> 
T & Sonya<T>::operator [](size_t i){return i;}

template <class T> Sonya<T>::~Sonya() {}
*/

#include "Array_impl.h"





