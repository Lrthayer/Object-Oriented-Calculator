// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT 100
//
// Array; basic default constructor, create a default array for usage later
//
template <typename T>
Array_Base <T>::Array_Base (void)
	:
	cur_size_B(0),
	data_B(0)
{
	this->data_B = new T[DEFAULT];
}

//
// Array (size_t); same as default except add length to default and make the length the new current size of the array
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
	:
	cur_size_B(length),
	data_B(new T[length + DEFAULT])
{

}

//
// Array (size_t, char); same as size_t constructor except fill in new array will fill
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
	:
	cur_size_B(length),
	data_B(new T[length + DEFAULT])
{
	this->fill(fill);
}

//
// Array (const Array &); copy constructor
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
	:
	cur_size_B (array.cur_size_B),
	data_B(new T[cur_size_B])
{
	for ( int i = 0; i < this->cur_size_B; i++ )
	{
		this->data_B[i] = array.data_B[i];
	}
}
//
// ~Array
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	delete [] this->data_B;
}

//
// operator [],
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if (index < this->cur_size_B)
	{
		return this->data_B[index];
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if (index < this->cur_size_B)
	{
		return this->data_B[index];
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	if(index < this->cur_size_B)
	{
		return  this->data_B[index];
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if (index <= this->cur_size_B)
	{
		this->data_B[index] = value;
	}
	else
	{
		throw std::out_of_range("index out of range");
	}
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
		for (int i=0; i < this->cur_size_B ; i++)
		{
			if (this->data_B[i] == value)
			{
				return i;
			}
		}
		return -1;
}

//
// find (char, size_t)
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	if (start < this->cur_size_B)
	{
		for (int i=start; i < this->cur_size_B ; i++)
		{
			if (this->data_B[i] == val)
			{
				return i;
			}
		}
	}
	else
	{
		throw std::out_of_range("index out of range");
	}

	return -1;
}

//
// operator ==, check whether two arrays are equalivant or not
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if(this->cur_size_B == rhs.cur_size_B)
	{
		for (int i=0; i < this->cur_size_B ; i++)
		{
			if (this->data_B[i] != rhs.data_B[i])
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return !((*this) == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	for (int i=0; i < this->cur_size_B ; i++)
	{
		this->data_B[i] = value;
	}
}
