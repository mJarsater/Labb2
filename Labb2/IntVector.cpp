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
	int j = 0;
	for (auto i: list)
	{
		data[j++] = i;
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
	int* temp = new int[length];
	
	for (int i = 0; i < length; i++) {
		temp[i] = data[i];
		
	}
	delete[] data;
	data = temp;
	data[length - 1] = element;


	//Allokera nytt utrymme som är 1 större än det gamla + kopiera.
	//Avalloker det gamla utrymmet.
	
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

//Destruktor

IntVector:: ~IntVector() {
	delete[] data;
}



std::ostream& operator<<(std::ostream& os, const IntVector& t)
{
	// TODO: insert return statement here
	for (int i = 0; i < t.size(); i++)
		os << t.data[i] <<" ";
	return os;
}
