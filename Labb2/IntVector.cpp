// Martin Jarsäter
// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner
#include "IntVector.h"
#include <stdexcept>


// Standard-konstruktor
IntVector::IntVector() :length(0), data(new int[length])
{
	
}

// Konstruktor för { element }
IntVector::IntVector(std::initializer_list<int>)
{

}


// Copy-konstuktor
IntVector::IntVector(const IntVector& other):length(other.length)
{
	for (int i = 0; i < length; i++)
		data[i] = other.data[i];
}

// Copy-konstuktor
IntVector::IntVector(IntVector& other) :length(other.length)
{
	for (int i = 0; i < length; i++)
		data[i] = other.data[i];

}


// Returnera Storleken på listan
int const IntVector::size() {
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
int& const IntVector::operator[](int index)
{
	if (index < 0 || index >= length)
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

// Tilldelnings-operator
IntVector IntVector::operator=(const IntVector& other)
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


// Cout operator
