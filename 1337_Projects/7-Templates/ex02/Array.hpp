#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& right);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		~Array();
		unsigned int size() const;
};

template <typename T>
Array<T>::Array() : array(NULL), n(0){}

template <typename T>
Array<T>::Array(unsigned int n) : n(n)
{
	array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& other) : array(NULL), n(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& right)
{
	if (this != &right)
	{
		delete[] array;
		this->n = right.n;
		if (n > 0)
		{
			array = new T[n];
			for (unsigned int i = 0; i < n; i++)
			{
				this->array[i] = right.array[i];
			}
		}
		else
			array = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->n);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= n)
		throw std::out_of_range("Index out of bounds");
	return (array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= n)
		throw std::out_of_range("Index out of bounds");
	return (array[index]);
}

#endif