#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <math.h>
#include <time.h>
using namespace std;
Array::Array(const Array::size_type	n)
{
	First = 0;
	Count = size_array = n;
	data = new value_type[size_array];
	for
		(UINT i = 0; i < size_array; i++)
		data[i] = 0;
}
Array::Array(const iterator first, const iterator last)
throw
(bad_alloc, invalid_argument)
{
	First = 0
		;
	if
		(first <= last)

	{
		Count = size_array = (last
			- first) + 1;
		data = new value_type[size_array];
		for
			(UINT i = 0; i < size_array; ++i)
			data[i] = 0;

	}
	else
		throw invalid_argument
		("!!!");
}
Array::Array(const size_type first, const size_type last)
throw
(bad_alloc, invalid_argument)
{
	if
		(first <= last)

	{
		First = first
			;
		Count = size_array = (last
			- first) + 1;
		data = new value_type[size_array];
		for
			(UINT i = 0; i < size_array; ++i)
			data[i] = 0;

	}
	else
		throw invalid_argument
		("!!!");
}
Array::Array(const Array& t) throw(bad_alloc) : size_array(t.size_array), Count(t.Count), First(t.First), data(new value_type[size_array])
{
	for (UINT i = 0; i < size_array; ++i)
		data[i] = t.data[i];
}
Array::~Array() {
	delete[] data;
	data = 0;
}
Array& Array::operator =(const Array& rhs)
{
	size_array = rhs.size_array;
	Count = rhs.Count;
	First = rhs.First;
	value_type* new_data = new value_type[size_array];
	for (UINT i = 0; i < size_array; ++i)
		new_data[i] = rhs.data[i];
	delete[] data;
	data = new_data;
	return *this;
}
Array& Array::operator +(value_type x)
{
	for (UINT i = 0; i < size_array; ++i)
		this->data[i] = this->data[i] + x;
	return *this;
}
Array& Array::operator -(value_type x)
{
	for (UINT i = 0; i < size_array; ++i)
		this->data[i] = this->data[i] - x;
	return *this;
}
Array& Array::operator *(value_type x)
{
	for (UINT i = 0; i < size_array; ++i)
		this->data[i] = this->data[i] * x;
	return *this;
}
Array& Array::operator /(value_type x)
{
	for (UINT i = 0; i < size_array; ++i)
		this->data[i] = this->data[i] / x;
	return *this;
}
bool Array::operator==(const Array& rhs)const
{
	bool checker = 1;
	for (UINT i = 0; i < size_array; ++i)
	{
		if (this->data[i] != rhs.data[i])
			checker = 0;
	}
	return checker;
}
bool Array::operator!=(const Array& rhs)const
{
	return !(operator==(rhs));
}
Array::reference Array::operator[](UINT index) throw(out_of_range)
{
	if (index < size_array)
		return data[index];
	else
		throw out_of_range("Index out of range!");
}
Array::const_reference Array::operator[](UINT index) const throw(out_of_range)
{
	if (index < size_array)
		return data[index];
	else
		throw out_of_range("Index out of range!");
}
Array::UINT Array::size() const
{
	return size_array;
}
ostream& operator <<(ostream& out, const Array& tmp)
{
	for (size_t j = 0; j < tmp.size_array; j++)
		out << tmp[j] << " ";
	out << endl;
	return out;
}
istream& operator >>(istream& in, Array& tmp)
{

	for (size_t j = 0; j < tmp.size_array; j++)
	{
		in >> tmp[j];
	}
	return in;
}
