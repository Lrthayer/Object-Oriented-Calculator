// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT 100
//
// Array; basic default constructor, create a default array for usage later
//
template <typename T>
Array <T>::Array (void)
	:
	max_size_(DEFAULT),
	Array_Base<T>::Array_Base()
{
	
}

//
// Array (size_t); same as default except add length to default and make the length the new current size of the array
//
template <typename T>
Array <T>::Array (size_t length)
	:
	max_size_(length + DEFAULT),		
	Array_Base<T>::Array_Base(length)
{
	
}

//
// Array (size_t, char); same as size_t constructor except fill in new array will fill
//
template <typename T>
Array <T>::Array (size_t length, T fill)
	:
	max_size_(length + DEFAULT),
	Array_Base<T>::Array_Base(length,fill)
{
	
}

//
// Array (const Array &); copy constructor
//
template <typename T>
Array <T>::Array (const Array & array)
	:
	max_size_(array.max_size_)
{
	this->cur_size_B = array.cur_size_B;
	delete [] this->data_B;
    	this->data_B = new T[this->max_size_];

	for ( int i = 0; i < this->cur_size_B; i++ )
	{
		this->set(i, array.get(i));
	}
}
//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =, copy private variables, delete old data_ to replace with the new one and return.
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	this->cur_size_B = rhs.size();

	delete [] this->data_B;
	this->max_size_ = rhs.max_size_;
	this->data_B = new T[this->max_size_];

	for(int i = 0; i < this->cur_size_B; i++)
	{
		this->set(i, rhs.get(i));
	}

	return *this;
}

//
// resize, if smaller than max size but not cur size just change max size, if smaller throw exception to prevent data loss, if larger delete old array to make a new array to match desired size then copy old data over.
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size < this->max_size_)
	{
		if(new_size < this->size())
		{
			throw std::out_of_range("cannot make array smaller than current amount of elements");
		}
		this->cur_size_B = new_size;
		this->max_size_ = this->cur_size_B + 10;
	}

	else if (new_size > this->max_size_)
	{
		T *temp = new T[new_size];
		for (int i=0; i < this->size() ; i++)
		{
			temp[i] = this->data_B[i];
		}
		delete [] this->data_B;
		this->data_B = temp;
		this->cur_size_B = new_size;
		this->max_size_ = this->cur_size_B + 10;
	}
}
