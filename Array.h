#pragma once
#include <list>

template <class T, class Allocator = std::allocator<T>>
class Array
{
public:
	//   êîíñòðóêòîð êëàññà
	//	 ìåòîäû ñ ïàðàìåòðàìè ïî óìîë÷àíèþ íå ìîãóò áûòü îïðåäåëåíû âíå êëàññà
	explicit Array(size_t size, const T& value = T())
		: size_(size) {
		//std::cout << this << " constructor\n"; 

		data_ = (T*)new char[size_ * sizeof(T)];
		//T * Pdata = data_;

		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(value);
	};

	//   êîíñòðóêòîð ïî óìîë÷àíèþ
	Array();

	//   äåñòðóêòîð
	~Array();

	//   êîíñòðóêòîð êîïèðîâàíèÿ
	Array(const Array & other);
	Array(const std::vector<T> & other);

	//	 îïåðàòîð ïðèñâàèâàíèÿ
	Array& operator=(const Array & other);

	//	 ïåðåìåùàþùèé êîíñòðóêòîð
	Array(Array && s) {
		swap(s);
		s.data_ = nullptr; 
		s.size_ = 0;
	}

	//	 ïåðåìåùàþùèé îïåðàòîð ïðèñâàèâàíèÿ
	Array & operator=(Array && s) {
		
		swap(s);

		return *this;
	}

	void swap(Array &other);
	//   âîçâðàùàåò ðàçìåð ìàññèâà (êîëè÷åñòâî ýëåìåíòîâ).
	size_t size() const;
	//T * data() const { return data_; };

	//   äâå âåðñèè îïåðàòîðà äîñòóïà ïî èíäåêñó
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


#include "Array_impl.h"





