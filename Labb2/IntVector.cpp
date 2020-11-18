// Martin Jarsäter
// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner
#include "IntVector.h"
#include <stdexcept>


// Standard-konstruktor
IntVector::IntVector() :length(0), data(new int[length])
{
	
}

// Konstruktor för { element }
IntVector::IntVector(std::initializer_list<int> list) :length(list.size()), data(new int[length])
{
	std::initializer_list<int>::iterator it = list.begin();
	for (int i = 0; i < length; i++)
	{
		data[i] = *it++;
	}
}


// Copy-konstuktor
IntVector::IntVector(const IntVector& other) :length(other.length), data(new int[length])
{
	for (int i = 0; i < length; i++)
		data[i] = other.data[i];

}


// Returnera Storleken på listan
int IntVector::size()const {
	return length;
}


// Lägga till i listan
void IntVector::push_back(int element)
{
	length += 1;

	data[length - 1] = element;
	// Lägg till i arrayen
}


// Index-operator
int& IntVector::operator[](int index)const
{
	if (index < 0 || index >= length)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

// Tilldelnings-operator
IntVector const IntVector::operator=(const IntVector& other)
{
	if (this != &other)
	{
		delete[] data;
		length = other.length;
		data = new int[length];
		for (int i = 0; i < length; i++)
			data[i] = other.data[i];
	}
	return *this;
}



std::ostream& operator<<(std::ostream os, IntVector& t)
{
	// TODO: insert return statement here
	for (int i = 0; i < t.size(); i++)
		os << t.data;
	return os;
}
