#pragma once
#include <iostream>
using namespace std;
class Array
{
public:
	// типи
	typedef unsigned int UINT;
	typedef int* iterator;
	typedef const int* const_iterator;
	typedef int& reference;
	typedef const int& const_reference;
	typedef int value_type;
	typedef size_t size_type;
	typedef value_type* TArray;
private:
	static const size_type minsize = 10;
	UINT size_array;
	value_type* data;
	UINT Count;
	size_type First;
public:
	// конструктори
	
	Array(const size_type n = minsize);
	Array(const Array&) throw(bad_alloc);
	Array(const iterator first, const iterator last)
		throw(bad_alloc, invalid_argument);
	Array(const size_type first, const size_type last)
		throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator =(const Array& rhs);
	Array& operator +(value_type x);
	Array& operator -(value_type x);
	Array& operator *(value_type x);
	Array& operator /(value_type x);
	bool operator==(const Array& rhs) const;
	bool operator!=(const Array& rhs)const;
	// операції індексування
	reference operator[](UINT);
	const_reference operator[](UINT) const;
	// дружні функції вводу/виводу
	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);
	// розмір
	UINT size() const;
	// ітератори
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return data + Count; }
	const_iterator end() const { return data + Count; }
	
};